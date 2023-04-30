cmake_minimum_required(VERSION 3.22)

project(Maze VERSION 2.0 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(Matrix)

add_library(${PROJECT_NAME} STATIC
    ${PROJECT_SOURCE_DIR}/maze.h
    ${PROJECT_SOURCE_DIR}/maze.cc
    ${PROJECT_SOURCE_DIR}/cave.cc
    ${PROJECT_SOURCE_DIR}/cave.h
    ${PROJECT_SOURCE_DIR}/maze_solver.cc
    ${PROJECT_SOURCE_DIR}/maze_solver.h
)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR} Matrix)
