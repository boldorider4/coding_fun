cmake_minimum_required(VERSION 3.5)

project (weird_factory)

set(CMAKE_CXX_STANDARD 11)

set(SOURCES factory.cpp factory_test.cpp)
include_directories(.)

add_executable(${PROJECT_NAME} ${SOURCES})
