cmake_minimum_required(VERSION 3.15.0)
project(TernaryLogic VERSION 0.1.0)

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
	set(CMAKE_CXX_STANDARD 20)
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -v -Wall -O0 ")
	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -v -Wall ")
	set(GCC_COVERAGE_COMPILE_FLAGS "-fprofile-arcs -ftest-coverage")
	set(GCC_COVERAGE_LINK_FLAGS    "-lgcov")
	add_definitions(--coverage)
	set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} " --coverage")
	Message(STATUS "Debug flags: " ${CMAKE_CXX_FLAGS_DEBUG})
	Message(STATUS "Release flags: " ${CMAKE_CXX_FLAGS_RELEASE})
	Message(STATUS "Linker flags: " ${CMAKE_EXE_LINKER_FLAGS})
endif()

enable_testing()

find_package(jsoncpp CONFIG REQUIRED)
#target_link_libraries(TernaryLogic PRIVATE jsoncpp_lib jsoncpp_object)

include_directories(
	TernaryLogic
	lib
)

add_subdirectory(TernaryLogic)
add_subdirectory(test)

target_link_libraries(
	TernaryLogic
	jsoncpp_lib 
	#jsoncpp_object
)
