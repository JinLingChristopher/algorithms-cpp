# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

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
CMAKE_COMMAND = /opt/cmake/cmake-3.14.3-Linux-x86_64/bin/cmake

# The command to remove a file.
RM = /opt/cmake/cmake-3.14.3-Linux-x86_64/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/d/workspace/algorithm-cpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d/workspace/algorithm-cpp/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/n-queen.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/n-queen.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/n-queen.dir/flags.make

CMakeFiles/n-queen.dir/backtracking/n-queen.cpp.o: CMakeFiles/n-queen.dir/flags.make
CMakeFiles/n-queen.dir/backtracking/n-queen.cpp.o: ../backtracking/n-queen.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/workspace/algorithm-cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/n-queen.dir/backtracking/n-queen.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/n-queen.dir/backtracking/n-queen.cpp.o -c /mnt/d/workspace/algorithm-cpp/backtracking/n-queen.cpp

CMakeFiles/n-queen.dir/backtracking/n-queen.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/n-queen.dir/backtracking/n-queen.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/workspace/algorithm-cpp/backtracking/n-queen.cpp > CMakeFiles/n-queen.dir/backtracking/n-queen.cpp.i

CMakeFiles/n-queen.dir/backtracking/n-queen.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/n-queen.dir/backtracking/n-queen.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/workspace/algorithm-cpp/backtracking/n-queen.cpp -o CMakeFiles/n-queen.dir/backtracking/n-queen.cpp.s

# Object files for target n-queen
n__queen_OBJECTS = \
"CMakeFiles/n-queen.dir/backtracking/n-queen.cpp.o"

# External object files for target n-queen
n__queen_EXTERNAL_OBJECTS =

n-queen: CMakeFiles/n-queen.dir/backtracking/n-queen.cpp.o
n-queen: CMakeFiles/n-queen.dir/build.make
n-queen: CMakeFiles/n-queen.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/workspace/algorithm-cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable n-queen"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/n-queen.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/n-queen.dir/build: n-queen

.PHONY : CMakeFiles/n-queen.dir/build

CMakeFiles/n-queen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/n-queen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/n-queen.dir/clean

CMakeFiles/n-queen.dir/depend:
	cd /mnt/d/workspace/algorithm-cpp/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/workspace/algorithm-cpp /mnt/d/workspace/algorithm-cpp /mnt/d/workspace/algorithm-cpp/cmake-build-debug /mnt/d/workspace/algorithm-cpp/cmake-build-debug /mnt/d/workspace/algorithm-cpp/cmake-build-debug/CMakeFiles/n-queen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/n-queen.dir/depend

