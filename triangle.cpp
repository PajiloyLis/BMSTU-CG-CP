#include "triangle.h"

triangle::triangle(const point &normal, const array<point, 3> &points) {
    n = normal;
    vertices = points;
}

triangle::triangle(const point &normal, array<point, 3> &&points) {
    n = normal;
    vertices = points;
}

triangle::triangle(point &&normal, const array<point, 3> &points) {
    n = normal;
    vertices = points;
}

triangle::triangle(point &&normal, array<point, 3> &&points) {
    n = normal;
    vertices = points;
}

void triangle::setVertices(const array<point, 3> &vertices) {
    this->vertices = vertices;
}

void triangle::setN(const point &n) {
    this->n = n;
}

const array<point, 3> &triangle::getVertices() const {
    return vertices;
}

const point &triangle::getN() const {
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
