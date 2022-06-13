#pragma once

#include "geo.h"
#include "svg.h"

//#include <set>
#include <filesystem>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

namespace domain {

enum class ROUTE_TYPE {
    LINEAR,
    CIRCLE
};

struct Stop {
    int id;
    std::string name;
    geo::Coordinates coordinates;
    std::unordered_map<int, size_t> distance_to_other_stops{};
    std::unordered_set<int> buses{};
};

struct Bus {
    int id;
    std::string name;
    ROUTE_TYPE route_type;
    std::vector<int> route;
};

struct StopInfo {
    int request_id{};
    std::vector<std::string_view> buses;
};

struct BusInfo {
    int request_id{};
    uint64_t route_length{};
    size_t stop_count{};
    size_t unique_stop_count{};
    double curvature{};
};

enum class ItemType {
    WAIT,
    BUS
};

struct RouteItem {
    ItemType item_type;
    size_t item_id;
    std::string_view item_name;
    double time{};
    size_t span_count{};
};

struct RouteInfo {
    double weight;
    std::vector<RouteItem> items;
};

//settings

struct MapRendererSettings {
    double width;
    double height;
    double padding;
    double stop_radius;
    double line_width;
    int32_t bus_lable_font_size;
    svg::Point bus_lable_offset;
    int32_t stop_lable_font_size;
    svg::Point stop_lable_offset;
    svg::Color underlayer_color;
    double underlayer_width;
    std::vector<svg::Color> color_palette;
};

struct TransportRouterSettings {
    double bus_velocity{}; //km/h
    double bus_wait_time{}; //min
};

struct SerializerSettings {
    std::filesystem::path data_base;
};

} //domain
