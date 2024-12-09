#ifndef HANDLER_HPP
#define HANDLER_HPP

#include <stack>
#include "textured_figure.h"
#include "scene.h"
#include "camera.h"

class TaskHandler {
public:
    TaskHandler();

    ~TaskHandler() = default;

    void AddNewSegment(const int &x, const int &y);

    void AddNewOrthogonalSegment(const int &x, const int &y);

    void AddFinalSegment();

    void SetFigureColor(const Color &color);

    void SetScene(const Scene &scene_to_set);

    void AddCamera(const camera &cam);

    void DrawScene();

    void ClearFigure();

    void ClearScene() const;

    void FillFigure(const bool &delay, const int &x, const int &y);

    void FigureDelLastPoint();

    void LoadModel(const string &filepath);

    void RotateCurCameraLeft();

    void RotateCurCameraRight();

    void RotateCurCameraUp();

    void RotateCurCameraDown();

    void MoveCamera(const move_t &move);

private:

    static vector<triangle> read_stl(const string &filename);

    Scene scene;
};

#endif
