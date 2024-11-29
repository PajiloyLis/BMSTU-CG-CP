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

point point::rotate(const rotate_t &rotate) {
    double tmp_x = p.x;
    p.x = std::cos(rotate.angle_y) * p.x + std::sin(rotate.angle_y) * p.z;
    p.z = -std::sin(rotate.angle_y) * tmp_x + std::cos(rotate.angle_y) * p.z;
    return *this;
}

float point::dot(const point &a) {
    return glm::dot(p, a.p);
}

point::point(const glm::vec3 &p) {
    this->p = p;
}

point point::normalize() {
    this->p = glm::normalize(p);
    return *this;
}

point point::operator-(const point &a) const {
    return {p.x - a.p.x, p.y - a.p.y, p.z - a.p.z};
}

point point::operator+(const point &a) const {
    return {p.x + a.p.x, p.y + a.p.y, p.z + a.p.z};
}

point point::cross(const point &a) {
    return glm::cross(p, a.p);
}

void RotatePointX(point_t &p, const rotate_t &rotate)
{
    double tmp_y = p.y;
    p.y = std::cos(rotate.angle_x) * p.y - std::sin(rotate.angle_x) * p.z;
    p.z = std::sin(rotate.angle_x) * tmp_y + std::cos(rotate.angle_x) * p.z;
    return SUCCESS;
}

static my_error_t RotatePointY(point_t &p, const rotate_t &rotate)
{
    double tmp_x = p.x;
    p.x = std::cos(rotate.angle_y) * p.x + std::sin(rotate.angle_y) * p.z;
    p.z = -std::sin(rotate.angle_y) * tmp_x + std::cos(rotate.angle_y) * p.z;
    return SUCCESS;
}

static my_error_t RotatePointZ(point_t &p, const rotate_t &rotate)
{
    double tmp_x = p.x;
    p.x = std::cos(rotate.angle_z) * p.x - std::sin(rotate.angle_z) * p.y;
    p.y = std::sin(rotate.angle_z) * tmp_x + std::cos(rotate.angle_z) * p.y;
    return SUCCESS;
}