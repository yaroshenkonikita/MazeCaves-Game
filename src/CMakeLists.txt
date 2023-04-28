cmake_minimum_required(VERSION 3.22)

project(Maze-Caves VERSION 2.0 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(dependence)

find_package(Qt6 COMPONENTS Core Gui Widgets OpenGL OpenGLWidgets REQUIRED)

add_executable(Maze-Caves
        main.cc

        Maze-Caves/OpenGLWidget/gl_override.cc

        Maze-Caves/OpenGLWidget/gl_override.h

        Maze-Caves/applicationview.cc
        Maze-Caves/applicationview.h
        Maze-Caves/applicationview.ui

        Maze-Caves/SettingsClass/options_t.cc
        Maze-Caves/SettingsClass/options_t.h

        maze.h
        maze.cc)

target_link_libraries(Maze-Caves PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets Qt6::OpenGL Qt6::OpenGLWidgets matrix)
