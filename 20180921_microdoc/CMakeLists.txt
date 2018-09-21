cmake_minimum_required(VERSION 3.5)

project (medianChallenge)

set(CMAKE_CXX_STANDARD 11)

set(SOURCES src/median.cpp src/RBTree.cpp src/SuperInt.cpp src/priorityQueue.cpp src/main.cpp)
include_directories(include)

add_executable(medianChallenge ${SOURCES})
