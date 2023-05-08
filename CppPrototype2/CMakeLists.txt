cmake_minimum_required (VERSION 3.26)
project (Ternary)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(Ternary)

add_executable(ternary main.cpp)

target_link_libraries (ternary LINK_PUBLIC Ternary)