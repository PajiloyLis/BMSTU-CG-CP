#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "map_prepare.h"
#include <cmath>

int main() {
    vector<vector<point>> triangles = read_stl("./prepared_srtm/klyuchevskaya.STL");
//    vector<point> map = read_map("./prepared_srtm/klyuchevskaya.bin", "./prepared_srtm/klyuchevskaya.hdr");
    float min_z = triangles[0][0].getZ(), max_z = triangles[0][0].getZ(),
            min_x = triangles[0][0].getX(), max_x = triangles[0][0].getX(),
            min_y = triangles[0][0].getY(), max_y = triangles[0][0].getY();
    for (auto &triangle: triangles) {
        for (auto j: triangle) {
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
    float k = (delta == max_z - min_z ? screen_size.y/delta : screen_size.x/delta);
    for (auto &i: triangles) {
        for (auto &j: i) {
            j.setZ(j.getZ() * k);
            j.setY(j.getY() * k);
            j.setX(j.getX() * k);
        }
    }
    window.clear(sf::Color{0x87CEEB});
    array<sf::Vertex, 3> triangle;
    int index;
    for (const auto &i: triangles) {
        index = 0;
        for (auto j: i) {
            triangle[index] = {sf::Vector2f(j.getX(), -j.getZ() + screen_size.y),
                               sf::Color::Black};
            ++index;
        }
        window.draw(&triangle[0], 3, sf::LineStrip);
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