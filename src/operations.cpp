#include "operations.h"

void z_buffer(array<glm::vec3, 3> points, Image &image, sf::Color color, vector<float> &z_buffer) {
    if (points[0].getZ() == points[1].getZ() && points[1].getZ() == points[2].getZ()) return;
    if (points[0].getZ() > points[1].getZ()) std::swap(points[0], points[1]);
    if (points[0].getZ() > points[2].getZ()) std::swap(points[0], points[2]);
    if (points[1].getZ() > points[2].getZ()) std::swap(points[1], points[2]);
    points[0].setZ(ceil(points[0].getZ())), points[0].setX(ceil(points[0].getX())), points[0].setY(
            ceil(points[0].getY()));
    points[1].setZ(ceil(points[1].getZ())), points[1].setX(ceil(points[1].getX())), points[1].setY(
            ceil(points[1].getY()));
    points[2].setZ(ceil(points[2].getZ())), points[2].setX(ceil(points[2].getX())), points[2].setY(
            ceil(points[2].getY()));
    int total_height = (int) (points[2].getZ() - points[0].getZ());
    for (int i = 0; i < total_height; i++) {
        bool second_half = i > points[1].getZ() - points[0].getZ() || points[1].getZ() == points[0].getZ();
        int segment_height = (second_half ? static_cast<int>(points[2].getZ() - points[1].getZ())
                                          : static_cast<int>(points[1].getZ() - points[0].getZ()));
        float alpha = (float) i / total_height;
        float beta = (float) (i - (second_half ? points[1].getZ() - points[0].getZ() : 0)) /
                     segment_height; // be careful: with above conditions no division by zero here
        glm::vec3 A = points[0] + glm::vec3(points[2] - points[0]) * alpha;
        glm::vec3 B = second_half ? points[1] + glm::vec3(points[2] - points[1]) * beta :
                     points[0] + glm::vec3(points[1] - points[0]) * beta;
        if (A.getY() > B.getY()) std::swap(A, B);
        for (int j = static_cast<int>(A.getY()); j <= static_cast<int>(B.getY()); j++) {
            float phi = B.getY() == A.getY() ? 1. : (float) (j - A.getY()) / (float) (B.getY() - A.getY());
            glm::vec3 P = glm::vec3(A) + glm::vec3(B - A) * phi;
            if (P.getZ() >= 0 && P.getY() >= 0 && P.getZ() < image.getSize().y && P.getY() < image.getSize().x) {
                int idx = static_cast<int>(round(P.getY() + P.getZ() * image.getSize().x));
                if (z_buffer[idx] < P.getX()) {
                    z_buffer[idx] = P.getX();
                    image.setPixel(static_cast<Uint32>(round(P.getY())), static_cast<Uint32>(round(P.getZ())), color);
                }
            }
        }
    }
}