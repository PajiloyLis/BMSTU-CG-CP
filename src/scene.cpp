#include "scene.h"

#define SCREEN_DEPTH 256*256*256

const glm::vec3 light_ray = glm::vec3(0, 0, 1);

Scene::Scene() : figures() {
    scene = nullptr;
    width = height = 0;
    running = false;
}

Scene::Scene(sf::RenderTarget *scene)
        : figures(), cameras(), cur_camera(0) {
    this->scene = scene;
    this->width = scene->getSize().x;
    this->height = scene->getSize().y;
    zbuffer.resize((this->height) * (this->width), -SCREEN_DEPTH);
    running = false;
}

void Scene::ClearScene() {
    scene->clear(sf::Color(0x87CEEB));
    zbuffer.resize(0);
    zbuffer.resize((this->height) * (this->width), -SCREEN_DEPTH);
}

void Scene::DrawFigures() {
    timespec start, end, start1, end1;
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (auto &figure: figures)
        for (auto &t: figure.triangles) {
            array<glm::vec3, 3> adapted;
            for (int i = 0; i < t.vertices.size(); ++i)
                adapted[i] = adapt_coords(cameras[cur_camera], t.vertices[i], width, height);
            triangle adapted_triangle(t.n, adapted);
            adapted_triangle.vertices[0].y = height - adapted_triangle.vertices[0].y,
            adapted_triangle.vertices[1].y = height - adapted_triangle.vertices[1].y,
            adapted_triangle.vertices[2].y = height - adapted_triangle.vertices[2].y;
            float intensity = glm::dot(light_ray, t.n);
            sf::Color color(static_cast<sf::Uint8>(255 * intensity), static_cast<sf::Uint8>(250 * intensity),
                            static_cast<sf::Uint8>(250 * intensity));
            adapted_triangle.draw(*scene, zbuffer, light_ray, {color, color, color}, sf::RenderStates());
        }
    clock_gettime(CLOCK_MONOTONIC, &end);
    cout << "figure draw time " << end.tv_sec - start.tv_sec + (end.tv_nsec - start.tv_nsec) * 1e-9 << '\n';
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

void Scene::MoveCamera(const Camera_Movement &move, const float &delta_time) {
    cameras[cur_camera].move(move, delta_time);
}


void Scene::DrawSmoke() {
    timespec start, end, start1, end1;
    clock_gettime(CLOCK_MONOTONIC, &start);
    if (running) {
        cout << "WELL IT MUST UPDATED RIGHT NOW, BUT WTF\n";
        ash.update();
    }
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

                    glm::vec3 vec000 = {(j - 1) * VOX_SIZE, (k - 1) * VOX_SIZE, (i - 1) * VOX_SIZE},
                            vec001 = vec000 + glm::vec3{0, 0, VOX_SIZE},
                            vec010 = vec000 + glm::vec3{0, VOX_SIZE, 0},
                            vec011 = vec000 + glm::vec3{0, VOX_SIZE, VOX_SIZE},
                            vec100 = vec000 + glm::vec3{VOX_SIZE, 0, 0},
                            vec101 = vec000 + glm::vec3{VOX_SIZE, 0, VOX_SIZE},
                            vec110 = vec000 + glm::vec3{VOX_SIZE, VOX_SIZE, 0},
                            vec111 = vec000 + glm::vec3{VOX_SIZE, VOX_SIZE, VOX_SIZE};

                    glm::vec3 a_vec000 = adapt_coords(cameras[cur_camera], vec000, this->width, this->height),
                            a_vec001 = adapt_coords(cameras[cur_camera], vec001, this->width, this->height),
                            a_vec010 = adapt_coords(cameras[cur_camera], vec010, this->width, this->height),
                            a_vec011 = adapt_coords(cameras[cur_camera], vec011, this->width, this->height),
                            a_vec100 = adapt_coords(cameras[cur_camera], vec100, this->width, this->height),
                            a_vec101 = adapt_coords(cameras[cur_camera], vec101, this->width, this->height),
                            a_vec110 = adapt_coords(cameras[cur_camera], vec110, this->width, this->height),
                            a_vec111 = adapt_coords(cameras[cur_camera], vec111, this->width, this->height);

                    glm::vec3 adapted_crater = adapt_coords(cameras[cur_camera], ash.source, width, height);

                    a_vec000.y = scene->getSize().y + a_vec000.y - 2 * adapted_crater.y,
                    a_vec001.y = scene->getSize().y + a_vec001.y - 2 * adapted_crater.y,
                    a_vec010.y = scene->getSize().y + a_vec010.y - 2 * adapted_crater.y,
                    a_vec011.y = scene->getSize().y + a_vec011.y - 2 * adapted_crater.y,
                    a_vec100.y = scene->getSize().y + a_vec100.y - 2 * adapted_crater.y,
                    a_vec101.y = scene->getSize().y + a_vec101.y - 2 * adapted_crater.y,
                    a_vec110.y = scene->getSize().y + a_vec110.y - 2 * adapted_crater.y,
                    a_vec111.y = scene->getSize().y + a_vec111.y - 2 * adapted_crater.y;


                    sf::VertexArray quad(sf::Quads, 4);

                    triangle adapted_triangle;

                    adapted_triangle.vertices[0] = a_vec000,
                    adapted_triangle.vertices[1] = a_vec001,
                    adapted_triangle.vertices[2] = a_vec010;

                    adapted_triangle.draw(*scene, zbuffer, light_ray, , sf::RenderStates())

                    //bottom
                    quad[0] = sf::Vertex(sf::Vector2f(a_vec000.x, a_vec000.y), colors[0]);
                    quad[1] = sf::Vertex(sf::Vector2f(a_vec010.x, a_vec010.y), colors[2]);
                    quad[2] = sf::Vertex(sf::Vector2f(a_vec110.x, a_vec110.y), colors[6]);
                    quad[3] = sf::Vertex(sf::Vector2f(a_vec100.x, a_vec100.y), colors[4]);

                    scene->draw(quad);

                    // up
                    quad[0] = sf::Vertex(sf::Vector2f(a_vec001.x, a_vec001.y), colors[1]);
                    quad[1] = sf::Vertex(sf::Vector2f(a_vec011.x, a_vec011.y), colors[3]);
                    quad[2] = sf::Vertex(sf::Vector2f(a_vec111.x, a_vec111.y), colors[7]);
                    quad[3] = sf::Vertex(sf::Vector2f(a_vec101.x, a_vec101.y), colors[5]);

                    scene->draw(quad);

                    // front
                    quad[0] = sf::Vertex(sf::Vector2f(a_vec100.x, a_vec100.y), colors[4]);
                    quad[1] = sf::Vertex(sf::Vector2f(a_vec110.x, a_vec110.y), colors[6]);
                    quad[2] = sf::Vertex(sf::Vector2f(a_vec111.x, a_vec111.y), colors[7]);
                    quad[3] = sf::Vertex(sf::Vector2f(a_vec101.x, a_vec101.y), colors[5]);

                    scene->draw(quad);

                    // backward
                    quad[0] = sf::Vertex(sf::Vector2f(a_vec000.x, a_vec000.y), colors[0]);
                    quad[1] = sf::Vertex(sf::Vector2f(a_vec010.x, a_vec010.y), colors[2]);
                    quad[2] = sf::Vertex(sf::Vector2f(a_vec011.x, a_vec011.y), colors[3]);
                    quad[3] = sf::Vertex(sf::Vector2f(a_vec001.x, a_vec001.y), colors[1]);

                    scene->draw(quad);

                    // left
                    quad[0] = sf::Vertex(sf::Vector2f(a_vec000.x, a_vec000.y), colors[0]);
                    quad[1] = sf::Vertex(sf::Vector2f(a_vec100.x, a_vec100.y), colors[4]);
                    quad[2] = sf::Vertex(sf::Vector2f(a_vec101.x, a_vec101.y), colors[5]);
                    quad[3] = sf::Vertex(sf::Vector2f(a_vec001.x, a_vec001.y), colors[1]);

                    scene->draw(quad);

                    // right
                    quad[0] = sf::Vertex(sf::Vector2f(a_vec010.x, a_vec010.y), colors[2]);
                    quad[1] = sf::Vertex(sf::Vector2f(a_vec110.x, a_vec110.y), colors[6]);
                    quad[2] = sf::Vertex(sf::Vector2f(a_vec111.x, a_vec111.y), colors[7]);
                    quad[3] = sf::Vertex(sf::Vector2f(a_vec011.x, a_vec011.y), colors[3]);

                    scene->draw(quad);
                }
            }
        }
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    cout << "smoke draw time" << end.tv_sec - start.tv_sec + (end.tv_nsec - start.tv_nsec) * 1e-9 << '\n';
//    glm::vec3 zero = adapt_coords(cameras[cur_camera], {0, 0, 0}, scene->getSize().x,
//                                  scene->getSize().y),
//            x_line = adapt_coords(cameras[cur_camera], {ash.height, 0, 0}, scene->getSize().x,
//                                  scene->getSize().y),
//            y_line = adapt_coords(cameras[cur_camera], {0, ash.width, 0}, width, height),
//            z_line = adapt_coords(cameras[cur_camera], {0, 0, ash.height}, width, height);
//    vector<sf::Vertex> p(6);
//    p[0] = sf::Vertex(sf::Vector2f(zero.x, scene->getSize().y - zero.y), sf::Color::Red);
//    p[1] = sf::Vertex(sf::Vector2f(x_line.x, scene->getSize().y - x_line.y), sf::Color::Red),
//    p[2] = sf::Vertex(sf::Vector2f(zero.x, scene->getSize().y - zero.y), sf::Color::Red),
//    p[3] = sf::Vertex(sf::Vector2f(y_line.x, scene->getSize().y - y_line.y), sf::Color::Red),
//    p[4] = sf::Vertex(sf::Vector2f(zero.x, scene->getSize().y - zero.y), sf::Color::Red),
//    p[5] = sf::Vertex(sf::Vector2f(z_line.x, scene->getSize().y - z_line.y), sf::Color::Red),
//
//            scene->draw(p.data(), 6, sf::Lines);
}

void
Scene::AddSmoke(int fig_width, int fig_height) {
    cout << "width " << fig_width << " height " << fig_height << '\n';
    ash = smoke(fig_width, fig_height,
                {53, 38, 36}, {0, 0}, 0.1f, 100, 10000.f, 5.f);
}

void Scene::UpdateWind(const glm::vec2 &wind) {
    ash.wind = wind;
}

void Scene::UpdateSimSpeed(float sim_speed) {
    ash.dt = sim_speed;
}
