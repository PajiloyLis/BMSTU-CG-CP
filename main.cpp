#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "map_prepare.h"
#include <cmath>
#include "figure.h"

int main() {
    vector<triangle> triangles = read_stl("./prepared_srtm/klyuchevskaya.STL");
//    vector<point> map = read_map("./prepared_srtm/klyuchevskaya.bin", "./prepared_srtm/klyuchevskaya.hdr");
    float min_z = triangles[0].getVertices()[0].getZ(), max_z = triangles[0].getVertices()[0].getZ(),
            min_x = triangles[0].getVertices()[0].getX(), max_x = triangles[0].getVertices()[0].getX(),
            min_y = triangles[0].getVertices()[0].getY(), max_y = triangles[0].getVertices()[0].getY();
    for (auto &triangle: triangles) {
        for (auto &j: triangle.getVertices()) {
            min_z = min(min_z, j.getZ()), max_z = max(max_z, j.getZ());
            min_y = min(min_y, j.getY()), max_y = max(max_y, j.getY());
            min_x = min(min_x, j.getX()), max_x = max(max_x, j.getX());
        }
    }
    cout << "Z " << min_z << " " << max_z << '\n' << "X " << min_x << " " << max_x << '\n' << "Y " << min_y << " "
         << max_y << '\n';
    float delta = max(max_z - min_z, max(max_x - min_x, max_y - min_y));
    cout << delta << '\n';
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "kek");
    sf::Vector2u screen_size = window.getSize();
    unsigned x_center = screen_size.x / 2, y_center = screen_size.y / 2;
    float k = (delta == max_z - min_z ? screen_size.y / delta : screen_size.x / delta);
    for (auto &triangle: triangles) {
        for (auto &j: triangle.getVertices()) {
            const_cast<point &>(j).setZ(j.getZ() * k);
            const_cast<point &>(j).setY(j.getY() * k);
            const_cast<point &>(j).setX(j.getX() * k);
        }
    }
    figure fig(triangles);
    window.clear(sf::Color{0x87CEEB});
    array<sf::Vertex, 3> triangle;
    glm::vec3 light_ray(1, 0, 0.2);
    light_ray = glm::normalize(light_ray);
    glm::vec3 camera(1, 0, 0);
    int index;
    for (auto &i: triangles) {
        index = 0;
        glm::vec3 a(i.getVertices()[1].getX() - i.getVertices()[0].getX(), i.getVertices()[1].getY() - i.getVertices()[0].getY(), i.getVertices()[1].getZ() - i.getVertices()[0].getZ()),
                b(i.getVertices()[2].getX() - i.getVertices()[0].getX(), i.getVertices()[2].getY() - i.getVertices()[0].getY(), i.getVertices()[2].getZ() - i.getVertices()[0].getZ());
        glm::vec3 normal = glm::normalize(glm::cross(a, b));
        float intensity = glm::dot(normal, light_ray);
        if (intensity > 0 && glm::dot(camera, normal) > 0) {
            for (auto &j: i.getVertices()) {
                triangle[index] = {sf::Vector2f(j.getY(), -j.getZ() + screen_size.y),
                                   {static_cast<sf::Uint8>(255 * intensity), static_cast<sf::Uint8>(255 * intensity),
                                    static_cast<sf::Uint8>(255 * intensity)}};
                ++index;
            }
            window.draw(&triangle[0], 3, sf::Triangles);
        }
    }
    window.display();
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }
    return 0;

}