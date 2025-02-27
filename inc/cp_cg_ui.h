/********************************************************************************
** Form generated from reading UI file 'main_window.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

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
    QLabel *label_11;
    QLabel *label;
    QLabel *label_5;
    QSlider *wind_angle_slider;
    QPushButton *load_model_button;
    QLabel *label_10;
    QLabel *sim_speed_label;
    QLabel *wind_speed_label;
    QLabel *wind_angle_label;
    QLabel *label_7;
    QSlider *sim_speed_slider;
    QLabel *label_3;
    QLabel *label_9;
    QSlider *wind_speed_slider;
    QLabel *label_6;
    QLabel *label_2;
    QPushButton *simulation_start_button;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(635, 626);
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
        gridLayoutWidget->setGeometry(QRect(10, 10, 611, 591));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_11 = new QLabel(gridLayoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_11, 8, 2, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 1, 0, 1, 3);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_5, 4, 0, 1, 3);

        wind_angle_slider = new QSlider(gridLayoutWidget);
        wind_angle_slider->setObjectName(QString::fromUtf8("wind_angle_slider"));
        wind_angle_slider->setMinimum(0);
        wind_angle_slider->setMaximum(359);
        wind_angle_slider->setSliderPosition(0);
        wind_angle_slider->setOrientation(Qt::Horizontal);
        wind_angle_slider->setTickPosition(QSlider::TicksBelow);
        wind_angle_slider->setTickInterval(10);

        gridLayout->addWidget(wind_angle_slider, 5, 1, 1, 1);

        load_model_button = new QPushButton(gridLayoutWidget);
        load_model_button->setObjectName(QString::fromUtf8("load_model_button"));

        gridLayout->addWidget(load_model_button, 0, 0, 1, 3);

        label_10 = new QLabel(gridLayoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_10, 8, 0, 1, 1);

        sim_speed_label = new QLabel(gridLayoutWidget);
        sim_speed_label->setObjectName(QString::fromUtf8("sim_speed_label"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(sim_speed_label->sizePolicy().hasHeightForWidth());
        sim_speed_label->setSizePolicy(sizePolicy1);
        sim_speed_label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(sim_speed_label, 9, 0, 1, 3);

        wind_speed_label = new QLabel(gridLayoutWidget);
        wind_speed_label->setObjectName(QString::fromUtf8("wind_speed_label"));
        wind_speed_label->setEnabled(true);
        sizePolicy1.setHeightForWidth(wind_speed_label->sizePolicy().hasHeightForWidth());
        wind_speed_label->setSizePolicy(sizePolicy1);
        wind_speed_label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(wind_speed_label, 3, 0, 1, 3);

        wind_angle_label = new QLabel(gridLayoutWidget);
        wind_angle_label->setObjectName(QString::fromUtf8("wind_angle_label"));
        sizePolicy1.setHeightForWidth(wind_angle_label->sizePolicy().hasHeightForWidth());
        wind_angle_label->setSizePolicy(sizePolicy1);
        wind_angle_label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(wind_angle_label, 6, 0, 1, 3);

        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_7, 5, 2, 1, 1);

        sim_speed_slider = new QSlider(gridLayoutWidget);
        sim_speed_slider->setObjectName(QString::fromUtf8("sim_speed_slider"));
        sim_speed_slider->setMinimum(1);
        sim_speed_slider->setMaximum(5);
        sim_speed_slider->setSliderPosition(1);
        sim_speed_slider->setOrientation(Qt::Horizontal);
        sim_speed_slider->setTickPosition(QSlider::TicksBelow);
        sim_speed_slider->setTickInterval(1);

        gridLayout->addWidget(sim_speed_slider, 8, 1, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 2, 2, 1, 1);

        label_9 = new QLabel(gridLayoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        sizePolicy.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy);
        label_9->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_9, 7, 0, 1, 3);

        wind_speed_slider = new QSlider(gridLayoutWidget);
        wind_speed_slider->setObjectName(QString::fromUtf8("wind_speed_slider"));
        wind_speed_slider->setMinimum(0);
        wind_speed_slider->setMaximum(25);
        wind_speed_slider->setSliderPosition(0);
        wind_speed_slider->setOrientation(Qt::Horizontal);
        wind_speed_slider->setTickPosition(QSlider::TicksBelow);
        wind_speed_slider->setTickInterval(1);

        gridLayout->addWidget(wind_speed_slider, 2, 1, 1, 1);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        simulation_start_button = new QPushButton(gridLayoutWidget);
        simulation_start_button->setObjectName(QString::fromUtf8("simulation_start_button"));

        gridLayout->addWidget(simulation_start_button, 10, 0, 1, 3);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        load_model_action->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", nullptr));
        sim_start->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\207\320\260\321\202\321\214", nullptr));
        set_wind_action->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\264\320\260\321\202\321\214 \320\262\320\265\321\202\320\265\321\200", nullptr));
        set_speed_action->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\264\320\260\321\202\321\214 \321\201\320\272\320\276\321\200\320\276\321\201\321\202\321\214 \321\201\320\270\320\274\321\203\320\273\321\217\321\206\320\270\320\270", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "X5", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\264\320\260\321\202\321\214 \321\201\320\272\320\276\321\200\320\276\321\201\321\202\321\214 \320\262\320\265\321\202\321\200\320\260 (\320\274/\321\201)", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\264\320\260\321\202\321\214 \320\275\320\260\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\262\320\265\321\202\321\200\320\260 (\320\260\320\267\320\270\320\274\321\203\321\202)", nullptr));
        load_model_button->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\274\320\276\320\264\320\265\320\273\321\214", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "X1", nullptr));
        sim_speed_label->setText(QCoreApplication::translate("MainWindow", "X1", nullptr));
        wind_speed_label->setText(QCoreApplication::translate("MainWindow", "0 \320\274/\321\201", nullptr));
        wind_angle_label->setText(QCoreApplication::translate("MainWindow", "0 \302\260", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "360", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "35", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\201\320\272\320\276\321\200\320\276\321\201\321\202\321\214 \321\201\320\270\320\274\321\203\320\273\321\217\321\206\320\270\320\270", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        simulation_start_button->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\207\320\260\321\202\321\214 \321\201\320\270\320\274\321\203\320\273\321\217\321\206\320\270\321\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MAIN_WINDOW_H
