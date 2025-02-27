#include "main_window.h"

MainWindow::MainWindow() : QMainWindow() {
    std::setlocale(LC_ALL, "");
    Ui::MainWindow ui;
    ui.setupUi(this);
}

void MainWindow::LoadModelActionTriggered() {
    string file_path = QFileDialog::getOpenFileName(nullptr, "Выберите STL файл", ".", "*.STL").toStdString();
    emit ModelPathFetched(file_path);
}

void MainWindow::WindChanged() {
    auto speed_slider = this->findChild<QSlider *>("wind_speed_slider");
    int speed = speed_slider->value();
    auto angle_slider = this->findChild<QSlider *>("wind_angle_slider");
    int angle = angle_slider->value();
    emit WindSettingsFetched(speed, angle);
}

void MainWindow::SimulationSpeedChanged() {
    auto sim_speed_slider = this->findChild<QSlider *>("sim_speed_slider");
    int x = sim_speed_slider->value();
    emit SimulationSpeedSettingsFetched(x);
}

void MainWindow::StartButtonHandler() {
    returnValue = 100;
    this->close();
}

void MainWindow::closeEvent(QCloseEvent *event) {
    qDebug() << "Window closed with return value:" << returnValue;
    if(returnValue == 100)
        event->accept();
    else
        event->ignore();
}
