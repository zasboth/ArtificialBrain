cmake_minimum_required(VERSION 3.15.0)

enable_testing()


set(Sources
	main.cpp
    TbitTest.cpp
)

add_executable(tester ${Sources})

add_test(NAME tester
	COMMAND tester)

target_link_libraries(tester
	TernaryLogic_lib
	gtest
)