cmake_minimum_required(VERSION 3.26)
project(Chapter1)

set(CMAKE_CXX_STANDARD 17)

add_executable(Chapter1 main.cpp
        Person.h
        Person.cpp
        SmartPointer.h)
