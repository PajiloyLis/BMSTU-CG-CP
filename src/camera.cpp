#include "camera.h"

camera::camera(const my_vec3f &pos, const my_vec3f &pov, const my_vec3f &global_up, float relation) {
    this->pos = pos;
    this->relation = relation;
    this->front = (pos-pov).normalize();
    this->right = global_up.cross(front).normalize();
    this->up = (front.cross(right)).normalize();
    cout << "pos " << this->pos << "\npov " << this->front << "\nright " << right << "\nup " << up << '\n';
}


camera::camera(const camera &c) {
    pos = c.pos;
    front = c.front;
    right = c.right;
    up = c.up;
    relation = c.relation;
    near_distance = c.near_distance;
}

camera::camera(camera &&c) noexcept {
    pos = c.pos;
    front = c.front;
    right = c.right;
    up = c.up;
    relation = c.relation;
    near_distance = c.near_distance;
}

mat4 camera::perspective() const {
    return glm::perspective(angle_of_view, relation, near_distance, far_distance);
}

camera::camera(const my_vec3f &pos, const my_vec3f &pov, const my_vec3f &global_up, float width, float height) {
    this->pos = pos;
    this->relation = width/height;
    this->front = (pos-pov).normalize();
    this->right = global_up.cross(front).normalize();
    this->up = (front.cross(right)).normalize();
    cout << "pos " << this->pos << "\npov " << this->front << "\nright " << right << "\nup " << up << '\n';
}

camera &camera::operator=(const camera &c) {
    pos = c.pos;
    front = c.front;
    right = c.right;
    up = c.up;
    relation = c.relation;
    near_distance = c.near_distance;
    return *this;
}

mat4 camera::camLookAt() const {
    return glm::lookAt(pos.p, (pos+front).p, up.p);
}

void camera::rotate(const rotate_t &rotate) {
    front = (front - pos).rotate(rotate) + pos;
    up.rotate(rotate).normalize();
    right.rotate(rotate).normalize();
    cout << "camera rotated\npos " << pos << "\npov " << front << '\n';
}

void camera::move(const move_t &move) {
    my_vec3f tmp = pos;
    pos += (pos - front).normalize() * move.dz;
    pos += right * move.dx;
    pos += up * move.dy;
    front += right * move.dx;
    front += up * move.dy;
//    near_distance+=move.dz/near_distance;
//    far_distance+=move.dz/far_distance;
    cout << "camera moved \npos " << pos << "\npov " << front << '\n';
}

