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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tiger/linux/GTK/29-cmake

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tiger/linux/GTK/cmake-build-Debug/29-cmake

# Include any dependencies generated for this target.
include CMakeFiles/29-cmake.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/29-cmake.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/29-cmake.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/29-cmake.dir/flags.make

CMakeFiles/29-cmake.dir/main.c.o: CMakeFiles/29-cmake.dir/flags.make
CMakeFiles/29-cmake.dir/main.c.o: /home/tiger/linux/GTK/29-cmake/main.c
CMakeFiles/29-cmake.dir/main.c.o: CMakeFiles/29-cmake.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tiger/linux/GTK/cmake-build-Debug/29-cmake/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/29-cmake.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS)  -g -Wall -O0 -pthread -MD -MT CMakeFiles/29-cmake.dir/main.c.o -MF CMakeFiles/29-cmake.dir/main.c.o.d -o CMakeFiles/29-cmake.dir/main.c.o -c /home/tiger/linux/GTK/29-cmake/main.c

CMakeFiles/29-cmake.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/29-cmake.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS)  -g -Wall -O0 -pthread -E /home/tiger/linux/GTK/29-cmake/main.c > CMakeFiles/29-cmake.dir/main.c.i

CMakeFiles/29-cmake.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/29-cmake.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS)  -g -Wall -O0 -pthread -S /home/tiger/linux/GTK/29-cmake/main.c -o CMakeFiles/29-cmake.dir/main.c.s

# Object files for target 29-cmake
29__cmake_OBJECTS = \
"CMakeFiles/29-cmake.dir/main.c.o"

# External object files for target 29-cmake
29__cmake_EXTERNAL_OBJECTS =

/home/tiger/linux/GTK/cmake-build-Debug/output/29-cmake: CMakeFiles/29-cmake.dir/main.c.o
/home/tiger/linux/GTK/cmake-build-Debug/output/29-cmake: CMakeFiles/29-cmake.dir/build.make
/home/tiger/linux/GTK/cmake-build-Debug/output/29-cmake: CMakeFiles/29-cmake.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tiger/linux/GTK/cmake-build-Debug/29-cmake/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable /home/tiger/linux/GTK/cmake-build-Debug/output/29-cmake"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/29-cmake.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/29-cmake.dir/build: /home/tiger/linux/GTK/cmake-build-Debug/output/29-cmake
.PHONY : CMakeFiles/29-cmake.dir/build

CMakeFiles/29-cmake.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/29-cmake.dir/cmake_clean.cmake
.PHONY : CMakeFiles/29-cmake.dir/clean

CMakeFiles/29-cmake.dir/depend:
	cd /home/tiger/linux/GTK/cmake-build-Debug/29-cmake && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tiger/linux/GTK/29-cmake /home/tiger/linux/GTK/29-cmake /home/tiger/linux/GTK/cmake-build-Debug/29-cmake /home/tiger/linux/GTK/cmake-build-Debug/29-cmake /home/tiger/linux/GTK/cmake-build-Debug/29-cmake/CMakeFiles/29-cmake.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/29-cmake.dir/depend
