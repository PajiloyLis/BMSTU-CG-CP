//
// Created by ivan on 17.02.25.
//

#ifndef CP_CG_SMOKE_H
#define CP_CG_SMOKE_H

#include <glm/glm.hpp>
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <random>
#include <set>
#include <deque>
using namespace std;

#define EPS 1e-5

#define VOX_SIZE 5

class smoke {
public:

    int width, height;

    glm::vec3 source;

    vector<vector<vector<float>>> u, v, u_prev, v_prev, z, z_prev, dens, dens_prev;


    smoke(int grid_width, int grid_height, const glm::vec3 &crater);

};


#endif //CP_CG_SMOKE_H
