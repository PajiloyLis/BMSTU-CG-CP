#ifndef CP_CG_FIGURE_H
#define CP_CG_FIGURE_H

#include <vector>
#include "my_vec3f.h"
#include <set>
#include <unordered_set>
#include "triangle.h"
#include "conversions.h"
#include <iostream>
#include <algorithm>
#include <textured_triangle.h>

using namespace std;

class figure {
public:
    explicit figure(const vector<textured_triangle> &triangles);

    explicit figure(vector<textured_triangle> &&triangles);

    figure() = default;

    [[nodiscard]] my_vec3f get_center() const;

    [[nodiscard]] array<float, 3> get_size() const;

    void rotate(const rotate_t &rotate);

    void addTexture(const Texture &texture)
    {
        textures.push_back(texture);
        auto start = clock();
        for(auto &triangle: triangles)
            triangle.setTexture(textures.back());
        auto end = clock();
        cout<<"TEXTURED PER "<<(end-start)/CLOCKS_PER_SEC<<'\n';
    }
//    void scale();

    vector<textured_triangle> triangles;
    vector<Texture> textures;
public:
    [[nodiscard]] const vector<textured_triangle> & getTriangles() const;

    float min_x, max_x, min_y, max_y, min_z, max_z;
    my_vec3f center;
public:
    void setCenter(const my_vec3f &center);
};

#endif //CP_CG_FIGURE_H
