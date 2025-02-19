#include "QSFML.h"

bool on_load = false;

const glm::vec3 QSFMLCanvas::light_ray = glm::vec3(0, 0, 1);

QSFMLCanvas::QSFMLCanvas(QWidget *parent, const QSize &Size)
        : QWidget(parent),
          sf::RenderWindow(sf::VideoMode(Size.width(), Size.height()), "OpenGL",
                           sf::Style::Default),
          zbuffer(Size.width() * Size.height(), std::numeric_limits<float>::min()),
          m_initialized(false),
          back_color(sf::Color(0x87CEEB)), mouse_left_pressed(false), w_pressed(false), a_pressed(false),
          s_pressed(false), d_pressed(false) {
    image.create(Size.width(), Size.height(), back_color);
    setAttribute(Qt::WA_PaintOnScreen);
    setAttribute(Qt::WA_OpaquePaintEvent);
    setAttribute(Qt::WA_NoSystemBackground);

    setFocusPolicy(Qt::StrongFocus);
    timers[KEYBOARD] = 0;
    timers[SMOKE] = 0;
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
    cout << "KEK" << '\n';
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


void
QSFMLCanvas::DrawTriangle(const triangle &t, const camera &cam, const glm::vec3 &figure_center,
                          const sf::Color &color) {
    float intensity = glm::dot(light_ray, t.n);
    if (dot(cam.Front, t.n) > 0) {
        array<glm::vec3, 3> points_;
        array<sf::Vertex, 3> points_to_render;
        for (int i = 0; i < points_.size(); ++i) {
            points_[i] = adapt_coords(cam, t.vertices[i], figure_center);
//            points_to_render[i] = Vertex({points_[i].x, points_[i].y},
//                                         sf::Color(static_cast<Uint8>(color.r * intensity),
//                                                   static_cast<Uint8>(color.g * intensity),
//                                                   static_cast<Uint8>(color.b * intensity)));
        }
        z_buffer(points_, image, {static_cast<Uint8>(color.r * intensity), static_cast<Uint8>(color.g * intensity),
                                  static_cast<Uint8>(color.b * intensity)}, zbuffer);
//        this->draw(&points_to_render[0], points_to_render.size(), sf::Triangles);
    }
}

void QSFMLCanvas::z_buffer(array<glm::vec3, 3> points_, Image &image, sf::Color color_, vector<float> &zbuffer) {
    if (points_[0].y == points_[1].y && points_[1].y == points_[2].y) return;
    if (points_[0].y > points_[1].y) std::swap(points_[0], points_[1]);
    if (points_[0].y > points_[2].y) std::swap(points_[0], points_[2]);
    if (points_[1].y > points_[2].y) std::swap(points_[1], points_[2]);
    points_[0].z = (ceil(points_[0].z)), points_[0].x = (ceil(points_[0].x)), points_[0].y = (
            ceil(points_[0].y));
    points_[1].z = (ceil(points_[1].z)), points_[1].x = (ceil(points_[1].x)), points_[1].y = (
            ceil(points_[1].y));
    points_[2].z = (ceil(points_[2].z)), points_[2].x = (ceil(points_[2].x)), points_[2].y = (
            ceil(points_[2].y));
    int total_height = (int) (points_[2].y - points_[0].y);
    for (int i = 0; i < total_height; i++) {
        bool second_half = i > points_[1].y - points_[0].y || points_[1].y == points_[0].y;
        int segment_height = (second_half ? static_cast<int>(points_[2].y - points_[1].y)
                                          : static_cast<int>(points_[1].y - points_[0].y));
        float alpha = (float) i / total_height;
        float beta = (float) (i - (second_half ? points_[1].y - points_[0].y : 0)) /
                     segment_height;
        glm::vec3 a = points_[0] + (points_[2] - points_[0]) * alpha;
        glm::vec3 b = second_half ? points_[1] + (points_[2] - points_[1]) * beta :
                      points_[0] + (points_[1] - points_[0]) * beta;
        if (a.x > b.x) std::swap(a, b);
        for (int j = static_cast<int>(a.x ); j <= static_cast<int>(b.x ); j++) {
            float phi = (b.x == a.x ? 1.f : (float) (j - a.x) / (float) (b.x - a.x));
            glm::vec3 P = a + ((b - a) * phi);
            if (P.x >= 0 && P.y >= 0 && P.x < image.getSize().x && P.y < image.getSize().y) {
                int idx = static_cast<int>(round(P.x + P.y * image.getSize().x));
                if (zbuffer[idx] > P.z) {
                    zbuffer[idx] = P.z;
                    image.setPixel(static_cast<Uint32>(round(P.x)), static_cast<Uint32>(round(P.y)), color_);
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

glm::vec3 QSFMLCanvas::adapt_coords(const camera &c, const glm::vec3 &point, const glm::vec3 &center) {
    glm::mat4 trans(1.0f);
//    if (on_load)
//    vec4 res_1 = c.perspective() * c.camLookAt() * vec4(center.x , center.y, center.z, 1);
//    trans *= model(c.Position, point);
    trans *= viewport(center, c.Position, point);
    trans *= c.perspective();
    trans *= c.camLookAt();
    glm::vec4 res = trans * glm::vec4(point.x, point.y, point.z, 1);
    return {res.x, res.y, res.z};
}

glm::mat4 QSFMLCanvas::viewport(const glm::vec3 &center, const glm::vec3 &cam_pos, const glm::vec3 &point) {
    float k = std::min(this->width() / (2), this->height() / (2));
    return {k, 0, 0, this->width(),
            0, k, 0, this->height(),
            0, 0, 1, 0,
            0, 0, 0, 1};
}

void QSFMLCanvas::keyPressEvent(QKeyEvent *event) {
    last_motion_time = time(nullptr);
    if (event->key() == Qt::Key_W)
        w_pressed = true;
    else if (event->key() == Qt::Key_A)
        a_pressed = true;
    else if (event->key() == Qt::Key_S)
        s_pressed = true;
    else if (event->key() == Qt::Key_D)
        d_pressed = true;
    timers[KEYBOARD] = this->startTimer(1000);
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

void QSFMLCanvas::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        mouse_left_press_pos = event->pos();
        mouse_left_pressed = true;
    }
}

void QSFMLCanvas::mouseMoveEvent(QMouseEvent *event) {
    if (mouse_left_pressed) {
        QPoint currentPos = event->pos();
        emit MouseMove(currentPos.y() - mouse_left_press_pos.y(), currentPos.x() - mouse_left_press_pos.x());
    }
}

void QSFMLCanvas::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        // Завершаем перетаскивание
        mouse_left_pressed = false;
        QPoint currentPos = event->pos();
        emit MouseMove(currentPos.y() - mouse_left_press_pos.y(), currentPos.x() - mouse_left_press_pos.x());
    }
}

void QSFMLCanvas::keyReleaseEvent(QKeyEvent *event) {
    now_time = time(nullptr);
    float delta = now_time - last_motion_time;
    last_motion_time = now_time;
    if (event->key() == Qt::Key_W) {
        w_pressed = false;
        emit WKeyPressed(FORWARD, delta);
    } else if (event->key() == Qt::Key_A) {
        a_pressed = false;
        emit AKeyPressed(LEFT, delta);
    } else if (event->key() == Qt::Key_S) {
        s_pressed = false;
        emit SKeyPressed(BACKWARD, delta);
    } else if (event->key() == Qt::Key_D) {
        d_pressed = false;
        emit DKeyPressed(RIGHT, delta);
    }
    if (timers[KEYBOARD]) {
        cout << "THIS MUTHERFUCKER MUST DIE\n";
        this->killTimer(timers[KEYBOARD]);
    }
}

void QSFMLCanvas::timerEvent(QTimerEvent *event) {
    if(event->timerId() == timers[KEYBOARD]) {
        now_time = time(nullptr);
        float delta = now_time - last_motion_time;
        last_motion_time = now_time;
        cout << "TIMER KEK" << '\n';
        Q_UNUSED(event);
        if (w_pressed) {
            emit WKeyPressed(FORWARD, delta);
        } else if (a_pressed) {
            emit AKeyPressed(LEFT, delta);
        } else if (s_pressed) {
            emit SKeyPressed(BACKWARD, delta);
        } else if (d_pressed) {
            emit DKeyPressed(RIGHT, delta);
        }
    }
    else if(event->timerId()==timers[SMOKE])
    {
        cout<<"WORK BITCH\n";
        emit SmokeTimerElapsed();
    }
}

glm::mat4 QSFMLCanvas::model(const glm::vec3 &cam_pos, const glm::vec3 &point) {
    return glm::translate(glm::mat4(1.0f), cam_pos - point);
}

void QSFMLCanvas::DrawParticles(const particles_system &system, const camera &cam) {
    vector<sf::Vertex> adapted_points(system.particles.size());
    for (int i = 0; i < adapted_points.size(); ++i) {
        glm::vec3 adapted = adapt_coords(cam, system.particles[i].position, system.spawn);
//        adapted_points[i] = sf::Vertex(sf::Vector2f(adapted.x, adapted.y), system.particles[i].color);
    }

}

void QSFMLCanvas::StartSmokeTimer() {
    timers[SMOKE] = startTimer(100);
    if(timers[SMOKE]!=0)
        cout<<"SMOKE TIMER STARTED\n";
}


