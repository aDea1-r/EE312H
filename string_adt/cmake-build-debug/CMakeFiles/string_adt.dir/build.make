# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /cygdrive/c/Users/adeel/.CLion2019.3/system/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/adeel/.CLion2019.3/system/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/cygdrive/c/Users/adeel/CLionProjects/EE 312H Labs/string_adt"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/cygdrive/c/Users/adeel/CLionProjects/EE 312H Labs/string_adt/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/string_adt.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/string_adt.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/string_adt.dir/flags.make

CMakeFiles/string_adt.dir/main.cpp.o: CMakeFiles/string_adt.dir/flags.make
CMakeFiles/string_adt.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/cygdrive/c/Users/adeel/CLionProjects/EE 312H Labs/string_adt/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/string_adt.dir/main.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/string_adt.dir/main.cpp.o -c "/cygdrive/c/Users/adeel/CLionProjects/EE 312H Labs/string_adt/main.cpp"

CMakeFiles/string_adt.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/string_adt.dir/main.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/cygdrive/c/Users/adeel/CLionProjects/EE 312H Labs/string_adt/main.cpp" > CMakeFiles/string_adt.dir/main.cpp.i

CMakeFiles/string_adt.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/string_adt.dir/main.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/cygdrive/c/Users/adeel/CLionProjects/EE 312H Labs/string_adt/main.cpp" -o CMakeFiles/string_adt.dir/main.cpp.s

CMakeFiles/string_adt.dir/Project3.cpp.o: CMakeFiles/string_adt.dir/flags.make
CMakeFiles/string_adt.dir/Project3.cpp.o: ../Project3.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/cygdrive/c/Users/adeel/CLionProjects/EE 312H Labs/string_adt/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/string_adt.dir/Project3.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/string_adt.dir/Project3.cpp.o -c "/cygdrive/c/Users/adeel/CLionProjects/EE 312H Labs/string_adt/Project3.cpp"

CMakeFiles/string_adt.dir/Project3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/string_adt.dir/Project3.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/cygdrive/c/Users/adeel/CLionProjects/EE 312H Labs/string_adt/Project3.cpp" > CMakeFiles/string_adt.dir/Project3.cpp.i

CMakeFiles/string_adt.dir/Project3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/string_adt.dir/Project3.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/cygdrive/c/Users/adeel/CLionProjects/EE 312H Labs/string_adt/Project3.cpp" -o CMakeFiles/string_adt.dir/Project3.cpp.s

# Object files for target string_adt
string_adt_OBJECTS = \
"CMakeFiles/string_adt.dir/main.cpp.o" \
"CMakeFiles/string_adt.dir/Project3.cpp.o"

# External object files for target string_adt
string_adt_EXTERNAL_OBJECTS =

string_adt.exe: CMakeFiles/string_adt.dir/main.cpp.o
string_adt.exe: CMakeFiles/string_adt.dir/Project3.cpp.o
string_adt.exe: CMakeFiles/string_adt.dir/build.make
string_adt.exe: CMakeFiles/string_adt.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/cygdrive/c/Users/adeel/CLionProjects/EE 312H Labs/string_adt/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable string_adt.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/string_adt.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/string_adt.dir/build: string_adt.exe

.PHONY : CMakeFiles/string_adt.dir/build

CMakeFiles/string_adt.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/string_adt.dir/cmake_clean.cmake
.PHONY : CMakeFiles/string_adt.dir/clean

CMakeFiles/string_adt.dir/depend:
	cd "/cygdrive/c/Users/adeel/CLionProjects/EE 312H Labs/string_adt/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/cygdrive/c/Users/adeel/CLionProjects/EE 312H Labs/string_adt" "/cygdrive/c/Users/adeel/CLionProjects/EE 312H Labs/string_adt" "/cygdrive/c/Users/adeel/CLionProjects/EE 312H Labs/string_adt/cmake-build-debug" "/cygdrive/c/Users/adeel/CLionProjects/EE 312H Labs/string_adt/cmake-build-debug" "/cygdrive/c/Users/adeel/CLionProjects/EE 312H Labs/string_adt/cmake-build-debug/CMakeFiles/string_adt.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/string_adt.dir/depend
