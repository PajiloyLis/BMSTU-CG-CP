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
class Scene {
public:
    Scene();

    explicit Scene(QSFMLCanvas *&scene, const double &width, const double &height);

    ~Scene() = default;

    void DrawFigures() const;

    void DrawSmoke() const;

    void AddSmoke(int fig_width, int fig_height);

    void ClearScene() const;

    void AddCamera(const camera &c);

    void ChangeCurCamera(int ind) { cur_camera = ind; }

    const figure & AddFigure(const figure &f);

    void RotateCurCamera(const float &dx, const float &dy);

    void MoveCamera(const Camera_Movement &move, const float &delta_time);

    void ScaleCamera(float &k);

    void StartSimulation();

    void SmokeTimerElapsed();

    void UpdateWind(const glm::vec2 &wind);

    void UpdateSimSpeed(float sim_speed);

    void Show();

private:
    QSFMLCanvas *scene;
    double width, height;
    vector<figure> figures;
    smoke ash;
    vector<camera> cameras;
    int cur_camera;
    float cur_frame_time, last_frame_time;
};

#endif
