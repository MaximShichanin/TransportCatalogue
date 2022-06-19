#pragma once

#include "map_renderer.h"
#include "serialization.h"
#include "transport_catalogue.h"
#include "transport_router.h"

class RequestHandler {
public:
    RequestHandler();
    virtual ~RequestHandler();
    template<typename RequestType, typename... Contents>
    [[maybe_unused]] decltype(auto) request(RequestType type, Contents&&... content);
protected:
    RequestHandler(serialization::Serializer&& serializer);
    void Serialize() const;
    void Deserialize();
public:
    class SET_STOP{};
    class SET_BUS{};
    class SET_SPAN{};
    class SET_ROUTER{};
    class SET_RENDERER{};
    class SET_SERIALIZER{};
    class GET_STOP_INFO{};
    class GET_BUS_INFO{};
    class GET_ROUTE{};
    class GET_MAP{};
private:
    std::unique_ptr<transport_catalogue::TransportCatalogue> transport_catalogue_ptr_;
    std::unique_ptr<transport_router::TransportRouter> transport_router_ptr_;
    std::unique_ptr<map_renderer::MapRenderer> map_renderer_ptr_;
    std::unique_ptr<serialization::Serializer> serializer_ptr_;
    bool transport_router_updated_ = false;
    bool map_renderer_updated_ = false;
};

class RequestHandlerSerializer : public RequestHandler {
public:
    RequestHandlerSerializer() = default;
    ~RequestHandlerSerializer();
};

class RequestHandlerDeserializer : public RequestHandler {
public:
    RequestHandlerDeserializer();
    ~RequestHandlerDeserializer();
};

template<typename RequestType, typename... Contents>
[[maybe_unused]] decltype(auto) RequestHandler::request(RequestType, Contents&&... content) {
    using namespace std::literals;
    
    if constexpr(std::is_same_v<RequestType, SET_STOP>) {
        if(!transport_catalogue_ptr_) {
            throw std::runtime_error("TransportCatalogue does not exists\n"s);
        }
        transport_router_updated_ = false;
        map_renderer_updated_ = false;
        return transport_catalogue_ptr_->AddStop(std::forward<Contents>(content)...);
    }
    else if constexpr(std::is_same_v<RequestType, SET_BUS>) {
        if(!transport_catalogue_ptr_) {
            throw std::runtime_error("TransportCatalogue does not exists\n"s);
        }
        transport_router_updated_ = false;
        map_renderer_updated_ = false;
        return transport_catalogue_ptr_->AddBus(std::forward<Contents>(content)...);
    }
    else if constexpr(std::is_same_v<RequestType, SET_SPAN>) {
        if(!transport_catalogue_ptr_) {
            throw std::runtime_error("TransportCatalogue does not exists\n"s);
        }
        transport_catalogue_ptr_->AddSpanDistance(std::forward<Contents>(content)...);
        transport_router_updated_ = false;
    }
    else if constexpr(std::is_same_v<RequestType, SET_ROUTER>) {
        if(!transport_router_ptr_) {
            throw std::runtime_error("TransportRouter does not exists\n"s);
        }
        transport_router_ptr_->SetRouter(std::forward<Contents>(content)...);
        transport_router_updated_ = false;
    }
    else if constexpr(std::is_same_v<RequestType, SET_SERIALIZER>) {
        if(!serializer_ptr_) {
            throw std::runtime_error("Serializer does not exists\n"s);
        }
        serializer_ptr_->SetSerializer(std::forward<Contents>(content)...);
        if(!transport_catalogue_ptr_) {
            Deserialize();
        }
    }
    else if constexpr(std::is_same_v<RequestType, SET_RENDERER>) {
        if(!map_renderer_ptr_) {
            throw std::runtime_error("MapRenderer does not exists\n"s);
        }
        map_renderer_ptr_->SetRenderer(std::forward<Contents>(content)...);
    }
    else if constexpr(std::is_same_v<RequestType, GET_STOP_INFO>) {
        
        return transport_catalogue_ptr_->GetStopInfo(std::forward<Contents>(content)...);
    }
    else if constexpr(std::is_same_v<RequestType, GET_BUS_INFO>) {
        if(!transport_catalogue_ptr_) {
            throw std::runtime_error("TransportCatalogue does not exists\n"s);
        }
        return transport_catalogue_ptr_->GetBusInfo(std::forward<Contents>(content)...);
    }
    else if constexpr(std::is_same_v<RequestType, GET_ROUTE>) {
        if(!transport_catalogue_ptr_) {
            throw std::runtime_error("TransportCatalogue does not exists\n"s);
        }
        if(!transport_router_ptr_) {
            throw std::runtime_error("TransportRouter does not exists\n"s);
        }
        if(!transport_router_updated_) {
            transport_router_ptr_->UpdateRouter(*transport_catalogue_ptr_);
            transport_router_updated_ = true;
        }
        auto raw_result = transport_router_ptr_->BuildRoute(transport_catalogue_ptr_->GetStop(content)...);
        if(raw_result) {
            for(auto& route_item : raw_result->items) {
                route_item.item_name = route_item.item_type == domain::ItemType::WAIT ?
                                       transport_catalogue_ptr_->GetStop(route_item.item_id)->get().name :
                                       transport_catalogue_ptr_->GetBus(route_item.item_id)->get().name;
            }
        }
        return raw_result;
    }
    else if constexpr(std::is_same_v<RequestType, GET_MAP>) {
        if(!transport_catalogue_ptr_) {
            throw std::runtime_error("TransportCatalogue does not exists\n"s);
        }
        if(!map_renderer_ptr_) {
            throw std::runtime_error("MapRenderer does not exists\n"s);
        }
        if(!map_renderer_updated_) {
            map_renderer_ptr_->SetMinMaxCoordinates(transport_catalogue_ptr_->GetMinCoordinates(),
                                                    transport_catalogue_ptr_->GetMaxCoordinates());
            map_renderer_updated_ = true;
        }
        std::ostringstream oss;
        map_renderer_ptr_->RenderMap(*transport_catalogue_ptr_).Render(oss);
        return oss.str();
    }
    else {
        throw std::invalid_argument("invalid request key");
    }
}
