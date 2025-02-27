#ifndef HANDLER_HPP
#define HANDLER_HPP

#include <stack>
#include "textured_figure.h"
#include "scene.h"
#include "camera.h"
#include <ctime>

class TaskHandler {

Q_OBJECT

public:

    TaskHandler();

    ~TaskHandler() = default;

public slots:

    void UpdateWind(int speed, int angle);

    void UpdateSimSpeed(int x);

    void LoadModel(const string &filepath);

public:

    void SetScene(const Scene &scene_to_set);

    void AddCamera(const camera &cam);

    void DrawScene();

    void ClearFigure();

    void ClearScene();

    void RotateCurCamera(const float &dx, const float &dy);

    void MoveCamera(const Camera_Movement &move, const float &delta_time);

    void ScaleCamera(float &k);


private:

    static vector<triangle> read_stl(const string &filename);

    Scene scene;
};

#endif
