# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = "C:/Program Files/CMake/bin/cmake.exe"

# The command to remove a file.
RM = "C:/Program Files/CMake/bin/cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:/_work/ArtificialBrain/CppPrototype/TernaryLogic

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:/_work/ArtificialBrain/CppPrototype/TernaryLogic/build

# Include any dependencies generated for this target.
include CMakeFiles/tester.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tester.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tester.dir/flags.make

CMakeFiles/tester.dir/test/TbitTest.cpp.obj: CMakeFiles/tester.dir/flags.make
CMakeFiles/tester.dir/test/TbitTest.cpp.obj: ../test/TbitTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:/_work/ArtificialBrain/CppPrototype/TernaryLogic/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tester.dir/test/TbitTest.cpp.obj"
	C:/mingw-w64/i686-8.1.0-posix-dwarf-rt_v6-rev0/mingw32/bin/i686-w64-mingw32-g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tester.dir/test/TbitTest.cpp.obj -c C:/_work/ArtificialBrain/CppPrototype/TernaryLogic/test/TbitTest.cpp

CMakeFiles/tester.dir/test/TbitTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tester.dir/test/TbitTest.cpp.i"
	C:/mingw-w64/i686-8.1.0-posix-dwarf-rt_v6-rev0/mingw32/bin/i686-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:/_work/ArtificialBrain/CppPrototype/TernaryLogic/test/TbitTest.cpp > CMakeFiles/tester.dir/test/TbitTest.cpp.i

CMakeFiles/tester.dir/test/TbitTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tester.dir/test/TbitTest.cpp.s"
	C:/mingw-w64/i686-8.1.0-posix-dwarf-rt_v6-rev0/mingw32/bin/i686-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:/_work/ArtificialBrain/CppPrototype/TernaryLogic/test/TbitTest.cpp -o CMakeFiles/tester.dir/test/TbitTest.cpp.s

# Object files for target tester
tester_OBJECTS = \
"CMakeFiles/tester.dir/test/TbitTest.cpp.obj"

# External object files for target tester
tester_EXTERNAL_OBJECTS =

tester.exe: CMakeFiles/tester.dir/test/TbitTest.cpp.obj
tester.exe: CMakeFiles/tester.dir/build.make
tester.exe: CMakeFiles/tester.dir/linklibs.rsp
tester.exe: CMakeFiles/tester.dir/objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:/_work/ArtificialBrain/CppPrototype/TernaryLogic/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable tester.exe"
	"C:/Program Files/CMake/bin/cmake.exe" -E rm -f CMakeFiles/tester.dir/objects.a
	C:/mingw-w64/i686-8.1.0-posix-dwarf-rt_v6-rev0/mingw32/bin/ar.exe cr CMakeFiles/tester.dir/objects.a @CMakeFiles/tester.dir/objects1.rsp
	C:/mingw-w64/i686-8.1.0-posix-dwarf-rt_v6-rev0/mingw32/bin/i686-w64-mingw32-g++.exe -g   -Wl,--whole-archive CMakeFiles/tester.dir/objects.a -Wl,--no-whole-archive  -o tester.exe -Wl,--out-implib,libtester.dll.a -Wl,--major-image-version,0,--minor-image-version,0 @CMakeFiles/tester.dir/linklibs.rsp

# Rule to build all files generated by this target.
CMakeFiles/tester.dir/build: tester.exe

.PHONY : CMakeFiles/tester.dir/build

CMakeFiles/tester.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tester.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tester.dir/clean

CMakeFiles/tester.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" C:/_work/ArtificialBrain/CppPrototype/TernaryLogic C:/_work/ArtificialBrain/CppPrototype/TernaryLogic C:/_work/ArtificialBrain/CppPrototype/TernaryLogic/build C:/_work/ArtificialBrain/CppPrototype/TernaryLogic/build C:/_work/ArtificialBrain/CppPrototype/TernaryLogic/build/CMakeFiles/tester.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tester.dir/depend

