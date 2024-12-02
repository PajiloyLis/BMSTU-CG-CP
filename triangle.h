#ifndef CP_CG_TRIANGLE_H
#define CP_CG_TRIANGLE_H

#include<cmath>
#include<fstream>
#include <compare>
#include <GL/gl.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#include <my_vec3f.h>
#include <array>
#include "conversions.h"

using namespace std;

class triangle {
public:
    triangle(const my_vec3f &normal, const array<my_vec3f, 3> &points);

    triangle() = default;

    triangle(const my_vec3f &normal, array<my_vec3f, 3> &&points);

    triangle(my_vec3f &&normal, const array<my_vec3f, 3> &points);

    triangle(my_vec3f &&normal, array<my_vec3f, 3> &&points);

    void setVertices(const array<my_vec3f, 3> &vertices);

    void setN(const my_vec3f &n);

    [[nodiscard]] const array<my_vec3f, 3> &getVertices() const;

    [[nodiscard]] const my_vec3f &getN() const;

    bool operator==(const triangle &t) const {
        return vertices[0] == t.vertices[0] && vertices[1] == t.vertices[1] && vertices[2] == t.vertices[2];
    }

    bool operator!=(const triangle &t) const {
        return !(*this == t);
    }

//    bool operator<(const triangle &t) const {
//        return min(vertices[0], min(vertices[1], vertices[2])) <
//               min(t.vertices[0], min(t.vertices[1], min(t.vertices[2], t.vertices[0])));
//    }
//
//    bool operator<=(const triangle &t) const {
//        return *this < t || *this == t;
//    }
//
//    bool operator>(const triangle &t) const {
//        return !(*this <= t);
//    }
//
//    bool operator>=(const triangle &t) const {
//        return !(*this < t);
//    }

    triangle &operator=(const triangle &t);

    void rotate(const rotate_t &rotate);

    array<my_vec3f, 3> vertices;
    my_vec3f n;
    float max_x, min_x, max_y, min_y, max_z, min_z;

};


#endif //CP_CG_TRIANGLE_H
