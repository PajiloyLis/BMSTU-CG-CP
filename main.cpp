#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "map_prepare.h"
#include <cmath>
#include "figure.h"
#include "point.h"

int main() {
    figure mountain(read_stl("./prepared_srtm/klyuchevskaya.STL"));
    point figure_center = mountain.get_center();
    array<float, 3> size = mountain.get_size();
    float delta = max(size[0], max(size[1], size[2]));
    cout << delta << '\n';
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "kek");
    sf::Vector2u screen_size = window.getSize();
    unsigned x_center = screen_size.x / 2, y_center = screen_size.y / 2;
    float k = (delta == size[2] ? screen_size.y / delta : screen_size.x / delta);
    for (auto &triangle: mountain.getTriangles()) {
        for (auto &j: triangle.getVertices()) {
            const_cast<point &>(j).setZ(j.getZ() * k);
            const_cast<point &>(j).setY(j.getY() * k);
            const_cast<point &>(j).setX(j.getX() * k);
        }
    }
    figure_center.setX(figure_center.getX() * k);
    figure_center.setY(figure_center.getY() * k);
    figure_center.setZ(figure_center.getZ() * k);
    mountain.setCenter(figure_center);
    array<sf::Vertex, 3> triangle;
    point light_ray = normalize(point(1, 0, 0.2));
    point cam = normalize(point(1, 0, 0));
    int index;
    while (window.isOpen()) {
        sf::Event event;

        if (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                    mountain.rotate({0, 0, -M_PI / 90});
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                    mountain.rotate({0, 0, M_PI / 90});
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                    mountain.rotate({0, -M_PI / 90, 0});
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                    mountain.rotate({0, M_PI / 90, 0});
            }
        }
        window.clear(sf::Color{0x87CEEB});
        for (auto &i: mountain.getTriangles()) {
            index = 0;
            float intensity = light_ray.dot(i.getN());
            if (intensity > 0) {
                for (auto &j: i.getVertices()) {
                    triangle[index] = {sf::Vector2f(j.getY(), -j.getZ() + screen_size.y),
                                       {static_cast<sf::Uint8>(255 * intensity),
                                        static_cast<sf::Uint8>(255 * intensity),
                                        static_cast<sf::Uint8>(255 * intensity)}};
                    ++index;
                }
                window.draw(&triangle[0], 3, sf::Triangles);
            }
        }
        window.display();
    }

    return 0;

}