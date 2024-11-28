#ifndef CP_CG_TRIANGLE_H
#define CP_CG_TRIANGLE_H

#include<cmath>
#include<fstream>
#include <compare>
#include <GL/gl.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#include <point.h>
#include <array>

using namespace std;

class triangle {
public:
    triangle(const point &normal, const array<point, 3> &points);

    triangle() = default;

    triangle(const point &normal, array<point, 3> &&points);

    triangle(point &&normal, const array<point, 3> &points);

    triangle(point &&normal, array<point, 3> &&points);

    void setVertices(const array<point, 3> &vertices);

    void setN(const point &n);

    const array<point, 3> &getVertices() const;

    const point &getN() const;

private:
    array<point, 3> vertices;
    point n;

};


#endif //CP_CG_TRIANGLE_H
