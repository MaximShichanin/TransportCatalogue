#include "json_reader.h"

using namespace json_reader;
using namespace std::literals;

svg::Color GetColor(const json::Array& raw_color) {
    switch(raw_color.size()) {
        case 3:
            return svg::Rgb(raw_color.at(0).AsInt(),
                            raw_color.at(1).AsInt(),
                            raw_color.at(2).AsInt());
            break;
        case 4:
            return svg::Rgba(raw_color.at(0).AsInt(),
                             raw_color.at(1).AsInt(),
                             raw_color.at(2).AsInt(),
                             raw_color.at(3).AsDouble());
            break;
        default:
            throw std::invalid_argument("bad color settings"s);
            break;
    }
}

JsonReader::JsonReader(std::istream& input, RequestHandler& request_handler) 
    : raw_request_(json::Load(input))
    , request_handler_(request_handler) {
    ParseRequest();
}

JsonReader::JsonReader(json::Document&& document, RequestHandler& request_handler)
    : raw_request_(std::move(document))
    , request_handler_(request_handler) {
    ParseRequest();
}
    
void JsonReader::GetResult(std::ostream& out) const {
    json::Print(json::Document(raw_output_), out);
}

void JsonReader::ParseRequest() {
    for(const auto& [key, node] : raw_request_.GetRoot().AsDict()) {
        if(key == "base_requests"s) {
            for(const auto& next_item : node.AsArray()) {
                AddItem(next_item.AsDict());
            }
        }
        else if(key == "stat_requests"s) {
            for(const auto& next_stat_request : node.AsArray()) {
                const std::string& request_type = next_stat_request.AsDict().at("type"s).AsString();
                if(request_type == "Stop"s) {
                    raw_output_.push_back(MakeStopInfo(next_stat_request.AsDict()));
                }
                else if(request_type == "Bus"s) {
                    raw_output_.push_back(MakeBusInfo(next_stat_request.AsDict()));
                }
                else if(request_type == "Map"s) {
                    raw_output_.push_back(MakeMap(next_stat_request.AsDict())); 
                }
                else if(request_type == "Route"s) {
                    raw_output_.push_back(MakeRoute(next_stat_request.AsDict()));
                }
                else {
                    throw std::invalid_argument("bad request type: "s + request_type);
                }
            }
        }
        else if(key == "render_settings"s) {
            SetRenderer(node.AsDict());
        }
        else if(key == "routing_settings"s) {
            SetRouter(node.AsDict());
        }
        else if(key == "serialization_settings"s) {
            SetSerializer(node.AsDict());
        }
        else {
            throw std::invalid_argument("invalid request type: "s + key);
        }
    }
}

void JsonReader::AddItem(const json::Dict& item) {
    const std::string_view item_type(item.at("type"s).AsString());
    if(item_type == "Stop"sv) {
        request_handler_.request(RequestHandler::SET_STOP{},
                                 item.at("name"s).AsString(),
                                 geo::Coordinates{item.at("latitude"s).AsDouble(), item.at("longitude"s).AsDouble(), false});
        for(const auto& [stop_name, distance] : item.at("road_distances"s).AsDict()) {
            request_handler_.request(RequestHandler::SET_SPAN{},
                                     item.at("name"s).AsString(),
                                     stop_name, distance.AsInt());
        }
    }
    else if(item_type == "Bus"sv) {
        std::vector<int> stops;
        for(const auto& next_stop : item.at("stops"s).AsArray()) {
            stops.emplace_back(request_handler_.request(RequestHandler::SET_STOP{},
                                                        next_stop.AsString(),
                                                        geo::Coordinates{}));
        }
        if(item.at("is_roundtrip").AsBool()) {
            if(stops.front() != stops.back()) {
                stops.emplace_back(stops.front());
            }
        }
        else {
            for(int i = stops.size() - 2; i >= 0; --i) {
                stops.emplace_back(stops.at(i));
            }
        }
        request_handler_.request(RequestHandler::SET_BUS{},
                                 item.at("name"s).AsString(),
                                 item.at("is_roundtrip"s).AsBool() ? domain::ROUTE_TYPE::CIRCLE
                                                                   : domain::ROUTE_TYPE::LINEAR,
                                 std::move(stops));
    }
    else {
        throw std::invalid_argument("AddItem: wrong type");
    }
}

void JsonReader::SetRenderer(const json::Dict& settings) {
    domain::MapRendererSettings map_renderer_settings{settings.at("width"s).AsDouble(),
                                                      settings.at("height"s).AsDouble(),
                                                      settings.at("padding"s).AsDouble(),
                                                      settings.at("stop_radius"s).AsDouble(),
                                                      settings.at("line_width"s).AsDouble(),
                                                      settings.at("bus_label_font_size"s).AsInt(),
                                                      svg::Point{settings.at("bus_label_offset"s).AsArray().at(0).AsDouble(),
                                                                 settings.at("bus_label_offset"s).AsArray().at(1).AsDouble()},
                                                      settings.at("stop_label_font_size"s).AsInt(),
                                                      svg::Point{settings.at("stop_label_offset"s).AsArray().at(0).AsDouble(),
                                                                 settings.at("stop_label_offset"s).AsArray().at(1).AsDouble()},
                                                      svg::Color{settings.at("underlayer_color"s).IsString() ?
                                                                 settings.at("underlayer_color"s).AsString() :
                                                                 GetColor(settings.at("underlayer_color"s).AsArray())},
                                                      settings.at("underlayer_width"s).AsDouble(),
                                                      {}};
    for(const auto& next_color : settings.at("color_palette"s).AsArray()) {
        if(next_color.IsString()) {
            map_renderer_settings.color_palette.emplace_back(next_color.AsString());
        }
        else if(next_color.IsArray()) {
            map_renderer_settings.color_palette.emplace_back(GetColor(next_color.AsArray()));
        }
    }
    request_handler_.request(RequestHandler::SET_RENDERER{}, std::move(map_renderer_settings));
}

void JsonReader::SetRouter(const json::Dict& settings) {
    domain::TransportRouterSettings router_settings{settings.at("bus_velocity"s).AsDouble(),
                                                    settings.at("bus_wait_time"s).AsDouble()};
    request_handler_.request(RequestHandler::SET_ROUTER{}, std::move(router_settings));
}

void JsonReader::SetSerializer(const json::Dict& settings) {
    domain::SerializerSettings serializer_settings{settings.at("file"s).AsString()};
    request_handler_.request(RequestHandler::SET_SERIALIZER{}, std::move(serializer_settings));
}

json::Dict JsonReader::MakeBusInfo(const json::Dict& route_query) {
    auto raw_bus_info = request_handler_.request(RequestHandler::GET_BUS_INFO{},
                                                 route_query.at("name"s).AsString());
    int request_id = route_query.at("id"s).AsInt();
    if(raw_bus_info == std::nullopt) {
        return {{"request_id"s, request_id},
                {"error_message"s, "not found"s}};
    }
    return {{"curvature"s, raw_bus_info->curvature},
            {"request_id"s, request_id},
            {"route_length"s, static_cast<int>(raw_bus_info->route_length)},
            {"stop_count"s, static_cast<int>(raw_bus_info->stop_count)},
            {"unique_stop_count"s, static_cast<int>(raw_bus_info->unique_stop_count)}};
}

json::Dict JsonReader::MakeStopInfo(const json::Dict& route_query) {
    auto raw_stop_info = request_handler_.request(RequestHandler::GET_STOP_INFO{},
                                                  route_query.at("name"s).AsString());
    int request_id = route_query.at("id"s).AsInt();
    if(raw_stop_info == std::nullopt) {
        return {{"request_id"s, request_id},
                {"error_message"s, "not found"s}};
    }
    json::Array buses_via_stop;
    for(auto bus_name : raw_stop_info.value().buses) {
        buses_via_stop.push_back(std::string(bus_name));
    }
    std::sort(buses_via_stop.begin(), buses_via_stop.end(), [] (const auto& lhs, const auto& rhs) {return lhs.AsString() < rhs.AsString();});
    return {{"buses"s, buses_via_stop},
            {"request_id"s, request_id}};
}

json::Dict JsonReader::MakeMap(const json::Dict& map_query) {
    auto raw_map = request_handler_.request(RequestHandler::GET_MAP{});
    int request_id = map_query.at("id"s).AsInt();
    return {{"request_id"s, request_id},
            {"map"s, raw_map}};
}

json::Dict JsonReader::MakeRoute(const json::Dict& router_query) {
    std::string_view from_stop_name = router_query.at("from"s).AsString();
    std::string_view to_stop_name = router_query.at("to"s).AsString();
    auto raw_result = request_handler_.request(RequestHandler::GET_ROUTE{},
                                               from_stop_name,
                                               to_stop_name);
    if(raw_result) {
        return {{"request_id"s, router_query.at("id"s).AsInt()},
                {"total_time"s, raw_result->weight},
                {"items"s, std::move(TranslateRouteToJson(raw_result->items))}};
    }
    else {
        return {{"request_id"s, router_query.at("id"s).AsInt()},
                {"error_message"s, "not found"s}};
    }
}

json::Array JsonReader::TranslateRouteToJson(const std::vector<domain::RouteItem>& items) const {
    if(items.empty()) {
        return {};
    }
    json::Array result;
    result.reserve(items.size());
    for(auto item : items) {
        switch(item.item_type) {
            case domain::ItemType::WAIT :
                result.push_back(json::Dict{{"type"s, "Wait"s},
                                            {"stop_name"s, std::string(item.item_name)},
                                            {"time"s, item.time}});
                break;
            case domain::ItemType::BUS :
                result.push_back(json::Dict{{"type"s, "Bus"s},
                                            {"bus"s, std::string(item.item_name)},
                                            {"time"s, item.time},
                                            {"span_count"s, static_cast<int>(item.span_count)}});
                break;
            default:
                throw std::logic_error("wrong result type"s);
        }
    }
    return result;
}
