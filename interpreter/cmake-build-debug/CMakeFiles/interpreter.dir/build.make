# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.3.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.3.3\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\adeel\CLionProjects\EE312H\interpreter

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\adeel\CLionProjects\EE312H\interpreter\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/interpreter.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/interpreter.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/interpreter.dir/flags.make

CMakeFiles/interpreter.dir/Input.cpp.obj: CMakeFiles/interpreter.dir/flags.make
CMakeFiles/interpreter.dir/Input.cpp.obj: CMakeFiles/interpreter.dir/includes_CXX.rsp
CMakeFiles/interpreter.dir/Input.cpp.obj: ../Input.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\adeel\CLionProjects\EE312H\interpreter\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/interpreter.dir/Input.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\interpreter.dir\Input.cpp.obj -c C:\Users\adeel\CLionProjects\EE312H\interpreter\Input.cpp

CMakeFiles/interpreter.dir/Input.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/interpreter.dir/Input.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\adeel\CLionProjects\EE312H\interpreter\Input.cpp > CMakeFiles\interpreter.dir\Input.cpp.i

CMakeFiles/interpreter.dir/Input.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/interpreter.dir/Input.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\adeel\CLionProjects\EE312H\interpreter\Input.cpp -o CMakeFiles\interpreter.dir\Input.cpp.s

CMakeFiles/interpreter.dir/Interpret.cpp.obj: CMakeFiles/interpreter.dir/flags.make
CMakeFiles/interpreter.dir/Interpret.cpp.obj: CMakeFiles/interpreter.dir/includes_CXX.rsp
CMakeFiles/interpreter.dir/Interpret.cpp.obj: ../Interpret.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\adeel\CLionProjects\EE312H\interpreter\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/interpreter.dir/Interpret.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\interpreter.dir\Interpret.cpp.obj -c C:\Users\adeel\CLionProjects\EE312H\interpreter\Interpret.cpp

CMakeFiles/interpreter.dir/Interpret.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/interpreter.dir/Interpret.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\adeel\CLionProjects\EE312H\interpreter\Interpret.cpp > CMakeFiles\interpreter.dir\Interpret.cpp.i

CMakeFiles/interpreter.dir/Interpret.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/interpreter.dir/Interpret.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\adeel\CLionProjects\EE312H\interpreter\Interpret.cpp -o CMakeFiles\interpreter.dir\Interpret.cpp.s

CMakeFiles/interpreter.dir/exptree.cpp.obj: CMakeFiles/interpreter.dir/flags.make
CMakeFiles/interpreter.dir/exptree.cpp.obj: CMakeFiles/interpreter.dir/includes_CXX.rsp
CMakeFiles/interpreter.dir/exptree.cpp.obj: ../exptree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\adeel\CLionProjects\EE312H\interpreter\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/interpreter.dir/exptree.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\interpreter.dir\exptree.cpp.obj -c C:\Users\adeel\CLionProjects\EE312H\interpreter\exptree.cpp

CMakeFiles/interpreter.dir/exptree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/interpreter.dir/exptree.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\adeel\CLionProjects\EE312H\interpreter\exptree.cpp > CMakeFiles\interpreter.dir\exptree.cpp.i

CMakeFiles/interpreter.dir/exptree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/interpreter.dir/exptree.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\adeel\CLionProjects\EE312H\interpreter\exptree.cpp -o CMakeFiles\interpreter.dir\exptree.cpp.s

# Object files for target interpreter
interpreter_OBJECTS = \
"CMakeFiles/interpreter.dir/Input.cpp.obj" \
"CMakeFiles/interpreter.dir/Interpret.cpp.obj" \
"CMakeFiles/interpreter.dir/exptree.cpp.obj"

# External object files for target interpreter
interpreter_EXTERNAL_OBJECTS =

interpreter.exe: CMakeFiles/interpreter.dir/Input.cpp.obj
interpreter.exe: CMakeFiles/interpreter.dir/Interpret.cpp.obj
interpreter.exe: CMakeFiles/interpreter.dir/exptree.cpp.obj
interpreter.exe: CMakeFiles/interpreter.dir/build.make
interpreter.exe: CMakeFiles/interpreter.dir/linklibs.rsp
interpreter.exe: CMakeFiles/interpreter.dir/objects1.rsp
interpreter.exe: CMakeFiles/interpreter.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\adeel\CLionProjects\EE312H\interpreter\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable interpreter.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\interpreter.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/interpreter.dir/build: interpreter.exe

.PHONY : CMakeFiles/interpreter.dir/build

CMakeFiles/interpreter.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\interpreter.dir\cmake_clean.cmake
.PHONY : CMakeFiles/interpreter.dir/clean

CMakeFiles/interpreter.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\adeel\CLionProjects\EE312H\interpreter C:\Users\adeel\CLionProjects\EE312H\interpreter C:\Users\adeel\CLionProjects\EE312H\interpreter\cmake-build-debug C:\Users\adeel\CLionProjects\EE312H\interpreter\cmake-build-debug C:\Users\adeel\CLionProjects\EE312H\interpreter\cmake-build-debug\CMakeFiles\interpreter.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/interpreter.dir/depend
