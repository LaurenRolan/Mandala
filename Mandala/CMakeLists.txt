cmake_minimum_required(VERSION 3.13)
project(Mandala)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Gui REQUIRED)


include_directories(.)
include_directories(lib)
include_directories(model)
include_directories(ui)

add_executable(Mandala
        ui/mainwindow.cpp
        ui/mainwindow.h
        ui/mainwindow.ui
        main.cpp
        Mandala.pro)

target_link_libraries(Mandala Qt5::Widgets)