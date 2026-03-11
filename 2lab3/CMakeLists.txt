cmake_minimum_required(VERSION 3.15)

set(PROJECT_NAME application)
project("${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 17)
if(MSVC)
    add_compile_options(/utf-8)
endif()

add_library(StudentsLib STATIC class.cpp class.hpp)
add_executable("${PROJECT_NAME}" main.cpp)
target_link_libraries("${PROJECT_NAME}" StudentsLib)