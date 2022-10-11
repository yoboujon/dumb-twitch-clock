set(CMAKE_CXX_COMPILER "g++" )
set(CMAKE_C_COMPILER "gcc" )
project(MyApp C CXX)
cmake_minimum_required(VERSION 3.3.2)

include(cmake/App.cmake)

set(SOURCES "include/dtcApp.h"
            "src/dtcApp.cpp"
            "src/clock.cpp"
            "include/clock.hpp"
            "src/main.cpp"
            "assets/icon.rc"
            "assets/info.rc")

add_app("${SOURCES}")