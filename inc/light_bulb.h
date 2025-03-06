//
// Created by ivan on 05.03.25.
//

#ifndef CP_CG_LIGHT_BULB_H
#define CP_CG_LIGHT_BULB_H

#include <glm/glm.hpp>

class light_bulb {
public:
    static const int ratio = 200;
    glm::vec3 ray_direction;
    glm::vec3 pos;
    light_bulb(const glm::vec2 &position);
    light_bulb()=default;
    light_bulb(const light_bulb &);
};


#endif //CP_CG_LIGHT_BULB_H
