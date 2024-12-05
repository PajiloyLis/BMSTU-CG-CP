#include "QSFML.h"

const my_vec3f QSFMLCanvas::light_ray = my_vec3f(1, 0, 0);
//const my_vec3f QSFMLCanvas::camera_ray = my_vec3f(1, 0, 0);

QSFMLCanvas::QSFMLCanvas(QWidget *parent, const QSize &Size)
        : QWidget(parent),
          sf::RenderWindow(sf::VideoMode(Size.width(), Size.height()), "OpenGL",
                           sf::Style::Default),
          zbuffer(Size.width() * Size.height(), std::numeric_limits<float>::min()),
          m_initialized(false),
          back_color(sf::Color(0x87CEEB)) {
    image.create(Size.width(), Size.height(), back_color);
    setAttribute(Qt::WA_PaintOnScreen);
    setAttribute(Qt::WA_OpaquePaintEvent);
    setAttribute(Qt::WA_NoSystemBackground);

    setFocusPolicy(Qt::StrongFocus);
}

void QSFMLCanvas::onInit() {
    this->clear(back_color);
    this->display();
}

void QSFMLCanvas::onUpdate() {
    this->widgetDraw();
    display();
}

QPaintEngine *QSFMLCanvas::paintEngine() const {
    return nullptr;
}

void QSFMLCanvas::showEvent(QShowEvent *) {
    if (!m_initialized) {
        RenderWindow::create(winId());
        onInit();
        m_initialized = true;
    }
}

void QSFMLCanvas::paintEvent(QPaintEvent *) {
    onUpdate();
//    display();
}


void QSFMLCanvas::mousePressEvent(QMouseEvent *event) {
    sf::Vector2i mouse_pos = sf::Mouse::getPosition(*this);
    if (event->button() == Qt::LeftButton) {
        if (QApplication::keyboardModifiers() == Qt::ShiftModifier) {
            emit
            this->ShiftLeftMouseButton(mouse_pos.x, mouse_pos.y);
        } else {
            emit
            this->LeftMouseButton(mouse_pos.x, mouse_pos.y);
        }
    } else if (event->button() == Qt::RightButton) {
        emit
        this->RightMouseButton();
    }
}

void QSFMLCanvas::mouseDoubleClickEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        sf::Vector2i mouse_pos = sf::Mouse::getPosition(*this);
        emit this->LeftMouseButtonDouble(mouse_pos.x, mouse_pos.y);
    }
}


void QSFMLCanvas::DrawTriangle(const triangle &t, const camera &cam, const my_vec3f &figure_center) {
    float intensity = light_ray.dot(t.n);
    if (cam.p.dot(t.n) > 0) {
        array<my_vec3f, 3> points;
        array<sf::Vertex, 3> points_to_render;
        for (int i = 0; i < points.size(); ++i) {
            points[i] = cam.perspective(t.vertices[i]);
            points_to_render[i] = Vertex({points[i].getX(), this->size().height() - points[i].getY()},
                                         sf::Color(static_cast<Uint8>(255 * intensity),
                                                   static_cast<Uint8>(255 * intensity),
                                                   static_cast<Uint8>(255 * intensity)));
//        z_buffer(points, image, {static_cast<Uint8>(255 * intensity), static_cast<Uint8>(255 * intensity),
//                                 static_cast<Uint8>(255 * intensity)}, zbuffer);
        }
        this->draw(&points_to_render[0], points_to_render.size(), sf::Triangles);
    }
}

void QSFMLCanvas::z_buffer(array<my_vec3f, 3> points, Image &image, sf::Color color, vector<float> &z_buffer) {
    if (points[0].getY() == points[1].getY() && points[1].getY() == points[2].getY()) return;
    if (points[0].getY() > points[1].getY()) std::swap(points[0], points[1]);
    if (points[0].getY() > points[2].getY()) std::swap(points[0], points[2]);
    if (points[1].getY() > points[2].getY()) std::swap(points[1], points[2]);
    points[0].setZ(ceil(points[0].getZ())), points[0].setX(ceil(points[0].getX())), points[0].setY(
            ceil(points[0].getY()));
    points[1].setZ(ceil(points[1].getZ())), points[1].setX(ceil(points[1].getX())), points[1].setY(
            ceil(points[1].getY()));
    points[2].setZ(ceil(points[2].getZ())), points[2].setX(ceil(points[2].getX())), points[2].setY(
            ceil(points[2].getY()));
    int total_height = (int) (points[2].getY() - points[0].getY());
    for (int i = 0; i < total_height; i++) {
        bool second_half = i > points[1].getY() - points[0].getY() || points[1].getY() == points[0].getY();
        int segment_height = (second_half ? static_cast<int>(points[2].getY() - points[1].getY())
                                          : static_cast<int>(points[1].getY() - points[0].getY()));
        float alpha = (float) i / total_height;
        float beta = (float) (i - (second_half ? points[1].getY() - points[0].getY() : 0)) /
                     segment_height;
        my_vec3f A = points[0] + (points[2] - points[0]) * alpha;
        my_vec3f B = second_half ? points[1] + my_vec3f(points[2] - points[1]) * beta :
                     points[0] + my_vec3f(points[1] - points[0]) * beta;
        if (A.getX() > B.getX()) std::swap(A, B);
        for (int j = static_cast<int>(A.getX()); j <= static_cast<int>(B.getX()); j++) {
            float phi = B.getX() == A.getX() ? 1. : (float) (j - A.getX()) / (float) (B.getX() - A.getX());
            my_vec3f P = A + (B - A) * phi;
            if (P.getX() >= 0 && P.getY() >= 0 && P.getX() < image.getSize().y && P.getY() < image.getSize().x) {
                int idx = static_cast<int>(round(P.getX() + P.getY() * image.getSize().x));
                if (z_buffer[idx] < P.getZ()) {
                    z_buffer[idx] = P.getZ();
                    image.setPixel(static_cast<Uint32>(round(P.getX())), static_cast<Uint32>(round(P.getY())), color);
                }
            }
        }
    }
}

void QSFMLCanvas::widgetDraw() {
    for (int i = 0; i < image.getSize().y; ++i) {
        VertexArray line(sf::Points, image.getSize().x);
        for (int j = 0; j < image.getSize().x; ++j)
            line[j] = Vertex(Vector2f(j, image.getSize().y - i), image.getPixel(j, i));
        this->draw(line);
    }
}

void QSFMLCanvas::Clear() {
    this->clear(back_color);
}

my_vec3f QSFMLCanvas::viewport(const my_vec3f &point, const my_vec3f &center) {
    mat4 mat(this->size().width() / (2 * center.getX()), 0, 0, 0,
             0, this->size().height() / (2 * center.getY()), 0, 0,
             0, 0, 255 / 2.f, 0,
             0, 0, 0, 1);
    vec4 res = mat * vec4(point.getX(), point.getY(), point.getZ(), 1);
    return {res.x, res.y, res.z};
}

void QSFMLCanvas::keyPressEvent(QKeyEvent *event) {
    if (event->keyCombination().key() == Qt::Key_Left)

}

