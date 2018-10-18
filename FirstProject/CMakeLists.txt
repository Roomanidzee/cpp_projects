cmake_minimum_required(VERSION 3.12)
project(FirstProject)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fopenmp")

add_executable(FirstProject main.cpp)

include_directories(/usr/include/openmpi-x86_64)

set(CMAKE_C_COMPILER "/usr/lib64/openmpi/bin/mpicc")
set(CMAKE_CXX_COMPILER "/usr/lib64/openmpi/bin/mpic++")