#ifndef CP_CG_OPERATIONS_H
#define CP_CG_OPERATIONS_H

#include <array>
#include <iostream>
#include <algorithm>
#include "my_vec3f.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Image.hpp>
#include <cmath>

using namespace std;
using namespace sf;

void z_buffer(array<my_vec3f, 3> points, Image &image, sf::Color color, vector<float> &z_buffer);

#endif //CP_CG_OPERATIONS_Hs