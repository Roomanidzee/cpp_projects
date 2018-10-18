cmake_minimum_required(VERSION 3.12)
project(SomeOpenMPThird)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp")

add_executable(SomeOpenMPThird main.cpp)
add_executable(AtomicCounter atomic_counter.cpp)
add_executable(MaxCounter max_counter.cpp)