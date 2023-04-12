cmake_minimum_required(VERSION 3.0.0)
project(hw2 VERSION 0.1.0)

set(CMAKE_CXX_CPPLINT "cpplint")

add_executable(hw2 src/main.cpp src/operations.cpp src/commands_processing.cpp)
target_include_directories(hw2 PUBLIC include)