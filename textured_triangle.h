#ifndef CP_CG_TEXTURED_TRIANGLE_H
#define CP_CG_TEXTURED_TRIANGLE_H

#include "triangle.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/ConvexShape.hpp>
#include <cmath>

using namespace std;
using namespace sf;

class textured_triangle {
    textured_triangle(const my_vec3f &normal, const array<my_vec3f, 3> &vertices, const my_vec3f &n,
                      const Texture &texture);

    textured_triangle(const triangle &other, const Texture &texture);

    void rotate(const rotate_t &rotate);

private:
    triangle t;
public:
    const triangle &getT() const;

    void setShape(const triangle &shape);

private:
    ConvexShape shape;
};

#endif