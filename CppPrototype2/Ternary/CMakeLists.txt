
add_library(Ternary 
    TernaryBit.hpp
    TernaryBit.cpp
    Perceptron.hpp
    Pebble.hpp
    PebbleStatistical.cpp
    PebbleStatistical.hpp
    )

target_include_directories (Ternary PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})