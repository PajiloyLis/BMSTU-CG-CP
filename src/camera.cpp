#include "camera.h"

camera::camera(float _x, float _y, float _z, float relation, float angle) {
    p.setX(_x), p.setY(_y), p.setZ(_z);
    angle_of_view = angle;
    this->relation = relation;
    p.normalize();
}

camera::camera(const camera &c) {
    p = c.p;
    angle_of_view = c.angle_of_view;
    relation = c.relation;
    near_distance = c.near_distance;
    p.normalize();
}

camera::camera(camera &&c) noexcept {
    p = c.p;
    angle_of_view = c.angle_of_view;
    relation = c.relation;
    near_distance = c.near_distance;
    p.normalize();
}

my_vec3f camera::perspective(const my_vec3f &point) const {
    mat4 proj = glm::perspective(angle_of_view, relation, near_distance, p.getZ());
    vec4 res = proj * vec4(point.getX(), point.getY(), point.getZ(), 1);
    return {res.x, res.y, res.z};
}

camera::camera(float _x, float _y, float _z, float width, float height, float angle) {
    p.setX(_x), p.setY(_y), p.setZ(_z);
    angle_of_view = angle;
    this->relation = width / height;
    p.normalize();
}

camera &camera::operator=(const camera &c) {
    p = c.p;
    angle_of_view = c.angle_of_view;
    relation = c.relation;
    near_distance = c.near_distance;
    p.normalize();
    return *this;
}

my_vec3f camera::camLookAt(const my_vec3f &point, const my_vec3f &center) const {
    mat4 proj = glm::lookAt(p.p, center.p, {0, 0, 1});
    vec4 res = proj * vec4(point.getX(), point.getY(), point.getZ(), 1);
    return {res.x, res.y, res.z};
}