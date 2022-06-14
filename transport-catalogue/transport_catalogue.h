#pragma once

#include "domain.h"

#include <algorithm>
#include <cassert>
#include <functional>
#include <transport_catalogue.pb.h>

namespace transport_catalogue {

class TransportCatalogue {
private:
    using StopContainer = std::unordered_map<int, std::unique_ptr<domain::Stop>>;
    using BusContainer = std::unordered_map<int, std::unique_ptr<domain::Bus>>;
    
    class TransportCatalogueIterator final : public BusContainer::const_iterator {
    public:
        [[nodiscard]] domain::Bus& operator*();
        [[nodiscard]] domain::Bus* operator->();
    };
    
    struct pair_hash { 
        size_t operator()(const std::pair<int, int>& p) const;
    };
public:
    //ctors
    TransportCatalogue() = default;
    TransportCatalogue(const transport_base::TransportCatalogue& base);
    TransportCatalogue(transport_base::TransportCatalogue&& base);
    void operator=(const transport_base::TransportCatalogue&) = delete;
    void operator=(transport_base::TransportCatalogue&& base);
    
    //stop methods
    int AddStop(std::string_view name, geo::Coordinates&& coordinates = {}); //returns id of inserted Stop, or -1 if insertion falls
    int AddStop(int id, std::string_view name, geo::Coordinates&& coordinates = {}); //returns id of inserted Stop, or -1 if insertion falls
    void AddSpanDistance(std::string_view from, std::string_view to, size_t distance);
    void AddBusesToStop(int stop_id, const std::vector<int>& buses);
    size_t StopCount() const;
    size_t GetSpanDistance(std::string_view from, std::string_view to) const;
    size_t GetSpanDistance(int from, int to) const;
    std::optional<std::reference_wrapper<const domain::Stop>> GetStop(int stop_id) const;
    std::optional<std::reference_wrapper<const domain::Stop>> GetStop(std::string_view stop_name) const;
    std::optional<domain::StopInfo> GetStopInfo(std::string_view name) const;
    geo::Coordinates GetMinCoordinates() const;
    geo::Coordinates GetMaxCoordinates() const;
    
    //bus methods
    int AddBus(std::string_view name, domain::ROUTE_TYPE route_type, std::vector<int>&& stops = {}); //returns id of inserted Bus, or -1 if insertion falls
    int AddBus(int id, std::string_view name, domain::ROUTE_TYPE route_type, std::vector<int>&& stops = {}); //returns id of inserted Bus, or -1 if insertion falls
    size_t BusCount() const;
    std::optional<std::reference_wrapper<const domain::Bus>> GetBus(int bus_id) const;
    std::optional<std::reference_wrapper<const domain::Bus>> GetBus(std::string_view bus_name) const;
    std::optional<domain::BusInfo> GetBusInfo(std::string_view name) const;
    
    //
    operator transport_base::TransportCatalogue() const;
    TransportCatalogueIterator begin() const;
    TransportCatalogueIterator end() const;
private:
    //stops data
    StopContainer stops_;
    std::unordered_map<std::string_view, int> stop_id_by_name_;
    std::unordered_map<std::pair<int, int>, size_t, pair_hash> span_distances_;
    
    static int next_stop_id;
    
    //buses data
    BusContainer buses_;
    std::unordered_map<std::string_view, int> bus_id_by_name_;
    
    static int next_bus_id;
private:
    //void SetMinMaxCoordinates(const geo::Coordinates& coordinates);
    std::optional<domain::StopInfo> GetStopInfo(int stop_id) const;
    std::optional<domain::BusInfo> GetBusInfo(int bus_id) const;
    void ClearCatalogue();
};

inline int TransportCatalogue::next_stop_id = 0;
inline int TransportCatalogue::next_bus_id = 0;
}  //transport_catalogue
