#include "figure.h"

figure::figure(const vector<triangle> &triangles) {
    this->triangles = triangles;
}

figure::figure(vector<triangle> &&triangles) {
    this->triangles = triangles;
}

void figure::rotate(float x_angle, float y_angle, float z_angle) {

}

