cmake_minimum_required(VERSION 3.22)

project(Matrix VERSION 2.0 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(${PROJECT_NAME} STATIC
    ${PROJECT_SOURCE_DIR}/matrix_oop.h
    ${PROJECT_SOURCE_DIR}/matrix_oop.cc
)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR})