# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\User\Desktop\Uni\Year 1\OOP\Git\Project"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\User\Desktop\Uni\Year 1\OOP\Git\Project\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/StringNumber_Tests.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/StringNumber_Tests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/StringNumber_Tests.dir/flags.make

CMakeFiles/StringNumber_Tests.dir/StringNumber/Tests/StringNumber_Tests.cpp.obj: CMakeFiles/StringNumber_Tests.dir/flags.make
CMakeFiles/StringNumber_Tests.dir/StringNumber/Tests/StringNumber_Tests.cpp.obj: CMakeFiles/StringNumber_Tests.dir/includes_CXX.rsp
CMakeFiles/StringNumber_Tests.dir/StringNumber/Tests/StringNumber_Tests.cpp.obj: ../StringNumber/Tests/StringNumber_Tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\User\Desktop\Uni\Year 1\OOP\Git\Project\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/StringNumber_Tests.dir/StringNumber/Tests/StringNumber_Tests.cpp.obj"
	C:\ProgramData\chocolatey\lib\mingw\tools\install\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\StringNumber_Tests.dir\StringNumber\Tests\StringNumber_Tests.cpp.obj -c "C:\Users\User\Desktop\Uni\Year 1\OOP\Git\Project\StringNumber\Tests\StringNumber_Tests.cpp"

CMakeFiles/StringNumber_Tests.dir/StringNumber/Tests/StringNumber_Tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/StringNumber_Tests.dir/StringNumber/Tests/StringNumber_Tests.cpp.i"
	C:\ProgramData\chocolatey\lib\mingw\tools\install\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\User\Desktop\Uni\Year 1\OOP\Git\Project\StringNumber\Tests\StringNumber_Tests.cpp" > CMakeFiles\StringNumber_Tests.dir\StringNumber\Tests\StringNumber_Tests.cpp.i

CMakeFiles/StringNumber_Tests.dir/StringNumber/Tests/StringNumber_Tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/StringNumber_Tests.dir/StringNumber/Tests/StringNumber_Tests.cpp.s"
	C:\ProgramData\chocolatey\lib\mingw\tools\install\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\User\Desktop\Uni\Year 1\OOP\Git\Project\StringNumber\Tests\StringNumber_Tests.cpp" -o CMakeFiles\StringNumber_Tests.dir\StringNumber\Tests\StringNumber_Tests.cpp.s

CMakeFiles/StringNumber_Tests.dir/StringNumber/StringNumber.cpp.obj: CMakeFiles/StringNumber_Tests.dir/flags.make
CMakeFiles/StringNumber_Tests.dir/StringNumber/StringNumber.cpp.obj: CMakeFiles/StringNumber_Tests.dir/includes_CXX.rsp
CMakeFiles/StringNumber_Tests.dir/StringNumber/StringNumber.cpp.obj: ../StringNumber/StringNumber.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\User\Desktop\Uni\Year 1\OOP\Git\Project\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/StringNumber_Tests.dir/StringNumber/StringNumber.cpp.obj"
	C:\ProgramData\chocolatey\lib\mingw\tools\install\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\StringNumber_Tests.dir\StringNumber\StringNumber.cpp.obj -c "C:\Users\User\Desktop\Uni\Year 1\OOP\Git\Project\StringNumber\StringNumber.cpp"

CMakeFiles/StringNumber_Tests.dir/StringNumber/StringNumber.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/StringNumber_Tests.dir/StringNumber/StringNumber.cpp.i"
	C:\ProgramData\chocolatey\lib\mingw\tools\install\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\User\Desktop\Uni\Year 1\OOP\Git\Project\StringNumber\StringNumber.cpp" > CMakeFiles\StringNumber_Tests.dir\StringNumber\StringNumber.cpp.i

CMakeFiles/StringNumber_Tests.dir/StringNumber/StringNumber.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/StringNumber_Tests.dir/StringNumber/StringNumber.cpp.s"
	C:\ProgramData\chocolatey\lib\mingw\tools\install\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\User\Desktop\Uni\Year 1\OOP\Git\Project\StringNumber\StringNumber.cpp" -o CMakeFiles\StringNumber_Tests.dir\StringNumber\StringNumber.cpp.s

# Object files for target StringNumber_Tests
StringNumber_Tests_OBJECTS = \
"CMakeFiles/StringNumber_Tests.dir/StringNumber/Tests/StringNumber_Tests.cpp.obj" \
"CMakeFiles/StringNumber_Tests.dir/StringNumber/StringNumber.cpp.obj"

# External object files for target StringNumber_Tests
StringNumber_Tests_EXTERNAL_OBJECTS =

StringNumber_Tests.exe: CMakeFiles/StringNumber_Tests.dir/StringNumber/Tests/StringNumber_Tests.cpp.obj
StringNumber_Tests.exe: CMakeFiles/StringNumber_Tests.dir/StringNumber/StringNumber.cpp.obj
StringNumber_Tests.exe: CMakeFiles/StringNumber_Tests.dir/build.make
StringNumber_Tests.exe: CMakeFiles/StringNumber_Tests.dir/linklibs.rsp
StringNumber_Tests.exe: CMakeFiles/StringNumber_Tests.dir/objects1.rsp
StringNumber_Tests.exe: CMakeFiles/StringNumber_Tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\User\Desktop\Uni\Year 1\OOP\Git\Project\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable StringNumber_Tests.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\StringNumber_Tests.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/StringNumber_Tests.dir/build: StringNumber_Tests.exe
.PHONY : CMakeFiles/StringNumber_Tests.dir/build

CMakeFiles/StringNumber_Tests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\StringNumber_Tests.dir\cmake_clean.cmake
.PHONY : CMakeFiles/StringNumber_Tests.dir/clean

CMakeFiles/StringNumber_Tests.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\User\Desktop\Uni\Year 1\OOP\Git\Project" "C:\Users\User\Desktop\Uni\Year 1\OOP\Git\Project" "C:\Users\User\Desktop\Uni\Year 1\OOP\Git\Project\cmake-build-debug" "C:\Users\User\Desktop\Uni\Year 1\OOP\Git\Project\cmake-build-debug" "C:\Users\User\Desktop\Uni\Year 1\OOP\Git\Project\cmake-build-debug\CMakeFiles\StringNumber_Tests.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/StringNumber_Tests.dir/depend

