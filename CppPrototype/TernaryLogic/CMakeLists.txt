cmake_minimum_required(VERSION 3.15.0)
project(TernaryLogic VERSION 0.1.0)

include(CTest)
enable_testing()

link_directories(${CMAKE_SOURCE_DIR}/lib)

add_library(TernaryLogic 
    Tbit.h
    Tbit.cpp
)

add_subdirectory(test)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

#add_executable(tests TbitTest.cpp)
#add_test(tester tests)
