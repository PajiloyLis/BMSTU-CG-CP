#ifndef CP_CG_OPERATIONS_H
#define CP_CG_OPERATIONS_H

#include <array>
#include <iostream>
#include <algorithm>
#include <glm/glm.hpp>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Image.hpp>
#include <cmath>
#include "camera.h"

using namespace std;
using namespace sf;

void z_buffer(array<glm::vec3, 3> points, sf::RenderTarget &image, const sf::Color &color, vector<float> &z_buffer);

glm::vec3 adapt_coords(const camera &c, const glm::vec3 &point, const float &scene_width, const float &scene_height);

#endif //CP_CG_OPERATIONS_Hs