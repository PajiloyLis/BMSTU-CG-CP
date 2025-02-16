#ifndef CP_CG_FIGURE_H
#define CP_CG_FIGURE_H

#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <glm/glm.hpp>
#include "triangle.h"

using namespace std;
using namespace sf;

class figure {
public:
    explicit figure(const vector<triangle> &triangles);

    explicit figure(vector<triangle> &&triangles);

    figure() = default;

    [[nodiscard]] glm::vec3 get_center() const;

    [[nodiscard]] array<float, 3> get_size() const;

    void rotate(const rotate_t &rotate);

    void setCenter(const glm::vec3 &center);

    vector<triangle> triangles;
    vector<Texture> textures;
    float min_x, max_x, min_y, max_y, min_z, max_z;
    glm::vec3 center;
};


#endif //CP_CG_FIGURE_H
