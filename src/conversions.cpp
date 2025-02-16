#include "conversions.h"

glm::vec3 rotate(const rotate_t &rotate_v, const glm::vec3 &p) {
    glm::mat4 transform = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
    transform = glm::rotate(transform, static_cast<float>(rotate_v.angle_x), {1, 0, 0});
    transform = glm::rotate(transform, static_cast<float>(rotate_v.angle_y), {0, 1, 0});
    transform = glm::rotate(transform, static_cast<float>(rotate_v.angle_z), {0, 0, 1});
    glm::vec4 res = transform * glm::vec4(p.x, p.y, p.z, 1);
    return {p.x, p.y, p.z};
}

glm::vec3 move_point(const move_t &move, const glm::vec3 &p) {
    glm::mat4 transform = {1, 0, 0, move.dx, 0, 1, 0, move.dy, 0, 0, 1, move.dz, 0, 0, 0, 1};
    glm::vec4 res = transform * glm::vec4(p.x, p.y, p.z, 1);
    return {p.x, p.y, p.z};
}