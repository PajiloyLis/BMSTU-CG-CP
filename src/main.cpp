#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Image.hpp>
#include "map_prepare.h"
#include <cmath>
//#include "textured_figure.h"
//#include "my_vec3f.h"
//#include "operations.h"
#include <cstdlib>

using namespace std;
using namespace sf;

#include "main_window.h"

signed main(int argc, char *argv[]) {
    TaskHandler handler;
    {
        QApplication app(argc, argv);
        MainWindow window;
        QObject::connect(window.findChild<QPushButton *>("load_model_button"), &QPushButton::clicked, &window,
                         &MainWindow::LoadModelActionTriggered);
        QObject::connect(&window, &MainWindow::ModelPathFetched, &handler, &TaskHandler::LoadModel);
        QObject::connect(window.findChild<QSlider *>("wind_speed_slider"), &QSlider::sliderReleased, &window,
                         &MainWindow::WindChanged);
        QObject::connect(window.findChild<QSlider *>("wind_angle_slider"), &QSlider::sliderReleased, &window,
                         &MainWindow::WindChanged);
        QObject::connect(&window, &MainWindow::WindSettingsFetched, &handler, &TaskHandler::UpdateWind);
        QObject::connect(window.findChild<QSlider *>("sim_speed_slider"), &QSlider::sliderReleased, &window,
                         &MainWindow::SimulationSpeedChanged);
        QObject::connect(&window, &MainWindow::SimulationSpeedSettingsFetched, &handler, &TaskHandler::UpdateSimSpeed);
        QObject::connect(window.findChild<QPushButton *>("simulation_start_button"), &QPushButton::clicked, &window,
                         &MainWindow::StartButtonHandler);
        window.show();
        app.exec();
    }

////    Color snow(255, 0, 0), mount_1(10, 12, 23), mount_2(25, 26, 33);
////    textured_figure mountain(read_stl("./prepared_srtm/klyuchevskaya.STL"));
//////    Texture texture;
//////    if (!texture.loadFromFile("./textures/snow_rock_2.jpg"))
//////        throw exception();
////    my_vec3f figure_center = mountain.get_center();
////    array<float, 3> size = mountain.get_size();
////    float delta = std::max(size[0], std::max(size[1], size[2]));
////    cout << delta << '\n';
    sf::RenderWindow window(sf::VideoMode(1850, 1016), "kek");
////    sf::Vector2u screen_size = window.getSize();
////    cout << screen_size.x << " " << screen_size.y << '\n';
////    unsigned x_center = screen_size.x / 2, y_center = screen_size.y / 2;
////    float k = (delta == size[2] ? screen_size.y / delta : screen_size.x / delta);
////    for (auto &triangle: mountain.getTriangles()) {
////        for (auto &j: triangle.getT().getVertices()) {
////            const_cast<my_vec3f &>(j).setZ(j.getZ() * k);
////            const_cast<my_vec3f &>(j).setY(j.getY() * k);
////            const_cast<my_vec3f &>(j).setX(j.getX() * k);
////        }
////    }
////    figure_center.setX(figure_center.getX() * k);
////    figure_center.setY(figure_center.getY() * k);
////    figure_center.setZ(figure_center.getZ() * k);
////    mountain.setCenter(figure_center);
////    mountain.addTexture(texture);
////    array<sf::Vertex, 3> triangle;
////    my_vec3f light_ray = normalize(my_vec3f(1, 0, 0));
////    my_vec3f cam = normalize(my_vec3f(1, 0, 0));
////    int index;
////    Image image;
////    image.create(screen_size.x, screen_size.y, Color(0x87CEEB));
////
////    vector<float> zbuffer(screen_size.x * screen_size.y, std::numeric_limits<float>::min());

//    handler.SetScene()

    bool mouse_pressed = false;
    sf::Vector2f mouse_last_pos(0, 0);
    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                    handler.MoveCamera(LEFT, 0.f);
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                    handler.MoveCamera(RIGHT, 0.f);
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                    handler.MoveCamera(FORWARD, 0.f);
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                    handler.MoveCamera(BACKWARD, 0.f);
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    mouse_pressed = true;
                    mouse_last_pos = {static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y)};
                }
            }
            if (event.type == sf::Event::MouseMoved) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    handler.RotateCurCamera(event.mouseButton.x - mouse_last_pos.x,
                                            event.mouseButton.y - mouse_last_pos.y);
                    mouse_last_pos = {static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y)};
                }
            }
            if (event.type == sf::Event::MouseButtonReleased) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    mouse_pressed = false;
                    handler.RotateCurCamera(event.mouseButton.x - mouse_last_pos.x,
                                            event.mouseButton.y - mouse_last_pos.y);
                }
            }
            if (event.type == sf::Event::MouseWheelScrolled) {
                if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel) {
                    handler.ScaleCamera(event.mouseWheelScroll.delta);
                }
            }
        }
        window.clear(sf::Color{0x87CEEB});
    }
}