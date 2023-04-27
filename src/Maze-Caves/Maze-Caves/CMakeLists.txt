cmake_minimum_required(VERSION 3.22)

project(Maze-Caves VERSION 2.0 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 COMPONENTS Core Gui Widgets OpenGL OpenGLWidgets REQUIRED)

add_executable(Maze-Caves
        main.cc

        applicationview.cc
        applicationview.h
        applicationview.ui

        OpenGLWidget/gl_override.cc

        OpenGLWidget/gl_override.h

        SettingsClass/options_t.cc
        SettingsClass/options_t.h)

target_link_libraries(Maze-Caves PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets Qt6::OpenGL Qt6::OpenGLWidgets)
