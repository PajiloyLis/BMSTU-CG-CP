#ifndef SCENE_HPP
#define SCENE_HPP

#include "QSFML.h"
#include "textured_figure.h"
#include "figure.h"
#include "camera.h"
#include <GL/gl.h>
#include "particles_system.h"
class Scene {
public:
    Scene();

    explicit Scene(QSFMLCanvas *&scene, const double &width, const double &height);

    ~Scene() = default;

    void DrawFigures() const;

    void DrawParticlesSystems() const;

    void AddParticlesSystem(const particles_system &system);

    void ClearScene() const;

    void AddCamera(const camera &c);

    void ChangeCurCamera(int ind) { cur_camera = ind; }

    void AddFigure(const figure &f);

    void RotateCurCamera(const float &dx, const float &dy);

    void MoveCamera(const Camera_Movement &move, float &delta_time);

    void ScaleCamera(float &k);

    void StartSimulation();

    void SmokeTimerElapsed();

    glm::vec3 wind;
private:
    QSFMLCanvas *scene;
    double width, height;
    vector<figure> figures;
    vector<particles_system> p_systems;
    vector<camera> cameras;
    int cur_camera;
    float cur_frame_time, last_frame_time;
};

#endif
