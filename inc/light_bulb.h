//
// Created by ivan on 05.03.25.
//

#ifndef CP_CG_LIGHT_BULB_H
#define CP_CG_LIGHT_BULB_H

#include <glm/glm.hpp>

class light_bulb {
public:
    const int ratio = 500;
    glm::vec3 ray_direction;
    glm::vec2 pos;
    light_bulb(const glm::vec2 &position);
};


#endif //CP_CG_LIGHT_BULB_H
