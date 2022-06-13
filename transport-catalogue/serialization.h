#pragma once

#include "map_renderer.h"
#include "transport_catalogue.h"
#include "transport_router.h"

namespace serialization {

struct DeserializedBase {
    std::unique_ptr<transport_catalogue::TransportCatalogue> tc_ptr;
    std::unique_ptr<map_renderer::MapRenderer> mr_ptr;
    std::unique_ptr<transport_router::TransportRouter> tr_ptr;
};

class Serializer {
public:
    void SetSerializer(const domain::SerializerSettings& settings);
    void Serialize(const transport_catalogue::TransportCatalogue& tc,
                   const map_renderer::MapRenderer& mr,
                   const transport_router::TransportRouter& tr) const;
    DeserializedBase Deserialize() const;
private:
    //settings
    domain::SerializerSettings settings_;
};

} //serialization
