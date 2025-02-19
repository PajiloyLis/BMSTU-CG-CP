//
// Created by ivan on 17.02.25.
//

#include "particles_system.h"

particles_system::particles_system(const int &start_count, const glm::vec3 &spawn, const sf::Color &color,
                                   const glm::vec3 &speed) {
    gen = mt19937(rd());
    particles.resize(start_count, particle(spawn, 10.f,
                                           speed + glm::vec3(1-rand()%3, 1-rand()%3,
                                                             1-rand()%3),
                                           color));
    this->spawn = spawn;
    timer_id = 0;
    base_system_color = color;
}

particles_system::particles_system(const particles_system &system) {
    particles = system.particles;
    spawn = system.spawn;
    gen = system.gen;
    base_system_color = system.base_system_color;
}

particles_system &particles_system::operator=(const particles_system &system) {
    spawn = system.spawn;
    particles = system.particles;
    gen = system.gen;
    base_system_color = system.base_system_color;
    return *this;
}

void particles_system::update_coords(const int &add_count) {
    for (int i = 0; i < add_count; ++i) {
        particles.push_back(
                particle(spawn + glm::vec3(1-rand()%3, 1-rand()%3, 1-rand()%3), 10.f,
                         particles[0].speed +
                         glm::vec3(1-rand()%3, 1-rand()%3, 1-rand()%3),
                         base_system_color));
    }
    for (auto &particle: particles) {
        particle.position +=
                particle.speed + glm::vec3(1-rand()%3, 1-rand()%3, 1-rand()%3);
//        cout << particle.position.x << ' '<<particle.position.y << " "<<particle.position.z << '\n';
    }
}

