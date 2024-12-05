#include "camera.h"

camera::camera(float _x, float _y, float _z, float relation, float angle) {
    pos.setX(_x), pos.setY(_y), pos.setZ(_z);
    angle_of_view = angle;
    this->relation = relation;
    pos.normalize();
    up={0, 0, 1};
}

camera::camera(const camera &c) {
    pos = c.pos;
    angle_of_view = c.angle_of_view;
    relation = c.relation;
    near_distance = c.near_distance;
    pos.normalize();
    up={0, 0, 1};
}

camera::camera(camera &&c) noexcept {
    pos = c.pos;
    angle_of_view = c.angle_of_view;
    relation = c.relation;
    near_distance = c.near_distance;
    pos.normalize();
    up={0, 0, 1};
}

my_vec3f camera::perspective(const my_vec3f &point) const {
    mat4 proj = glm::perspective(angle_of_view, relation, near_distance, 500.f);
    vec4 res = proj * vec4(point.getX(), point.getY(), point.getZ(), 1);
    return {res.x, res.y, res.z};
}

camera::camera(float _x, float _y, float _z, float width, float height, float angle) {
    pos.setX(_x), pos.setY(_y), pos.setZ(_z);
    angle_of_view = angle;
    this->relation = width / height;
    pos.normalize();
}

camera &camera::operator=(const camera &c) {
    pos = c.pos;
    angle_of_view = c.angle_of_view;
    relation = c.relation;
    near_distance = c.near_distance;
    pos.normalize();
    return *this;
}

my_vec3f camera::camLookAt(const my_vec3f &point, const my_vec3f &center) const {
    mat4 proj = glm::lookAt(pos.p, center.p, up.p);
    vec4 res = proj * vec4(point.getX(), point.getY(), point.getZ(), 1);
    return {res.x/res.w, res.y/res.w, res.z/res.w};
}

void camera::rotate(const rotate_t &rotate) {
    pos.rotate(rotate);
    up.rotate(rotate);
    cout<<"camera rotated "<<pos;
}
