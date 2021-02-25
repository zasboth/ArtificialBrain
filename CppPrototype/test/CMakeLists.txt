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

target_link_libraries(tester
	TernaryLogic
	gtest
)
