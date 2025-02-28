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

    sf::RenderWindow sf_window(sf::VideoMode(1850, 1016), "kek");

    TaskHandler handler;

    handler.SetScene(Scene(&sf_window));
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
        if(app.exec()!=100)
            exit(EXIT_FAILURE);
    }

    handler.AddCamera(camera({200, 50, 10}));

    bool mouse_pressed = false;
    sf::Vector2f mouse_last_pos(0, 0);
    while (sf_window.isOpen()) {
        sf::Event event;

        while (sf_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                sf_window.close();
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
                if (event.mouseButton.button == sf::Mouse::Left && mouse_pressed) {
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
        handler.DrawScene();
    }
}