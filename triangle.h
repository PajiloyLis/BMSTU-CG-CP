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

    [[nodiscard]] const array<point, 3> &getVertices() const;

    [[nodiscard]] const point &getN() const;

    bool operator==(const triangle &t) const {
        return vertices[0] == t.vertices[0] && vertices[1] == t.vertices[1] && vertices[2] == t.vertices[2];
    }

    bool operator!=(const triangle &t) const {
        return !(*this == t);
    }

    bool operator<(const triangle &t) const {
        return min(vertices[0], min(vertices[1], vertices[2])) <
               min(t.vertices[0], min(t.vertices[1], min(t.vertices[2], t.vertices[0])));
    }

    bool operator<=(const triangle &t) const {
        return *this < t || *this == t;
    }

    bool operator>(const triangle &t) const {
        return !(*this <= t);
    }

    bool operator>=(const triangle &t) const {
        return !(*this < t);
    }

private:
    array<point, 3> vertices;
    point n;

};


#endif //CP_CG_TRIANGLE_H
