# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = /cygdrive/c/Users/17723/.CLion2017.1/system/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/17723/.CLion2017.1/system/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/c/Users/17723/Desktop/GitHub/IPC

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/17723/Desktop/GitHub/IPC/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/29shm_read.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/29shm_read.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/29shm_read.dir/flags.make

CMakeFiles/29shm_read.dir/29shm_read.cpp.o: CMakeFiles/29shm_read.dir/flags.make
CMakeFiles/29shm_read.dir/29shm_read.cpp.o: ../29shm_read.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/17723/Desktop/GitHub/IPC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/29shm_read.dir/29shm_read.cpp.o"
	/usr/bin/c++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/29shm_read.dir/29shm_read.cpp.o -c /cygdrive/c/Users/17723/Desktop/GitHub/IPC/29shm_read.cpp

CMakeFiles/29shm_read.dir/29shm_read.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/29shm_read.dir/29shm_read.cpp.i"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/17723/Desktop/GitHub/IPC/29shm_read.cpp > CMakeFiles/29shm_read.dir/29shm_read.cpp.i

CMakeFiles/29shm_read.dir/29shm_read.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/29shm_read.dir/29shm_read.cpp.s"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/17723/Desktop/GitHub/IPC/29shm_read.cpp -o CMakeFiles/29shm_read.dir/29shm_read.cpp.s

CMakeFiles/29shm_read.dir/29shm_read.cpp.o.requires:

.PHONY : CMakeFiles/29shm_read.dir/29shm_read.cpp.o.requires

CMakeFiles/29shm_read.dir/29shm_read.cpp.o.provides: CMakeFiles/29shm_read.dir/29shm_read.cpp.o.requires
	$(MAKE) -f CMakeFiles/29shm_read.dir/build.make CMakeFiles/29shm_read.dir/29shm_read.cpp.o.provides.build
.PHONY : CMakeFiles/29shm_read.dir/29shm_read.cpp.o.provides

CMakeFiles/29shm_read.dir/29shm_read.cpp.o.provides.build: CMakeFiles/29shm_read.dir/29shm_read.cpp.o


# Object files for target 29shm_read
29shm_read_OBJECTS = \
"CMakeFiles/29shm_read.dir/29shm_read.cpp.o"

# External object files for target 29shm_read
29shm_read_EXTERNAL_OBJECTS =

29shm_read.exe: CMakeFiles/29shm_read.dir/29shm_read.cpp.o
29shm_read.exe: CMakeFiles/29shm_read.dir/build.make
29shm_read.exe: CMakeFiles/29shm_read.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/17723/Desktop/GitHub/IPC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 29shm_read.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/29shm_read.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/29shm_read.dir/build: 29shm_read.exe

.PHONY : CMakeFiles/29shm_read.dir/build

CMakeFiles/29shm_read.dir/requires: CMakeFiles/29shm_read.dir/29shm_read.cpp.o.requires

.PHONY : CMakeFiles/29shm_read.dir/requires

CMakeFiles/29shm_read.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/29shm_read.dir/cmake_clean.cmake
.PHONY : CMakeFiles/29shm_read.dir/clean

CMakeFiles/29shm_read.dir/depend:
	cd /cygdrive/c/Users/17723/Desktop/GitHub/IPC/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/17723/Desktop/GitHub/IPC /cygdrive/c/Users/17723/Desktop/GitHub/IPC /cygdrive/c/Users/17723/Desktop/GitHub/IPC/cmake-build-debug /cygdrive/c/Users/17723/Desktop/GitHub/IPC/cmake-build-debug /cygdrive/c/Users/17723/Desktop/GitHub/IPC/cmake-build-debug/CMakeFiles/29shm_read.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/29shm_read.dir/depend
