cmake_minimum_required(VERSION 3.22)

project(Cave VERSION 2.0 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 COMPONENTS Widgets)

add_library(${PROJECT_NAME} STATIC
        ${PROJECT_SOURCE_DIR}/cave.h
        ${PROJECT_SOURCE_DIR}/cave.cc)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR})
