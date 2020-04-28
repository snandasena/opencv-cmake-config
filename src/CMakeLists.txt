cmake_minimum_required(VERSION 3.5)

project(opencvdemo)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV REQUIRED)

#add_executable(opencvdemo LoadImage.cpp)
#add_executable(opencvdemo imageprocessing/BlurImage.cpp)
#add_executable(opencvdemo imageprocessing/BasicImageDraw.cpp)
#add_executable(opencvdemo imageprocessing/MorphologicalOperation_1.cpp)
#add_executable(opencvdemo imageprocessing/MorphologicalOperation_3.cpp)
#add_executable(opencvdemo imageprocessing/HitOrMiss.cpp)
#add_executable(opencvdemo imageprocessing/MorphologicalOperation_3.cpp)
#add_executable(opencvdemo imageprocessing/ImagePyramid.cpp)
#add_executable(opencvdemo imageprocessing/BasicThreshold.cpp)
#add_executable(opencvdemo imageprocessing/Threshold_inRange.cpp)
#add_executable(opencvdemo imageprocessing/Filter2D.cpp)
#add_executable(opencvdemo imageprocessing/AddingBorderImage.cpp)
#add_executable(opencvdemo imageprocessing/SobelDemo.cpp)
#add_executable(opencvdemo imageprocessing/Laplace_Demo.cpp)
#add_executable(opencvdemo imageprocessing/CannyDetector_Demo.cpp)
#add_executable(opencvdemo imageprocessing/HoughLines_Demo.cpp)
#add_executable(opencvdemo imageprocessing/HoughCircle_Demo.cpp)
add_executable(opencvdemo imageprocessing/Remap_Demo.cpp)

target_link_libraries(opencvdemo ${OpenCV_LIBS})
