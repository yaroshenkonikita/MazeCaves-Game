cmake_minimum_required(VERSION 3.22)

project(AppMaze VERSION 2.0 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(Maze)

find_package(Qt6 COMPONENTS Core Gui Widgets OpenGL OpenGLWidgets REQUIRED)

add_executable(AppMaze
        main.cc
        View/OpenGLWidget/gl_override.cc
        View/OpenGLWidget/gl_override.h
        View/applicationview.cc
        View/applicationview.h
        View/applicationview.ui)

target_link_libraries(AppMaze PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets Qt6::OpenGL Qt6::OpenGLWidgets Maze Matrix)
