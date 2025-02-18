//
// Created by ivan on 17.02.25.
//

#ifndef CP_CG_PARTICLES_SYSTEM_H
#define CP_CG_PARTICLES_SYSTEM_H

#include <glm/glm.hpp>
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <random>

using namespace std;

class particle {
public:
    particle() = default;

    explicit particle(const glm::vec3 &pos = {0, 0, 0}, const float &r = 1.f, const glm::vec3 &sp = {0, 0, 0},
                      const sf::Color &c = {255, 255, 255}) : position(pos), radius(r), speed(sp), color(c)
                                                              {};

    glm::vec3 position;
    float radius;
    glm::vec3 speed;
    sf::Color color;
};

class particles_system {
public:

    particles_system(const int &start_count, const glm::vec3 &spawn, const sf::Color &color,
                     const glm::vec3 &speed);

    particles_system &operator=(const particles_system &system);

    void update_coords();

    particles_system(const particles_system &system);

    vector<particle> particles;
    glm::vec3 spawn;
    std::random_device rd;
    std::mt19937 gen;
    int timer_id;
};


#endif //CP_CG_PARTICLES_SYSTEM_H
