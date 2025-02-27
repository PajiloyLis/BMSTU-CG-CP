#include "operations.h"

void z_buffer(array<glm::vec3, 3> points, Image &image, sf::Color color, vector<float> &z_buffer) {
    if (points[0].z == points[1].z && points[1].z == points[2].z) return;
    if (points[0].z > points[1].z) std::swap(points[0], points[1]);
    if (points[0].z > points[2].z) std::swap(points[0], points[2]);
    if (points[1].z > points[2].z) std::swap(points[1], points[2]);
    points[0].z = (ceil(points[0].z)), points[0].x = (ceil(points[0].x)), points[0].y = (
            ceil(points[0].y));
    points[1].z = (ceil(points[1].z)), points[1].x = (ceil(points[1].x)), points[1].y = (
            ceil(points[1].y));
    points[2].z = (ceil(points[2].z)), points[2].x = (ceil(points[2].x)), points[2].y = (
            ceil(points[2].y));
    int total_height = (int) (points[2].z - points[0].z);
    for (int i = 0; i < total_height; i++) {
        bool second_half = i > points[1].z - points[0].z || points[1].z == points[0].z;
        int segment_height = (second_half ? static_cast<int>(points[2].z - points[1].z)
                                          : static_cast<int>(points[1].z - points[0].z));
        float alpha = (float) i / total_height;
        float beta = (float) (i - (second_half ? points[1].z - points[0].z : 0)) /
                     segment_height; // be careful: with above conditions no division by zero here
        glm::vec3 A = points[0] + glm::vec3(points[2] - points[0]) * alpha;
        glm::vec3 B = second_half ? points[1] + glm::vec3(points[2] - points[1]) * beta :
                     points[0] + glm::vec3(points[1] - points[0]) * beta;
        if (A.y > B.y) std::swap(A, B);
        for (int j = static_cast<int>(A.y); j <= static_cast<int>(B.y); j++) {
            float phi = B.y == A.y ? 1. : (float) (j - A.y) / (float) (B.y - A.y);
            glm::vec3 P = glm::vec3(A) + glm::vec3(B - A) * phi;
            if (P.z >= 0 && P.y >= 0 && P.z < image.getSize().y && P.y < image.getSize().x) {
                int idx = static_cast<int>(round(P.y + P.z * image.getSize().x));
                if (z_buffer[idx] < P.x) {
                    z_buffer[idx] = P.x;
                    image.setPixel(static_cast<Uint32>(round(P.y)), static_cast<Uint32>(round(P.z)), color);
                }
            }
        }
    }
}

glm::vec3 adapt_coords(const camera &c, const glm::vec3 &point) {
    glm::mat4 view = c.camLookAt(), perspective = c.perspective();
    glm::mat4 trans = perspective * view;
    // Преобразуем вектор из мировой системы в экранную
    glm::vec4 clipSpacePosition = trans * glm::vec4(point.x, point.y, point.z, 1);

    // Преобразуем в нормализованные координаты устройства (NDC)
    glm::vec3 ndcPosition = glm::vec3(clipSpacePosition) / clipSpacePosition.w;

    // Теперь можете использовать ndcPosition для дальнейшего преобразования в экранные координаты
    float screenX = (ndcPosition.x * 0.5f + 0.5f) * this->size().width(); // ширина окна
    float screenY = ((0.5 - ndcPosition.y) * 0.5f) * this->size().height(); // высота окна
    float screenZ = (ndcPosition.z * 0.5f + 0.5f) * SCREEN_DEPTH;

    return {screenX, screenY, clipSpacePosition.z};
}