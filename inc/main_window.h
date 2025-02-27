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

public:
    MainWindow();

    ~MainWindow() override = default;

signals:

    void ModelPathFetched(const string &path);

    void WindSettingsFetched(const int &speed, const int &angle);

    void SimulationSpeedSettingsFetched(const int &x);

public slots:

    void WindChanged();

    void SimulationSpeedChanged();

    void LoadModelActionTriggered();

    void ClearButtonClicked();

    void AddPointButtonClicked();

    void DrawingModeChanged();

    void LeftMouseButtonClicked(const int &x, const int &y);

    void RightMouseButtonClicked();

    void ShiftLeftMouseButtonClicked(const int &x, const int &y);

    void FillButtonClicked(const int &x, const int &y);

    void ShowTime(const double &time);

    void RotateCurCamera(float dx, float dy);

    void MoveCurCamera(const Camera_Movement &move, float delta_time);

    void ScaleCurCamera(float k);

    void StartSimulation();

    void SmokeTimerElapsedHandler();

    void WindSettingsHandler();

    void SpeedSettingsHandler();

private:
    static bool NumericFieldCheck(QLineEdit *&field);

    void DrawScene();

    void SetBindings();

    TaskHandler handler;
};

#endif