cmake_minimum_required(VERSION 2.6)
set(TARGET "hand_detect")
project(hand_detect)
find_package(OpenCV REQUIRED)

SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -D_REENTRANT ")

set(SOURCE_FILES  handGesture.cpp  handGesture.hpp  main.cpp  main.hpp  myImage.cpp  myImage.hpp  roi.cpp  roi.hpp)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
# include_directories(${PROJECT_SOURCE_DIR}/src/Interface/CoreStructures/Inc)
include_directories(
        ./
)

## Declare a C++ executable
add_executable(${TARGET} ${SOURCE_FILES})

## Specify libraries to link a library or executable target against
target_link_libraries(${TARGET}  ${OpenCV_LIBS})
