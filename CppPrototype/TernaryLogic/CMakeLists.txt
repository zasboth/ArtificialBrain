cmake_minimum_required(VERSION 3.15.0)

add_library(TernaryLogic STATIC
    tbit.h
    tbit.cpp
    pebble.h
    pebble.cpp
    arbitrator.h
    arbitrator.cpp
)

target_include_directories(TernaryLogic PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
