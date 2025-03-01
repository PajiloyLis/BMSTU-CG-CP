#include "operations.h"

void z_buffer(array<glm::vec3, 3> points, sf::RenderTarget &image, const vector<sf::Color> &colors,
              vector<float> &z_buffer) {
//    if (abs(points[0].y - points[1].y) < 1e-5 && abs(points[1].y - points[2].y) < 1e-5) return;
//    glm::vec<3, int, glm::defaultp> t0(round(points[0].x), round(points[0].y), round(points[0].z)),
//            t1(round(points[1].x), round(points[1].y), round(points[1].z)),
//            t2(round(points[2].x), round(points[2].y), round(points[2].z));
//    if (t0.y > t1.y) std::swap(t0, t1);
//    if (t0.y > t2.y) std::swap(t0, t2);
//    if (t1.y > t2.y) std::swap(t1, t2);
//    int total_height = t2.y - t0.y;
//    for (int i = 0; i < total_height; i++) {
//        bool second_half = i > t1.y - t0.y || t1.y == t0.y;
//        int segment_height = second_half ? t2.y - t1.y : t1.y - t0.y;
//        float alpha = (float) i / total_height;
//        float beta = (float) (i - (second_half ? t1.y - t0.y : 0)) /
//                     segment_height; // be careful: with above conditions no division by zero here
//        glm::vec3 A = glm::vec3(t0) + glm::vec3(t2 - t0) * alpha;
//        glm::vec3 B = (second_half ? glm::vec3(t1) + glm::vec3(t2 - t1) * beta :
//                       glm::vec3(t0) + glm::vec3(t1 - t0) * beta);
//        if (A.x > B.x) std::swap(A, B);
//        for (int j = round(A.x); j <= round(B.x); j++) {
//            float phi = B.x == A.x ? 1. : (float) (j - A.x) / (float) (B.x - A.x);
//            glm::vec3 P = glm::vec3(A) + glm::vec3(B - A) * phi;
//
//            int idx = round(P.x + P.y * image.getSize().x);
//            if (idx >= 0 && idx < z_buffer.size() && z_buffer[idx] < P.z) {
//                glm::vec3 barycentric = glm::vec3(
//                        ((t1.y - t2.y) * (j - t2.x) + (t2.x - t1.x) * (P.y - t2.y)) /
//                        ((t1.y - t2.y) * (t0.x - t2.x) + (t2.x - t1.x) * (t0.y - t2.y)),
//                        ((t2.y - t0.y) * (j - t2.x) + (t0.x - t2.x) * (P.y - t2.y)) /
//                        ((t1.y - t2.y) * (t0.x - t2.x) + (t2.x - t1.x) * (t0.y - t2.y)),
//                        1.0f - barycentric.x - barycentric.y);
//
//                sf::Color color;
//                color.r = static_cast<sf::Uint8>(barycentric.x * colors[0].r + barycentric.y * colors[1].r +
//                                                 barycentric.z * colors[2].r);
//                color.g = static_cast<sf::Uint8>(barycentric.x * colors[0].g + barycentric.y * colors[1].g +
//                                                 barycentric.z * colors[2].g);
//                color.b = static_cast<sf::Uint8>(barycentric.x * colors[0].b + barycentric.y * colors[1].b +
//                                                 barycentric.z * colors[2].b);
//                z_buffer[idx] = P.z;
//                image.draw(vector<sf::Vertex>(1, sf::Vertex(sf::Vector2f(P.x, P.y), color)).data(),
//                           1,
//                           sf::Points);
//            }
//        }
//    }

//    if (abs(points[0].y - points[1].y) < 1e-9 && abs(points[1].y - points[2].y) < 1e-9) return;;
//    if (points[0].y > points[1].y) std::swap(points[0], points[1]);
//    if (points[0].y > points[2].y) std::swap(points[0], points[2]);
//    if (points[1].y > points[2].y) std::swap(points[1], points[2]);
//    points[0].z = (ceil(points[0].z)), points[0].x = (ceil(points[0].x)), points[0].y = (
//            ceil(points[0].y));
//    points[1].z = (ceil(points[1].z)), points[1].x = (ceil(points[1].x)), points[1].y = (
//            ceil(points[1].y));
//    points[2].z = (ceil(points[2].z)), points[2].x = (ceil(points[2].x)), points[2].y = (
//            ceil(points[2].y));
//    int total_height = (int) (points[2].y - points[0].y);
//    for (int i = 0; i < total_height; i++) {
//        bool second_half = i > points[1].y - points[0].y || points[1].y == points[0].y;
//        int segment_height = (second_half ? static_cast<int>(points[2].y - points[1].y)
//                                          : static_cast<int>(points[1].y - points[0].y));
//        float alpha = (float) i / total_height;
//        float beta = (float) (i - (second_half ? points[1].y - points[0].y : 0)) /
//                     segment_height;
//        glm::vec3 a = points[0] + (points[2] - points[0]) * alpha;
//        glm::vec3 b = second_half ? points[1] + (points[2] - points[1]) * beta :
//                      points[0] + (points[1] - points[0]) * beta;
//        if (a.x > b.x) std::swap(a, b);
//        for (int j = static_cast<int>(a.x ); j <= static_cast<int>(b.x ); j++) {
//            float phi = (b.x == a.x ? 1.f : (float) (j - a.x) / (float) (b.x - a.x));
//            glm::vec3 P = a + ((b - a) * phi);
//            if (P.x >= 0 && P.y >= 0 && P.x < image.getSize().x && P.y < image.getSize().y) {
//                int idx = static_cast<int>(round(P.x + P.y * image.getSize().x));
//                if (z_buffer[idx] > P.z) {
//                    glm::vec3 barycentric = glm::vec3(
//                            ((points[1].y - points[2].y) * (j - points[2].x) +
//                             (points[2].x - points[1].x) * (P.y - points[2].y)) /
//                            ((points[1].y - points[2].y) * (points[0].x - points[2].x) +
//                             (points[2].x - points[1].x) * (points[0].y - points[2].y)),
//                            ((points[2].y - points[0].y) * (j - points[2].x) +
//                             (points[0].x - points[2].x) * (P.y - points[2].y)) /
//                            ((points[1].y - points[2].y) * (points[0].x - points[2].x) +
//                             (points[2].x - points[1].x) * (points[0].y - points[2].y)),
//                            1.0f - barycentric.x - barycentric.y);
//
//                    sf::Color color;
//                    color.r = static_cast<sf::Uint8>(barycentric.x * colors[0].r + barycentric.y * colors[1].r +
//                                                     barycentric.z * colors[2].r);
//                    color.g = static_cast<sf::Uint8>(barycentric.x * colors[0].g + barycentric.y * colors[1].g +
//                                                     barycentric.z * colors[2].g);
//                    color.b = static_cast<sf::Uint8>(barycentric.x * colors[0].b + barycentric.y * colors[1].b +
//                                                     barycentric.z * colors[2].b);
//                    z_buffer[idx] = P.z;
//                    image.draw(vector<sf::Vertex>(1, sf::Vertex(sf::Vector2f(P.x, P.y),
//                                                                color)).data(), 1, sf::Points);
//                }
//            }
//        }
//    }
    int minX = std::max(0, static_cast<int>(std::min({points[0].x, points[1].x, points[2].x})));
    int maxX = std::min(image.getSize().x - 1, static_cast<unsigned int>(std::max({points[0].x, points[1].x, points[2].x})));
    int minY = std::max(0, static_cast<int>(std::min({points[0].y, points[1].y, points[2].y})));
    int maxY = std::min(screenHeight - 1, static_cast<int>(std::max({points[0].y, points[1].y, points[2].y})));

    // Проходим по всем пикселям в ограничивающем прямоугольнике
    for (int y = minY; y <= maxY; ++y) {
        for (int x = minX; x <= maxX; ++x) {
            glm::vec2 p(x, y);

            // Вычисляем барицентрические координаты
            float alpha = ((points[1].y - points[2].y) * (p.x - points[2].x) + (points[2].x - points[1].x) * (p.y - points[2].y)) /
                          ((points[1].y - points[2].y) * (points[0].x - points[2].x) + (points[2].x - points[1].x) * (points[0].y - points[2].y));
            float beta = ((points[2].y - points[0].y) * (p.x - points[2].x) + (points[0].x - points[2].x) * (p.y - points[2].y)) /
                         ((points[1].y - points[2].y) * (points[0].x - points[2].x) + (points[2].x - points[1].x) * (points[0].y - points[2].y));
            float gamma = 1.0f - alpha - beta;

            // Если точка внутри треугольника
            if (alpha >= 0 && beta >= 0 && gamma >= 0) {
                // Интерполируем глубину и цвет
                float depth = alpha * points[0].z + beta * points[1].z + gamma * points[2].z;
                sf::Color color;
                color.r = static_cast<sf::Uint8>(alpha * colors[0].r + beta * colors[1].r + gamma * colors[2].r);
                color.g = static_cast<sf::Uint8>(alpha * colors[0].g + beta * colors[1].g + gamma * colors[2].g);
                color.b = static_cast<sf::Uint8>(alpha * colors[0].b + beta * colors[1].b + gamma * colors[2].b);

                int idx = static_cast<int>(round(p.x + image.getSize().x*p.y));
                // Добавляем пиксель в список
                if(depth<z_buffer[idx])
                {

                }
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