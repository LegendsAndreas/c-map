# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.29

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\andre\AppData\Local\Programs\CLion\bin\cmake\win\x64\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\andre\AppData\Local\Programs\CLion\bin\cmake\win\x64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\andre\Desktop\c_map\c_map

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\andre\Desktop\c_map\c_map\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/c_map.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/c_map.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/c_map.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/c_map.dir/flags.make

CMakeFiles/c_map.dir/main.c.obj: CMakeFiles/c_map.dir/flags.make
CMakeFiles/c_map.dir/main.c.obj: C:/Users/andre/Desktop/c_map/c_map/main.c
CMakeFiles/c_map.dir/main.c.obj: CMakeFiles/c_map.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\andre\Desktop\c_map\c_map\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/c_map.dir/main.c.obj"
	C:\Users\andre\AppData\Local\Programs\CLion\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/c_map.dir/main.c.obj -MF CMakeFiles\c_map.dir\main.c.obj.d -o CMakeFiles\c_map.dir\main.c.obj -c C:\Users\andre\Desktop\c_map\c_map\main.c

CMakeFiles/c_map.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/c_map.dir/main.c.i"
	C:\Users\andre\AppData\Local\Programs\CLion\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\andre\Desktop\c_map\c_map\main.c > CMakeFiles\c_map.dir\main.c.i

CMakeFiles/c_map.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/c_map.dir/main.c.s"
	C:\Users\andre\AppData\Local\Programs\CLion\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\andre\Desktop\c_map\c_map\main.c -o CMakeFiles\c_map.dir\main.c.s

# Object files for target c_map
c_map_OBJECTS = \
"CMakeFiles/c_map.dir/main.c.obj"

# External object files for target c_map
c_map_EXTERNAL_OBJECTS =

c_map.exe: CMakeFiles/c_map.dir/main.c.obj
c_map.exe: CMakeFiles/c_map.dir/build.make
c_map.exe: CMakeFiles/c_map.dir/linkLibs.rsp
c_map.exe: CMakeFiles/c_map.dir/objects1.rsp
c_map.exe: CMakeFiles/c_map.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\andre\Desktop\c_map\c_map\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable c_map.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\c_map.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/c_map.dir/build: c_map.exe
.PHONY : CMakeFiles/c_map.dir/build

CMakeFiles/c_map.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\c_map.dir\cmake_clean.cmake
.PHONY : CMakeFiles/c_map.dir/clean

CMakeFiles/c_map.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\andre\Desktop\c_map\c_map C:\Users\andre\Desktop\c_map\c_map C:\Users\andre\Desktop\c_map\c_map\cmake-build-debug C:\Users\andre\Desktop\c_map\c_map\cmake-build-debug C:\Users\andre\Desktop\c_map\c_map\cmake-build-debug\CMakeFiles\c_map.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/c_map.dir/depend

