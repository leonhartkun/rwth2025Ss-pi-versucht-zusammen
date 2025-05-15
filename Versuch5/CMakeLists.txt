cmake_minimum_required(VERSION 3.31)
project(Versuch5)

set(CMAKE_CXX_STANDARD 20)

add_executable(Versuch5 main.cpp
        ListenElement.cpp
        Liste.cpp
        Liste.h
        ListenElement.h
        Student.cpp
        Student.h)

