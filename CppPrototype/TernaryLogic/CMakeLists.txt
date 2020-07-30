cmake_minimum_required(VERSION 3.15.0)

add_library(TernaryLogic STATIC
    Tbit.h
    Tbit.cpp
    Pebble.h
    Pebble.cpp
    Arbitrator.h
    Arbitrator.cpp
    Perceptron.h
    Perceptron.cpp
    Layer.h
    Layer.cpp
    Node.h
    Node.cpp
    RootNode.h
    RootNode.cpp
)

target_include_directories(TernaryLogic PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
