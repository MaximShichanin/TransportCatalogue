#pragma once

namespace geo {

struct Coordinates {
    double lat = 0.0; // Широта
    double lng = 0.0; // Долгота
    bool is_empty = true;
};

double ComputeDistance(Coordinates from, Coordinates to);

}  // namespace geo
