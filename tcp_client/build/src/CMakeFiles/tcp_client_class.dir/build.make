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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tomasz/Projects/Embedded_Projects/embedded_projects/tcp_client

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tomasz/Projects/Embedded_Projects/embedded_projects/tcp_client/build

# Include any dependencies generated for this target.
include src/CMakeFiles/tcp_client_class.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/tcp_client_class.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/tcp_client_class.dir/flags.make

src/CMakeFiles/tcp_client_class.dir/tcp_client.cpp.o: src/CMakeFiles/tcp_client_class.dir/flags.make
src/CMakeFiles/tcp_client_class.dir/tcp_client.cpp.o: ../src/tcp_client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tomasz/Projects/Embedded_Projects/embedded_projects/tcp_client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/tcp_client_class.dir/tcp_client.cpp.o"
	cd /home/tomasz/Projects/Embedded_Projects/embedded_projects/tcp_client/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tcp_client_class.dir/tcp_client.cpp.o -c /home/tomasz/Projects/Embedded_Projects/embedded_projects/tcp_client/src/tcp_client.cpp

src/CMakeFiles/tcp_client_class.dir/tcp_client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tcp_client_class.dir/tcp_client.cpp.i"
	cd /home/tomasz/Projects/Embedded_Projects/embedded_projects/tcp_client/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tomasz/Projects/Embedded_Projects/embedded_projects/tcp_client/src/tcp_client.cpp > CMakeFiles/tcp_client_class.dir/tcp_client.cpp.i

src/CMakeFiles/tcp_client_class.dir/tcp_client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tcp_client_class.dir/tcp_client.cpp.s"
	cd /home/tomasz/Projects/Embedded_Projects/embedded_projects/tcp_client/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tomasz/Projects/Embedded_Projects/embedded_projects/tcp_client/src/tcp_client.cpp -o CMakeFiles/tcp_client_class.dir/tcp_client.cpp.s

# Object files for target tcp_client_class
tcp_client_class_OBJECTS = \
"CMakeFiles/tcp_client_class.dir/tcp_client.cpp.o"

# External object files for target tcp_client_class
tcp_client_class_EXTERNAL_OBJECTS =

src/libtcp_client_class.so: src/CMakeFiles/tcp_client_class.dir/tcp_client.cpp.o
src/libtcp_client_class.so: src/CMakeFiles/tcp_client_class.dir/build.make
src/libtcp_client_class.so: src/CMakeFiles/tcp_client_class.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tomasz/Projects/Embedded_Projects/embedded_projects/tcp_client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libtcp_client_class.so"
	cd /home/tomasz/Projects/Embedded_Projects/embedded_projects/tcp_client/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tcp_client_class.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/tcp_client_class.dir/build: src/libtcp_client_class.so

.PHONY : src/CMakeFiles/tcp_client_class.dir/build

src/CMakeFiles/tcp_client_class.dir/clean:
	cd /home/tomasz/Projects/Embedded_Projects/embedded_projects/tcp_client/build/src && $(CMAKE_COMMAND) -P CMakeFiles/tcp_client_class.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/tcp_client_class.dir/clean

src/CMakeFiles/tcp_client_class.dir/depend:
	cd /home/tomasz/Projects/Embedded_Projects/embedded_projects/tcp_client/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tomasz/Projects/Embedded_Projects/embedded_projects/tcp_client /home/tomasz/Projects/Embedded_Projects/embedded_projects/tcp_client/src /home/tomasz/Projects/Embedded_Projects/embedded_projects/tcp_client/build /home/tomasz/Projects/Embedded_Projects/embedded_projects/tcp_client/build/src /home/tomasz/Projects/Embedded_Projects/embedded_projects/tcp_client/build/src/CMakeFiles/tcp_client_class.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/tcp_client_class.dir/depend

