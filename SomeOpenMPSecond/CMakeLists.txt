cmake_minimum_required(VERSION 3.12)
project(SomeOpenMPSecond)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp")

add_executable(SomeOpenMPSecond parallel_arithmetic.cpp)
add_executable(MoreParallel two_parallel.cpp)
add_executable(TimeMetrics time_metrics.cpp)
add_executable(MatrixAndVector matrix_and_vector.cpp)