#ifndef CP_CG_CAMERA_H
#define CP_CG_CAMERA_H

#include <my_vec3f.h>
#include "conversions.h"
#include <iostream>

class camera {
public:
    camera() = default;

    camera(float _x, float _y, float _z, float relation, float angle = 45 * M_PI / 180);

    camera(float _x, float _y, float _z, float width, float height, float angle);

    camera(const camera &c);

    camera& operator=(const camera &);

    camera(camera &&c) noexcept;

    [[nodiscard]] my_vec3f perspective(const my_vec3f &point) const;

    my_vec3f camLookAt(const my_vec3f &point, const my_vec3f &center) const;

    void rotate(const rotate_t &rotate);

    my_vec3f pos; //must
    my_vec3f up;
    float near_distance = 0.1;
    float relation;
    float angle_of_view;
};


#endif //CP_CG_CAMERA_H
