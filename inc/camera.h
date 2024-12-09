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

    [[nodiscard]] mat4 perspective() const;

    mat4 camLookAt() const;

    void rotate(const rotate_t &rotate);

    my_vec3f pos, pov, up, right;
    float near_distance = 0.1;
    float relation;
    float angle_of_view=45;
    float far_distance = 500;

    void move(const move_t &move);
};


#endif //CP_CG_CAMERA_H
