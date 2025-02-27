#include "triangle.h"

const glm::vec3 light_ray = glm::vec3(0, 0, 1);

triangle::triangle(const glm::vec3 &normal, const array<glm::vec3, 3> &points) {
    n = normal;
    vertices = points;
    max_x = std::max(vertices[0].x, std::max(vertices[1].x, vertices[2].x));
    max_y = std::max(vertices[0].y, std::max(vertices[1].y, vertices[2].y));
    max_z = std::max(vertices[0].z, std::max(vertices[1].z, vertices[2].z));

    min_x = std::min(vertices[0].x, std::min(vertices[1].x, vertices[2].x));
    min_y = std::min(vertices[0].y, std::min(vertices[1].y, vertices[2].y));
    min_z = std::min(vertices[0].z, std::min(vertices[1].z, vertices[2].z));
}

triangle::triangle(const glm::vec3 &normal, array<glm::vec3, 3> &&points) {
    n = normal;
    vertices = points;
    max_x = std::max(vertices[0].x, std::max(vertices[1].x, vertices[2].x));
    max_y = std::max(vertices[0].y, std::max(vertices[1].y, vertices[2].y));
    max_z = std::max(vertices[0].z, std::max(vertices[1].z, vertices[2].z));

    min_x = std::min(vertices[0].x, std::min(vertices[1].x, vertices[2].x));
    min_y = std::min(vertices[0].y, std::min(vertices[1].y, vertices[2].y));
    min_z = std::min(vertices[0].z, std::min(vertices[1].z, vertices[2].z));
}

triangle::triangle(glm::vec3 &&normal, const array<glm::vec3, 3> &points) {
    n = normal;
    vertices = points;
    max_x = std::max(vertices[0].x, std::max(vertices[1].x, vertices[2].x));
    max_y = std::max(vertices[0].y, std::max(vertices[1].y, vertices[2].y));
    max_z = std::max(vertices[0].z, std::max(vertices[1].z, vertices[2].z));

    min_x = std::min(vertices[0].x, std::min(vertices[1].x, vertices[2].x));
    min_y = std::min(vertices[0].y, std::min(vertices[1].y, vertices[2].y));
    min_z = std::min(vertices[0].z, std::min(vertices[1].z, vertices[2].z));
}

triangle::triangle(glm::vec3 &&normal, array<glm::vec3, 3> &&points) {
    n = normal;
    vertices = points;
    max_x = std::max(vertices[0].x, std::max(vertices[1].x, vertices[2].x));
    max_y = std::max(vertices[0].y, std::max(vertices[1].y, vertices[2].y));
    max_z = std::max(vertices[0].z, std::max(vertices[1].z, vertices[2].z));

    min_x = std::min(vertices[0].x, std::min(vertices[1].x, vertices[2].x));
    min_y = std::min(vertices[0].y, std::min(vertices[1].y, vertices[2].y));
    min_z = std::min(vertices[0].z, std::min(vertices[1].z, vertices[2].z));
}

void triangle::setVertices(const array<glm::vec3, 3> &vertices) {
    this->vertices = vertices;
    max_x = std::max(vertices[0].x, std::max(vertices[1].x, vertices[2].x));
    max_y = std::max(vertices[0].y, std::max(vertices[1].y, vertices[2].y));
    max_z = std::max(vertices[0].z, std::max(vertices[1].z, vertices[2].z));

    min_x = std::min(vertices[0].x, std::min(vertices[1].x, vertices[2].x));
    min_y = std::min(vertices[0].y, std::min(vertices[1].y, vertices[2].y));
    min_z = std::min(vertices[0].z, std::min(vertices[1].z, vertices[2].z));
}

void triangle::setN(const glm::vec3 &n) {
    this->n = n;
}

const array<glm::vec3, 3> &triangle::getVertices() const {
    return vertices;
}

triangle &triangle::operator=(const triangle &t) {
    if (this != &t) {
        vertices = t.vertices;
        n = t.n;
    }
    return *this;
}

void triangle::rotate(const rotate_t &rotate_data) {
    for (auto &vertex: vertices)
        ::rotate(rotate_data, vertex);
}

void triangle::draw(sf::RenderTarget &target, vector<float> &zbuffer, sf::RenderStates states) const {
    float intensity = glm::dot(light_ray, n);
    z_buffer(vertices, target, {static_cast<Uint8>(255 * intensity), static_cast<Uint8>(250 * intensity),
                              static_cast<Uint8>(250 * intensity)}, zbuffer);
//        this->draw(&points_to_render[0], points_to_render.size(), sf::Triangles);

}
