/********************************************************************************
** Form generated from reading UI file 'main_window.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_WINDOW_H
#define UI_MAIN_WINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *load_model_action;
    QAction *sim_start;
    QAction *set_wind_action;
    QAction *set_speed_action;
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QSlider *light_azimuth_slider;
    QLabel *wind_angle_label;
    QLabel *label_10;
    QLabel *label_2;
    QSlider *wind_angle_slider;
    QLabel *label_6;
    QLabel *label_11;
    QPushButton *load_model_button;
    QSlider *wind_speed_slider;
    QLabel *label_12;
    QLabel *label_7;
    QLabel *loaded_model_name;
    QSlider *light_height_slider;
    QLabel *light_height_label;
    QLabel *wind_speed_label;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_13;
    QLabel *label_9;
    QLabel *label_5;
    QLabel *label_14;
    QPushButton *simulation_start_button;
    QLabel *light_azimuth_label;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(632, 761);
        load_model_action = new QAction(MainWindow);
        load_model_action->setObjectName(QString::fromUtf8("load_model_action"));
        sim_start = new QAction(MainWindow);
        sim_start->setObjectName(QString::fromUtf8("sim_start"));
        set_wind_action = new QAction(MainWindow);
        set_wind_action->setObjectName(QString::fromUtf8("set_wind_action"));
        set_speed_action = new QAction(MainWindow);
        set_speed_action->setObjectName(QString::fromUtf8("set_speed_action"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 611, 721));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        light_azimuth_slider = new QSlider(gridLayoutWidget);
        light_azimuth_slider->setObjectName(QString::fromUtf8("light_azimuth_slider"));
        light_azimuth_slider->setMinimum(0);
        light_azimuth_slider->setMaximum(360);
        light_azimuth_slider->setSingleStep(1);
        light_azimuth_slider->setPageStep(1);
        light_azimuth_slider->setValue(0);
        light_azimuth_slider->setSliderPosition(0);
        light_azimuth_slider->setOrientation(Qt::Horizontal);
        light_azimuth_slider->setTickPosition(QSlider::TicksBelow);
        light_azimuth_slider->setTickInterval(5);

        gridLayout->addWidget(light_azimuth_slider, 12, 1, 1, 1);

        wind_angle_label = new QLabel(gridLayoutWidget);
        wind_angle_label->setObjectName(QString::fromUtf8("wind_angle_label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(wind_angle_label->sizePolicy().hasHeightForWidth());
        wind_angle_label->setSizePolicy(sizePolicy);
        wind_angle_label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(wind_angle_label, 7, 0, 1, 3);

        label_10 = new QLabel(gridLayoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_10, 9, 0, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        wind_angle_slider = new QSlider(gridLayoutWidget);
        wind_angle_slider->setObjectName(QString::fromUtf8("wind_angle_slider"));
        wind_angle_slider->setMinimum(0);
        wind_angle_slider->setMaximum(359);
        wind_angle_slider->setSliderPosition(0);
        wind_angle_slider->setOrientation(Qt::Horizontal);
        wind_angle_slider->setTickPosition(QSlider::TicksBelow);
        wind_angle_slider->setTickInterval(10);

        gridLayout->addWidget(wind_angle_slider, 6, 1, 1, 1);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_6, 6, 0, 1, 1);

        label_11 = new QLabel(gridLayoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_11, 9, 2, 1, 1);

        load_model_button = new QPushButton(gridLayoutWidget);
        load_model_button->setObjectName(QString::fromUtf8("load_model_button"));

        gridLayout->addWidget(load_model_button, 0, 0, 1, 3);

        wind_speed_slider = new QSlider(gridLayoutWidget);
        wind_speed_slider->setObjectName(QString::fromUtf8("wind_speed_slider"));
        wind_speed_slider->setMinimum(0);
        wind_speed_slider->setMaximum(20);
        wind_speed_slider->setSliderPosition(0);
        wind_speed_slider->setOrientation(Qt::Horizontal);
        wind_speed_slider->setTickPosition(QSlider::TicksBelow);
        wind_speed_slider->setTickInterval(1);

        gridLayout->addWidget(wind_speed_slider, 3, 1, 1, 1);

        label_12 = new QLabel(gridLayoutWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy1);
        label_12->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_12, 11, 0, 1, 3);

        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_7, 6, 2, 1, 1);

        loaded_model_name = new QLabel(gridLayoutWidget);
        loaded_model_name->setObjectName(QString::fromUtf8("loaded_model_name"));
        sizePolicy.setHeightForWidth(loaded_model_name->sizePolicy().hasHeightForWidth());
        loaded_model_name->setSizePolicy(sizePolicy);
        loaded_model_name->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(loaded_model_name, 1, 0, 1, 3);

        light_height_slider = new QSlider(gridLayoutWidget);
        light_height_slider->setObjectName(QString::fromUtf8("light_height_slider"));
        light_height_slider->setMinimum(0);
        light_height_slider->setMaximum(90);
        light_height_slider->setSingleStep(1);
        light_height_slider->setPageStep(1);
        light_height_slider->setSliderPosition(45);
        light_height_slider->setOrientation(Qt::Horizontal);
        light_height_slider->setTickPosition(QSlider::TicksBelow);
        light_height_slider->setTickInterval(5);

        gridLayout->addWidget(light_height_slider, 9, 1, 1, 1);

        light_height_label = new QLabel(gridLayoutWidget);
        light_height_label->setObjectName(QString::fromUtf8("light_height_label"));
        sizePolicy.setHeightForWidth(light_height_label->sizePolicy().hasHeightForWidth());
        light_height_label->setSizePolicy(sizePolicy);
        light_height_label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(light_height_label, 10, 0, 1, 3);

        wind_speed_label = new QLabel(gridLayoutWidget);
        wind_speed_label->setObjectName(QString::fromUtf8("wind_speed_label"));
        wind_speed_label->setEnabled(true);
        sizePolicy.setHeightForWidth(wind_speed_label->sizePolicy().hasHeightForWidth());
        wind_speed_label->setSizePolicy(sizePolicy);
        wind_speed_label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(wind_speed_label, 4, 0, 1, 3);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 3, 2, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 2, 0, 1, 3);

        label_13 = new QLabel(gridLayoutWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_13, 12, 0, 1, 1);

        label_9 = new QLabel(gridLayoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        sizePolicy1.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy1);
        label_9->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_9, 8, 0, 1, 3);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_5, 5, 0, 1, 3);

        label_14 = new QLabel(gridLayoutWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_14, 12, 2, 1, 1);

        simulation_start_button = new QPushButton(gridLayoutWidget);
        simulation_start_button->setObjectName(QString::fromUtf8("simulation_start_button"));

        gridLayout->addWidget(simulation_start_button, 14, 0, 1, 3);

        light_azimuth_label = new QLabel(gridLayoutWidget);
        light_azimuth_label->setObjectName(QString::fromUtf8("light_azimuth_label"));
        sizePolicy.setHeightForWidth(light_azimuth_label->sizePolicy().hasHeightForWidth());
        light_azimuth_label->setSizePolicy(sizePolicy);
        light_azimuth_label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(light_azimuth_label, 13, 0, 1, 3);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \320\262\320\270\320\267\321\203\320\260\320\273\320\270\320\267\320\260\321\206\320\270\320\270", nullptr));
        load_model_action->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", nullptr));
        sim_start->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\207\320\260\321\202\321\214", nullptr));
        set_wind_action->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\264\320\260\321\202\321\214 \320\262\320\265\321\202\320\265\321\200", nullptr));
        set_speed_action->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\264\320\260\321\202\321\214 \321\201\320\272\320\276\321\200\320\276\321\201\321\202\321\214 \321\201\320\270\320\274\321\203\320\273\321\217\321\206\320\270\320\270", nullptr));
        wind_angle_label->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "90", nullptr));
        load_model_button->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\274\320\276\320\264\320\265\320\273\321\214", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "\320\220\320\267\320\270\320\274\321\203\321\202 \320\270\321\201\321\202\320\276\321\207\320\275\320\270\320\272\320\260 \321\201\320\262\320\265\321\202\320\260", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "360", nullptr));
        loaded_model_name->setText(QCoreApplication::translate("MainWindow", "\320\234\320\276\320\264\320\265\320\273\321\214 \320\275\320\265 \320\267\320\260\320\263\321\200\321\203\320\266\320\265\320\275\320\260", nullptr));
        light_height_label->setText(QCoreApplication::translate("MainWindow", "45", nullptr));
        wind_speed_label->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "20", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\264\320\260\321\202\321\214 \321\201\320\272\320\276\321\200\320\276\321\201\321\202\321\214 \320\262\320\265\321\202\321\200\320\260 (\320\274/\321\201)", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\320\243\320\263\320\273\320\276\320\262\320\260\321\217 \320\262\321\213\321\201\320\276\321\202\320\260 \320\270\321\201\321\202\320\276\321\207\320\275\320\270\320\272\320\260 \321\201\320\262\320\265\321\202\320\260", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\264\320\260\321\202\321\214 \320\275\320\260\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\262\320\265\321\202\321\200\320\260 (\320\260\320\267\320\270\320\274\321\203\321\202)", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "360", nullptr));
        simulation_start_button->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\271\321\202\320\270 \320\272 \320\276\320\272\320\275\321\203 \320\262\320\270\320\267\321\203\320\260\320\273\320\270\320\267\320\260\321\206\320\270\320\270", nullptr));
        light_azimuth_label->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
