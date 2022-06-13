#include "request_handler.h"

namespace TC = transport_catalogue;
namespace TR = transport_router;
namespace MR = map_renderer;

RequestHandler::RequestHandler() 
    : transport_catalogue_ptr_(std::make_unique<TC::TransportCatalogue>(TC::TransportCatalogue{}))
    , transport_router_ptr_(std::make_unique<TR::TransportRouter>(TR::TransportRouter{}))
    , map_renderer_ptr_(std::make_unique<MR::MapRenderer>(MR::MapRenderer{}))
    , serializer_ptr_(std::make_unique<serialization::Serializer>(serialization::Serializer{})) {

}

RequestHandler::~RequestHandler() {}

RequestHandler::RequestHandler(serialization::Serializer&& serializer)
    : serializer_ptr_(std::make_unique<serialization::Serializer>(std::move(serializer))) {
}

void RequestHandler::Serialize() const {
    transport_router_ptr_->UpdateRouter(*transport_catalogue_ptr_);
    serializer_ptr_->Serialize(*transport_catalogue_ptr_, *map_renderer_ptr_, *transport_router_ptr_);
}

void RequestHandler::Deserialize() {
    auto proto_base = std::move(serializer_ptr_->Deserialize());
    if(!transport_catalogue_ptr_) {
        transport_catalogue_ptr_ = std::move(proto_base.tc_ptr);
    }
    if(!map_renderer_ptr_) {
        map_renderer_ptr_ = std::move(proto_base.mr_ptr);
    }
    if(!transport_router_ptr_) {
        transport_router_ptr_ = std::move(proto_base.tr_ptr);
        transport_router_updated_ = true;
    }
}

RequestHandlerSerializer::~RequestHandlerSerializer() {
    Serialize();
}

RequestHandlerDeserializer::RequestHandlerDeserializer()
    : RequestHandler(serialization::Serializer{}) {
}
