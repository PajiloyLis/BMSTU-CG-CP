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

using namespace std;
using namespace sf;


class QSFMLCanvas : public QWidget, public sf::RenderWindow {
Q_OBJECT
public:
    QSFMLCanvas(QWidget *parent, const QSize &Size);

    ~QSFMLCanvas() override = default;

    void Clear();

    void DrawTriangle(const triangle &t, const camera &cam, const glm::vec3 &figure_center, const sf::Color &color);

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

    void WKeyPressed(const Camera_Movement &move);

signals:

    void AKeyPressed(const Camera_Movement &move);

signals:

    void SKeyPressed(const Camera_Movement &move);

signals:

    void DKeyPressed(const Camera_Movement &move);

signals:

    void WheelScrolledUp(float k);

signals:

    void WheelScrolledDown(float k);

private:
//    void mousePressEvent(QMouseEvent *event) override;

    static void z_buffer(array<glm::vec3, 3> points_, Image &image, sf::Color color_, vector<float> &zbuffer);

    void keyPressEvent(QKeyEvent *event) override;

    void wheelEvent(QWheelEvent *event) override;

    glm::mat4 viewport(const glm::vec3 &center);

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

public:

    glm::vec3 adapt_coords(const camera &c, const glm::vec3 &point, const glm::vec3 &center);
};

#endif
