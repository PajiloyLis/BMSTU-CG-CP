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

#include "QSFML.h"
#include "handler.h"
#include "cp_cg_ui.h"
#include "scene.h"

class MainWindow : public QMainWindow {

public:
    MainWindow();

    ~MainWindow() override = default;

private slots:

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
private:
    static bool NumericFieldCheck(QLineEdit *&field);

    void DrawScene();

    void SetBindings();

    TaskHandler handler;
};

#endif