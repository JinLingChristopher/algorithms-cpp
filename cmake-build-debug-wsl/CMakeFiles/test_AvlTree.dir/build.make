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
CMAKE_COMMAND = /opt/cmake/bin/cmake

# The command to remove a file.
RM = /opt/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/d/workspace/algorithm-cpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d/workspace/algorithm-cpp/cmake-build-debug-wsl

# Include any dependencies generated for this target.
include CMakeFiles/test_AvlTree.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test_AvlTree.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_AvlTree.dir/flags.make

CMakeFiles/test_AvlTree.dir/Trees/AvlTree.cpp.o: CMakeFiles/test_AvlTree.dir/flags.make
CMakeFiles/test_AvlTree.dir/Trees/AvlTree.cpp.o: ../Trees/AvlTree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/workspace/algorithm-cpp/cmake-build-debug-wsl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test_AvlTree.dir/Trees/AvlTree.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_AvlTree.dir/Trees/AvlTree.cpp.o -c /mnt/d/workspace/algorithm-cpp/Trees/AvlTree.cpp

CMakeFiles/test_AvlTree.dir/Trees/AvlTree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_AvlTree.dir/Trees/AvlTree.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/workspace/algorithm-cpp/Trees/AvlTree.cpp > CMakeFiles/test_AvlTree.dir/Trees/AvlTree.cpp.i

CMakeFiles/test_AvlTree.dir/Trees/AvlTree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_AvlTree.dir/Trees/AvlTree.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/workspace/algorithm-cpp/Trees/AvlTree.cpp -o CMakeFiles/test_AvlTree.dir/Trees/AvlTree.cpp.s

CMakeFiles/test_AvlTree.dir/Trees/test_avltree.cpp.o: CMakeFiles/test_AvlTree.dir/flags.make
CMakeFiles/test_AvlTree.dir/Trees/test_avltree.cpp.o: ../Trees/test_avltree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/workspace/algorithm-cpp/cmake-build-debug-wsl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/test_AvlTree.dir/Trees/test_avltree.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_AvlTree.dir/Trees/test_avltree.cpp.o -c /mnt/d/workspace/algorithm-cpp/Trees/test_avltree.cpp

CMakeFiles/test_AvlTree.dir/Trees/test_avltree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_AvlTree.dir/Trees/test_avltree.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/workspace/algorithm-cpp/Trees/test_avltree.cpp > CMakeFiles/test_AvlTree.dir/Trees/test_avltree.cpp.i

CMakeFiles/test_AvlTree.dir/Trees/test_avltree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_AvlTree.dir/Trees/test_avltree.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/workspace/algorithm-cpp/Trees/test_avltree.cpp -o CMakeFiles/test_AvlTree.dir/Trees/test_avltree.cpp.s

# Object files for target test_AvlTree
test_AvlTree_OBJECTS = \
"CMakeFiles/test_AvlTree.dir/Trees/AvlTree.cpp.o" \
"CMakeFiles/test_AvlTree.dir/Trees/test_avltree.cpp.o"

# External object files for target test_AvlTree
test_AvlTree_EXTERNAL_OBJECTS =

test_AvlTree: CMakeFiles/test_AvlTree.dir/Trees/AvlTree.cpp.o
test_AvlTree: CMakeFiles/test_AvlTree.dir/Trees/test_avltree.cpp.o
test_AvlTree: CMakeFiles/test_AvlTree.dir/build.make
test_AvlTree: /usr/lib/libgtest.a
test_AvlTree: /usr/lib/libgtest_main.a
test_AvlTree: CMakeFiles/test_AvlTree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/workspace/algorithm-cpp/cmake-build-debug-wsl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable test_AvlTree"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_AvlTree.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_AvlTree.dir/build: test_AvlTree

.PHONY : CMakeFiles/test_AvlTree.dir/build

CMakeFiles/test_AvlTree.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_AvlTree.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_AvlTree.dir/clean

CMakeFiles/test_AvlTree.dir/depend:
	cd /mnt/d/workspace/algorithm-cpp/cmake-build-debug-wsl && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/workspace/algorithm-cpp /mnt/d/workspace/algorithm-cpp /mnt/d/workspace/algorithm-cpp/cmake-build-debug-wsl /mnt/d/workspace/algorithm-cpp/cmake-build-debug-wsl /mnt/d/workspace/algorithm-cpp/cmake-build-debug-wsl/CMakeFiles/test_AvlTree.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_AvlTree.dir/depend
