#include "camera.h"

camera::camera(const my_vec3f &pos, const my_vec3f &pov, const my_vec3f &global_up, float relation) {
    this->pos = normalize(pos);
    this->relation = relation;
    this->pov = normalize(pov);
    this->right = global_up.cross((pos - pov).normalize()).normalize();
    this->up = ((pos - pos).normalize().cross(right)).normalize();
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
mat4 camera::perspective(const my_vec3f &point) const {
    return glm::perspective(angle_of_view, relation, near_distance, 500.f);
}

camera::camera(const my_vec3f &pos, const my_vec3f &pov, const my_vec3f &global_up, float width, float height) {
    this->pos = normalize(pos);
    this->relation = width / height;
    this->pov = normalize(pov);
    this->right = global_up.cross((pos - pov).normalize()).normalize();
    this->up = ((pos - pos).normalize().cross(right)).normalize();
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

mat4 camera::camLookAt(const my_vec3f &point, const my_vec3f &center) const {
    return glm::lookAt(pos.p, {0, 0, 0}, up.p);
}

void camera::rotate(const rotate_t &rotate) {
    pov.rotate(rotate);
    up.rotate(rotate);
    right.rotate(rotate);
    cout<<"camera rotated "<<pos<<'\n';
}

void camera::scale(const scale_t &scale)
{
    pos.scale(scale);
    up.scale(scale).normalize();
    cout<<"camera scaled "<<pos<<'\n';
}
