#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP

#include <QColor>
#include <QColorDialog>
#include <QCoreApplication>
#include <QLabel>
#include <QMessageBox>
#include <QObject>
#include <QPushButton>
#include <QTableWidget>
#include <iostream>
#include <string>
#include <map>
#include <QProgressBar>
#include <QFileDialog>
#include <QSlider>

#include "qdialogs.h"
#include "QSFML.h"
#include "handler.h"
#include "cp_cg_ui.h"
#include "scene.h"

class MainWindow : public QMainWindow {

    Q_OBJECT

public:
    MainWindow();

    ~MainWindow() override = default;

signals:

    void ModelPathFetched(const std::string &path);

    void WindSettingsFetched(const int &speed, const int &angle);

    void SimulationSpeedSettingsFetched(const int &x);

public slots:

    void WindChanged();

    void SimulationSpeedChanged();

    void LoadModelActionTriggered();

};

#endif