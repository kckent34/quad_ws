# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/odroid/quad_ws/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/odroid/quad_ws/build

# Utility rule file for xbee_generate_messages.

# Include the progress variables for this target.
include xbee/CMakeFiles/xbee_generate_messages.dir/progress.make

xbee/CMakeFiles/xbee_generate_messages:

xbee_generate_messages: xbee/CMakeFiles/xbee_generate_messages
xbee_generate_messages: xbee/CMakeFiles/xbee_generate_messages.dir/build.make
.PHONY : xbee_generate_messages

# Rule to build all files generated by this target.
xbee/CMakeFiles/xbee_generate_messages.dir/build: xbee_generate_messages
.PHONY : xbee/CMakeFiles/xbee_generate_messages.dir/build

xbee/CMakeFiles/xbee_generate_messages.dir/clean:
	cd /home/odroid/quad_ws/build/xbee && $(CMAKE_COMMAND) -P CMakeFiles/xbee_generate_messages.dir/cmake_clean.cmake
.PHONY : xbee/CMakeFiles/xbee_generate_messages.dir/clean

xbee/CMakeFiles/xbee_generate_messages.dir/depend:
	cd /home/odroid/quad_ws/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/odroid/quad_ws/src /home/odroid/quad_ws/src/xbee /home/odroid/quad_ws/build /home/odroid/quad_ws/build/xbee /home/odroid/quad_ws/build/xbee/CMakeFiles/xbee_generate_messages.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : xbee/CMakeFiles/xbee_generate_messages.dir/depend
