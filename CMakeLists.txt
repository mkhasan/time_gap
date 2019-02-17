cmake_minimum_required(VERSION 3.4.1)
PROJECT (time_gap)

set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb -Wall" )

add_executable(${PROJECT_NAME} src/time_gap.cpp)


