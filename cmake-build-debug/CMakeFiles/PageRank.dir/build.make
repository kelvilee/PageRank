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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/kelvin/CLionProjects/PageRank

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/kelvin/CLionProjects/PageRank/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/PageRank.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/PageRank.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PageRank.dir/flags.make

CMakeFiles/PageRank.dir/main.cpp.o: CMakeFiles/PageRank.dir/flags.make
CMakeFiles/PageRank.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kelvin/CLionProjects/PageRank/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PageRank.dir/main.cpp.o"
	/Library/Developer/CommandLinetools/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PageRank.dir/main.cpp.o -c /Users/kelvin/CLionProjects/PageRank/main.cpp

CMakeFiles/PageRank.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PageRank.dir/main.cpp.i"
	/Library/Developer/CommandLinetools/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kelvin/CLionProjects/PageRank/main.cpp > CMakeFiles/PageRank.dir/main.cpp.i

CMakeFiles/PageRank.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PageRank.dir/main.cpp.s"
	/Library/Developer/CommandLinetools/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kelvin/CLionProjects/PageRank/main.cpp -o CMakeFiles/PageRank.dir/main.cpp.s

CMakeFiles/PageRank.dir/matrix.cpp.o: CMakeFiles/PageRank.dir/flags.make
CMakeFiles/PageRank.dir/matrix.cpp.o: ../matrix.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kelvin/CLionProjects/PageRank/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/PageRank.dir/matrix.cpp.o"
	/Library/Developer/CommandLinetools/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PageRank.dir/matrix.cpp.o -c /Users/kelvin/CLionProjects/PageRank/matrix.cpp

CMakeFiles/PageRank.dir/matrix.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PageRank.dir/matrix.cpp.i"
	/Library/Developer/CommandLinetools/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kelvin/CLionProjects/PageRank/matrix.cpp > CMakeFiles/PageRank.dir/matrix.cpp.i

CMakeFiles/PageRank.dir/matrix.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PageRank.dir/matrix.cpp.s"
	/Library/Developer/CommandLinetools/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kelvin/CLionProjects/PageRank/matrix.cpp -o CMakeFiles/PageRank.dir/matrix.cpp.s

# Object files for target PageRank
PageRank_OBJECTS = \
"CMakeFiles/PageRank.dir/main.cpp.o" \
"CMakeFiles/PageRank.dir/matrix.cpp.o"

# External object files for target PageRank
PageRank_EXTERNAL_OBJECTS =

PageRank: CMakeFiles/PageRank.dir/main.cpp.o
PageRank: CMakeFiles/PageRank.dir/matrix.cpp.o
PageRank: CMakeFiles/PageRank.dir/build.make
PageRank: CMakeFiles/PageRank.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/kelvin/CLionProjects/PageRank/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable PageRank"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PageRank.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PageRank.dir/build: PageRank

.PHONY : CMakeFiles/PageRank.dir/build

CMakeFiles/PageRank.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PageRank.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PageRank.dir/clean

CMakeFiles/PageRank.dir/depend:
	cd /Users/kelvin/CLionProjects/PageRank/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/kelvin/CLionProjects/PageRank /Users/kelvin/CLionProjects/PageRank /Users/kelvin/CLionProjects/PageRank/cmake-build-debug /Users/kelvin/CLionProjects/PageRank/cmake-build-debug /Users/kelvin/CLionProjects/PageRank/cmake-build-debug/CMakeFiles/PageRank.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PageRank.dir/depend

