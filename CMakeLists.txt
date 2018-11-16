cmake_minimum_required(VERSION 3.12)
project(uml)

set(CMAKE_CXX_STANDARD 14)

add_executable(uml main.cpp course.cpp course.h interface.cpp interface.h lists.cpp lists.h student.cpp student.h)
