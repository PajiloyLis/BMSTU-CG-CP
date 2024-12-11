#include "main_window.h"

extern bool on_load;

MainWindow::MainWindow() : QMainWindow(), handler() {
    std::setlocale(LC_ALL, "");
    Ui::MainWindow ui;
    ui.setupUi(this);

    auto const *grid = this->findChild<QWidget *>("gridLayoutWidget");
    auto const *menu = this->findChild<QMenuBar *>("menubar");
    auto *drawer = new QSFMLCanvas(this, QSize(grid->size()));
    drawer->setObjectName("drawer");
    drawer->setGeometry(menu->pos().x(), grid->pos().y() + menu->size().height(),
                        grid->size().width(), grid->size().height());
    drawer->setMouseTracking(true);
    this->handler.AddCamera(
            {{150, 0, 50}, {0, 0, 0}, {0, 0, 1}, static_cast<float>(drawer->width()) / drawer->height()});
    this->handler.SetScene(
            Scene(drawer, drawer->size().width(), drawer->size().height()));

    this->SetBindings();
    DrawScene();
}

void MainWindow::SetBindings() {
    QObject::connect(this->findChild<QAction *>("load_model_action"),
                     &QAction::triggered, this,
                     &MainWindow::LoadModelActionTriggered);
    QObject::connect(this->findChild<QSFMLCanvas *>("drawer"), &QSFMLCanvas::LeftKeyPressed, this,
                     &MainWindow::RotateCurCameraLeft);
    QObject::connect(this->findChild<QSFMLCanvas *>("drawer"), &QSFMLCanvas::RightKeyPressed, this,
                     &MainWindow::RotateCurCameraRight);
    QObject::connect(this->findChild<QSFMLCanvas *>("drawer"), &QSFMLCanvas::DownKeyPressed, this,
                     &MainWindow::RotateCurCameraDown);
    QObject::connect(this->findChild<QSFMLCanvas *>("drawer"), &QSFMLCanvas::UpKeyPressed, this,
                     &MainWindow::RotateCurCameraUp);
    QObject::connect(this->findChild<QSFMLCanvas *>("drawer"), &QSFMLCanvas::WKeyPressed, this,
                     &MainWindow::MoveCurCamera);
    QObject::connect(this->findChild<QSFMLCanvas *>("drawer"), &QSFMLCanvas::AKeyPressed, this,
                     &MainWindow::MoveCurCamera);
    QObject::connect(this->findChild<QSFMLCanvas *>("drawer"), &QSFMLCanvas::SKeyPressed, this,
                     &MainWindow::MoveCurCamera);
    QObject::connect(this->findChild<QSFMLCanvas *>("drawer"), &QSFMLCanvas::DKeyPressed, this,
                     &MainWindow::MoveCurCamera);
    QObject::connect(this->findChild<QSFMLCanvas *>("drawer"), &QSFMLCanvas::WheelScrolledDown, this,
                     &MainWindow::ScaleCurCamera);
    QObject::connect(this->findChild<QSFMLCanvas *>("drawer"), &QSFMLCanvas::WheelScrolledUp, this,
                     &MainWindow::ScaleCurCamera);
}

void MainWindow::LoadModelActionTriggered() {
    on_load = true;
    string file_path = QFileDialog::getOpenFileName(nullptr, "Выберите STL файл", ".", "*.STL").toStdString();
    handler.LoadModel(file_path);
    DrawScene();
    on_load = false;
}

void MainWindow::DrawScene() {
    handler.DrawScene();
}

void MainWindow::RotateCurCameraLeft() {
    handler.RotateCurCameraLeft();
    DrawScene();
}

void MainWindow::RotateCurCameraRight() {
    handler.RotateCurCameraRight();
    DrawScene();
}

void MainWindow::RotateCurCameraUp() {
    handler.RotateCurCameraUp();
    DrawScene();
}

void MainWindow::RotateCurCameraDown() {
    handler.RotateCurCameraDown();
    DrawScene();
}

void MainWindow::MoveCurCamera(const move_t &move) {
    handler.MoveCamera(move);
    DrawScene();
}

void MainWindow::ScaleCurCamera(float k) {
    handler.ScaleCamera(k);
    DrawScene();
}
