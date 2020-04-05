cmake_minimum_required(VERSION 3.5)

project(opencvdemo)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV REQUIRED)

add_executable(opencvdemo main.cpp)

target_link_libraries(opencvdemo ${OpenCV_LIBS})
