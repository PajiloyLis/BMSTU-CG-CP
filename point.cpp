#include "point.h"

point::point(float x, float y, float z) {
    this->p.x = x;
    this->p.y = y;
    this->p.z = z;
}

float point::distance(const point &a) const {
    return sqrtf((this->p.x - a.p.x) * (p.x - a.p.x) + (p.y - a.p.y) * (p.y - a.p.y) + (p.z - a.p.z) * (p.z - a.p.z));
}

std::ostream &operator<<(std::ostream &os, const point &m) {
    return os << m.p.x << ' ' << m.p.y << ' ' << m.p.z;
}

point::point(const point &p) {
    this->p = p.p;
}

point::point(point &&p) noexcept {
    if (&p != this) {
        this->p = p.p;
        p.p.x = p.p.y = p.p.z = 0;
    }
}

point &point::operator=(const point &p) {
    if (this != &p) {
        this->p.x = p.p.x, this->p.y = p.p.y, this->p.z = p.p.z;
    }
    return *this;
}

point::point(point &p) {
    this->p = p.p;
}

void point::rotate(const rotate_t &rotate) {
    double tmp_x = p.x;
    p.x = std::cos(rotate.angle_y) * p.x + std::sin(rotate.angle_y) * p.z;
    p.z = -std::sin(rotate.angle_y) * tmp_x + std::cos(rotate.angle_y) * p.z;
}

float point::dot(const point &a) {
    return glm::dot(p, a.p);
}

point::point(glm::vec3 p) {
    this->p = p;
}

void point::normalize() {
    glm::normalize(p);
}

point point::operator-(const point &a) const {
    return {p.x - a.p.x, p.y - a.p.y, p.y - a.p.y};
}

point point::operator+(const point &a) const {
    return {p.x + a.p.x, p.y + a.p.y, p.z + a.p.z};
}

point point::cross(const point &a) {
    return glm::cross(p, a.p);
}
