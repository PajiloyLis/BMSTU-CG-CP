#include "operations.h"

void z_buffer(array<glm::vec3, 3> points, sf::RenderTarget &image, sf::Color color, vector<float> &z_buffer) {
    if (abs(points[0].y - points[1].y) < 1e-5 && abs(points[1].y - points[2].y) < 1e-5) return;
    glm::vec<3, int, glm::defaultp> t0(ceil(points[0].x), ceil(points[0].y), ceil(points[0].z)),
            t1(ceil(points[1].x), ceil(points[1].y), ceil(points[1].z)),
            t2(ceil(points[2].x), ceil(points[2].y), ceil(points[2].z));
    if (t0.y > t1.y) std::swap(t0, t1);
    if (t0.y > t2.y) std::swap(t0, t2);
    if (t1.y > t2.y) std::swap(t1, t2);
    int total_height = t2.y - t0.y;
    for (int i = 0; i < total_height; i++) {
        bool second_half = i > t1.y - t0.y || t1.y == t0.y;
        int segment_height = second_half ? t2.y - t1.y : t1.y - t0.y;
        float alpha = (float) i / total_height;
        float beta = (float) (i - (second_half ? t1.y - t0.y : 0)) /
                     segment_height; // be careful: with above conditions no division by zero here
        glm::vec3 A = glm::vec3(t0) + glm::vec3(t2 - t0) * alpha;
        glm::vec3 B = (second_half ? glm::vec3(t1) + glm::vec3(t2 - t1) * beta :
                       glm::vec3(t0) + glm::vec3(t1 - t0) * beta);
        if (A.x > B.x) std::swap(A, B);
        for (int j = round(A.x); j <= round(B.x); j++) {
            float phi = B.x == A.x ? 1. : (float) (j - A.x) / (float) (B.x - A.x);
            glm::vec3 P = glm::vec3(A) + glm::vec3(B - A) * phi;
            int idx = round(P.x + P.y * image.getSize().x);
            if (idx >= 0 && idx < z_buffer.size() && z_buffer[idx] < P.z) {
                z_buffer[idx] = P.z;
                image.draw(vector<sf::Vertex>(1, sf::Vertex(sf::Vector2f(P.x, image.getSize().y - P.y), color)).data(),
                           1,
                           sf::Points);
            }
        }
    }
}

glm::vec3 adapt_coords(const camera &c, const glm::vec3 &point, const float &scene_width, const float &scene_height) {
    glm::mat4 view = c.camLookAt(), perspective = c.perspective();
    glm::mat4 trans = perspective * view;
    // Преобразуем вектор из мировой системы в экранную
    glm::vec4 clipSpacePosition = trans * glm::vec4(point.x, point.y, point.z, 1);

    // Преобразуем в нормализованные координаты устройства (NDC)
    glm::vec3 ndcPosition = glm::vec3(clipSpacePosition) / clipSpacePosition.w;

    // Теперь можете использовать ndcPosition для дальнейшего преобразования в экранные координаты
    float screenX = (ndcPosition.x * 0.5f + 0.5f) * scene_width; // ширина окна
    float screenY = ((0.5 - ndcPosition.y) * 0.5f) * scene_height; // высота окна

    return {screenX, screenY, clipSpacePosition.z};
}