# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/alexandr/Dokumenty/alg-project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alexandr/Dokumenty/alg-project/build

# Include any dependencies generated for this target.
include CMakeFiles/height_map.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/height_map.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/height_map.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/height_map.dir/flags.make

CMakeFiles/height_map.dir/src/main.cpp.o: CMakeFiles/height_map.dir/flags.make
CMakeFiles/height_map.dir/src/main.cpp.o: ../src/main.cpp
CMakeFiles/height_map.dir/src/main.cpp.o: CMakeFiles/height_map.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alexandr/Dokumenty/alg-project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/height_map.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/height_map.dir/src/main.cpp.o -MF CMakeFiles/height_map.dir/src/main.cpp.o.d -o CMakeFiles/height_map.dir/src/main.cpp.o -c /home/alexandr/Dokumenty/alg-project/src/main.cpp

CMakeFiles/height_map.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/height_map.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alexandr/Dokumenty/alg-project/src/main.cpp > CMakeFiles/height_map.dir/src/main.cpp.i

CMakeFiles/height_map.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/height_map.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alexandr/Dokumenty/alg-project/src/main.cpp -o CMakeFiles/height_map.dir/src/main.cpp.s

CMakeFiles/height_map.dir/src/height_map.cpp.o: CMakeFiles/height_map.dir/flags.make
CMakeFiles/height_map.dir/src/height_map.cpp.o: ../src/height_map.cpp
CMakeFiles/height_map.dir/src/height_map.cpp.o: CMakeFiles/height_map.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alexandr/Dokumenty/alg-project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/height_map.dir/src/height_map.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/height_map.dir/src/height_map.cpp.o -MF CMakeFiles/height_map.dir/src/height_map.cpp.o.d -o CMakeFiles/height_map.dir/src/height_map.cpp.o -c /home/alexandr/Dokumenty/alg-project/src/height_map.cpp

CMakeFiles/height_map.dir/src/height_map.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/height_map.dir/src/height_map.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alexandr/Dokumenty/alg-project/src/height_map.cpp > CMakeFiles/height_map.dir/src/height_map.cpp.i

CMakeFiles/height_map.dir/src/height_map.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/height_map.dir/src/height_map.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alexandr/Dokumenty/alg-project/src/height_map.cpp -o CMakeFiles/height_map.dir/src/height_map.cpp.s

# Object files for target height_map
height_map_OBJECTS = \
"CMakeFiles/height_map.dir/src/main.cpp.o" \
"CMakeFiles/height_map.dir/src/height_map.cpp.o"

# External object files for target height_map
height_map_EXTERNAL_OBJECTS =

height_map: CMakeFiles/height_map.dir/src/main.cpp.o
height_map: CMakeFiles/height_map.dir/src/height_map.cpp.o
height_map: CMakeFiles/height_map.dir/build.make
height_map: CMakeFiles/height_map.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alexandr/Dokumenty/alg-project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable height_map"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/height_map.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/height_map.dir/build: height_map
.PHONY : CMakeFiles/height_map.dir/build

CMakeFiles/height_map.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/height_map.dir/cmake_clean.cmake
.PHONY : CMakeFiles/height_map.dir/clean

CMakeFiles/height_map.dir/depend:
	cd /home/alexandr/Dokumenty/alg-project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alexandr/Dokumenty/alg-project /home/alexandr/Dokumenty/alg-project /home/alexandr/Dokumenty/alg-project/build /home/alexandr/Dokumenty/alg-project/build /home/alexandr/Dokumenty/alg-project/build/CMakeFiles/height_map.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/height_map.dir/depend

