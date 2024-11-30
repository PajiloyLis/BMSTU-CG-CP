#ifndef CP_CG_FIGURE_H
#define CP_CG_FIGURE_H

#include <vector>
#include "point.h"
#include <set>
#include <unordered_set>
#include "triangle.h"
#include "conversions.h"
#include <iostream>
#include <algorithm>

using namespace std;

class figure {
public:
    explicit figure(const vector<triangle> &triangles);

    explicit figure(vector<triangle> &&triangles);

    figure() = default;

    [[nodiscard]] point get_center() const;

    [[nodiscard]] array<float, 3> get_size() const;

    void rotate(const rotate_t &rotate);

    void scale();

private:
    vector<triangle> triangles;
public:
    const vector<triangle> &getTriangles() const;

private:
    float min_x, max_x, min_y, max_y, min_z, max_z;
    point center;
public:
    void setCenter(const point &center);

    void sort();
};

#endif //CP_CG_FIGURE_H
