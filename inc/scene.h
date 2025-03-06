#ifndef SCENE_HPP
#define SCENE_HPP

#include "QSFML.h"
#include "textured_figure.h"
#include "figure.h"
#include "camera.h"
#include <GL/gl.h>
#include "smoke.h"
#include "operations.h"
#include "triangle.h"
#include "light_bulb.h"

#define SCREEN_DEPTH 256*256*256

class Scene {
public:
    Scene();

    explicit Scene(sf::RenderTarget *scene);

    ~Scene() = default;

    void DrawFigures();

    void DrawSmoke() ;

    void AddSmoke(int fig_width, int fig_height);

    void DrawLight();

    void ClearScene();

    void AddCamera(const camera &c);

    void ChangeCurCamera(int ind) { cur_camera = ind; }

    const figure & AddFigure(const figure &f);

    void RotateCurCamera(const float &dx, const float &dy);

    void MoveCamera(const Camera_Movement &move, const float &delta_time);

    void ScaleCamera(float &k);

    void UpdateWind(const glm::vec2 &wind);

    void UpdateSimSpeed(float sim_speed);

    vector<float> zbuffer;

    bool running;
private:
    sf::RenderTarget *scene;
    float width, height;
    vector<figure> figures;
    smoke ash;
    vector<camera> cameras;
    int cur_camera;
    light_bulb light;
};

#endif
