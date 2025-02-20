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
#include <set>
#include <deque>
using namespace std;

#define EPS 1e-5

class particle {
public:
    particle() = default;

    explicit particle(const glm::vec3 &pos = {0, 0, 0}, const float &r = 150.f, const glm::vec3 &sp = {0, 0, 0},
                      const sf::Color &c = {198, 195, 181}) : position(pos), radius(r), speed(sp), color(c),
                                                              iterations_count(0) {};

    bool operator<(const particle &p) const {
        if (position.x < p.position.x || (abs(position.x - p.position.x) < EPS && position.y < p.position.y) ||
            (abs(position.x - p.position.x) < EPS && abs(position.y - p.position.y) < EPS && position.z < p.position.z))
            return true;
        return false;
    }

    glm::vec3 position;
    float radius;
    glm::vec3 speed;
    sf::Color color;
    int iterations_count;
};

class particles_system {
public:

    particles_system(const int &start_count, const glm::vec3 &spawn, const sf::Color &color,
                     const glm::vec3 &speed);

    particles_system &operator=(const particles_system &system);

    void update_coords(const int &add_count);

    particles_system(const particles_system &system);

    deque<particle> particles;
    glm::vec3 spawn;
    std::random_device rd;
    std::mt19937 gen;
    int timer_id;
    sf::Color base_system_color;
};


#endif //CP_CG_PARTICLES_SYSTEM_H
