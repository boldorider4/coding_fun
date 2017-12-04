cmake_minimum_required(VERSION 3.6)
project(RFFluxCompensator)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic")

set(SOURCE_FILES
        CapacitorConstant.h
        main.cpp
        FieldCatcher.cpp
        FieldCatcher.h
        )

add_executable(
        RFFieldCompensator
        ${SOURCE_FILES})
