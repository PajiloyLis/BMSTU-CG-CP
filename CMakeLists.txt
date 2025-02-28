cmake_minimum_required(VERSION 3.27)
project(cp_cg)

set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

#qt_standard_project_setup()

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

find_package(OpenMP REQUIRED)



include_directories(./inc .)

add_executable(cp_cg
        src/main.cpp
        src/operations.cpp
        inc/operations.h
        src/triangle.cpp
        inc/triangle.h
        inc/conversions.h
        src/main_window.cpp
        inc/main_window.h
        inc/cp_cg_ui.h
        src/scene.cpp
        inc/handler.h
        src/handler.cpp
        src/figure.cpp
        inc/figure.h
        src/camera.cpp
        inc/camera.h
        src/conversions.cpp
        src/smoke.cpp
        inc/smoke.h
        moc_main_window.cpp
        moc_handler.cpp
        moc_predefs.h
)

target_link_libraries(cp_cg PUBLIC
        Qt::Core
        Qt::Gui
        Qt::Widgets sfml-graphics sfml-window sfml-system pthread
        OpenMP::OpenMP_CXX
)

#target_link_options(cp_cg PUBLIC fopenmp)
