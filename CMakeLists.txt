cmake_minimum_required(VERSION 3.27)
project(cp_cg)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

#qt_standard_project_setup()

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

include_directories(./inc .)

add_executable(cp_cg
        src/main.cpp
#        src/my_vec3f.cpp
#        inc/my_vec3f.h
        src/operations.cpp
        inc/operations.h
        src/triangle.cpp
        inc/triangle.h
        inc/conversions.h
        src/main_window.cpp
        inc/main_window.h
        inc/cp_cg_ui.h
        src/scene.cpp
        src/handler.cpp
        src/QSFML.cpp
        src/figure.cpp
        inc/figure.h
        src/camera.cpp
        inc/camera.h
        src/conversions.cpp
        src/particles_system.cpp
        inc/particles_system.h
        moc_QSFML.cpp
        moc_predefs.h)

target_link_libraries(cp_cg PUBLIC
        Qt::Core
        Qt::Gui
        Qt::Widgets sfml-graphics sfml-window sfml-system)
