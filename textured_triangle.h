#ifndef CP_CG_TEXTURED_TRIANGLE_H
#define CP_CG_TEXTURED_TRIANGLE_H

#include "triangle.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/ConvexShape.hpp>

using namespace std;
using namespace sf;

class textured_triangle {
    textured_triangle(const my_vec3f &normal, const array<my_vec3f, 3> &vertices, const my_vec3f &n,
                      const Texture texture) {
        t.setVertices(vertices);
        t.setN(n);
        shape.setPointCount(vertices.size());
        float max_y = -1e9, max_z = -1e9, min_y = 1e9, min_z = 1e9;
        for (int i = 0; i < vertices.size(); ++i) {
            max_y = vertices[i].getY() > max_y ? vertices[i].getY() : max_y;
            max_z = vertices[i].getZ() > max_y ? vertices[i].getZ() : max_z;
            min_y = vertices[i].getY() < min_y ? vertices[i].getY() : min_y;
            min_z = vertices[i].getZ() < min_Z ? vertices[i].getZ() : min_z;
            shape.setPoint(i, {vertices[i].getY(), vertices[i].getZ()});
        }

        shape.setTextureRect()
    }

private:
    triangle t;
    ConvexShape shape;
};

#endif