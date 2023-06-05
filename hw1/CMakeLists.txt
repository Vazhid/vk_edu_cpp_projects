cmake_minimum_required(VERSION 3.0.0)
project(hw1 VERSION 0.1.0)

add_executable(hw1 src/main.cpp src/functions.cpp)
target_include_directories(hw1 PUBLIC include)