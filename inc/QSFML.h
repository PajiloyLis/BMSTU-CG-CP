#ifndef QSFML_HPP
#define QSFML_HPP

#include <SFML/Graphics.hpp>
#include <qt6/QtWidgets/QWidget>
#include <glm/glm.hpp>
#include <vector>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QApplication>
#include <QObject>
#include <ctime>
#include <chrono>
#include <thread>
#include <stack>
#include <set>
#include <iostream>
#include <thread>
#include <SFML/Graphics/Image.hpp>
#include <glm/glm.hpp>
#include "triangle.h"
#include "camera.h"
#include "smoke.h"

using namespace std;
using namespace sf;

enum TIMERS {
    KEYBOARD,
    SMOKE
};

class QSFMLCanvas : public QWidget, public sf::RenderWindow {
Q_OBJECT
public:
    QSFMLCanvas(QWidget *parent, const QSize &Size);

    ~QSFMLCanvas() override = default;

    void Clear();

    void DrawTriangle(const triangle &t, const camera &cam, const glm::vec3 &figure_center, const sf::Color &color);

    void DrawSmoke(const glm::vec3 &vec000, const vector<sf::Color> &colors, int voxel_size, const camera &cam);

    void StartSmokeTimer();

    void z_buffer(array<glm::vec3, 3> points_, Image &image, sf::Color color_, vector<float> &zbuffer);

    void keyPressEvent(QKeyEvent *event) override;

    void keyReleaseEvent(QKeyEvent *event) override;

    void timerEvent(QTimerEvent *event) override;

    void wheelEvent(QWheelEvent *event) override;

    void mousePressEvent(QMouseEvent *event) override;

    void mouseMoveEvent(QMouseEvent *event) override;

    void mouseReleaseEvent(QMouseEvent *event) override;

    glm::mat4 viewport(const glm::vec3 &center, const glm::vec3 &cam_pos, const glm::vec3 &point);

    glm::mat4 model(const glm::vec3 &cam_pos, const glm::vec3 &point);

    void onInit();

    void onUpdate();

    void DrawPolygon();

    QPaintEngine *paintEngine() const override;

    void showEvent(QShowEvent *) override;

    void paintEvent(QPaintEvent *) override;

    void widgetDraw();

    Image image;

    vector<float> zbuffer;

    bool m_initialized;

    sf::Color back_color;

    static const glm::vec3 light_ray;

    bool mouse_left_pressed;

    QPoint mouse_left_press_pos;

    bool w_pressed, a_pressed, s_pressed, d_pressed;

    float last_motion_time, now_time;

    map<int, int> timers;


    glm::vec3 adapt_coords(const camera &c, const glm::vec3 &point, const glm::vec3 &center);

signals:

    void LeftMouseButton(const int &x, const int &y);

signals:

    void ShiftLeftMouseButton(const int &x, const int &y);

signals:

    void RightMouseButton();

signals:

    void LeftMouseButtonDouble(const int &x, const int &y);

signals:

    void WKeyPressed(const Camera_Movement &move, float delta_time);

signals:

    void AKeyPressed(const Camera_Movement &move, float delta_time);

signals:

    void SKeyPressed(const Camera_Movement &move, float delta_time);

signals:

    void DKeyPressed(const Camera_Movement &move, float delta_time);

signals:

    void WheelScrolledUp(float k);

signals:

    void WheelScrolledDown(float k);

signals:

    void MouseMove(float dx, float dy);

signals:

    void Redraw();
};

#endif
