cmake_minimum_required(VERSION 3.12)
project(SecondProject)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp")

add_executable(SecondProject main.cpp)
add_executable(OpenMPExample openmp_example.cpp)