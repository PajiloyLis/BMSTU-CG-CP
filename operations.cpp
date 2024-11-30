#include "operations.h"

void z_buffer(array<my_vec3f, 3> points, vector<vector<int>> &image, sf::Color color, int *zbuffer) {
    if (points[0].getZ() == points[1].getZ() && points[1].getZ() == points[2].getZ()) return;
    if (points[0].getZ() > points[1].getZ()) std::swap(points[0], points[1]);
    if (points[0].getZ() > points[2].getZ()) std::swap(points[0], points[2]);
    if (points[1].getZ() > points[2].getZ()) std::swap(points[1], points[2]);
    int total_height = (int) round(points[2].getZ() - points[0].getZ());
    for (int i = 0; i < total_height; i++) {
        bool second_half = i > points[1].getZ() - points[0].getZ() || points[1].getZ() == points[0].getZ();
        int segment_height = second_half ? points[2].getZ() - points[1].getZ() : points[1].getZ() - points[0].getZ();
        float alpha = (float) i / total_height;
        float beta = (float) (i - (second_half ? points[1].getZ() - points[0].getZ() : 0)) /
                     segment_height; // be careful: with above conditions no division by zero here
        my_vec3f A = points[0] + my_vec3f(points[2] - points[0]) * alpha;
        my_vec3f B = second_half ? points[1] + my_vec3f(points[2] - points[1]) * beta : points[0] +
                                                                                        my_vec3f(
                                                                                                points[1] - points[0]) *
                                                                                        beta;
        if (A.getY() > B.getY()) std::swap(A, B);
        for (int j = static_cast<int>(round(A.getY())); j <= static_cast<int>(round(B.getY())); j++) {
            float phi = B.getY() == A.getY() ? 1. : (float) (j - A.getY()) / (float) (B.getY() - A.getY());
            my_vec3f P = my_vec3f(A) + my_vec3f(B - A) * phi;
            int idx = P.getY() + P.getZ() * width;
            if (zbuffer[idx] < P.getX()) {
                zbuffer[idx] = P.getX();
                image.P.getY(), P.getZ(), color);
            }
        }
    }
}