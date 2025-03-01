#include "triangle.h"

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

void
triangle::draw(sf::RenderTarget &target, vector<float> &zbuffer, const glm::vec3 &light, const vector<sf::Color> &colors,
               sf::RenderStates states) const {
#ifndef GL
    z_buffer(vertices, target, colors, zbuffer);
#else
//    cout<<"GL"<<'\n';
    sf::VertexArray to_draw(sf::Triangles, 3);
    for (int i = 0; i < 3; ++i) {
        to_draw[i] = sf::Vertex(sf::Vector2f(vertices[i].x, vertices[i].y), colors[i]);
    }
    glBegin(GL_TRIANGLES);
    glColor3ui(colors[0].r, colors[0].g, colors[0].b); glVertex3f(vertices[0].x, vertices[0].y, vertices[0].z);
    glColor3ui(0, 1, 0); glVertex3f(vertices[1].x, vertices[1].y, vertices[1].z);
    glColor3ui(0, 0, 1); glVertex3f(vertices[2].x, vertices[2].y, vertices[2].z);
    glEnd();
#endif
}
