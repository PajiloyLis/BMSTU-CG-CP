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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
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
    QMenuBar *menubar;
    QMenu *model_menu;
    QMenu *params_menu;
    QMenu *sim_menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1850, 1016);
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
        gridLayoutWidget->setGeometry(QRect(0, 0, 1841, 971));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1850, 22));
        model_menu = new QMenu(menubar);
        model_menu->setObjectName(QString::fromUtf8("model_menu"));
        params_menu = new QMenu(menubar);
        params_menu->setObjectName(QString::fromUtf8("params_menu"));
        sim_menu = new QMenu(menubar);
        sim_menu->setObjectName(QString::fromUtf8("sim_menu"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(model_menu->menuAction());
        menubar->addAction(params_menu->menuAction());
        menubar->addAction(sim_menu->menuAction());
        model_menu->addAction(load_model_action);
        params_menu->addAction(set_wind_action);
        params_menu->addAction(set_speed_action);
        sim_menu->addAction(sim_start);

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
        model_menu->setTitle(QCoreApplication::translate("MainWindow", "\320\234\320\276\320\264\320\265\320\273\321\214", nullptr));
        params_menu->setTitle(QCoreApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213", nullptr));
        sim_menu->setTitle(QCoreApplication::translate("MainWindow", "\320\241\320\270\320\274\321\203\320\273\321\217\321\206\320\270\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MAIN_WINDOW_H
