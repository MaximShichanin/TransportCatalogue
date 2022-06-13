#include "serialization.h"

#include <fstream>

using namespace serialization;

void Serializer::SetSerializer(const domain::SerializerSettings& settings) {
    settings_ = settings;
}

void Serializer::Serialize(const transport_catalogue::TransportCatalogue& tc,
                           const map_renderer::MapRenderer& mr,
                           const transport_router::TransportRouter& tr) const {
    std::ofstream ofs(settings_.data_base, std::ios::binary);
    if(!ofs) {
        //error case will be here
    }
    transport_base::TransportCatalogue proto_catalogue = tc;
    *proto_catalogue.mutable_mr_settings() = static_cast<transport_base::TransportCatalogue>(mr).mr_settings();
    *proto_catalogue.mutable_transport_router() = static_cast<transport_base::TransportCatalogue>(tr).transport_router();
    proto_catalogue.SerializeToOstream(&ofs);
}

DeserializedBase Serializer::Deserialize() const {
    transport_base::TransportCatalogue proto_base{};
    std::ifstream ifs(settings_.data_base, std::ios::binary);
    proto_base.ParseFromIstream(&ifs);
    return std::move(DeserializedBase{std::make_unique<transport_catalogue::TransportCatalogue>(proto_base),
                                      std::make_unique<map_renderer::MapRenderer>(proto_base),
                                      std::make_unique<transport_router::TransportRouter>(proto_base)});
}
