#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "map_prepare.h"
#include <cmath>
#include "figure.h"
#include "my_vec3f.h"
#include "operations.h"
#include <thread>

int main() {
    figure mountain(read_stl("./prepared_srtm/klyuchevskaya.STL"));
    my_vec3f figure_center = mountain.get_center();
    array<float, 3> size = mountain.get_size();
    float delta = max(size[0], max(size[1], size[2]));
    cout << delta << '\n';
    sf::RenderWindow window(sf::VideoMode(1850, 1016), "kek");
    sf::Vector2u screen_size = window.getSize();
    cout << screen_size.x << " " << screen_size.y << '\n';
    unsigned x_center = screen_size.x / 2, y_center = screen_size.y / 2;
    float k = (delta == size[2] ? screen_size.y / delta : screen_size.x / delta);
    for (auto &triangle: mountain.getTriangles()) {
        for (auto &j: triangle.getVertices()) {
            const_cast<my_vec3f &>(j).setZ(j.getZ() * k);
            const_cast<my_vec3f &>(j).setY(j.getY() * k);
            const_cast<my_vec3f &>(j).setX(j.getX() * k);
        }
    }
    figure_center.setX(figure_center.getX() * k);
    figure_center.setY(figure_center.getY() * k);
    figure_center.setZ(figure_center.getZ() * k);
    mountain.setCenter(figure_center);
    array<sf::Vertex, 3> triangle;
    my_vec3f light_ray = normalize(my_vec3f(1, 0, 0));
    my_vec3f cam = normalize(my_vec3f(1, 0, 0));
    int index;
    vector<vector<sf::Vertex>> image(screen_size.y, vector<sf::Vertex>(screen_size.x));
    for (int i = 0; i < image.size(); ++i) {
        for (int j = 0; j < image[i].size(); ++j) {
            image[i][j].position.x = j, image[i][j].position.y = screen_size.y-i, image[i][j].color = sf::Color{0x87CEEB};
        }
    }
    vector<float> zbuffer(screen_size.x * screen_size.y, std::numeric_limits<float>::min());
    int threads_cnt = thread::hardware_concurrency() - 1;
    auto triangles = mountain.getTriangles();
    int n = triangles.size();
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
                fill(zbuffer.begin(), zbuffer.end(), std::numeric_limits<float>::min());
                for (int i = 0; i < image.size(); ++i) {
                    for (int j = 0; j < image[i].size(); ++j) {
                        image[i][j].position.x = j, image[i][j].position.y = screen_size.y-i, image[i][j].color = sf::Color{0x87CEEB};
                    }
                }
            }
        }
//        window.clear(sf::Color{0x87CEEB});

        thread t_1(z_buffer, , 0, n / threads_cnt, image, zbuffer,light_ray);
        thread t_2(is_ok, ref(ans), n / threads_cnt, 2 * n / threads_cnt);
        thread t_3(is_ok, ref(ans), 2 * n / threads_cnt, 3 * n / threads_cnt);
        thread t_4(is_ok, ref(ans), 3 * n / threads_cnt, 4 * n / threads_cnt);
        thread t_5(is_ok, ref(ans), 4 * n / threads_cnt, 5 * n / threads_cnt);
        thread t_6(is_ok, ref(ans), 5 * n / threads_cnt, 6 * n / threads_cnt);
        thread t_7(is_ok, ref(ans), 6 * n / threads_cnt, 7 * n / threads_cnt);
        t_1.join();
        t_2.join();
        t_3.join();
        t_4.join();
        t_5.join();
        t_6.join();
        t_7.join();
        }
        for(auto &line:image)
            window.draw(&line[0], line.size(), sf::Points);
        window.display();
    }

    return 0;

}