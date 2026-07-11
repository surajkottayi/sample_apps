cmake_minimum_required(VERSION 3.10)
project(sample_project
VERSION 1.0
LANGUAGES CXX
DESCRIPTION "A sample C++ project to explain global variables"
)
file(GLOB_RECURSE SOURCES src/*.cpp)
add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(sample_project PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)