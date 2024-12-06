#include "camera.h"

camera::camera(float _x, float _y, float _z, float relation, float angle) {
    pos.setX(_x), pos.setY(_y), pos.setZ(_z);
    angle_of_view = angle;
    this->relation = relation;
//    pos.normalize();
    up={0, 0, 1};
}

camera::camera(const camera &c) {
    pos = c.pos;
    angle_of_view = c.angle_of_view;
    relation = c.relation;
    near_distance = c.near_distance;
//    pos.normalize();
    up={0, 0, 1};
}

camera::camera(camera &&c) noexcept {
    pos = c.pos;
    angle_of_view = c.angle_of_view;
    relation = c.relation;
    near_distance = c.near_distance;
//    pos.normalize();
    up={0, 0, 1};
}

mat4 camera::perspective(const my_vec3f &point) const {
    return glm::perspective(angle_of_view, relation, near_distance, 500.f);
}

camera::camera(float _x, float _y, float _z, float width, float height, float angle) {
    pos.setX(_x), pos.setY(_y), pos.setZ(_z);
    angle_of_view = angle;
    this->relation = width / height;
//    pos.normalize();
}

camera &camera::operator=(const camera &c) {
    pos = c.pos;
    angle_of_view = c.angle_of_view;
    relation = c.relation;
    near_distance = c.near_distance;
//    pos.normalize();
    return *this;
}

mat4 camera::camLookAt(const my_vec3f &point, const my_vec3f &center) const {
    return glm::lookAt(pos.p, {0, 0, 0}, up.p);
}

void camera::rotate(const rotate_t &rotate) {
    pos.rotate(rotate);
    up.rotate(rotate);
    cout<<"camera rotated "<<pos<<'\n';
}

void camera::scale(const scale_t &scale)
{
    
}