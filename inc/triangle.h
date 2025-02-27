#ifndef CP_CG_TRIANGLE_H
#define CP_CG_TRIANGLE_H

#include<cmath>
#include<fstream>
#include <compare>
#include <GL/gl.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#include <array>
#include "conversions.h"
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics.hpp>
#include <operations.h>

using namespace std;

class triangle {
public:
    triangle(const glm::vec3 &normal, const array<glm::vec3, 3> &points);

    void draw(sf::RenderTarget &target, vector<float> &zbuffer, sf::RenderStates states = sf::RenderStates()) const;

    triangle() = default;

    triangle(const glm::vec3 &normal, array<glm::vec3, 3> &&points);

    triangle(glm::vec3 &&normal, const array<glm::vec3, 3> &points);

    triangle(glm::vec3 &&normal, array<glm::vec3, 3> &&points);

    void setVertices(const array<glm::vec3, 3> &vertices);

    void setN(const glm::vec3 &n);

    [[nodiscard]] const array<glm::vec3, 3> &getVertices() const;

    bool operator==(const triangle &t) const {
        return vertices[0] == t.vertices[0] && vertices[1] == t.vertices[1] && vertices[2] == t.vertices[2];
    }

    bool operator!=(const triangle &t) const {
        return !(*this == t);
    }

    triangle &operator=(const triangle &t);

    void rotate(const rotate_t &rotate_data);

    array<glm::vec3, 3> vertices;
    glm::vec3 n;
    float max_x, min_x, max_y, min_y, max_z, min_z;

};


#endif //CP_CG_TRIANGLE_H
