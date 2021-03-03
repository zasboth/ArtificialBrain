cmake_minimum_required(VERSION 3.15.0)

enable_testing()

set(Sources
	main.cpp
    tbit_test.cpp
    pebble_test.cpp
    arbitrator_test.cpp
    AbstractNeuron_test.cpp
    perceptron_test.cpp
)

add_executable(tester ${Sources})

add_test(NAME tester COMMAND tester)

find_package(GTest CONFIG REQUIRED)
#target_link_libraries(tester PRIVATE GTest::gmock GTest::gtest GTest::gmock_main GTest::gtest_main)

target_link_libraries(tester
	TernaryLogic
	GTest::gmock 
	GTest::gtest 
	GTest::gmock_main 
	GTest::gtest_main
)
