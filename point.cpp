#include "point.h"

point::point(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

float point::distance(const point &a) const {
    return sqrtf((x - a.x) * (x - a.x) + (y - a.y) * (y - a.y) + (z - a.z) * (z - a.z));
}

std::ostream &operator<<(std::ostream &os, const point &m) {
        return os << m.x<<' '<<m.y<<' '<<m.z;
}
