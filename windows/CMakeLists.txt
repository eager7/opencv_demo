cmake_minimum_required(VERSION 2.6)
set(TARGET "windows")
project(${TARGET})


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
find_package(OpenCV REQUIRED)
set(SOURCE_FILES main.cpp)
add_executable(${TARGET} ${SOURCE_FILES})
target_link_libraries(${TARGET} ${OpenCV_LIBS})