cmake_minimum_required(VERSION 3.6)
project(Final)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


set(SOURCE_FILES WaitList.h Queue.h WaitList.cpp BookStore.cpp Book.h main.cpp)
add_executable(Final ${SOURCE_FILES})
