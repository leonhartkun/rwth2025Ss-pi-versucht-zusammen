cmake_minimum_required(VERSION 3.31)
project(Versuch8)

set(CMAKE_CXX_STANDARD 20)

add_executable(Versuch8 Buecherei.cpp
        Datum.h
        Datum.cpp
        Medium.cpp
        Medium.h
        Person.cpp
        Person.h
        Buch.cpp
        Buch.h
        Magazin.cpp
        Magazin.h
        DVD.cpp
        DVD.h)
