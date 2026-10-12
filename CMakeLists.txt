cmake_minimum_required(VERSION 3.10)
project(ElevatorSystem)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -Wall -Wextra")

add_executable(code src/elevator.cpp)