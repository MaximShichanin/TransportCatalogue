#include "transport_catalogue.h"

using namespace transport_catalogue;

[[nodiscard]] domain::Bus& TransportCatalogue::TransportCatalogueIterator::operator*() {
    return *BusContainer::const_iterator::operator*().second;
}

[[nodiscard]] domain::Bus* TransportCatalogue::TransportCatalogueIterator::operator->() {
    return BusContainer::const_iterator::operator*().second.get();
}

size_t TransportCatalogue::pair_hash::operator()(const std::pair<int, int>& p) const {
    return std::hash<int>()(p.first) ^ std::hash<int>()(p.second);
}

TransportCatalogue::TransportCatalogue(const transport_base::TransportCatalogue& base) {
    using proto_type = transport_base::Bus;
    using domain_type = domain::ROUTE_TYPE;
        
    for(const auto& next_stop : base.stops()) {
        auto stop_id = AddStop(next_stop.id(),
                               next_stop.name(),
                               geo::Coordinates{next_stop.coordinates().latitude(), next_stop.coordinates().longitude(), false});
        for(const auto& [key, value] : next_stop.distance_to_other_stops()) {
            stops_[stop_id]->distance_to_other_stops[key] = value;
            span_distances_[{stop_id, key}] = value;
        }
    }
    for(const auto& next_bus : base.buses()) {
        std::vector<int> stops_on_route;
        stops_on_route.reserve(next_bus.route_size());
        for(int stop_id : next_bus.route()) {
            stops_on_route.emplace_back(stop_id);
        }
        auto bus_id = AddBus(next_bus.id(),
                             next_bus.name(),
                             next_bus.route_type() == proto_type::LINEAR ? domain_type::LINEAR : domain_type::CIRCLE,
                             std::move(stops_on_route));
    }
}

void TransportCatalogue::operator=(transport_base::TransportCatalogue&& base) {
    using proto_type = transport_base::Bus;
    using domain_type = domain::ROUTE_TYPE;

    ClearCatalogue();
    for(const auto& next_stop : base.stops()) {
        auto stop_id = AddStop(next_stop.id(),
                               next_stop.name(),
                               geo::Coordinates{next_stop.coordinates().latitude(), next_stop.coordinates().longitude(), false});
        for(const auto& [key, value] : next_stop.distance_to_other_stops()) {
            stops_[stop_id]->distance_to_other_stops[key] = value;
            span_distances_[{stop_id, key}] = value;
        }
    }
    for(const auto& next_bus : base.buses()) {
        std::vector<int> stops_on_route;
        stops_on_route.reserve(next_bus.route_size());
        for(int stop_id : next_bus.route()) {
            stops_on_route.emplace_back(stop_id);
        }
        auto bus_id = AddBus(next_bus.id(),
                             next_bus.name(),
                             next_bus.route_type() == proto_type::LINEAR ? domain_type::LINEAR : domain_type::CIRCLE,
                             std::move(stops_on_route));
    }
}

int TransportCatalogue::AddStop(std::string_view name, geo::Coordinates&& coordinates) {
    auto iter = stop_id_by_name_.find(name);
    if(iter == stop_id_by_name_.end()) {
        return AddStop(next_stop_id++, name, std::move(coordinates));
    }
    else {
        return coordinates.is_empty ? iter->second : AddStop(iter->second, name, std::move(coordinates));
    }
}

int TransportCatalogue::AddStop(int id, std::string_view name, geo::Coordinates&& coordinates) {
    auto iter = stops_.find(id);
    if(iter == stops_.end()) {
        domain::Stop current_stop{id, std::move(std::string(name)), std::move(coordinates)};
        auto stop_ptr = std::make_unique<domain::Stop>(std::move(current_stop));
        stop_id_by_name_[stop_ptr->name] = id;
        stops_[id] = std::move(stop_ptr);
    }
    else {
        auto& current_stop = *(iter->second);
        assert(current_stop.name == name);
        if(!coordinates.is_empty) {
            current_stop.coordinates = std::move(coordinates);
        }
    }
    return id;
}

void TransportCatalogue::AddSpanDistance(std::string_view from, std::string_view to, size_t distance) {
    int from_stop_id = AddStop(from);
    int to_stop_id = AddStop(to);
    span_distances_[{from_stop_id, to_stop_id}] = distance;
    stops_[from_stop_id]->distance_to_other_stops[to_stop_id] = distance;
}

void TransportCatalogue::AddBusesToStop(int stop_id, const std::vector<int>& buses) {
    domain::Stop& current_stop = *stops_.at(stop_id);
    for(int bus_id : buses) {
        current_stop.buses.insert(bus_id);
    }
}

size_t TransportCatalogue::StopCount() const {
    return stops_.size();
}

size_t TransportCatalogue::GetSpanDistance(std::string_view from, std::string_view to) const {
    return GetSpanDistance(stop_id_by_name_.at(from), stop_id_by_name_.at(to));
}

size_t TransportCatalogue::GetSpanDistance(int from_id, int to_id) const {
    auto iter = span_distances_.find({from_id, to_id});
    if(iter != span_distances_.end()) {
        return iter->second;
    }
    else {
        iter = span_distances_.find({to_id, from_id});
        return iter == span_distances_.end() ? 0 : iter->second;
    }
}

std::optional<std::reference_wrapper<const domain::Stop>> TransportCatalogue::GetStop(int stop_id) const {
    auto iter = stops_.find(stop_id);
    return iter == stops_.end() ? std::nullopt : 
                                  std::optional<std::reference_wrapper<const domain::Stop>>{std::cref<const domain::Stop>(*iter->second)};
}

std::optional<std::reference_wrapper<const domain::Stop>> TransportCatalogue::GetStop(std::string_view stop_name) const {
    auto iter = stop_id_by_name_.find(stop_name);
    return iter == stop_id_by_name_.end() ? std::nullopt : GetStop(iter->second);
}

std::optional<domain::StopInfo> TransportCatalogue::GetStopInfo(std::string_view stop_name) const {
    auto iter = stop_id_by_name_.find(stop_name);
    return iter == stop_id_by_name_.end() ? std::nullopt : GetStopInfo(iter->second);
}

geo::Coordinates TransportCatalogue::GetMinCoordinates() const {
    geo::Coordinates min_coordinates{};
    for(const auto& [_, next_stop_ptr] : stops_) {
        if(next_stop_ptr->buses.empty()) {
            continue;
        }
        const auto& current_coordinates = next_stop_ptr->coordinates;
        if(min_coordinates.is_empty) {
            min_coordinates = current_coordinates;
        }
        else if(current_coordinates.lat < min_coordinates.lat) {
            min_coordinates.lat = current_coordinates.lat;
        }
        else if(current_coordinates.lng < min_coordinates.lng) {
            min_coordinates.lng = current_coordinates.lng;
        }
    }
    return min_coordinates;
}

geo::Coordinates TransportCatalogue::GetMaxCoordinates() const {
    geo::Coordinates max_coordinates{};
    for(const auto& [_, next_stop_ptr] : stops_) {
        if(next_stop_ptr->buses.empty()) {
            continue;
        }
        const auto& current_coordinates = next_stop_ptr->coordinates;
        if(max_coordinates.is_empty) {
            max_coordinates = current_coordinates;
        }
        else if(max_coordinates.lat < current_coordinates.lat) {
            max_coordinates.lat = current_coordinates.lat;
        }
        else if(max_coordinates.lng < current_coordinates.lng) {
            max_coordinates.lng = current_coordinates.lng;
        }
    }
    return max_coordinates;
}

int TransportCatalogue::AddBus(std::string_view name, domain::ROUTE_TYPE route_type, std::vector<int>&& stops) {
    auto iter = bus_id_by_name_.find(name);
    if(iter == bus_id_by_name_.end()) {
        return AddBus(next_bus_id++, name, route_type, std::move(stops));
    }
    else {
        return AddBus(iter->second, name, route_type, std::move(stops));
    }
}

int TransportCatalogue::AddBus(int bus_id, std::string_view name, domain::ROUTE_TYPE route_type, std::vector<int>&& stops) {
    auto iter = buses_.find(bus_id);
    if(iter == buses_.end()) {
        domain::Bus current_bus{bus_id, std::move(std::string(name)), route_type, std::move(stops)};
        auto bus_ptr = std::make_unique<domain::Bus>(std::move(current_bus));
        bus_id_by_name_[bus_ptr->name] = bus_id;
        for(auto stop_id : bus_ptr->route) {
            AddBusesToStop(stop_id, {bus_id, });
        }
        buses_[bus_id] = std::move(bus_ptr);
    }
    else {
        if(iter->second->route.empty() && !stops.empty()) {
            iter->second->route = std::move(stops);
            for(auto stop_id : iter->second->route) {
                AddBusesToStop(stop_id, {bus_id, });
            }
        }
    }
    return bus_id;
}

size_t TransportCatalogue::BusCount() const {
    return buses_.size();
}

std::optional<std::reference_wrapper<const domain::Bus>> TransportCatalogue::GetBus(int bus_id) const {
    auto iter = buses_.find(bus_id);
    return iter == buses_.end() ? std::nullopt : 
                                  std::optional<std::reference_wrapper<const domain::Bus>>{std::cref<domain::Bus>(*iter->second)};
}

std::optional<std::reference_wrapper<const domain::Bus>> TransportCatalogue::GetBus(std::string_view bus_name) const {
    auto iter = bus_id_by_name_.find(bus_name);
    return iter == bus_id_by_name_.end() ? std::nullopt : GetBus(iter->second);
}

std::optional<domain::BusInfo> TransportCatalogue::GetBusInfo(std::string_view name) const {
    auto iter = bus_id_by_name_.find(name);
    return iter == bus_id_by_name_.end() ? std::nullopt : GetBusInfo(iter->second);
}

TransportCatalogue::operator transport_base::TransportCatalogue() const {
    transport_base::TransportCatalogue proto_catalogue{};
    for(auto& bus : *this) {
        transport_base::Bus& current_proto_bus = *proto_catalogue.add_buses();
        current_proto_bus.set_id(bus.id);
        current_proto_bus.set_name(bus.name);
        //need to set type here
        current_proto_bus.set_route_type(bus.route_type == domain::ROUTE_TYPE::LINEAR ?
                                         transport_base::Bus_ROUTE_TYPE_LINEAR :
                                         transport_base::Bus_ROUTE_TYPE_CIRCLE);
        for(auto stop_id : bus.route) {
            current_proto_bus.add_route(stop_id);
        }
    }
    for(const auto& [stop_id, stop_ptr] : stops_) {
        transport_base::Stop& current_proto_stop = *proto_catalogue.add_stops();
        current_proto_stop.set_id(stop_id);
        current_proto_stop.set_name(stop_ptr->name);
        transport_base::Coordinates& current_coordinates = *current_proto_stop.mutable_coordinates();
        current_coordinates.set_latitude(stop_ptr->coordinates.lat);
        current_coordinates.set_longitude(stop_ptr->coordinates.lng);
        auto& distance_to_other_stops = *current_proto_stop.mutable_distance_to_other_stops();
        for(const auto& [other_stop_id, distance] : stop_ptr->distance_to_other_stops) {
            distance_to_other_stops[other_stop_id] = distance;
        }
    }
    return std::move(proto_catalogue);
}

TransportCatalogue::TransportCatalogueIterator TransportCatalogue::begin() const {
    return TransportCatalogueIterator{buses_.begin()};
}

TransportCatalogue::TransportCatalogueIterator TransportCatalogue::end() const {
    return TransportCatalogueIterator{buses_.end()};
}

std::optional<domain::StopInfo> TransportCatalogue::GetStopInfo(int stop_id) const {
    auto iter = stops_.find(stop_id);
    if(iter == stops_.end()) {
        return std::nullopt;
    }
    std::vector<std::string_view> buses_via_stop;
    for(auto bus_id : iter->second->buses) {
        buses_via_stop.emplace_back(GetBus(bus_id)->get().name);
    }
    return domain::StopInfo{{}, std::move(buses_via_stop)};
}

std::optional<domain::BusInfo> TransportCatalogue::GetBusInfo(int bus_id) const {
    auto iter = buses_.find(bus_id);
    if(iter == buses_.end()) {
        return std::nullopt;
    }
    const auto& bus = *iter->second;
    domain::BusInfo bus_info;
    double geo_distance = 0.0;
    bus_info.stop_count = bus.route.size();
    for(auto stop_id_iter = bus.route.begin(); stop_id_iter + 1 != bus.route.end(); ++stop_id_iter) {
        auto stop_id_end = bus.route_type == domain::ROUTE_TYPE::LINEAR ? bus.route.begin() + bus.route.size() / 2 + 1
                                                                        : bus.route.end() - 1;
        if(stop_id_iter < stop_id_end && std::none_of(stop_id_iter + 1,
                                                      stop_id_end,
                                                      [stop_id_iter](auto rhs){return *stop_id_iter == rhs;})) {
             ++bus_info.unique_stop_count;
        }
        const auto& stop_from = GetStop(*stop_id_iter)->get();
        const auto& stop_to = GetStop(*(stop_id_iter + 1))->get();
        auto span_distance = GetSpanDistance(stop_from.id, stop_to.id);
        bus_info.route_length += span_distance;
        geo_distance += geo::ComputeDistance(stop_from.coordinates, stop_to.coordinates);
    }
    bus_info.curvature = 1.0 * bus_info.route_length / geo_distance;
    return bus_info;
}

void TransportCatalogue::ClearCatalogue() {
    stops_.clear();
    stop_id_by_name_.clear();
    span_distances_.clear();
    buses_.clear();
    bus_id_by_name_.clear();
}
