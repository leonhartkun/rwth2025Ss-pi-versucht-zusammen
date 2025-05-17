cmake_minimum_required(VERSION 3.31)
project(Versuch3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Versuch_3_0_1
        config.h
        othelloKI.h
        test.h
        othello.cpp
        test.cpp
        othelloKI.cpp)
