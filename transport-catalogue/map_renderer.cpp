#include "map_renderer.h"

using namespace map_renderer;
using namespace std::literals;

decltype(auto) SortCatalogue(const transport_catalogue::TransportCatalogue& tc) {
    std::vector<std::reference_wrapper<const domain::Bus>> sorted_catalogue{tc.begin(), tc.end()};
    std::sort(sorted_catalogue.begin(), sorted_catalogue.end(), [](const auto& lhs, const auto& rhs) {return lhs.get().name < rhs.get().name;});
    return sorted_catalogue;
}

MapRenderer::MapRenderer(const transport_base::TransportCatalogue& base) {
    const auto& proto_settings = base.mr_settings();
    settings_.width = proto_settings.width();
    settings_.height = proto_settings.height();
    settings_.padding = proto_settings.padding();
    settings_.stop_radius = proto_settings.stop_radius();
    settings_.line_width = proto_settings.line_width();
    settings_.bus_lable_font_size = proto_settings.bus_lable_font_size();
    settings_.bus_lable_offset = {proto_settings.bus_lable_offset().x(),
                                  proto_settings.bus_lable_offset().y()};
    settings_.stop_lable_font_size = proto_settings.stop_lable_font_size();
    settings_.stop_lable_offset = {proto_settings.stop_lable_offset().x(),
                                   proto_settings.stop_lable_offset().y()};
    settings_.underlayer_color = ColorInterpreter{proto_settings.underlayer_color()};
    settings_.underlayer_width = proto_settings.underlayer_width();
    for(size_t i = 0; i < proto_settings.color_palette_size(); ++i) {
        settings_.color_palette.emplace_back(ColorInterpreter{proto_settings.color_palette(i)});
    }
    SetDefaultObjects();
}

void MapRenderer::SetRenderer(domain::MapRendererSettings&& settings) {
    settings_ = std::move(settings);
    SetDefaultObjects();
}

MapRenderer::operator transport_base::TransportCatalogue() const {
    transport_base::TransportCatalogue proto_catalogue{};
    auto& proto_settings = *proto_catalogue.mutable_mr_settings();
    proto_settings.set_width(settings_.width);
    proto_settings.set_height(settings_.height);
    proto_settings.set_padding(settings_.padding);
    proto_settings.set_stop_radius(settings_.stop_radius);
    proto_settings.set_line_width(settings_.line_width);
    proto_settings.set_bus_lable_font_size(settings_.bus_lable_font_size);
    proto_settings.mutable_bus_lable_offset()->set_x(settings_.bus_lable_offset.x);
    proto_settings.mutable_bus_lable_offset()->set_y(settings_.bus_lable_offset.y);
    proto_settings.set_stop_lable_font_size(settings_.stop_lable_font_size);
    proto_settings.mutable_stop_lable_offset()->set_x(settings_.stop_lable_offset.x);
    proto_settings.mutable_stop_lable_offset()->set_y(settings_.stop_lable_offset.y);
    *proto_settings.mutable_underlayer_color() = std::move(ColorInterpreter{settings_.underlayer_color});
    proto_settings.set_underlayer_width(settings_.underlayer_width);
    for(const auto& next_color : settings_.color_palette) {
        *proto_settings.add_color_palette() = std::move(ColorInterpreter{next_color});
    }
    return std::move(proto_catalogue);
}

void MapRenderer::SetDefaultObjects() {
    using namespace std::literals;
    
    route_name_color_.SetFillColor(settings_.underlayer_color).
                      SetStrokeColor(settings_.underlayer_color).
                      SetStrokeWidth(settings_.underlayer_width).
                      SetStrokeLineCap(svg::StrokeLineCap::ROUND).
                      SetStrokeLineJoin(svg::StrokeLineJoin::ROUND).
                      SetOffset(settings_.bus_lable_offset).
                      SetFontSize(settings_.bus_lable_font_size).
                      SetFontFamily("Verdana"s).
                      SetFontWeight("bold"s);
    route_name_black_.SetOffset(settings_.bus_lable_offset).
                      SetFontSize(settings_.bus_lable_font_size).
                      SetFontFamily("Verdana"s).
                      SetFontWeight("bold"s);
    stop_name_black_.SetFillColor("black"s).
                     SetOffset(settings_.stop_lable_offset).
                     SetFontSize(settings_.stop_lable_font_size).
                     SetFontFamily("Verdana"s);
    stop_name_color_.SetFillColor(settings_.underlayer_color).
                     SetStrokeColor(settings_.underlayer_color).
                     SetStrokeWidth(settings_.underlayer_width).
                     SetStrokeLineCap(svg::StrokeLineCap::ROUND).
                     SetStrokeLineJoin(svg::StrokeLineJoin::ROUND).
                     SetOffset(settings_.stop_lable_offset).
                     SetFontSize(settings_.stop_lable_font_size).
                     SetFontFamily("Verdana"s);
    poly_.SetFillColor(svg::NoneColor).
          SetStrokeLineCap(svg::StrokeLineCap::ROUND).
          SetStrokeLineJoin(svg::StrokeLineJoin::ROUND).
          SetStrokeWidth(settings_.line_width);
    stop_mark_.SetFillColor("white"s).
               SetRadius(settings_.stop_radius);
}

void MapRenderer::SetMinMaxCoordinates(const geo::Coordinates& min, const geo::Coordinates& max) {
    min_coordinates_ = min;
    max_coordinates_ = max;
}

double MapRenderer::GetScale() const {
    double zoom;
    double d_x = std::abs(max_coordinates_.lng - min_coordinates_.lng);
    double d_y = std::abs(max_coordinates_.lat - min_coordinates_.lat);
    double scale_x = d_x > 0 ? (settings_.width - 2.0 * settings_.padding) / d_x : 0.0;
    double scale_y = d_y > 0 ? (settings_.height - 2.0 * settings_.padding) / d_y : 0.0;
    zoom = scale_x > 0 && scale_x < scale_y ? scale_x : scale_y;
    return zoom;
}

svg::Point MapRenderer::GetScaledCoordinates(const geo::Coordinates& raw_coordinates, double zoom) const {
    double x = (raw_coordinates.lng - min_coordinates_.lng) * zoom + settings_.padding;
    double y = (max_coordinates_.lat - raw_coordinates.lat) * zoom + settings_.padding;
    return {x, y};
}

svg::Document MapRenderer::RenderMap(const transport_catalogue::TransportCatalogue& tc) const {
    double zoom = GetScale();
    std::vector<svg::Polyline> polylines;
    std::vector<svg::Text> route_names;
    std::map<std::string_view, svg::Circle> stop_marks;
    std::map<std::string_view, std::pair<svg::Text, svg::Text>> stop_names;
    size_t color_id = 0;
    auto sorted_catalogue = std::move(SortCatalogue(tc));
    for(const auto& bus : sorted_catalogue) {
        if(bus.get().route.empty()) {
            continue;
        }
        svg::Polyline poly = poly_;
        poly.SetStrokeColor(settings_.color_palette.at(color_id % settings_.color_palette.size()));
        svg::Circle stop_mark = stop_mark_;
        svg::Text route_name_color = route_name_color_;
        svg::Text route_name_black = route_name_black_;
        route_name_color.SetData(bus.get().name);
        route_name_black.SetData(bus.get().name).
                         SetFillColor(settings_.color_palette.at(color_id++ % settings_.color_palette.size()));
        int stop_count = 0;
        for(auto stop_id : bus.get().route) {
            svg::Text stop_name_black = stop_name_black_;
            svg::Text stop_name_color = stop_name_color_;
            auto point = GetScaledCoordinates(tc.GetStop(stop_id)->get().coordinates, zoom);
            poly.AddPoint(point);
            stop_mark.SetCenter(point);
            const std::string& stop_name = tc.GetStop(stop_id)->get().name;
            stop_name_black.SetPosition(point).
                            SetData(stop_name);
            stop_name_color.SetPosition(point).
                            SetData(stop_name);
            stop_marks[stop_name] = stop_mark;
            stop_names[stop_name] = {stop_name_color, stop_name_black};
            
            //add stop text for the first and the last stops (if there is non-CIRCLE route)
            
            if(stop_count == 0 || (bus.get().route_type == domain::ROUTE_TYPE::LINEAR && 
               stop_count == static_cast<int>(bus.get().route.size() / 2) && 
               bus.get().route.front() != stop_id)) {
                route_name_color.SetPosition(point);
                route_name_black.SetPosition(point);
                route_names.push_back(route_name_color);
                route_names.push_back(route_name_black);
            }
            ++stop_count;
        }
        polylines.push_back(poly);
    }
    svg::Document result;
    for(auto line : polylines) {
        result.AddPtr(std::make_unique<svg::Polyline>(std::move(line)));
    }
    for(auto route_name : route_names) {
        result.AddPtr(std::make_unique<svg::Text>(std::move(route_name)));
    }
    for(auto [_, mark] : stop_marks) {
        result.AddPtr(std::make_unique<svg::Circle>(std::move(mark)));
    }
    for(auto [_, value] : stop_names) {
        result.AddPtr(std::make_unique<svg::Text>(std::move(value.first)));
        result.AddPtr(std::make_unique<svg::Text>(std::move(value.second)));
    }
    return result;
}

MapRenderer::ColorInterpreter::ColorInterpreter(const proto_svg::Color& color) {
    const auto color_case = color.color__case();
    switch(color_case) {
        case 1: //has_name
            proto_color_.set_name(color.name());
            svg_color_ = color.name();
            break;
        case 2: //has_rgb
            *proto_color_.mutable_rgb() = color.rgb();
            svg_color_ = svg::Rgb{static_cast<uint8_t>(color.rgb().r()),
                                  static_cast<uint8_t>(color.rgb().g()),
                                  static_cast<uint8_t>(color.rgb().b())};
            break;
        case 3: //has_rgba
            *proto_color_.mutable_rgba() = color.rgba();
            svg_color_ = svg::Rgba{static_cast<uint8_t>(color.rgba().rgb().r()),
                                   static_cast<uint8_t>(color.rgba().rgb().g()),
                                   static_cast<uint8_t>(color.rgba().rgb().b()),
                                   color.rgba().opacity()};
            break;
        default:
            throw std::invalid_argument("invalid color\n"s);
            break;
    }
}

MapRenderer::ColorInterpreter::ColorInterpreter(const svg::Color& color) {
    const void* value_ptr;
    if(value_ptr = std::get_if<std::string>(&color)) {
        const std::string& name = *reinterpret_cast<const std::string*>(value_ptr);
        proto_color_.set_name(name);
        svg_color_ = name;
    }
    else if(value_ptr = std::get_if<svg::Rgb>(&color)) {
        const svg::Rgb& rgb = *reinterpret_cast<const svg::Rgb*>(value_ptr);
        proto_color_.mutable_rgb()->set_r(rgb.red);
        proto_color_.mutable_rgb()->set_g(rgb.green);
        proto_color_.mutable_rgb()->set_b(rgb.blue);
        svg_color_ = rgb;
    }
    else if(value_ptr = std::get_if<svg::Rgba>(&color)) {
        const svg::Rgba& rgba = *reinterpret_cast<const svg::Rgba*>(value_ptr);
        proto_color_.mutable_rgba()->mutable_rgb()->set_r(rgba.red);
        proto_color_.mutable_rgba()->mutable_rgb()->set_g(rgba.green);
        proto_color_.mutable_rgba()->mutable_rgb()->set_b(rgba.blue);
        proto_color_.mutable_rgba()->set_opacity(rgba.opacity);
        svg_color_ = rgba;
    }
    else {
        throw std::invalid_argument("invalid color\n"s);
    }
}

MapRenderer::ColorInterpreter::operator proto_svg::Color() const {
    return proto_color_;
}

MapRenderer::ColorInterpreter::operator svg::Color() const {
    return svg_color_;
}
