cmake_minimum_required(VERSION 3.30)
project(lib_utfrend)

set(CMAKE_CXX_STANDARD 23)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})
link_libraries(${OpenCV_LIBS})

add_executable(lib_utfrend example.cpp
        lib_utfrend.h)
