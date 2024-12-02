#include "my_vec3f.h"

my_vec3f::my_vec3f(float x, float y, float z) {
    this->p.x = x;
    this->p.y = y;
    this->p.z = z;
}

float my_vec3f::distance(const my_vec3f &a) const {
    return sqrtf((this->p.x - a.p.x) * (p.x - a.p.x) + (p.y - a.p.y) * (p.y - a.p.y) + (p.z - a.p.z) * (p.z - a.p.z));
}

std::ostream &operator<<(std::ostream &os, const my_vec3f &m) {
    return os << m.p.x << ' ' << m.p.y << ' ' << m.p.z;
}

my_vec3f::my_vec3f(const my_vec3f &p) {
    this->p = p.p;
}

my_vec3f::my_vec3f(my_vec3f &&p) noexcept {
    if (&p != this) {
        this->p = p.p;
        p.p.x = p.p.y = p.p.z = 0;
    }
}

my_vec3f &my_vec3f::operator=(const my_vec3f &p) {
    if (this != &p) {
        this->p.x = p.p.x, this->p.y = p.p.y, this->p.z = p.p.z;
    }
    return *this;
}

my_vec3f::my_vec3f(my_vec3f &p) {
    this->p = p.p;
}

float my_vec3f::dot(const my_vec3f &a) {
    return glm::dot(p, a.p);
}

my_vec3f::my_vec3f(const glm::vec3 &p) {
    this->p = p;
}

my_vec3f my_vec3f::normalize() {
    this->p = glm::normalize(p);
    return *this;
}

my_vec3f my_vec3f::operator-(const my_vec3f &a) const {
    return {p.x - a.p.x, p.y - a.p.y, p.z - a.p.z};
}

my_vec3f my_vec3f::operator+(const my_vec3f &a) const {
    return {p.x + a.p.x, p.y + a.p.y, p.z + a.p.z};
}

my_vec3f my_vec3f::cross(const my_vec3f &a) {
    return glm::cross(p, a.p);
}

void my_vec3f::rotate_point_x(const rotate_t &rotate) {
    p = rotate.x_rotate*p;
}

void my_vec3f::rotate_point_y(const rotate_t &rotate) {
    double tmp_x = p.x;
    p.x = std::cos(rotate.angle_y) * p.x + std::sin(rotate.angle_y) * p.z;
    p.z = -std::sin(rotate.angle_y) * tmp_x + std::cos(rotate.angle_y) * p.z;
}

void my_vec3f::rotate_point_z(const rotate_t &rotate) {
    double tmp_x = p.x;
    p.x = std::cos(rotate.angle_z) * p.x - std::sin(rotate.angle_z) * p.y;
    p.y = std::sin(rotate.angle_z) * tmp_x + std::cos(rotate.angle_z) * p.y;
}

my_vec3f my_vec3f::rotate(const rotate_t &rotate) {
    rotate_point_x(rotate);
    rotate_point_y(rotate);
    rotate_point_z(rotate);
    return *this;
}

my_vec3f my_vec3f::operator*(const float &v) const {
    return {p.x*v, p.y*v, p.z*v};
}
