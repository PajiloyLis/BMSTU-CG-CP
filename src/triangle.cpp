#include "triangle.h"

triangle::triangle(const glm::vec3 &normal, const array<glm::vec3, 3> &points) {
    n = normal;
    vertices = points;
    max_x = std::max(vertices[0].getX(), std::max(vertices[1].getX(), vertices[2].getX()));
    max_y = std::max(vertices[0].getY(), std::max(vertices[1].getY(), vertices[2].getY()));
    max_z = std::max(vertices[0].getZ(), std::max(vertices[1].getZ(), vertices[2].getZ()));

    min_x = std::min(vertices[0].getX(), std::min(vertices[1].getX(), vertices[2].getX()));
    min_y = std::min(vertices[0].getY(), std::min(vertices[1].getY(), vertices[2].getY()));
    min_z = std::min(vertices[0].getZ(), std::min(vertices[1].getZ(), vertices[2].getZ()));
}

triangle::triangle(const glm::vec3 &normal, array<glm::vec3, 3> &&points) {
    n = normal;
    vertices = points;
    max_x = std::max(vertices[0].getX(), std::max(vertices[1].getX(), vertices[2].getX()));
    max_y = std::max(vertices[0].getY(), std::max(vertices[1].getY(), vertices[2].getY()));
    max_z = std::max(vertices[0].getZ(), std::max(vertices[1].getZ(), vertices[2].getZ()));

    min_x = std::min(vertices[0].getX(), std::min(vertices[1].getX(), vertices[2].getX()));
    min_y = std::min(vertices[0].getY(), std::min(vertices[1].getY(), vertices[2].getY()));
    min_z = std::min(vertices[0].getZ(), std::min(vertices[1].getZ(), vertices[2].getZ()));
}

triangle::triangle(glm::vec3 &&normal, const array<glm::vec3, 3> &points) {
    n = normal;
    vertices = points;
    max_x = std::max(vertices[0].getX(), std::max(vertices[1].getX(), vertices[2].getX()));
    max_y = std::max(vertices[0].getY(), std::max(vertices[1].getY(), vertices[2].getY()));
    max_z = std::max(vertices[0].getZ(), std::max(vertices[1].getZ(), vertices[2].getZ()));

    min_x = std::min(vertices[0].getX(), std::min(vertices[1].getX(), vertices[2].getX()));
    min_y = std::min(vertices[0].getY(), std::min(vertices[1].getY(), vertices[2].getY()));
    min_z = std::min(vertices[0].getZ(), std::min(vertices[1].getZ(), vertices[2].getZ()));
}

triangle::triangle(glm::vec3 &&normal, array<glm::vec3, 3> &&points) {
    n = normal;
    vertices = points;
    max_x = std::max(vertices[0].getX(), std::max(vertices[1].getX(), vertices[2].getX()));
    max_y = std::max(vertices[0].getY(), std::max(vertices[1].getY(), vertices[2].getY()));
    max_z = std::max(vertices[0].getZ(), std::max(vertices[1].getZ(), vertices[2].getZ()));

    min_x = std::min(vertices[0].getX(), std::min(vertices[1].getX(), vertices[2].getX()));
    min_y = std::min(vertices[0].getY(), std::min(vertices[1].getY(), vertices[2].getY()));
    min_z = std::min(vertices[0].getZ(), std::min(vertices[1].getZ(), vertices[2].getZ()));
}

void triangle::setVertices(const array<glm::vec3, 3> &vertices) {
    this->vertices = vertices;
    max_x = std::max(vertices[0].getX(), std::max(vertices[1].getX(), vertices[2].getX()));
    max_y = std::max(vertices[0].getY(), std::max(vertices[1].getY(), vertices[2].getY()));
    max_z = std::max(vertices[0].getZ(), std::max(vertices[1].getZ(), vertices[2].getZ()));

    min_x = std::min(vertices[0].getX(), std::min(vertices[1].getX(), vertices[2].getX()));
    min_y = std::min(vertices[0].getY(), std::min(vertices[1].getY(), vertices[2].getY()));
    min_z = std::min(vertices[0].getZ(), std::min(vertices[1].getZ(), vertices[2].getZ()));
}

void triangle::setN(const glm::vec3 &n) {
    this->n = n;
}

const array<glm::vec3, 3> &triangle::getVertices() const {
    return vertices;
}

const glm::vec3 &triangle::getN() const {
    return n;
}

triangle &triangle::operator=(const triangle &t) {
    if(this != &t)
    {
        vertices=t.vertices;
        n=t.n;
    }
    return *this;
}

void triangle::rotate(const rotate_t &rotate) {
    for(auto &vertex:vertices)
        vertex.rotate(rotate);
}
