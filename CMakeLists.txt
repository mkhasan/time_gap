cmake_minimum_required(VERSION 3.4.1)
PROJECT (time_gap)

set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb -Wall" )

find_library(ACE ACE)

#add_executable(${PROJECT_NAME} src/time_gap.cpp)

add_executable(server src/server.cpp)

add_executable(client src/client.cpp src/queue.cpp)

add_executable(ace_server src/ace_server.cpp src/client_handler.cpp)

target_link_libraries(ace_server ${ACE} pthread)




