#include "camera.h"

//camera::camera(const my_vec3f &pos, const my_vec3f &pov, const my_vec3f &global_up, float relation) {
//    this->pos = pos;
//    this->relation = relation;
//    this->front = (pos - pov).normalize();
//    this->right = global_up.cross(front).normalize();
//    this->up = (front.cross(right)).normalize();
//    this->global_up = global_up;
//    cout << "pos " << this->pos << "\npov " << this->front << "\nright " << right << "\nup " << up << '\n';
//}
//
//
//camera::camera(const camera &c) {
//    pos = c.pos;
//    front = c.front;
//    right = c.right;
//    up = c.up;
//    relation = c.relation;
//    global_up = c.global_up;
//    near_distance = c.near_distance;
//}
//
//camera::camera(camera &&c) noexcept {
//    pos = c.pos;
//    front = c.front;
//    right = c.right;
//    up = c.up;
//    relation = c.relation;
//    global_up = c.global_up;
//    near_distance = c.near_distance;
//}
//
//mat4 camera::perspective() const {
//    return glm::perspective(radians(angle_of_view), relation, near_distance, far_distance);
//}
//
//camera::camera(const my_vec3f &pos, const my_vec3f &pov, const my_vec3f &global_up, float width, float height) {
//    this->pos = pos;
//    this->relation = width / height;
//    this->front = (pos - pov).normalize();
//    this->right = global_up.cross(front).normalize();
//    this->up = (front.cross(right)).normalize();
//    this->global_up = global_up;
//    cout << "pos " << this->pos << "\npov " << this->front << "\nright " << right << "\nup " << up << '\n';
//}
//
//camera &camera::operator=(const camera &c) {
//    pos = c.pos;
//    front = c.front;
//    right = c.right;
//    up = c.up;
//    relation = c.relation;
//    global_up = c.global_up;
//    near_distance = c.near_distance;
//    return *this;
//}
//
//mat4 camera::camLookAt() const {
//    return glm::lookAt(pos.p, (pos - front).p, up.p);
//}
//
//void camera::rotate(const rotate_t &rotate) {
//    front.rotate(rotate).normalize();
//    right = (global_up.cross(front)).normalize();
//    up = (front.cross(right)).normalize();
//    cout << "camera rotated\npos " << pos << "\npov " << front << '\n';
//}
//
//void camera::move(const move_t &move) {
////    my_vec3f tmp = pos;
//    pos += front * move.dz;
//    pos += right * move.dx;
//    pos += up * move.dy;
//    cout << "camera moved \npos " << pos << "\npov " << front << '\n';
//}
//
//void camera::scale(float &scale) {
//    angle_of_view += scale;
//    if (angle_of_view < 1.0f)
//        angle_of_view = 1.0f;
//    if (angle_of_view > 45.0f)
//        angle_of_view = 45.0f;
//    cout << "camera scaled " << angle_of_view << '\n';
//}
