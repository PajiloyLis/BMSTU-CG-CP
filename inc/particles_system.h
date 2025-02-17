//
// Created by ivan on 17.02.25.
//

#ifndef CP_CG_PARTICLES_SYSTEM_H
#define CP_CG_PARTICLES_SYSTEM_H

#include <glm/glm.hpp>
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

class particle {
public:
    particle() = default;

    glm::vec3 position;
    float radius;
    glm::vec3 speed;
    sf::Color color;
};

class particles_system {
public:

    particles_system(const int & start_count, const glm::vec3 & spawn);

    vector<particle> particles;
    glm::vec3 spawn;

};


#endif //CP_CG_PARTICLES_SYSTEM_H
