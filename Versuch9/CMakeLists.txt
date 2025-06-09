cmake_minimum_required(VERSION 3.19)
project(Versuch9 LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets LinguistTools)

qt_standard_project_setup()

qt_add_executable(Versuch9
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    city.h city.cpp
    map.h map.cpp
    abstractmap.cpp abstractmap.h
    street.h street.cpp
    add_city.h add_city.cpp add_city.ui
    mapio.cpp mapio.h mapionrw.cpp mapionrw.h
    dijkstra.cpp dijkstra.h
    bigtown.h bigtown.cpp
    smallcity.h smallcity.cpp
    mapiofileinput.cpp mapiofileinput.h
    smalltown.h smalltown.cpp
    stateroad.h stateroad.cpp
    motorway.h motorway.cpp
    mouse_control.h mouse_control.cpp
    check.h check.cpp
    add_street.h add_street.cpp add_street.ui
    icon.rc
)

qt_add_translations(
    TARGETS Versuch9
    TS_FILES Versuch9_zh_CN.ts
)

target_link_libraries(Versuch9
    PRIVATE
        Qt::Core
        Qt::Widgets
)

include(GNUInstallDirs)

install(TARGETS Versuch9
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET Versuch9
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
target_include_directories(Versuch9 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
