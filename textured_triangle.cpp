#include "textured_triangle.h"

textured_triangle::textured_triangle(const triangle &other, const Texture &texture) {
    t = other;
    shape.setPointCount(other.getVertices().size());
    float max_y = -1e9, max_z = -1e9, min_y = 1e9, min_z = 1e9;
    for (int i = 0; i < other.getVertices().size(); ++i) {
        max_y = other.getVertices()[i].getY() > max_y ? other.getVertices()[i].getY() : max_y;
        max_z = other.getVertices()[i].getZ() > max_y ? other.getVertices()[i].getZ() : max_z;
        min_y = other.getVertices()[i].getY() < min_y ? other.getVertices()[i].getY() : min_y;
        min_z = other.getVertices()[i].getZ() < min_z ? other.getVertices()[i].getZ() : min_z;
        shape.setPoint(i, {other.getVertices()[i].getY(), other.getVertices()[i].getZ()});
    }
    const_cast<Texture &>(texture).generateMipmap();
    shape.setTextureRect({{0,                                     0},
                          {static_cast<int>(ceil(max_y - min_y)), static_cast<int>(ceil(max_z - min_z))}});
    shape.setTexture(&texture);
}

textured_triangle::textured_triangle(const my_vec3f &normal, const array<my_vec3f, 3> &vertices, const my_vec3f &n,
                                     const Texture &texture) {
    t.setVertices(vertices);
    t.setN(n);
    shape.setPointCount(vertices.size());
    float max_y = -1e9, max_z = -1e9, min_y = 1e9, min_z = 1e9;
    for (int i = 0; i < vertices.size(); ++i) {
        max_y = vertices[i].getY() > max_y ? vertices[i].getY() : max_y;
        max_z = vertices[i].getZ() > max_y ? vertices[i].getZ() : max_z;
        min_y = vertices[i].getY() < min_y ? vertices[i].getY() : min_y;
        min_z = vertices[i].getZ() < min_z ? vertices[i].getZ() : min_z;
        shape.setPoint(i, {vertices[i].getY(), vertices[i].getZ()});
    }
    const_cast<Texture &>(texture).generateMipmap();
    shape.setTextureRect({{0,                                     0},
                          {static_cast<int>(ceil(max_y - min_y)), static_cast<int>(ceil(max_z - min_z))}});
    shape.setTexture(&texture);
}

void textured_triangle::setShape(const triangle &shape) {

}

const triangle &textured_triangle::getT() const {
    return t;
}

void textured_triangle::rotate(const rotate_t &rotate) {
    t.rotate(rotate);
    for (int i = 0; i < t.getVertices().size(); ++i) {
        shape.setPoint(i, {t.getVertices()[i].getY(), t.getVertices()[i].getZ()});
    }
}

void textured_triangle::setTexture(const Texture &texture) {
    shape.setPointCount(t.getVertices().size());
    float max_y = -1e9, max_z = -1e9, min_y = 1e9, min_z = 1e9;
    for (int i = 0; i < t.getVertices().size(); ++i) {
        max_y = t.getVertices()[i].getY() > max_y ? t.getVertices()[i].getY() : max_y;
        max_z = t.getVertices()[i].getZ() > max_y ? t.getVertices()[i].getZ() : max_z;
        min_y = t.getVertices()[i].getY() < min_y ? t.getVertices()[i].getY() : min_y;
        min_z = t.getVertices()[i].getZ() < min_z ? t.getVertices()[i].getZ() : min_z;
        shape.setPoint(i, {t.getVertices()[i].getY(), t.getVertices()[i].getZ()});
    }
    const_cast<Texture &>(texture).generateMipmap();
    shape.setTextureRect({{0,                                     0},
                          {static_cast<int>(ceil(max_y - min_y)), static_cast<int>(ceil(max_z - min_z))}});
    shape.setTexture(&texture);
}

