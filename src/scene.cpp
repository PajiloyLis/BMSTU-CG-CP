#include "scene.h"

Scene::Scene() : figures() {
    scene = nullptr;
    width = height = 0;
}

Scene::Scene(QSFMLCanvas *&scene, const double &width, const double &height)
        : figures(), cameras(), cur_camera(0) {
    this->scene = scene;
    this->width = width;
    this->height = height;
    last_frame_time = cur_frame_time = 0;
    wind = {1, 5};
}


void Scene::ClearScene() const {
    scene->Clear();
}

void Scene::DrawFigures() const {
    for (auto &figure: figures)
        for (auto &triangle: figure.triangles)
            scene->DrawTriangle(triangle, cameras[cur_camera],
                                glm::vec3((figure.max_x - figure.min_x) / 2, (figure.max_y - figure.min_y) / 2,
                                          (figure.max_z - figure.min_z) / 2), {255, 255, 250});
//    if (figures.size() > 0) {
//        sf::CircleShape crater_pos(5);
//        crater_pos.setFillColor(sf::Color::Red);
//        glm::vec3 possible_pos = scene->adapt_coords(cameras[cur_camera], {50, 43.55, 37.96},
//                                                     figures[0].get_center());
//        crater_pos.setPosition({possible_pos.x, possible_pos.y});
//        scene->draw(crater_pos);
//        scene->display();
//    }
}

void Scene::AddFigure(const figure &f) {
    figures.push_back(f);
}

void Scene::AddCamera(const camera &c) {
    cameras.push_back(c);
    if (cameras.size() == 1)
        cur_camera = 0;
}

void Scene::RotateCurCamera(const float &dx, const float &dy) {
    cameras[cur_camera].rotate(dx, -dy);
}

void Scene::ScaleCamera(float &k) {
    cameras[cur_camera].scale(k);
}

void Scene::MoveCamera(const Camera_Movement &move, float &delta_time) {
    cameras[cur_camera].move(move, delta_time);
}


//void Scene::DrawSmoke() const {
//    scene->DrawParticles(const_cast<smoke &>(system), cameras[cur_camera]);
//}

void
Scene::AddSmoke() {
    ash = smoke(static_cast<int>( width) / VOX_SIZE * VOX_SIZE);
}

void Scene::StartSimulation() {
    scene->StartSmokeTimer();
}

void Scene::SmokeTimerElapsed() {
    ash.update();
    ClearScene();
    DrawFigures();
//    DrawSmoke();
    Show();
    scene->Redraw();
}

void Scene::Show() {
    scene->repaint();
}
