cmake_minimum_required(VERSION 3.22)

project(AppCave VERSION 2.0 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(Matrix)

add_executable(${PROJECT_NAME}
        ${PROJECT_SOURCE_DIR}/main.cc
        ${PROJECT_SOURCE_DIR}/cave.cc
        ${PROJECT_SOURCE_DIR}/cave.h)

target_link_libraries(${PROJECT_NAME} PRIVATE Matrix)
