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
include imu/CMakeFiles/imu.dir/depend.make

# Include the progress variables for this target.
include imu/CMakeFiles/imu.dir/progress.make

# Include the compile flags for this target's objects.
include imu/CMakeFiles/imu.dir/flags.make

imu/CMakeFiles/imu.dir/src/imu.cpp.o: imu/CMakeFiles/imu.dir/flags.make
imu/CMakeFiles/imu.dir/src/imu.cpp.o: /home/odroid/quad_ws/src/imu/src/imu.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/odroid/quad_ws/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object imu/CMakeFiles/imu.dir/src/imu.cpp.o"
	cd /home/odroid/quad_ws/build/imu && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/imu.dir/src/imu.cpp.o -c /home/odroid/quad_ws/src/imu/src/imu.cpp

imu/CMakeFiles/imu.dir/src/imu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/imu.dir/src/imu.cpp.i"
	cd /home/odroid/quad_ws/build/imu && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/odroid/quad_ws/src/imu/src/imu.cpp > CMakeFiles/imu.dir/src/imu.cpp.i

imu/CMakeFiles/imu.dir/src/imu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/imu.dir/src/imu.cpp.s"
	cd /home/odroid/quad_ws/build/imu && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/odroid/quad_ws/src/imu/src/imu.cpp -o CMakeFiles/imu.dir/src/imu.cpp.s

imu/CMakeFiles/imu.dir/src/imu.cpp.o.requires:
.PHONY : imu/CMakeFiles/imu.dir/src/imu.cpp.o.requires

imu/CMakeFiles/imu.dir/src/imu.cpp.o.provides: imu/CMakeFiles/imu.dir/src/imu.cpp.o.requires
	$(MAKE) -f imu/CMakeFiles/imu.dir/build.make imu/CMakeFiles/imu.dir/src/imu.cpp.o.provides.build
.PHONY : imu/CMakeFiles/imu.dir/src/imu.cpp.o.provides

imu/CMakeFiles/imu.dir/src/imu.cpp.o.provides.build: imu/CMakeFiles/imu.dir/src/imu.cpp.o

imu/CMakeFiles/imu.dir/src/utility.cpp.o: imu/CMakeFiles/imu.dir/flags.make
imu/CMakeFiles/imu.dir/src/utility.cpp.o: /home/odroid/quad_ws/src/imu/src/utility.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/odroid/quad_ws/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object imu/CMakeFiles/imu.dir/src/utility.cpp.o"
	cd /home/odroid/quad_ws/build/imu && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/imu.dir/src/utility.cpp.o -c /home/odroid/quad_ws/src/imu/src/utility.cpp

imu/CMakeFiles/imu.dir/src/utility.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/imu.dir/src/utility.cpp.i"
	cd /home/odroid/quad_ws/build/imu && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/odroid/quad_ws/src/imu/src/utility.cpp > CMakeFiles/imu.dir/src/utility.cpp.i

imu/CMakeFiles/imu.dir/src/utility.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/imu.dir/src/utility.cpp.s"
	cd /home/odroid/quad_ws/build/imu && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/odroid/quad_ws/src/imu/src/utility.cpp -o CMakeFiles/imu.dir/src/utility.cpp.s

imu/CMakeFiles/imu.dir/src/utility.cpp.o.requires:
.PHONY : imu/CMakeFiles/imu.dir/src/utility.cpp.o.requires

imu/CMakeFiles/imu.dir/src/utility.cpp.o.provides: imu/CMakeFiles/imu.dir/src/utility.cpp.o.requires
	$(MAKE) -f imu/CMakeFiles/imu.dir/build.make imu/CMakeFiles/imu.dir/src/utility.cpp.o.provides.build
.PHONY : imu/CMakeFiles/imu.dir/src/utility.cpp.o.provides

imu/CMakeFiles/imu.dir/src/utility.cpp.o.provides.build: imu/CMakeFiles/imu.dir/src/utility.cpp.o

# Object files for target imu
imu_OBJECTS = \
"CMakeFiles/imu.dir/src/imu.cpp.o" \
"CMakeFiles/imu.dir/src/utility.cpp.o"

# External object files for target imu
imu_EXTERNAL_OBJECTS =

/home/odroid/quad_ws/devel/lib/imu/imu: imu/CMakeFiles/imu.dir/src/imu.cpp.o
/home/odroid/quad_ws/devel/lib/imu/imu: imu/CMakeFiles/imu.dir/src/utility.cpp.o
/home/odroid/quad_ws/devel/lib/imu/imu: imu/CMakeFiles/imu.dir/build.make
/home/odroid/quad_ws/devel/lib/imu/imu: /opt/ros/indigo/lib/libroscpp.so
/home/odroid/quad_ws/devel/lib/imu/imu: /usr/lib/arm-linux-gnueabihf/libboost_signals.so
/home/odroid/quad_ws/devel/lib/imu/imu: /usr/lib/arm-linux-gnueabihf/libboost_filesystem.so
/home/odroid/quad_ws/devel/lib/imu/imu: /opt/ros/indigo/lib/librosconsole.so
/home/odroid/quad_ws/devel/lib/imu/imu: /opt/ros/indigo/lib/librosconsole_log4cxx.so
/home/odroid/quad_ws/devel/lib/imu/imu: /opt/ros/indigo/lib/librosconsole_backend_interface.so
/home/odroid/quad_ws/devel/lib/imu/imu: /usr/lib/liblog4cxx.so
/home/odroid/quad_ws/devel/lib/imu/imu: /usr/lib/arm-linux-gnueabihf/libboost_regex.so
/home/odroid/quad_ws/devel/lib/imu/imu: /opt/ros/indigo/lib/libxmlrpcpp.so
/home/odroid/quad_ws/devel/lib/imu/imu: /opt/ros/indigo/lib/libroscpp_serialization.so
/home/odroid/quad_ws/devel/lib/imu/imu: /opt/ros/indigo/lib/librostime.so
/home/odroid/quad_ws/devel/lib/imu/imu: /usr/lib/arm-linux-gnueabihf/libboost_date_time.so
/home/odroid/quad_ws/devel/lib/imu/imu: /opt/ros/indigo/lib/libcpp_common.so
/home/odroid/quad_ws/devel/lib/imu/imu: /usr/lib/arm-linux-gnueabihf/libboost_system.so
/home/odroid/quad_ws/devel/lib/imu/imu: /usr/lib/arm-linux-gnueabihf/libboost_thread.so
/home/odroid/quad_ws/devel/lib/imu/imu: /usr/lib/arm-linux-gnueabihf/libpthread.so
/home/odroid/quad_ws/devel/lib/imu/imu: /usr/lib/arm-linux-gnueabihf/libconsole_bridge.so
/home/odroid/quad_ws/devel/lib/imu/imu: imu/CMakeFiles/imu.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable /home/odroid/quad_ws/devel/lib/imu/imu"
	cd /home/odroid/quad_ws/build/imu && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/imu.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
imu/CMakeFiles/imu.dir/build: /home/odroid/quad_ws/devel/lib/imu/imu
.PHONY : imu/CMakeFiles/imu.dir/build

imu/CMakeFiles/imu.dir/requires: imu/CMakeFiles/imu.dir/src/imu.cpp.o.requires
imu/CMakeFiles/imu.dir/requires: imu/CMakeFiles/imu.dir/src/utility.cpp.o.requires
.PHONY : imu/CMakeFiles/imu.dir/requires

imu/CMakeFiles/imu.dir/clean:
	cd /home/odroid/quad_ws/build/imu && $(CMAKE_COMMAND) -P CMakeFiles/imu.dir/cmake_clean.cmake
.PHONY : imu/CMakeFiles/imu.dir/clean

imu/CMakeFiles/imu.dir/depend:
	cd /home/odroid/quad_ws/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/odroid/quad_ws/src /home/odroid/quad_ws/src/imu /home/odroid/quad_ws/build /home/odroid/quad_ws/build/imu /home/odroid/quad_ws/build/imu/CMakeFiles/imu.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : imu/CMakeFiles/imu.dir/depend
