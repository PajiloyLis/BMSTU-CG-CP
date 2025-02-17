//
// Created by ivan on 17.02.25.
//

#include "particles_system.h"

particles_system::particles_system(const int &start_count, const glm::vec3 &spawn, const sf::Color &color,
                                   const glm::vec3 &speed) {
    gen = mt19937(rd());
    particles.resize(start_count, particle(spawn + glm::vec3(2 - gen() % 5, 2 - gen() % 5, 2 - gen() % 5), 1.f,
                                           speed + glm::vec3(2 - gen() % 5, 2 - gen() % 5, 2 - gen() % 5), color));

}

