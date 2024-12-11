#include "QSFML.h"

bool on_load = false;

const my_vec3f QSFMLCanvas::light_ray = my_vec3f(0, 0, 1);
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
//    this->widgetDraw();
//    this->display();
}

QPaintEngine *QSFMLCanvas::paintEngine() const {
    return nullptr;
}

void QSFMLCanvas::showEvent(QShowEvent *) {
    if (!m_initialized) {
//        XFlush(QX11Info::display());
        RenderWindow::create(winId());
        onInit();
        m_initialized = true;
    }
}

void QSFMLCanvas::paintEvent(QPaintEvent *) {
    this->widgetDraw();
    this->display();
}


//void QSFMLCanvas::mousePressEvent(QMouseEvent *event) {
//    sf::Vector2i mouse_pos = sf::Mouse::getPosition(*this);
//    if (event->button() == Qt::LeftButton) {
//        if (QApplication::keyboardModifiers() == Qt::ShiftModifier) {
//            emit
//            this->ShiftLeftMouseButton(mouse_pos.x, mouse_pos.y);
//        } else {
//            emit
//            this->LeftMouseButton(mouse_pos.x, mouse_pos.y);
//        }
//    } else if (event->button() == Qt::RightButton) {
//        emit
//        this->RightMouseButton();
//    }
//}

//void QSFMLCanvas::mouseDoubleClickEvent(QMouseEvent *event) {
//    if (event->button() == Qt::LeftButton) {
//        sf::Vector2i mouse_pos = sf::Mouse::getPosition(*this);
//        emit this->LeftMouseButtonDouble(mouse_pos.x, mouse_pos.y);
//    }
//}


void QSFMLCanvas::DrawTriangle(const triangle &t, const camera &cam, const my_vec3f &figure_center) {
    float intensity = light_ray.dot(t.n);
    if (cam.front.dot(t.n) > 0) {
        array<my_vec3f, 3> points_;
        array<sf::Vertex, 3> points_to_render;
        for (int i = 0; i < points_.size(); ++i) {
            points_[i] = adapt_coords(cam, t.vertices[i], figure_center);
            points_to_render[i] = Vertex({points_[i].getX(), points_[i].getY()},
                                         sf::Color(static_cast<Uint8>(255 * intensity),
                                                   static_cast<Uint8>(255 * intensity),
                                                   static_cast<Uint8>(250 * intensity)));
        }
        z_buffer(points_, image, {static_cast<Uint8>(255 * intensity), static_cast<Uint8>(255 * intensity),
                                  static_cast<Uint8>(250 * intensity)}, zbuffer);
//        this->draw(&points_to_render[0], points_to_render.size(), sf::Triangles);
    }
}

void QSFMLCanvas::z_buffer(array<my_vec3f, 3> points_, Image &image, sf::Color color_, vector<float> &zbuffer) {
    if (points_[0].getY() == points_[1].getY() && points_[1].getY() == points_[2].getY()) return;
    if (points_[0].getY() > points_[1].getY()) std::swap(points_[0], points_[1]);
    if (points_[0].getY() > points_[2].getY()) std::swap(points_[0], points_[2]);
    if (points_[1].getY() > points_[2].getY()) std::swap(points_[1], points_[2]);
    points_[0].setZ(ceil(points_[0].getZ())), points_[0].setX(ceil(points_[0].getX())), points_[0].setY(
            ceil(points_[0].getY()));
    points_[1].setZ(ceil(points_[1].getZ())), points_[1].setX(ceil(points_[1].getX())), points_[1].setY(
            ceil(points_[1].getY()));
    points_[2].setZ(ceil(points_[2].getZ())), points_[2].setX(ceil(points_[2].getX())), points_[2].setY(
            ceil(points_[2].getY()));
    int total_height = (int) (points_[2].getY() - points_[0].getY());
    for (int i = 0; i < total_height; i++) {
        bool second_half = i > points_[1].getY() - points_[0].getY() || points_[1].getY() == points_[0].getY();
        int segment_height = (second_half ? static_cast<int>(points_[2].getY() - points_[1].getY())
                                          : static_cast<int>(points_[1].getY() - points_[0].getY()));
        float alpha = (float) i / total_height;
        float beta = (float) (i - (second_half ? points_[1].getY() - points_[0].getY() : 0)) /
                     segment_height;
        my_vec3f a = points_[0] + (points_[2] - points_[0]) * alpha;
        my_vec3f b = second_half ? points_[1] + (points_[2] - points_[1]) * beta :
                     points_[0] + (points_[1] - points_[0]) * beta;
        if (a.getX() > b.getX()) std::swap(a, b);
        for (int j = static_cast<int>(a.getX()); j <= static_cast<int>(b.getX()); j++) {
            float phi = (b.getX() == a.getX() ? 1.f : (float) (j - a.getX()) / (float) (b.getX() - a.getX()));
            my_vec3f P = a + ((b - a) * phi);
            if (P.getX() >= 0 && P.getY() >= 0 && P.getX() < image.getSize().x && P.getY() < image.getSize().y) {
                int idx = static_cast<int>(round(P.getX() + P.getY() * image.getSize().x));
                if (zbuffer[idx] > P.getZ()) {
                    zbuffer[idx] = P.getZ();
                    image.setPixel(static_cast<Uint32>(round(P.getX())), static_cast<Uint32>(round(P.getY())), color_);
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
    for (int i = 0; i < image.getSize().y; ++i) {
        for (int j = 0; j < image.getSize().x; ++j)
            image.setPixel(j, i, back_color);
    }
    fill(zbuffer.begin(), zbuffer.end(), std::numeric_limits<float>::max());
    this->clear(back_color);
}

my_vec3f QSFMLCanvas::adapt_coords(const camera &c, const my_vec3f &point, const my_vec3f &center) {
    mat4 trans(1.0f);
//    if (on_load)
    vec4 res = c.perspective() * c.camLookAt() * vec4(center.getX(), center.getY(), center.getZ(), 1);
    my_vec3f modified_center(res.x, res.y, res.z);
    trans = viewport(modified_center);
    trans *= c.perspective();
    trans *= c.camLookAt();
    res = trans * vec4(point.getX(), point.getY(), point.getZ(), 1);
    return {res.x, res.y, res.z};
}

mat4 QSFMLCanvas::viewport(const my_vec3f &center) {
    return {this->size().width() / (2 * center.getX()), 0, 0, 0,
            0, this->size().height() / (2 * center.getY()), 0, 0,
            0, 0, 1, 1,
            0, 0, 0, 1};
}

void QSFMLCanvas::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Left)
            emit this->LeftKeyPressed();
    else if (event->key() == Qt::Key_Right)
            emit this->RightKeyPressed();
    else if (event->key() == Qt::Key_Up)
            emit this->UpKeyPressed();
    else if (event->key() == Qt::Key_Down)
            emit this->DownKeyPressed();
    else if (event->key() == Qt::Key_W)
            emit this->WKeyPressed({0, 0, -2});
    else if (event->key() == Qt::Key_A)
            emit this->AKeyPressed({-2, 0, 0});
    else if (event->key() == Qt::Key_S)
            emit this->SKeyPressed({0, 0, 2});
    else if (event->key() == Qt::Key_D)
            emit this->DKeyPressed({2, 0, 0});
}

void QSFMLCanvas::wheelEvent(QWheelEvent *event) {
    if (event->angleDelta().y() > 0)
            emit WheelScrolledUp(event->angleDelta().y() / (8.f * 180));
    else
            emit WheelScrolledDown(event->angleDelta().y() / (8.f * 180));
    if (event->angleDelta().x() > 0)
            emit WheelScrolledUp(event->angleDelta().y() / (8.f * 180));
    else
            emit WheelScrolledDown(event->angleDelta().y() / (8.f * 180));
}

