#include "camera.h"

camera::camera(const my_vec3f &pos, const my_vec3f &pov, const my_vec3f &global_up, float relation) {
    this->pos = pos;
    this->relation = relation;
    this->pov = pov;
    this->right = global_up.cross((pos - pov).normalize()).normalize();
    this->up = ((pos - pov).normalize().cross(right)).normalize();
    cout << "pos " << this->pos << "\npov " << this->pov << "\nright " << right << "\nup " << up << '\n';
}


camera::camera(const camera &c) {
    pos = c.pos;
    pov = c.pov;
    right = c.right;
    up = c.up;
    relation = c.relation;
    near_distance = c.near_distance;
}

camera::camera(camera &&c) noexcept {
    pos = c.pos;
    pov = c.pov;
    right = c.right;
    up = c.up;
    relation = c.relation;
    near_distance = c.near_distance;
}

mat4 camera::perspective() const {
    return glm::perspective(angle_of_view, relation, near_distance, 500.f);
}

camera::camera(const my_vec3f &pos, const my_vec3f &pov, const my_vec3f &global_up, float width, float height) {
    this->pos = pos;
    this->relation = width / height;
    this->pov = pov;
    this->right = global_up.cross((pos - pov).normalize()).normalize();
    this->up = ((pos - pov).normalize().cross(right)).normalize();
}

camera &camera::operator=(const camera &c) {
    pos = c.pos;
    pov = c.pov;
    right = c.right;
    up = c.up;
    relation = c.relation;
    near_distance = c.near_distance;
    return *this;
}

mat4 camera::camLookAt() const {
    return glm::lookAt(pos.p, pov.p, up.p);
}

void camera::rotate(const rotate_t &rotate) {
    pov = (pov - pos).rotate(rotate)+pos;
    up.rotate(rotate).normalize();
    right.rotate(rotate).normalize();
    cout << "camera rotated\npos " << pos << "\npov " << pov << '\n';
}

void camera::move(const move_t &move) {
    my_vec3f tmp = pos;
    pos += (tmp - pov).normalize() * move.dz;
    pos += right * move.dx;
    pos += up * move.dy;
    pov += right * move.dx;
    pov += up * move.dy;
    cout << "camera moved \npos " << pos << "\npov " << pov << '\n';
}

