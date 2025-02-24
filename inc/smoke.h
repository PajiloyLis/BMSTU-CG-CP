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

    glm::vec3 source, wind;

    float dt;

    vector<vector<vector<float>>> u, v, u_prev, v_prev, w, w_prev, dens, dens_prev;


    smoke(int grid_width, int grid_height, const glm::vec3 &crater, const glm::vec3 &wind_, float dt_) :
            width(grid_width / VOX_SIZE), height(grid_height / VOX_SIZE), source(crater), wind(wind_), dt(dt_),
            u(height + 2, vector<vector<float>>(height, vector<float>(width, 0.f))),
            v(height + 2, vector<vector<float>>(height, vector<float>(width, 0.f))),
            w(height + 2, vector<vector<float>>(height, vector<float>(width, 0.f))),
            u_prev(height + 2, vector<vector<float>>(height, vector<float>(width, 0.f))),
            v_prev(height + 2, vector<vector<float>>(height, vector<float>(width, 0.f))),
            w_prev(height + 2, vector<vector<float>>(height, vector<float>(width, 0.f))),
            dens(height + 2, vector<vector<float>>(height, vector<float>(width, 0.f))),
            dens_prev(height + 2, vector<vector<float>>(height, vector<float>(width, 0.f))) {}

    void add_source(vector<vector<vector<float>>> &x, vector<vector<vector<float>>> &s, float d);

    void set_bnd(int b, vector<vector<vector<float>>> &x);

    void lin_solve(int b, vector<vector<vector<float>>> &x, vector<vector<vector<float>>> &x0, float a, float c);

    void diffuse(int b, vector<vector<vector<float>>> &x, vector<vector<vector<float>>> &x0, float diff, float d);

    void
    advect(int b, vector<vector<vector<float>>> &d, vector<vector<vector<float>>> &d0, vector<vector<vector<float>>> &u_,
           vector<vector<vector<float>>> &v_, vector<vector<vector<float>>> &w_, float dt_);

    void project(vector<vector<vector<float>>> &u_, vector<vector<vector<float>>> &v_, vector<vector<vector<float>>> &w_,
                 vector<vector<vector<float>>> &p, vector<vector<vector<float>>> &div);

    void
    dens_step(vector<vector<vector<float>>> &x, vector<vector<vector<float>>> &x0, vector<vector<vector<float>>> &u,
              vector<vector<vector<float>>> &v, vector<vector<vector<float>>> &w, float dt, float diff);

    void vel_step(vector<vector<vector<float>>> &u, vector<vector<vector<float>>> &v, vector<vector<vector<float>>> &w,
                  vector<vector<vector<float>>> &v0, vector<vector<vector<float>>> &u0,
                  vector<vector<vector<float>>> &w0,
                  float visc, float dt);

    void update();

};


#endif //CP_CG_SMOKE_H
