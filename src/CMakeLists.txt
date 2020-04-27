cmake_minimum_required(VERSION 3.5)

project(opencvdemo)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV REQUIRED)

#add_executable(opencvdemo LoadImage.cpp)
#add_executable(opencvdemo BlurImage.cpp)
#add_executable(opencvdemo BasicImageDraw.cpp)
#add_executable(opencvdemo MorphologicalOperation_1.cpp)
#add_executable(opencvdemo MorphologicalOperation_3.cpp)
#add_executable(opencvdemo HitOrMiss.cpp)
#add_executable(opencvdemo MorphologicalOperation_3.cpp)
#add_executable(opencvdemo ImagePyramid.cpp)
#add_executable(opencvdemo BasicThreshold.cpp)
#add_executable(opencvdemo Threshold_inRange.cpp)
#add_executable(opencvdemo Filter2D.cpp)
#add_executable(opencvdemo AddingBorderImage.cpp)
#add_executable(opencvdemo SobelDemo.cpp)
#add_executable(opencvdemo Laplace_Demo.cpp)
#add_executable(opencvdemo CannyDetector_Demo.cpp)
#add_executable(opencvdemo HoughLines_Demo.cpp)
add_executable(opencvdemo HoughCircle_Demo.cpp)

target_link_libraries(opencvdemo ${OpenCV_LIBS})
