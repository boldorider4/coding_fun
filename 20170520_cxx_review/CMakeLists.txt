cmake_minimum_required(VERSION 3.6)

# Added by me to allow building as c++11. Warning are just to be pedantic.
set(CMAKE_CXX_FLAGS "-std=c++11 -Wextra")

add_subdirectory(FieldCatcher)
add_subdirectory(SongNames)
