//
// Created by ivan on 17.02.25.
//

#ifndef CP_CG_PARTICLES_SYSTEM_H
#define CP_CG_PARTICLES_SYSTEM_H

#include <glm/glm.hpp>
#include <vector>
#include <iostream>

using namespace std;

class particle {
public:
    particle() = default;

    glm::vec3 position;
    float radius;
    glm::vec3 speed;
};

class particles_system {
public:
    vector<particle> particles;


};



#endif //CP_CG_PARTICLES_SYSTEM_H
