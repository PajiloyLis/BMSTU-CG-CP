//
// Created by ivan on 05.12.24.
//

#include "figure.h"

figure::figure(const vector<triangle> &triangles) {
    this->triangles = triangles;
    max_x = max_y = max_z = -1e9;
    min_x = min_y = min_z = 1e9;
    for (auto &triangle: triangles) {
        for (auto &p: triangle.vertices) {
            max_x = std::max(max_x, p.x), min_x = std::min(min_x, p.x);
            max_y = std::max(max_y, p.y), min_y = std::min(min_y, p.y);
            max_z = std::max(max_z, p.z), min_z = std::min(min_z, p.z);
        }
    }
    center.x = (max_x - min_x) / 2, center.y = (max_y - min_y) / 2, center.z = (max_z - min_z) / 2;
}

figure::figure(vector<triangle> &&triangles) {
    this->triangles = triangles;
    max_x = max_y = max_z = -1e9;
    min_x = min_y = min_z = 1e9;
    for (auto &triangle: triangles) {
        for (auto &p: triangle.vertices) {
            max_x = std::max(max_x, p.x), min_x = std::min(min_x, p.x);
            max_y = std::max(max_y, p.y), min_y = std::min(min_y, p.y);
            max_z = std::max(max_z, p.z), min_z = std::min(min_z, p.z);
        }
    }
    center.x = (max_x - min_x) / 2, center.y = (max_y - min_y) / 2, center.z = (max_z - min_z) / 2;
}

void figure::rotate(const rotate_t &rotate) {
    for (auto &triangle: triangles) {
        triangle.rotate(rotate);
    }
    cout << "figure_rotated\n";
}

glm::vec3 figure::get_center() const {
    return {(max_x - min_x) / 2, (max_y - min_y) / 2, (max_z - min_z) / 2};
}

array<float, 3> figure::get_size() const {
    return {max_x - min_x, max_y - min_y, max_z - min_z};
}

void figure::setCenter(const glm::vec3 &center) {
    this->center = center;
}
