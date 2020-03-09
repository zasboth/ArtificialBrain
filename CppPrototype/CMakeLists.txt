cmake_minimum_required(VERSION 3.15.0)
project(TernaryLogic VERSION 0.1.0)

enable_testing()

include_directories(
	TernaryLogic
	lib
)

add_subdirectory(lib/googletest)
add_subdirectory(TernaryLogic)
add_subdirectory(test)