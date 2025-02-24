
QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++20

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += "/usr/include"
INCLUDEPATH += "/home/ivan/Study/CompG/cp_cg/inc"
LIBS += -L"/usr/include/sfml"
CONFIG(debug, debug|release){
    LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-system-d -lsfml-window-d
} else {
    LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window
}

SOURCES += \
    ./src/conversions.cpp \
    ./src/figure.cpp \
    ./src/handler.cpp \
    ./src/main.cpp \
    ./src/main_window.cpp \
    ./src/operations.cpp \
    ./src/QSFML.cpp \
    ./src/scene.cpp \
    ./src/triangle.cpp \
    ./src/camera.cpp \
    ./src/smoke.cpp

HEADERS += \
    ./inc/conversions.h \
    ./inc/cp_cg_ui.h \
    ./inc/figure.h \
    ./inc/handler.h \
    ./inc/main_window.h \
    ./inc/operations.h \
    ./inc/QSFML.h \
    ./inc/scene.h \
    ./inc/triangle.h \
    ./inc/camera.h \
    ./inc/smoke.h
FORMS += \
    ./inc/main_window.ui

# Default rules for deployment.
#qnx: target.path = /tmp/$${TARGET}/bin
#else: unix:!android: target.path = /opt/$${TARGET}/bin
#!isEmpty(target.path): INSTALLS += target