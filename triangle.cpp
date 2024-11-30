#include "triangle.h"

triangle::triangle(const my_vec3f &normal, const array<my_vec3f, 3> &points) {
    n = normal;
    vertices = points;
}

triangle::triangle(const my_vec3f &normal, array<my_vec3f, 3> &&points) {
    n = normal;
    vertices = points;
}

triangle::triangle(my_vec3f &&normal, const array<my_vec3f, 3> &points) {
    n = normal;
    vertices = points;
}

triangle::triangle(my_vec3f &&normal, array<my_vec3f, 3> &&points) {
    n = normal;
    vertices = points;
}

void triangle::setVertices(const array<my_vec3f, 3> &vertices) {
    this->vertices = vertices;
}

void triangle::setN(const my_vec3f &n) {
    this->n = n;
}

const array<my_vec3f, 3> &triangle::getVertices() const {
    return vertices;
}

const my_vec3f &triangle::getN() const {
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
