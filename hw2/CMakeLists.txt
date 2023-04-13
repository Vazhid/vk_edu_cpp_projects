cmake_minimum_required(VERSION 3.0.0)
project(hw2 VERSION 0.1.0)

set(CMAKE_CXX_CPPLINT "cpplint")

set(DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(INC_DIR ${DIR}/include)
set(SRC_DIR ${DIR}/src)

include_directories(${SRC_DIR}
                    ${INC_DIR})

add_executable(hw2 ${SRC_DIR}/main.cpp 
                   ${SRC_DIR}/operations.cpp 
                   ${INC_DIR}/operations.hpp 
                   ${SRC_DIR}/commands_processing.cpp 
                   ${INC_DIR}/commands_processing.hpp)
                   
target_include_directories(hw2 PUBLIC ${INC_DIR})