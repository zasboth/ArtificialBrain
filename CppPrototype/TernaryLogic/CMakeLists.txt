cmake_minimum_required(VERSION 3.0.0)
project(TernaryLogic VERSION 0.1.0)

include(CTest)
enable_testing()

add_library(TernaryLogic 
    TernaryLogic.cpp
    Tbit.h
    Tbit.cpp
)

add_executable(utest TbitTest.cpp)
add_test(Tester utest)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

