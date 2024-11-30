#ifndef CP_CG_OPERATIONS_H
#define CP_CG_OPERATIONS_H

#include <array>
#include <iostream>
#include <algorithm>
#include "my_vec3f.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include <cmath>
#include "triangle.h"

using namespace std;

void z_buffer(vector<triangle> &triangles, int start, int stop, vector<vector<sf::Vertex>> &image, sf::Color color,
              vector<float> &z_buffer, my_vec3f &light_ray);

#endif //CP_CG_OPERATIONS_H
