#include "transport_router.h"

using namespace transport_router;

TransportRouter::TransportRouter(const transport_base::TransportCatalogue& base) {
    const auto& proto_graph = base.transport_router().graph();
    graph_ptr_ = std::make_unique<Graph>(proto_graph.vertex_count());
    for(size_t i = 0; i < proto_graph.edges_size(); ++i) {
        const auto& current_proto_edge = proto_graph.edges(i);
        auto edge_id = graph_ptr_->AddEdge(graph::Edge<double>{current_proto_edge.from_id(),
                                                               current_proto_edge.to_id(),
                                                               current_proto_edge.weight(),
                                                               current_proto_edge.span_count()});
        bus_and_edges_[edge_id] = current_proto_edge.bus_id();
    }
    router_ptr_ = std::make_unique<graph::Router<double>>(*graph_ptr_);
    const auto& proto_router_settings = base.transport_router().settings();
    router_settings_ = {proto_router_settings.bus_velocity(), proto_router_settings.bus_wait_time()};
}

void TransportRouter::SetRouter(domain::TransportRouterSettings&& settings) {
    router_settings_ = std::move(settings);
}

std::optional<domain::RouteInfo> TransportRouter::BuildRoute(std::optional<std::reference_wrapper<const domain::Stop>> from,
                                                             std::optional<std::reference_wrapper<const domain::Stop>> to) const {
    return from && to ? BuildRoute(from->get().id, to->get().id) : std::nullopt;
}

std::optional<domain::RouteInfo> TransportRouter::BuildRoute(int from_id, int to_id) const {
    auto raw_result = router_ptr_->BuildRoute(from_id, to_id);
    if(!raw_result) {
        return std::nullopt;
    }
    std::vector<domain::RouteItem> items;
    items.reserve(2 * raw_result->edges.size());
    for(auto edge_id : raw_result->edges) {
        auto edge = graph_ptr_->GetEdge(edge_id);
        domain::RouteItem wait_item{domain::ItemType::WAIT,
                                    edge.from,
                                    std::string_view{}, //name will set in RequestHandler
                                    router_settings_.bus_wait_time,
                                    {}};
        items.emplace_back(std::move(wait_item));
        domain::RouteItem bus_item{domain::ItemType::BUS,
                                   bus_and_edges_.at(edge_id),
                                   std::string_view{}, //name will set in RequestHandler
                                   edge.weight - router_settings_.bus_wait_time,
                                   edge.span_count};
        items.emplace_back(std::move(bus_item));
    }
    return domain::RouteInfo{raw_result->weight, std::move(items)};
}

TransportRouter::operator transport_base::TransportCatalogue() const {
    transport_base::TransportCatalogue proto_catalogue{};
    auto& proto_router = *proto_catalogue.mutable_transport_router();
    proto_router.mutable_settings()->set_bus_wait_time(router_settings_.bus_wait_time);
    proto_router.mutable_settings()->set_bus_velocity(router_settings_.bus_velocity);
    auto& proto_graph = *proto_router.mutable_graph();
    proto_graph.set_vertex_count(graph_ptr_->GetVertexCount());
    for(const auto& [edge_id, bus_id] : bus_and_edges_) {
        auto& current_proto_edge = *proto_graph.add_edges();
        const auto& current_edge = graph_ptr_->GetEdge(edge_id);
        current_proto_edge.set_from_id(current_edge.from);
        current_proto_edge.set_to_id(current_edge.to);
        current_proto_edge.set_weight(current_edge.weight);
        current_proto_edge.set_span_count(current_edge.span_count);
        current_proto_edge.set_bus_id(bus_id);
    }
    return std::move(proto_catalogue);
}
