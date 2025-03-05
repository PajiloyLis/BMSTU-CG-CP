//
// Created by ivan on 05.03.25.
//

#include "light_bulb.h"

light_bulb::light_bulb(const glm::vec2 &position) {
    pos = position;
    ray_direction = glm::normalize(glm::vec3(ratio * cos(position.y * M_PI / 180),
                                             ratio * sin(position.y * M_PI / 180),
                                             ratio * sin(position.x * M_PI / 180)) - glm::vec3(0, 0, 0))
}
