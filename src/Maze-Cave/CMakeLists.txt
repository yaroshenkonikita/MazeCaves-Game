cmake_minimum_required(VERSION 3.22)

project(MazeCave VERSION 2.0 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(dependence)

add_library(${PROJECT_NAME} STATIC
    ${PROJECT_SOURCE_DIR}/maze.h
    ${PROJECT_SOURCE_DIR}/maze.cc
    ${PROJECT_SOURCE_DIR}/cave.cc
    ${PROJECT_SOURCE_DIR}/cave.h
)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR} Matrix)
