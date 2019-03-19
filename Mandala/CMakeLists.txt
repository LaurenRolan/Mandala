cmake_minimum_required(VERSION 3.12)
project(Mandala)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5PrintSupport REQUIRED)


include_directories(header)
include_directories(header/ui)

file(GLOB_RECURSE mandala_SRC src/*)
file(GLOB_RECURSE mandala_HDR header/*)


add_executable(Mandala ${mandala_SRC} ${mandala_HDR} )

target_link_libraries(Mandala Qt5::Widgets Qt5::PrintSupport)