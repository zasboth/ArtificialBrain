cmake_minimum_required (VERSION 3.26)
project (Ternary)

add_subdirectory(Ternary)

add_executable(runner main.cpp)

target_link_libraries (runner LINK_PUBLIC Ternary)