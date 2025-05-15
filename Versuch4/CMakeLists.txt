cmake_minimum_required(VERSION 3.10)

project(SichtweiteÜberErde LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(versuch4
        main.cpp
        Vektor.h
        Vektor.cpp
)

# 如果你要生成 Doxygen，可以加以下内容：
find_package(Doxygen QUIET)
if(DOXYGEN_FOUND)
    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile)
    add_custom_target(doc_doxygen
            COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_IN}
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
            COMMENT "Erzeuge Doxygen-Dokumentation"
            VERBATIM
    )
endif()
