#ifndef QSFML_HPP
#define QSFML_HPP

#include <SFML/Graphics.hpp>
#include <qt6/QtWidgets/QWidget>
//#include <Qt/qtimer.h>
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

using namespace std;
using namespace sf;

class QSFMLCanvas : public QWidget, public sf::RenderWindow {
Q_OBJECT
public:
    QSFMLCanvas(QWidget *parent, const QSize &Size);

    ~QSFMLCanvas() override = default;

    void Clear();

    void DrawTriangle(const triangle &t, const camera &cam, const my_vec3f &figure_center);

signals:

    void LeftMouseButton(const int &x, const int &y);

signals:

    void ShiftLeftMouseButton(const int &x, const int &y);

signals:

    void RightMouseButton();

signals:

    void LeftMouseButtonDouble(const int &x, const int &y);

signals:

    void LeftKeyPressed();

signals:

    void RightKeyPressed();

signals:

    void UpKeyPressed();

signals:

    void DownKeyPressed();
    signals:
    void WhellScrolled

private:
//    void mousePressEvent(QMouseEvent *event) override;

    static void z_buffer(array<my_vec3f, 3> points, Image &image, sf::Color color, vector<float> &z_buffer);

    void mouseDoubleClickEvent(QMouseEvent *event) override;

    void keyPressEvent(QKeyEvent *event) override;

    void wheelEvent(QWheelEvent *event) override;

    mat4 viewport(const my_vec3f &point, const my_vec3f &center);

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

    static const my_vec3f light_ray;

    my_vec3f adapt_coords(const camera &c, const my_vec3f &point, const my_vec3f &center);
};

#endif
