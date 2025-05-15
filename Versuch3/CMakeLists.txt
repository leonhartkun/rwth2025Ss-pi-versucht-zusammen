cmake_minimum_required(VERSION 3.31)
project(Versuch_3_0_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Versuch_3_0_1
        config.h
        othello.cpp
        othelloKI.h
        test.cpp
        test.h)
