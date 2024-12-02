#ifndef CP_CG_CONVERSIONS_H
#define CP_CG_CONVERSIONS_H

#include <glm/glm.hpp>
#include <cmath>

using namespace glm;

struct move_t {
    double dx, dy, dz;

};

class rotate_t {
public:
    rotate_t(const double &x, const double &y, const double &z) :
            x_rotate(1, 0, 0, 0, cos(x), -sin(x), 0, sin(x), cos(x)),
            y_rotate(cos(y), 0, sin(y), 0, 1, 0, -sin(y), 0, cos(y)),
            z_rotate(cos(z), -sin(z), 0, sin(z), cos(z), 0, 0, 0, 1) {
    };
    mat3 x_rotate, y_rotate, z_rotate;
};

struct scale_t {
    double kx, ky, kz;
};


#endif //CP_CG_CONVERSIONS_H
