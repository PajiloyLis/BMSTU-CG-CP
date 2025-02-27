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

const figure &Scene::AddFigure(const figure &f) {
    figures.push_back(f);
    return f;
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


void Scene::DrawSmoke() const {
    timespec start, end, start1, end1;
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (int i = ash.height; i >= 1; --i) {
        for (int j = ash.height; j >= 1; --j) {
            for (int k = ash.width; k >= 1; --k) {
                if (ash.dens[i][j][k] + ash.dens[i][j][k + 1] + ash.dens[i][j + 1][k] + ash.dens[i][j + 1][k + 1] +
                    ash.dens[i + 1][j][k] + ash.dens[i + 1][j][k + 1] + ash.dens[i + 1][j + 1][k] +
                    ash.dens[i + 1][j + 1][k + 1] > EPS) {
                    vector<sf::Color> colors;
                    sf::Uint8 color000 = smoke::convert_color(ash.dens[i][j][k]), //front left top
                    color001 = smoke::convert_color(ash.dens[i][j][k + 1]), //front right top
                    color010 = smoke::convert_color(ash.dens[i][j + 1][k]), //back left top
                    color011 = smoke::convert_color(ash.dens[i][j + 1][k + 1]), // back right top
                    color100 = smoke::convert_color(ash.dens[i + 1][j][k]), // front left bottom
                    color101 = smoke::convert_color(ash.dens[i + 1][j][k + 1]), //front right bottom
                    color110 = smoke::convert_color(ash.dens[i + 1][j + 1][k]), //back left bottom
                    color111 = smoke::convert_color(ash.dens[i + 1][j + 1][k + 1]); //back right bottom
                    colors.push_back({color000, color000, color000, smoke::convert_alpha(ash.dens[i][j][k])});
                    colors.push_back({color001, color001, color001, smoke::convert_alpha(ash.dens[i][j][k + 1])});
                    colors.push_back({color010, color010, color010, smoke::convert_alpha(ash.dens[i][j + 1][k])});
                    colors.push_back({color011, color011, color011, smoke::convert_alpha(ash.dens[i][j + 1][k + 1])});
                    colors.push_back({color100, color100, color100, smoke::convert_alpha(ash.dens[i + 1][j][k])});
                    colors.push_back({color101, color101, color101, smoke::convert_alpha(ash.dens[i + 1][j][k + 1])});
                    colors.push_back({color110, color110, color110, smoke::convert_alpha(ash.dens[i + 1][j + 1][k])});
                    colors.push_back(
                            {color111, color111, color111, smoke::convert_alpha(ash.dens[i + 1][j + 1][k + 1])});
                    scene->DrawSmoke({(j - 1) * VOX_SIZE, (k - 1) * VOX_SIZE, (i - 1) * VOX_SIZE}, colors, VOX_SIZE,
                                     cameras[cur_camera]);
                }
            }
        }
    }
//for(int i = 0 ; i < ash.width; ++i)
//{
//    vector<sf::Color> colors;
//    sf::Color color000 = sf::Color::Black,
//            color001 = sf::Color::Black,
//            color010 = sf::Color::Black,
//            color011 = sf::Color::Black,
//            color100 = sf::Color::Black,
//            color101 = sf::Color::Black,
//            color110 = sf::Color::Black,
//            color111 = sf::Color::Black;
//    colors.push_back(color000);
//    colors.push_back(color001);
//    colors.push_back(color010);
//    colors.push_back(color011);
//    colors.push_back(color100);
//    colors.push_back(color101);
//    colors.push_back(color110);
//    colors.push_back(color111);
//    scene->DrawSmoke({0 * VOX_SIZE, (i - 1) * VOX_SIZE, ash.height}, colors, VOX_SIZE,
//                                     cameras[cur_camera]);
//}
    clock_gettime(CLOCK_MONOTONIC, &end);
    cout << end.tv_sec - start.tv_sec + (end.tv_nsec - start.tv_nsec) * 1e-9 << '\n';
}

void
Scene::AddSmoke(int fig_width, int fig_height) {
    ash = smoke(fig_width / VOX_SIZE * VOX_SIZE, fig_height / VOX_SIZE * VOX_SIZE,
                {46, 33, 38}, {0, 0}, 0.1f, 100, 100.f, 5.f);
}

void Scene::StartSimulation() {
    scene->StartSmokeTimer();
}

void Scene::SmokeTimerElapsed() {
    timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    ash.update();
    clock_gettime(CLOCK_MONOTONIC, &end);
    cout << "UPDATE TIME " << end.tv_sec - start.tv_sec + (end.tv_nsec - start.tv_nsec) / 1e9 << '\n';
    ClearScene();
//    DrawFigures();
    DrawSmoke();
    Show();
    scene->Redraw();
}

void Scene::Show() {
    scene->repaint();
}

void Scene::UpdateWind(const glm::vec2 &wind) {
    ash.wind = wind;
}

void Scene::UpdateSimSpeed(float sim_speed) {
    ash.dt = sim_speed;
}
