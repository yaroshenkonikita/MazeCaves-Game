cmake_minimum_required(VERSION 3.22)

project(MazeCaves VERSION 2.0 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(Maze)
add_subdirectory(Cave)
add_subdirectory(Matrix)

find_package(Qt6 COMPONENTS Core Gui Widgets OpenGL OpenGLWidgets REQUIRED)

add_executable(${PROJECT_NAME}
        ${PROJECT_SOURCE_DIR}/main.cc
        ${PROJECT_SOURCE_DIR}/View/OpenGLWidget/gl_override.cc
        ${PROJECT_SOURCE_DIR}/View/OpenGLWidget/gl_override.h
        ${PROJECT_SOURCE_DIR}/View/application_view.cc
        ${PROJECT_SOURCE_DIR}/View/application_view.h
        ${PROJECT_SOURCE_DIR}/View/application_view.ui
        ${PROJECT_SOURCE_DIR}/CaveView/cave_view.h
        ${PROJECT_SOURCE_DIR}/CaveView/cave_view.cpp
        ${PROJECT_SOURCE_DIR}/CaveView/cave_view.ui
        ${PROJECT_SOURCE_DIR}/CaveView/OpenGLWidget/cave_opengl_widget_override.h
        ${PROJECT_SOURCE_DIR}/CaveView/OpenGLWidget/cave_opengl_widget_override.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets Qt6::OpenGL Qt6::OpenGLWidgets Cave Maze Matrix)
