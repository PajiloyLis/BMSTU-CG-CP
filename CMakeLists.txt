cmake_minimum_required(VERSION 3.27)
project(cp_cg)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(cp_cg
        main.cpp
        map_prepare.cpp
        map_prepare.h
        point.cpp
        point.h)

target_link_libraries(cp_cg PUBLIC sfml-graphics sfml-window sfml-system)
