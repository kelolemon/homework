# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /Users/kelo/kelo/cpp_project/Computer_Network_task1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/kelo/kelo/cpp_project/Computer_Network_task1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Computer_Network_task1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Computer_Network_task1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Computer_Network_task1.dir/flags.make

CMakeFiles/Computer_Network_task1.dir/TCP_client.cpp.o: CMakeFiles/Computer_Network_task1.dir/flags.make
CMakeFiles/Computer_Network_task1.dir/TCP_client.cpp.o: ../TCP_client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kelo/kelo/cpp_project/Computer_Network_task1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Computer_Network_task1.dir/TCP_client.cpp.o"
	/usr/local/Cellar/gcc/9.3.0_1/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Computer_Network_task1.dir/TCP_client.cpp.o -c /Users/kelo/kelo/cpp_project/Computer_Network_task1/TCP_client.cpp

CMakeFiles/Computer_Network_task1.dir/TCP_client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Computer_Network_task1.dir/TCP_client.cpp.i"
	/usr/local/Cellar/gcc/9.3.0_1/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kelo/kelo/cpp_project/Computer_Network_task1/TCP_client.cpp > CMakeFiles/Computer_Network_task1.dir/TCP_client.cpp.i

CMakeFiles/Computer_Network_task1.dir/TCP_client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Computer_Network_task1.dir/TCP_client.cpp.s"
	/usr/local/Cellar/gcc/9.3.0_1/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kelo/kelo/cpp_project/Computer_Network_task1/TCP_client.cpp -o CMakeFiles/Computer_Network_task1.dir/TCP_client.cpp.s

CMakeFiles/Computer_Network_task1.dir/TCP_server.cpp.o: CMakeFiles/Computer_Network_task1.dir/flags.make
CMakeFiles/Computer_Network_task1.dir/TCP_server.cpp.o: ../TCP_server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kelo/kelo/cpp_project/Computer_Network_task1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Computer_Network_task1.dir/TCP_server.cpp.o"
	/usr/local/Cellar/gcc/9.3.0_1/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Computer_Network_task1.dir/TCP_server.cpp.o -c /Users/kelo/kelo/cpp_project/Computer_Network_task1/TCP_server.cpp

CMakeFiles/Computer_Network_task1.dir/TCP_server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Computer_Network_task1.dir/TCP_server.cpp.i"
	/usr/local/Cellar/gcc/9.3.0_1/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kelo/kelo/cpp_project/Computer_Network_task1/TCP_server.cpp > CMakeFiles/Computer_Network_task1.dir/TCP_server.cpp.i

CMakeFiles/Computer_Network_task1.dir/TCP_server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Computer_Network_task1.dir/TCP_server.cpp.s"
	/usr/local/Cellar/gcc/9.3.0_1/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kelo/kelo/cpp_project/Computer_Network_task1/TCP_server.cpp -o CMakeFiles/Computer_Network_task1.dir/TCP_server.cpp.s

CMakeFiles/Computer_Network_task1.dir/UDP_server.cpp.o: CMakeFiles/Computer_Network_task1.dir/flags.make
CMakeFiles/Computer_Network_task1.dir/UDP_server.cpp.o: ../UDP_server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kelo/kelo/cpp_project/Computer_Network_task1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Computer_Network_task1.dir/UDP_server.cpp.o"
	/usr/local/Cellar/gcc/9.3.0_1/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Computer_Network_task1.dir/UDP_server.cpp.o -c /Users/kelo/kelo/cpp_project/Computer_Network_task1/UDP_server.cpp

CMakeFiles/Computer_Network_task1.dir/UDP_server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Computer_Network_task1.dir/UDP_server.cpp.i"
	/usr/local/Cellar/gcc/9.3.0_1/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kelo/kelo/cpp_project/Computer_Network_task1/UDP_server.cpp > CMakeFiles/Computer_Network_task1.dir/UDP_server.cpp.i

CMakeFiles/Computer_Network_task1.dir/UDP_server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Computer_Network_task1.dir/UDP_server.cpp.s"
	/usr/local/Cellar/gcc/9.3.0_1/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kelo/kelo/cpp_project/Computer_Network_task1/UDP_server.cpp -o CMakeFiles/Computer_Network_task1.dir/UDP_server.cpp.s

# Object files for target Computer_Network_task1
Computer_Network_task1_OBJECTS = \
"CMakeFiles/Computer_Network_task1.dir/TCP_client.cpp.o" \
"CMakeFiles/Computer_Network_task1.dir/TCP_server.cpp.o" \
"CMakeFiles/Computer_Network_task1.dir/UDP_server.cpp.o"

# External object files for target Computer_Network_task1
Computer_Network_task1_EXTERNAL_OBJECTS =

Computer_Network_task1: CMakeFiles/Computer_Network_task1.dir/TCP_client.cpp.o
Computer_Network_task1: CMakeFiles/Computer_Network_task1.dir/TCP_server.cpp.o
Computer_Network_task1: CMakeFiles/Computer_Network_task1.dir/UDP_server.cpp.o
Computer_Network_task1: CMakeFiles/Computer_Network_task1.dir/build.make
Computer_Network_task1: CMakeFiles/Computer_Network_task1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/kelo/kelo/cpp_project/Computer_Network_task1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable Computer_Network_task1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Computer_Network_task1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Computer_Network_task1.dir/build: Computer_Network_task1

.PHONY : CMakeFiles/Computer_Network_task1.dir/build

CMakeFiles/Computer_Network_task1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Computer_Network_task1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Computer_Network_task1.dir/clean

CMakeFiles/Computer_Network_task1.dir/depend:
	cd /Users/kelo/kelo/cpp_project/Computer_Network_task1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/kelo/kelo/cpp_project/Computer_Network_task1 /Users/kelo/kelo/cpp_project/Computer_Network_task1 /Users/kelo/kelo/cpp_project/Computer_Network_task1/cmake-build-debug /Users/kelo/kelo/cpp_project/Computer_Network_task1/cmake-build-debug /Users/kelo/kelo/cpp_project/Computer_Network_task1/cmake-build-debug/CMakeFiles/Computer_Network_task1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Computer_Network_task1.dir/depend

