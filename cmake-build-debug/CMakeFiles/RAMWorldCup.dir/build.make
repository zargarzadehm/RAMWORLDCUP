# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /home/moein/program/clion-2017.2.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/moein/program/clion-2017.2.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/moein/CLionProjects/RAMWORLDCUP

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/moein/CLionProjects/RAMWORLDCUP/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/RAMWorldCup.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/RAMWorldCup.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/RAMWorldCup.dir/flags.make

CMakeFiles/RAMWorldCup.dir/main.c.o: CMakeFiles/RAMWorldCup.dir/flags.make
CMakeFiles/RAMWorldCup.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/moein/CLionProjects/RAMWORLDCUP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/RAMWorldCup.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/RAMWorldCup.dir/main.c.o   -c /home/moein/CLionProjects/RAMWORLDCUP/main.c

CMakeFiles/RAMWorldCup.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/RAMWorldCup.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/moein/CLionProjects/RAMWORLDCUP/main.c > CMakeFiles/RAMWorldCup.dir/main.c.i

CMakeFiles/RAMWorldCup.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/RAMWorldCup.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/moein/CLionProjects/RAMWORLDCUP/main.c -o CMakeFiles/RAMWorldCup.dir/main.c.s

CMakeFiles/RAMWorldCup.dir/main.c.o.requires:

.PHONY : CMakeFiles/RAMWorldCup.dir/main.c.o.requires

CMakeFiles/RAMWorldCup.dir/main.c.o.provides: CMakeFiles/RAMWorldCup.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/RAMWorldCup.dir/build.make CMakeFiles/RAMWorldCup.dir/main.c.o.provides.build
.PHONY : CMakeFiles/RAMWorldCup.dir/main.c.o.provides

CMakeFiles/RAMWorldCup.dir/main.c.o.provides.build: CMakeFiles/RAMWorldCup.dir/main.c.o


# Object files for target RAMWorldCup
RAMWorldCup_OBJECTS = \
"CMakeFiles/RAMWorldCup.dir/main.c.o"

# External object files for target RAMWorldCup
RAMWorldCup_EXTERNAL_OBJECTS =

RAMWorldCup: CMakeFiles/RAMWorldCup.dir/main.c.o
RAMWorldCup: CMakeFiles/RAMWorldCup.dir/build.make
RAMWorldCup: CMakeFiles/RAMWorldCup.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/moein/CLionProjects/RAMWORLDCUP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable RAMWorldCup"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/RAMWorldCup.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/RAMWorldCup.dir/build: RAMWorldCup

.PHONY : CMakeFiles/RAMWorldCup.dir/build

CMakeFiles/RAMWorldCup.dir/requires: CMakeFiles/RAMWorldCup.dir/main.c.o.requires

.PHONY : CMakeFiles/RAMWorldCup.dir/requires

CMakeFiles/RAMWorldCup.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/RAMWorldCup.dir/cmake_clean.cmake
.PHONY : CMakeFiles/RAMWorldCup.dir/clean

CMakeFiles/RAMWorldCup.dir/depend:
	cd /home/moein/CLionProjects/RAMWORLDCUP/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/moein/CLionProjects/RAMWORLDCUP /home/moein/CLionProjects/RAMWORLDCUP /home/moein/CLionProjects/RAMWORLDCUP/cmake-build-debug /home/moein/CLionProjects/RAMWORLDCUP/cmake-build-debug /home/moein/CLionProjects/RAMWORLDCUP/cmake-build-debug/CMakeFiles/RAMWorldCup.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/RAMWorldCup.dir/depend

