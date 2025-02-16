#ifndef CP_CG_TEXTURED_FIGURE_H
#define CP_CG_TEXTURED_FIGURE_H

#include <vector>
#include <glm/glm.hpp>
#include <set>
#include <unordered_set>
#include "triangle.h"
#include "conversions.h"
#include <iostream>
#include <algorithm>
#include "textured_triangle.h"

using namespace std;

class textured_figure {
public:
    explicit textured_figure(const vector<textured_triangle> &triangles);

    explicit textured_figure(vector<textured_triangle> &&triangles);

    textured_figure() = default;

    [[nodiscard]] glm::vec3 get_center() const;

    [[nodiscard]] array<float, 3> get_size() const;

    void rotate(const rotate_t &rotate);
//    void scale();

    [[nodiscard]] const vector<textured_triangle> &getTriangles() const;


    void setCenter(const glm::vec3 &center);

    vector<textured_triangle> triangles;
    vector<Texture> textures;
    float min_x, max_x, min_y, max_y, min_z, max_z;
    glm::vec3 center;
};

#endif //CP_CG_TEXTURED_FIGURE_H
