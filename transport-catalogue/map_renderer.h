#pragma once

#include "geo.h"
#include "svg.h"
#include "transport_catalogue.h"

namespace map_renderer {

class MapRenderer {
public:
    MapRenderer();
    MapRenderer(const transport_base::TransportCatalogue& base);
    MapRenderer(const MapRenderer&) = delete;
    MapRenderer(MapRenderer&&) = default;
    
    MapRenderer& operator=(const MapRenderer&) = delete;
    MapRenderer& operator=(MapRenderer&&) = default;
    
    ~MapRenderer() = default;
    
    void SetRenderer(domain::MapRendererSettings&& settings);
    operator transport_base::TransportCatalogue() const;

    void SetDefaultObjects();
    void SetMinMaxCoordinates(const geo::Coordinates& min, const geo::Coordinates& max);
    svg::Document RenderMap(const transport_catalogue::TransportCatalogue&) const;
private:
    class ColorInterpreter {
    public:
        ColorInterpreter() = delete;
        ColorInterpreter(const proto_svg::Color& color);
        ColorInterpreter(const svg::Color& color);
        operator proto_svg::Color() const;
        operator svg::Color() const;
    private:
        proto_svg::Color proto_color_;
        svg::Color svg_color_;
    };
private:
    double GetScale() const;
    svg::Point GetScaledCoordinates(const geo::Coordinates&, double) const;

//settings
    domain::MapRendererSettings settings_;

//other settings
    geo::Coordinates min_coordinates_;
    geo::Coordinates max_coordinates_;
    
//default objects
    svg::Text route_name_color_, route_name_black_, stop_name_black_, stop_name_color_;
    svg::Polyline poly_;
    svg::Circle stop_mark_;
};

} //map_renderer
