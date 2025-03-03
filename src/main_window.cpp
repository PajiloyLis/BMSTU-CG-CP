#include "main_window.h"

MainWindow::MainWindow() : QMainWindow() {
    std::setlocale(LC_ALL, "");
    Ui::MainWindow ui;
    ui.setupUi(this);
    model_loaded = false;
}

void MainWindow::LoadModelActionTriggered() {
    string file_path = QFileDialog::getOpenFileName(nullptr, "Выберите STL файл", ".", "*.STL").toStdString();
    auto label = this->findChild<QLabel *>("loaded_model_name");
    if (file_path.empty() && !model_loaded) {
        label->setText("Модель не загружена");
        return;
    }
    if(!model_loaded) {
        model_loaded = true;
        label->setText(file_path.c_str());
        emit ModelPathFetched(file_path);
    }
}

void MainWindow::WindChanged() {
    auto speed_slider = this->findChild<QSlider *>("wind_speed_slider");
    int speed = speed_slider->value();
    auto label = this->findChild<QLabel *>("wind_speed_label");
    label ->setText(to_string(speed).c_str());
    auto angle_slider = this->findChild<QSlider *>("wind_angle_slider");
    int angle = angle_slider->value();
    label =
    emit WindSettingsFetched(speed, angle);
}

void MainWindow::SimulationSpeedChanged() {
    auto sim_speed_slider = this->findChild<QSlider *>("sim_speed_slider");
    int x = sim_speed_slider->value();
    emit SimulationSpeedSettingsFetched(x);
}

void MainWindow::VisualizationStart() {
    QApplication::exit(VIS_START);
    this->close();
}

