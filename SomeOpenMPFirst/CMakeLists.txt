cmake_minimum_required(VERSION 3.12)
project(SomeOpenMPFirst)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp")

add_executable(SomeOpenMPFirst main.cpp)
add_executable(OrderTask order.cpp)
add_executable(ParallelTask1 parallel_order_1.cpp)
add_executable(ParallelTask2 parallel_order_2.cpp)
add_executable(ParallelTask3 parallel_order_3.cpp)