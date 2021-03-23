cmake_minimum_required(VERSION 3.15.0)

add_library(TernaryLogic STATIC
    Serializable.h
    AbstractNeuron.h
    AbstractContainer.h
    Tbit.h
    Tbit.cpp
    Pebble.h
    Pebble.cpp
    Arbitrator.h
    Arbitrator.cpp
    Perceptron.h
    Perceptron.cpp
    Container.h
    Container.cpp
)

target_include_directories(TernaryLogic PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

