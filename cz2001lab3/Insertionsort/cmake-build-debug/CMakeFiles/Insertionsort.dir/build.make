# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.8

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2017.2.1\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2017.2.1\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Ben\Documents\GitHub\cz2001lab3\Insertionsort

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Ben\Documents\GitHub\cz2001lab3\Insertionsort\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Insertionsort.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Insertionsort.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Insertionsort.dir/flags.make

CMakeFiles/Insertionsort.dir/main.cpp.obj: CMakeFiles/Insertionsort.dir/flags.make
CMakeFiles/Insertionsort.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Ben\Documents\GitHub\cz2001lab3\Insertionsort\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Insertionsort.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Insertionsort.dir\main.cpp.obj -c C:\Users\Ben\Documents\GitHub\cz2001lab3\Insertionsort\main.cpp

CMakeFiles/Insertionsort.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Insertionsort.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Ben\Documents\GitHub\cz2001lab3\Insertionsort\main.cpp > CMakeFiles\Insertionsort.dir\main.cpp.i

CMakeFiles/Insertionsort.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Insertionsort.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Ben\Documents\GitHub\cz2001lab3\Insertionsort\main.cpp -o CMakeFiles\Insertionsort.dir\main.cpp.s

CMakeFiles/Insertionsort.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/Insertionsort.dir/main.cpp.obj.requires

CMakeFiles/Insertionsort.dir/main.cpp.obj.provides: CMakeFiles/Insertionsort.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Insertionsort.dir\build.make CMakeFiles/Insertionsort.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/Insertionsort.dir/main.cpp.obj.provides

CMakeFiles/Insertionsort.dir/main.cpp.obj.provides.build: CMakeFiles/Insertionsort.dir/main.cpp.obj


# Object files for target Insertionsort
Insertionsort_OBJECTS = \
"CMakeFiles/Insertionsort.dir/main.cpp.obj"

# External object files for target Insertionsort
Insertionsort_EXTERNAL_OBJECTS =

Insertionsort.exe: CMakeFiles/Insertionsort.dir/main.cpp.obj
Insertionsort.exe: CMakeFiles/Insertionsort.dir/build.make
Insertionsort.exe: CMakeFiles/Insertionsort.dir/linklibs.rsp
Insertionsort.exe: CMakeFiles/Insertionsort.dir/objects1.rsp
Insertionsort.exe: CMakeFiles/Insertionsort.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Ben\Documents\GitHub\cz2001lab3\Insertionsort\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Insertionsort.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Insertionsort.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Insertionsort.dir/build: Insertionsort.exe

.PHONY : CMakeFiles/Insertionsort.dir/build

CMakeFiles/Insertionsort.dir/requires: CMakeFiles/Insertionsort.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/Insertionsort.dir/requires

CMakeFiles/Insertionsort.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Insertionsort.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Insertionsort.dir/clean

CMakeFiles/Insertionsort.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Ben\Documents\GitHub\cz2001lab3\Insertionsort C:\Users\Ben\Documents\GitHub\cz2001lab3\Insertionsort C:\Users\Ben\Documents\GitHub\cz2001lab3\Insertionsort\cmake-build-debug C:\Users\Ben\Documents\GitHub\cz2001lab3\Insertionsort\cmake-build-debug C:\Users\Ben\Documents\GitHub\cz2001lab3\Insertionsort\cmake-build-debug\CMakeFiles\Insertionsort.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Insertionsort.dir/depend
