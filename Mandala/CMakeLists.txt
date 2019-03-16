cmake_minimum_required(VERSION 3.13)
project(Mandala)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Gui REQUIRED)


include_directories(.)

set(mandala_SRC
        src/lib/images/Form.cpp
        src/lib/images/Image.cpp
        src/ui/mainwindow.cpp
        src/ui/mainwindow.ui
        src/main.cpp
        )

set(mandala_HDR
        header/lib/images/Form.h
        header/lib/images/Image.h
        header/ui/mainwindow.h
        header/lib/command/command.h
        )


add_executable(Mandala
        ${mandala_SRC}
        ${mandala_HDR}
        Mandala.pro)

target_link_libraries(Mandala Qt5::Widgets)