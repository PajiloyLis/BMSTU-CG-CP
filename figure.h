#ifndef CP_CG_FIGURE_H
#define CP_CG_FIGURE_H

#include <vector>
#include "point.h"
#include <set>
#include <unordered_set>
#include "triangle.h"

using namespace std;

class figure
{
public:
    explicit figure(const vector<triangle> &triangles);
    explicit figure(vector<triangle> &&triangles);
    figure() = default;

    void rotate(float x_angle=0, float y_angle = 0, float z_angle = 0);

    void scale();
private:
    vector<triangle> triangles;
};

#endif //CP_CG_FIGURE_H
