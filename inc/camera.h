#ifndef CP_CG_CAMERA_H
#define CP_CG_CAMERA_H

#include <my_vec3f.h>
#include "conversions.h"
#include <iostream>

class camera {
public:
    camera() = default;

camera(const my_vec3f &pos, const my_vec3f &pov, const my_vec3f &global_up, float relation);

    camera(const my_vec3f &pos, const my_vec3f &pov, const my_vec3f &global_up, float width, float height);

    camera(const camera &c);

    camera& operator=(const camera &);

    camera(camera &&c) noexcept;

    [[nodiscard]] mat4 perspective(const my_vec3f &point) const;

    mat4 camLookAt(const my_vec3f &point, const my_vec3f &center) const;

    void rotate(const rotate_t &rotate);

    my_vec3f pos, pov, up, right;
    float near_distance = 10;
    float relation;
    float angle_of_view=45;

    void scale(const scale_t &scale);
};


#endif //CP_CG_CAMERA_H
