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

# Include any dependencies generated for this target.
include xbee/CMakeFiles/xbee.dir/depend.make

# Include the progress variables for this target.
include xbee/CMakeFiles/xbee.dir/progress.make

# Include the compile flags for this target's objects.
include xbee/CMakeFiles/xbee.dir/flags.make

xbee/CMakeFiles/xbee.dir/src/xbee1.cpp.o: xbee/CMakeFiles/xbee.dir/flags.make
xbee/CMakeFiles/xbee.dir/src/xbee1.cpp.o: /home/odroid/quad_ws/src/xbee/src/xbee1.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/odroid/quad_ws/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object xbee/CMakeFiles/xbee.dir/src/xbee1.cpp.o"
	cd /home/odroid/quad_ws/build/xbee && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/xbee.dir/src/xbee1.cpp.o -c /home/odroid/quad_ws/src/xbee/src/xbee1.cpp

xbee/CMakeFiles/xbee.dir/src/xbee1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/xbee.dir/src/xbee1.cpp.i"
	cd /home/odroid/quad_ws/build/xbee && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/odroid/quad_ws/src/xbee/src/xbee1.cpp > CMakeFiles/xbee.dir/src/xbee1.cpp.i

xbee/CMakeFiles/xbee.dir/src/xbee1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/xbee.dir/src/xbee1.cpp.s"
	cd /home/odroid/quad_ws/build/xbee && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/odroid/quad_ws/src/xbee/src/xbee1.cpp -o CMakeFiles/xbee.dir/src/xbee1.cpp.s

xbee/CMakeFiles/xbee.dir/src/xbee1.cpp.o.requires:
.PHONY : xbee/CMakeFiles/xbee.dir/src/xbee1.cpp.o.requires

xbee/CMakeFiles/xbee.dir/src/xbee1.cpp.o.provides: xbee/CMakeFiles/xbee.dir/src/xbee1.cpp.o.requires
	$(MAKE) -f xbee/CMakeFiles/xbee.dir/build.make xbee/CMakeFiles/xbee.dir/src/xbee1.cpp.o.provides.build
.PHONY : xbee/CMakeFiles/xbee.dir/src/xbee1.cpp.o.provides

xbee/CMakeFiles/xbee.dir/src/xbee1.cpp.o.provides.build: xbee/CMakeFiles/xbee.dir/src/xbee1.cpp.o

# Object files for target xbee
xbee_OBJECTS = \
"CMakeFiles/xbee.dir/src/xbee1.cpp.o"

# External object files for target xbee
xbee_EXTERNAL_OBJECTS =

/home/odroid/quad_ws/devel/lib/xbee/xbee: xbee/CMakeFiles/xbee.dir/src/xbee1.cpp.o
/home/odroid/quad_ws/devel/lib/xbee/xbee: xbee/CMakeFiles/xbee.dir/build.make
/home/odroid/quad_ws/devel/lib/xbee/xbee: /opt/ros/indigo/lib/libroscpp.so
/home/odroid/quad_ws/devel/lib/xbee/xbee: /usr/lib/arm-linux-gnueabihf/libboost_signals.so
/home/odroid/quad_ws/devel/lib/xbee/xbee: /usr/lib/arm-linux-gnueabihf/libboost_filesystem.so
/home/odroid/quad_ws/devel/lib/xbee/xbee: /opt/ros/indigo/lib/librosconsole.so
/home/odroid/quad_ws/devel/lib/xbee/xbee: /opt/ros/indigo/lib/librosconsole_log4cxx.so
/home/odroid/quad_ws/devel/lib/xbee/xbee: /opt/ros/indigo/lib/librosconsole_backend_interface.so
/home/odroid/quad_ws/devel/lib/xbee/xbee: /usr/lib/liblog4cxx.so
/home/odroid/quad_ws/devel/lib/xbee/xbee: /usr/lib/arm-linux-gnueabihf/libboost_regex.so
/home/odroid/quad_ws/devel/lib/xbee/xbee: /opt/ros/indigo/lib/libxmlrpcpp.so
/home/odroid/quad_ws/devel/lib/xbee/xbee: /opt/ros/indigo/lib/libroscpp_serialization.so
/home/odroid/quad_ws/devel/lib/xbee/xbee: /opt/ros/indigo/lib/librostime.so
/home/odroid/quad_ws/devel/lib/xbee/xbee: /usr/lib/arm-linux-gnueabihf/libboost_date_time.so
/home/odroid/quad_ws/devel/lib/xbee/xbee: /opt/ros/indigo/lib/libcpp_common.so
/home/odroid/quad_ws/devel/lib/xbee/xbee: /usr/lib/arm-linux-gnueabihf/libboost_system.so
/home/odroid/quad_ws/devel/lib/xbee/xbee: /usr/lib/arm-linux-gnueabihf/libboost_thread.so
/home/odroid/quad_ws/devel/lib/xbee/xbee: /usr/lib/arm-linux-gnueabihf/libpthread.so
/home/odroid/quad_ws/devel/lib/xbee/xbee: /usr/lib/arm-linux-gnueabihf/libconsole_bridge.so
/home/odroid/quad_ws/devel/lib/xbee/xbee: xbee/CMakeFiles/xbee.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable /home/odroid/quad_ws/devel/lib/xbee/xbee"
	cd /home/odroid/quad_ws/build/xbee && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/xbee.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
xbee/CMakeFiles/xbee.dir/build: /home/odroid/quad_ws/devel/lib/xbee/xbee
.PHONY : xbee/CMakeFiles/xbee.dir/build

xbee/CMakeFiles/xbee.dir/requires: xbee/CMakeFiles/xbee.dir/src/xbee1.cpp.o.requires
.PHONY : xbee/CMakeFiles/xbee.dir/requires

xbee/CMakeFiles/xbee.dir/clean:
	cd /home/odroid/quad_ws/build/xbee && $(CMAKE_COMMAND) -P CMakeFiles/xbee.dir/cmake_clean.cmake
.PHONY : xbee/CMakeFiles/xbee.dir/clean

xbee/CMakeFiles/xbee.dir/depend:
	cd /home/odroid/quad_ws/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/odroid/quad_ws/src /home/odroid/quad_ws/src/xbee /home/odroid/quad_ws/build /home/odroid/quad_ws/build/xbee /home/odroid/quad_ws/build/xbee/CMakeFiles/xbee.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : xbee/CMakeFiles/xbee.dir/depend

