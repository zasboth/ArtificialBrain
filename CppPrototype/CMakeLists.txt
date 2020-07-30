cmake_minimum_required(VERSION 3.15.0)
project(TernaryLogic VERSION 0.1.0)


set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")
#SET(GCC_COVERAGE_COMPILE_FLAGS "-fprofile-arcs -ftest-coverage")
#SET(GCC_COVERAGE_LINK_FLAGS    "-lgcov")
add_definitions(--coverage)
set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} " --coverage")

enable_testing()

include_directories(
	TernaryLogic
)

link_directories(
	
)

add_subdirectory(TernaryLogic)
add_subdirectory(test)
