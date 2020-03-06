cmake_minimum_required(VERSION 3.0.0)

include(CTest)
enable_testing()

Set(Tests)

set(Sources
    TbitTest.cpp
)

add_executable(Test ${Sources})
add_test(Tester Test)
