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

float my_vec3f::dot(const my_vec3f &a) const {
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

my_vec3f my_vec3f::operator-() const {
    return {-p};
}

my_vec3f my_vec3f::cross(const my_vec3f &a) {
    return glm::cross(p, a.p);
}

my_vec3f &my_vec3f::rotate(const rotate_t &rotate_v) {
    mat4 transform = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
    transform = glm::rotate(transform, static_cast<float>(rotate_v.angle_x), {1, 0, 0});
    transform = glm::rotate(transform, static_cast<float>(rotate_v.angle_y), {0, 1, 0});
    transform = glm::rotate(transform, static_cast<float>(rotate_v.angle_z), {0, 0, 1});
    vec4 res = transform * vec4(p.x, p.y, p.z, 1);
    p.x = res.x, p.y = res.y, p.z = res.z;
    return *this;
}

my_vec3f my_vec3f::operator*(const float &v) const {
    return {p.x * v, p.y * v, p.z * v};
}

my_vec3f &my_vec3f::scale(const scale_t &scale) {
    mat4 transform = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
    transform = glm::scale(transform, vec3(scale.kx, scale.ky, scale.kz));
    vec4 res = transform * vec4(p.x, p.y, p.z, 1);
    p.x = res.x, p.y = res.y, p.z = res.z;
    return *this;
}
