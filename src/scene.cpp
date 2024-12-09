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
            scene->DrawTriangle(triangle, cameras[cur_camera], figure.center);
    scene->repaint();
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
    cameras[cur_camera].rotate({0, 0, M_PI/360});
}

void Scene::RotateCurCameraRight() {
    cameras[cur_camera].rotate({0, 0, -M_PI/360});
}

void Scene::RotateCurCameraUp() {
    cameras[cur_camera].rotate({0, M_PI/360, 0});
}

void Scene::RotateCurCameraDown() {
    cameras[cur_camera].rotate({0, -M_PI/360, 0});
}

void Scene::MoveCamera(const move_t &move)
{
    cameras[cur_camera].move(move);
}






