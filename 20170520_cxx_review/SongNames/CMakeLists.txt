cmake_minimum_required(VERSION 3.6)

project(SongNames)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -O0 -ggdb ")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall ")

add_executable(
        RFTitles
        main_Titles-test.cpp
        CoupleCollection.h
        SongNames.cpp
)
