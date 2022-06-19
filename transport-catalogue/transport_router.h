#pragma once

#include "domain.h"
#include "router.h"
#include "transport_catalogue.h"

namespace transport_router {

class TransportRouter {
public:
    TransportRouter() = default;
    TransportRouter(const TransportRouter&) = delete;
    TransportRouter(TransportRouter&&) = default;
    TransportRouter(const transport_base::TransportCatalogue& base);
    
    TransportRouter& operator=(const TransportRouter&) = delete;
    TransportRouter& operator=(TransportRouter&&) = default;
    
    ~TransportRouter() = default;
    
    void SetRouter(domain::TransportRouterSettings&& settings);
    std::optional<domain::RouteInfo> BuildRoute(std::optional<std::reference_wrapper<const domain::Stop>> from,
                                                std::optional<std::reference_wrapper<const domain::Stop>> to) const;
    operator transport_base::TransportCatalogue() const;
    std::optional<domain::RouteInfo> BuildRoute(int from_id, int to_id) const;
    template<typename Catalogue>
    void UpdateRouter(const Catalogue& catalogue);
private:
    template<typename Iter, typename Catalogue>
    void AddRouteToGraph(Iter begin, Iter end, int bus_id, const Catalogue& catalogue);
    
private:
    //data
    using Graph = graph::DirectedWeightedGraph<double>;
    
    std::unique_ptr<Graph> graph_ptr_ = nullptr;
    std::unique_ptr<graph::Router<double>> router_ptr_ = nullptr;
    domain::TransportRouterSettings router_settings_;
    std::unordered_map<size_t, size_t> bus_and_edges_; //[EdgeId, BusId]
};

template<typename Catalogue>
void TransportRouter::UpdateRouter(const Catalogue& catalogue) {
    graph_ptr_ = std::make_unique<Graph>(catalogue.StopCount());
    for(const auto& next_bus : catalogue) {
        for(auto head_stop = next_bus.route.begin(); head_stop + 1 != next_bus.route.end(); ++head_stop) {
            AddRouteToGraph(head_stop, next_bus.route.end(), next_bus.id, catalogue);
        }
    }
    router_ptr_ = std::make_unique<graph::Router<double>>(*graph_ptr_);
}

template<typename Iter, typename Catalogue>
void TransportRouter::AddRouteToGraph(Iter begin, Iter end, int bus_id, const Catalogue& catalogue) {
    double current_weight = router_settings_.bus_wait_time;
    size_t current_span_count{};
    for(auto i = begin; i + 1 != end; ++i) {
        current_weight += 0.001 * catalogue.GetSpanDistance(*i, *(i + 1)) / router_settings_.bus_velocity * 60; //min
        graph::Edge<double> next_edge{static_cast<size_t>(*begin),
                                      static_cast<size_t>(*(i + 1)),
                                      current_weight,
                                      ++current_span_count};
        size_t next_edge_id = graph_ptr_->AddEdge(next_edge);
        bus_and_edges_[next_edge_id] = bus_id;
    }
}

} //transport_router
