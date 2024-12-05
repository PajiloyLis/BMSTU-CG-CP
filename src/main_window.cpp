#include "main_window.h"

MainWindow::MainWindow() : QMainWindow(), handler() {
    std::setlocale(LC_ALL, "");
    Ui::MainWindow ui;
    ui.setupUi(this);

    auto const *grid = this->findChild<QWidget *>("gridLayoutWidget");
    auto const *menu = this->findChild<QMenuBar *>("menubar");
    auto *drawer = new QSFMLCanvas(this, QSize(grid->size()));
    drawer->setObjectName("drawer");
    drawer->setGeometry(menu->pos().x(), grid->pos().y()+menu->size().height(),
                        grid->size().width(), grid->size().height());
    drawer->setMouseTracking(true);
    this->handler.AddCamera({120, 0, 0, static_cast<float>(drawer->size().width())/drawer->size().height()});
    this->handler.SetScene(
            Scene(drawer, drawer->size().width(), drawer->size().height()));

    this->SetBindings();
    DrawScene();
}

void MainWindow::SetBindings() {
    QObject::connect(this->findChild<QAction *>("load_model_action"),
                     &QAction::triggered, this,
                     &MainWindow::LoadModelActionTriggered);
    QObject::connect(this->findChild<QSFMLCanvas *>("drawer"), &QSFMLCanvas::LeftKeyPressed, this, )
}

void MainWindow::LoadModelActionTriggered() {
    string file_path = QFileDialog::getOpenFileName(nullptr, "Выберите STL файл", ".", "*.STL").toStdString();
    handler.LoadModel(file_path);
    DrawScene();
}

void MainWindow::DrawScene() {
    handler.DrawScene();
}

void MainWindow::RotateCurCameraLeft() {
    handler.RotateCurCameraLeft();
    DrawScene();
}
