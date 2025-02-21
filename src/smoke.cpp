//
// Created by ivan on 17.02.25.
//

#include "smoke.h"

//smoke::smoke(const int &start_count, const glm::vec3 &spawn, const sf::Color &color,
//             const glm::vec3 &speed) {
//    gen = mt19937(rd());
//    for (int i = 0; i < start_count; ++i) {
//        particles.push_back(particle(spawn, 1.f, speed + glm::vec3(1 - (float) rand() / RAND_MAX * 3,
//                                                                   1 - (float) rand() / RAND_MAX * 3,
//                                                                   1 - (float) rand() / RAND_MAX * 3),
//                                     color));
//    }
//    this->spawn = spawn;
//    timer_id = 0;
//    base_system_color = color;
//}
//
//smoke::smoke(const smoke &system) {
//    particles = system.particles;
//    spawn = system.spawn;
//    gen = system.gen;
//    base_system_color = system.base_system_color;
//}
//
//smoke &smoke::operator=(const smoke &system) {
//    spawn = system.spawn;
//    particles = system.particles;
//    gen = system.gen;
//    base_system_color = system.base_system_color;
//    return *this;
//}
//
//void smoke::update_coords(const int &add_count) {
//    for (int i = 0; i < add_count; ++i) {
//        particles.push_back(
//                particle(spawn + glm::vec3(1 - (float) rand() / RAND_MAX * 3, 1 - (float) rand() / RAND_MAX * 3,
//                                           1 - (float) rand() / RAND_MAX * 3), 1.f,
//                         (*particles.begin()).speed +
//                         glm::vec3(1 - (float) rand() / RAND_MAX * 3, 1 - (float) rand() / RAND_MAX * 3,
//                                   1 - (float) rand() / RAND_MAX * 3),
//                         base_system_color));
//    }
//    for (auto &particle: particles) {
//        particle.position +=
//                particle.speed + glm::vec3(1 - (float) rand() / RAND_MAX * 3, 1 - (float) rand() / RAND_MAX * 3,
//                                           1 - (float) rand() / RAND_MAX * 3);
////        cout << particle.position.x << ' '<<particle.position.y << " "<<particle.position.z << '\n';
//    }
//}

smoke::smoke(const int &grid_width, const int &grid_height) {
    int size = (grid_height + 1) * (grid_width + 1);
    u.resize(size, 0),
            v.resize(size, 0),
            u_prev.resize(size, 0),
            v_prev.resize(size, 0),
            dens.resize(size, 0),
            dens_prev.resize(size, 0);
    

}
