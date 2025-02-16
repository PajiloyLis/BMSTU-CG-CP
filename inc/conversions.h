#ifndef CP_CG_CONVERSIONS_H
#define CP_CG_CONVERSIONS_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

struct move_t {
    double dx, dy, dz;

};

struct rotate_t {
    double angle_x, angle_y, angle_z;
};

struct scale_t {
    double kx, ky, kz;
};

glm::vec3 rotate(const rotate_t &rotate_v, const glm::vec3 &p);

glm::vec3 move_point(const move_t &move, const glm::vec3 &p);

#endif //CP_CG_CONVERSIONS_H
