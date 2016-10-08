cmake_minimum_required(VERSION 2.6)
project(read_image)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
find_package(OpenCV REQUIRED)
set(SOURCE_FILES main.cpp)
add_executable(read_image ${SOURCE_FILES})
target_link_libraries(read_image ${OpenCV_LIBS})
