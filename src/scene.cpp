#include "scene.h"

Scene::Scene() : figures() {
    scene = nullptr;
    width = height = 0;
}

Scene::Scene(QSFMLCanvas *&scene, const double &width, const double &height) : figures(), cameras(), cur_camera(0) {
    this->scene = scene;
    this->width = width;
    this->height = height;
}


void Scene::ClearScene() const {
    scene->Clear();
}

void Scene::DrawFigures() const {
    ClearScene();
    for (auto &figure: figures)
        for (auto &triangle: figure.triangles)
            scene->DrawTriangle(triangle, cameras[cur_camera],
                                glm::vec3((figure.max_x - figure.min_x) / 2, (figure.max_y - figure.min_y) / 2,
                                         (figure.max_z - figure.min_z) / 2), {255, 255, 250});
    scene->repaint();
    if (figures.size() > 0) {
        sf::CircleShape crater_pos(5);
        crater_pos.setFillColor(sf::Color::Red);
        glm::vec3 possible_pos = scene->adapt_coords(cameras[cur_camera], {50, 43.55, 37.96},
                                                    figures[0].get_center());
        crater_pos.setPosition({possible_pos.getX(), possible_pos.getY()});
        scene->draw(crater_pos);
        scene->display();
    }
}

void Scene::AddFigure(const figure &f) {
    figures.push_back(f);
}

void Scene::AddCamera(const camera &c) {
    cameras.push_back(c);
    if (cameras.size() == 1)
        cur_camera = 0;
}

void Scene::RotateCurCameraLeft() {
    cameras[cur_camera].rotate({0, 0, M_PI / 360});
}

void Scene::RotateCurCameraRight() {
    cameras[cur_camera].rotate({0, 0, -M_PI / 360});
}

void Scene::RotateCurCameraUp() {
    cameras[cur_camera].rotate({0, M_PI / 360, 0});
}

void Scene::RotateCurCameraDown() {
    cameras[cur_camera].rotate({0, -M_PI / 360, 0});
}

void Scene::ScaleCamera(float &k) {
    cameras[cur_camera].scale(k);
}

void Scene::MoveCamera(const move_t &move) {
    cameras[cur_camera].move(move);
}






