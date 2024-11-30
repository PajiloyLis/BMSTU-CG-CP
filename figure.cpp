#include "figure.h"

figure::figure(const vector<triangle> &triangles) {
    this->triangles = triangles;
    max_x = max_y = max_z = -1e9;
    min_x = min_y = min_z = 1e9;
    for (auto &triangle: triangles) {
        for (auto &p: triangle.getVertices()) {
            max_x = max(max_x, p.getX()), min_x = min(min_x, p.getX());
            max_y = max(max_y, p.getY()), min_y = min(min_y, p.getY());
            max_z = max(max_z, p.getZ()), min_z = min(min_z, p.getZ());
        }
    }
    center.setX((max_x - min_x) / 2), center.setY((max_y - min_y) / 2), center.setZ((max_z - min_z) / 2);
}

figure::figure(vector<triangle> &&triangles) {
    this->triangles = triangles;
    max_x = max_y = max_z = -1e9;
    min_x = min_y = min_z = 1e9;
    for (auto &triangle: triangles) {
        for (auto &p: triangle.getVertices()) {
            max_x = max(max_x, p.getX()), min_x = min(min_x, p.getX());
            max_y = max(max_y, p.getY()), min_y = min(min_y, p.getY());
            max_z = max(max_z, p.getZ()), min_z = min(min_z, p.getZ());
        }
    }
    center.setX((max_x - min_x) / 2), center.setY((max_y - min_y) / 2), center.setZ((max_z - min_z) / 2);
}

void figure::rotate(const rotate_t &rotate) {
    for (auto &triangle: triangles) {
        const_cast<point &>(triangle.getN()).rotate(rotate);
        for (auto &p: triangle.getVertices())
            const_cast<point &>(p) = (p - center).rotate(rotate) + center;
    }
    cout << "figure_rotated\n";
}

point figure::get_center() const {
    return {(max_x - min_x) / 2, (max_y - min_y) / 2, (max_z - min_z) / 2};
}

array<float, 3> figure::get_size() const {
    return {max_x - min_x, max_y - min_y, max_z - min_z};
}

const vector<triangle> &figure::getTriangles() const {
    return triangles;
}

void figure::setCenter(const point &center) {
    this->center = center;
}

void figure::sort()
{
    std::sort(triangles.begin(), triangles.end());
}

