cmake_minimum_required(VERSION 3.27)
project(cp_cg)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

add_executable(cp_cg
        main.cpp
        map_prepare.cpp
        map_prepare.h
        point.cpp
        point.h
        operations.cpp
        operations.h
        figure.cpp
        figure.h
        triangle.cpp
        triangle.h
        conversions.h)

target_link_libraries(cp_cg PUBLIC sfml-graphics sfml-window sfml-system)
