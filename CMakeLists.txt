cmake_minimum_required(VERSION 3.17)
project(pthreads)

set(CMAKE_CXX_STANDARD 20)

add_definitions(-std=gnu++17 -U__STRICT_ANSI__)

set(SOURCE_FILES src/phtr.cpp)

add_executable(main main.cpp ${SOURCE_FILES})