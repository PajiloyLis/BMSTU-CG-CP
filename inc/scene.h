#ifndef SCENE_HPP
#define SCENE_HPP

#include "QSFML.h"
#include "textured_figure.h"
#include "figure.h"
#include "camera.h"

class Scene {
public:
    Scene();

    explicit Scene(QSFMLCanvas *&scene, const double &width, const double &height);

    ~Scene() = default;

    void DrawFigures() const;

    void ClearScene() const;

    void AddCamera(const camera &c);

    void ChangeCurCamera(int ind) { cur_camera = ind; }

    void AddFigure(const figure &f);


private:
    QSFMLCanvas *scene;
    double width, height;
    vector<figure> figures;
    vector<camera> cameras;
    int cur_camera;
};

#endif
