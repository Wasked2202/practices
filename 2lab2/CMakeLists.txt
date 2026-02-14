cmake_minimum_required(VERSION 3.15)

set(PROJECT_NAME application)
project("${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -finput-charset=UTF-8")

add_executable("${PROJECT_NAME}" main.cpp class.cpp)