#define _USE_MATH_DEFINES
#include "geo.h"

#include <cmath>

namespace geo {

double ComputeDistance(Coordinates from, Coordinates to) {
    using namespace std;
    const double dr = M_PI / 180.0;
    return acos(sin(1.0*from.lat * dr) * sin(1.0*to.lat * dr)
                + cos(1.0*from.lat * dr) * cos(1.0*to.lat * dr) * cos(abs(1.0*from.lng - 1.0*to.lng) * dr))
        * 6371000;
}
}  // namespace geo
