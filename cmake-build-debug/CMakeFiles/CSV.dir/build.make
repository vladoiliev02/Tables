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
include CMakeFiles/CSV.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/CSV.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CSV.dir/flags.make

CMakeFiles/CSV.dir/main.cpp.obj: CMakeFiles/CSV.dir/flags.make
CMakeFiles/CSV.dir/main.cpp.obj: CMakeFiles/CSV.dir/includes_CXX.rsp
CMakeFiles/CSV.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\User\Desktop\Uni\Year 1\OOP\Git\Project\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CSV.dir/main.cpp.obj"
	C:\ProgramData\chocolatey\lib\mingw\tools\install\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\CSV.dir\main.cpp.obj -c "C:\Users\User\Desktop\Uni\Year 1\OOP\Git\Project\main.cpp"

CMakeFiles/CSV.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CSV.dir/main.cpp.i"
	C:\ProgramData\chocolatey\lib\mingw\tools\install\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\User\Desktop\Uni\Year 1\OOP\Git\Project\main.cpp" > CMakeFiles\CSV.dir\main.cpp.i

CMakeFiles/CSV.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CSV.dir/main.cpp.s"
	C:\ProgramData\chocolatey\lib\mingw\tools\install\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\User\Desktop\Uni\Year 1\OOP\Git\Project\main.cpp" -o CMakeFiles\CSV.dir\main.cpp.s

CMakeFiles/CSV.dir/Cell/Cell.cpp.obj: CMakeFiles/CSV.dir/flags.make
CMakeFiles/CSV.dir/Cell/Cell.cpp.obj: CMakeFiles/CSV.dir/includes_CXX.rsp
CMakeFiles/CSV.dir/Cell/Cell.cpp.obj: ../Cell/Cell.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\User\Desktop\Uni\Year 1\OOP\Git\Project\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/CSV.dir/Cell/Cell.cpp.obj"
	C:\ProgramData\chocolatey\lib\mingw\tools\install\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\CSV.dir\Cell\Cell.cpp.obj -c "C:\Users\User\Desktop\Uni\Year 1\OOP\Git\Project\Cell\Cell.cpp"

CMakeFiles/CSV.dir/Cell/Cell.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CSV.dir/Cell/Cell.cpp.i"
	C:\ProgramData\chocolatey\lib\mingw\tools\install\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\User\Desktop\Uni\Year 1\OOP\Git\Project\Cell\Cell.cpp" > CMakeFiles\CSV.dir\Cell\Cell.cpp.i

CMakeFiles/CSV.dir/Cell/Cell.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CSV.dir/Cell/Cell.cpp.s"
	C:\ProgramData\chocolatey\lib\mingw\tools\install\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\User\Desktop\Uni\Year 1\OOP\Git\Project\Cell\Cell.cpp" -o CMakeFiles\CSV.dir\Cell\Cell.cpp.s

CMakeFiles/CSV.dir/Table/Table.cpp.obj: CMakeFiles/CSV.dir/flags.make
CMakeFiles/CSV.dir/Table/Table.cpp.obj: CMakeFiles/CSV.dir/includes_CXX.rsp
CMakeFiles/CSV.dir/Table/Table.cpp.obj: ../Table/Table.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\User\Desktop\Uni\Year 1\OOP\Git\Project\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/CSV.dir/Table/Table.cpp.obj"
	C:\ProgramData\chocolatey\lib\mingw\tools\install\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\CSV.dir\Table\Table.cpp.obj -c "C:\Users\User\Desktop\Uni\Year 1\OOP\Git\Project\Table\Table.cpp"

CMakeFiles/CSV.dir/Table/Table.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CSV.dir/Table/Table.cpp.i"
	C:\ProgramData\chocolatey\lib\mingw\tools\install\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\User\Desktop\Uni\Year 1\OOP\Git\Project\Table\Table.cpp" > CMakeFiles\CSV.dir\Table\Table.cpp.i

CMakeFiles/CSV.dir/Table/Table.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CSV.dir/Table/Table.cpp.s"
	C:\ProgramData\chocolatey\lib\mingw\tools\install\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\User\Desktop\Uni\Year 1\OOP\Git\Project\Table\Table.cpp" -o CMakeFiles\CSV.dir\Table\Table.cpp.s

CMakeFiles/CSV.dir/Expression/Expression.cpp.obj: CMakeFiles/CSV.dir/flags.make
CMakeFiles/CSV.dir/Expression/Expression.cpp.obj: CMakeFiles/CSV.dir/includes_CXX.rsp
CMakeFiles/CSV.dir/Expression/Expression.cpp.obj: ../Expression/Expression.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\User\Desktop\Uni\Year 1\OOP\Git\Project\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/CSV.dir/Expression/Expression.cpp.obj"
	C:\ProgramData\chocolatey\lib\mingw\tools\install\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\CSV.dir\Expression\Expression.cpp.obj -c "C:\Users\User\Desktop\Uni\Year 1\OOP\Git\Project\Expression\Expression.cpp"

CMakeFiles/CSV.dir/Expression/Expression.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CSV.dir/Expression/Expression.cpp.i"
	C:\ProgramData\chocolatey\lib\mingw\tools\install\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\User\Desktop\Uni\Year 1\OOP\Git\Project\Expression\Expression.cpp" > CMakeFiles\CSV.dir\Expression\Expression.cpp.i

CMakeFiles/CSV.dir/Expression/Expression.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CSV.dir/Expression/Expression.cpp.s"
	C:\ProgramData\chocolatey\lib\mingw\tools\install\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\User\Desktop\Uni\Year 1\OOP\Git\Project\Expression\Expression.cpp" -o CMakeFiles\CSV.dir\Expression\Expression.cpp.s

CMakeFiles/CSV.dir/Commands/Commands.cpp.obj: CMakeFiles/CSV.dir/flags.make
CMakeFiles/CSV.dir/Commands/Commands.cpp.obj: CMakeFiles/CSV.dir/includes_CXX.rsp
CMakeFiles/CSV.dir/Commands/Commands.cpp.obj: ../Commands/Commands.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\User\Desktop\Uni\Year 1\OOP\Git\Project\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/CSV.dir/Commands/Commands.cpp.obj"
	C:\ProgramData\chocolatey\lib\mingw\tools\install\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\CSV.dir\Commands\Commands.cpp.obj -c "C:\Users\User\Desktop\Uni\Year 1\OOP\Git\Project\Commands\Commands.cpp"

CMakeFiles/CSV.dir/Commands/Commands.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CSV.dir/Commands/Commands.cpp.i"
	C:\ProgramData\chocolatey\lib\mingw\tools\install\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\User\Desktop\Uni\Year 1\OOP\Git\Project\Commands\Commands.cpp" > CMakeFiles\CSV.dir\Commands\Commands.cpp.i

CMakeFiles/CSV.dir/Commands/Commands.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CSV.dir/Commands/Commands.cpp.s"
	C:\ProgramData\chocolatey\lib\mingw\tools\install\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\User\Desktop\Uni\Year 1\OOP\Git\Project\Commands\Commands.cpp" -o CMakeFiles\CSV.dir\Commands\Commands.cpp.s

CMakeFiles/CSV.dir/StringNumber/StringNumber.cpp.obj: CMakeFiles/CSV.dir/flags.make
CMakeFiles/CSV.dir/StringNumber/StringNumber.cpp.obj: CMakeFiles/CSV.dir/includes_CXX.rsp
CMakeFiles/CSV.dir/StringNumber/StringNumber.cpp.obj: ../StringNumber/StringNumber.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\User\Desktop\Uni\Year 1\OOP\Git\Project\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/CSV.dir/StringNumber/StringNumber.cpp.obj"
	C:\ProgramData\chocolatey\lib\mingw\tools\install\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\CSV.dir\StringNumber\StringNumber.cpp.obj -c "C:\Users\User\Desktop\Uni\Year 1\OOP\Git\Project\StringNumber\StringNumber.cpp"

CMakeFiles/CSV.dir/StringNumber/StringNumber.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CSV.dir/StringNumber/StringNumber.cpp.i"
	C:\ProgramData\chocolatey\lib\mingw\tools\install\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\User\Desktop\Uni\Year 1\OOP\Git\Project\StringNumber\StringNumber.cpp" > CMakeFiles\CSV.dir\StringNumber\StringNumber.cpp.i

CMakeFiles/CSV.dir/StringNumber/StringNumber.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CSV.dir/StringNumber/StringNumber.cpp.s"
	C:\ProgramData\chocolatey\lib\mingw\tools\install\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\User\Desktop\Uni\Year 1\OOP\Git\Project\StringNumber\StringNumber.cpp" -o CMakeFiles\CSV.dir\StringNumber\StringNumber.cpp.s

CMakeFiles/CSV.dir/Table_File/Table_File.cpp.obj: CMakeFiles/CSV.dir/flags.make
CMakeFiles/CSV.dir/Table_File/Table_File.cpp.obj: CMakeFiles/CSV.dir/includes_CXX.rsp
CMakeFiles/CSV.dir/Table_File/Table_File.cpp.obj: ../Table_File/Table_File.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\User\Desktop\Uni\Year 1\OOP\Git\Project\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/CSV.dir/Table_File/Table_File.cpp.obj"
	C:\ProgramData\chocolatey\lib\mingw\tools\install\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\CSV.dir\Table_File\Table_File.cpp.obj -c "C:\Users\User\Desktop\Uni\Year 1\OOP\Git\Project\Table_File\Table_File.cpp"

CMakeFiles/CSV.dir/Table_File/Table_File.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CSV.dir/Table_File/Table_File.cpp.i"
	C:\ProgramData\chocolatey\lib\mingw\tools\install\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\User\Desktop\Uni\Year 1\OOP\Git\Project\Table_File\Table_File.cpp" > CMakeFiles\CSV.dir\Table_File\Table_File.cpp.i

CMakeFiles/CSV.dir/Table_File/Table_File.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CSV.dir/Table_File/Table_File.cpp.s"
	C:\ProgramData\chocolatey\lib\mingw\tools\install\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\User\Desktop\Uni\Year 1\OOP\Git\Project\Table_File\Table_File.cpp" -o CMakeFiles\CSV.dir\Table_File\Table_File.cpp.s

# Object files for target CSV
CSV_OBJECTS = \
"CMakeFiles/CSV.dir/main.cpp.obj" \
"CMakeFiles/CSV.dir/Cell/Cell.cpp.obj" \
"CMakeFiles/CSV.dir/Table/Table.cpp.obj" \
"CMakeFiles/CSV.dir/Expression/Expression.cpp.obj" \
"CMakeFiles/CSV.dir/Commands/Commands.cpp.obj" \
"CMakeFiles/CSV.dir/StringNumber/StringNumber.cpp.obj" \
"CMakeFiles/CSV.dir/Table_File/Table_File.cpp.obj"

# External object files for target CSV
CSV_EXTERNAL_OBJECTS =

CSV\ Table\ Editor.exe: CMakeFiles/CSV.dir/main.cpp.obj
CSV\ Table\ Editor.exe: CMakeFiles/CSV.dir/Cell/Cell.cpp.obj
CSV\ Table\ Editor.exe: CMakeFiles/CSV.dir/Table/Table.cpp.obj
CSV\ Table\ Editor.exe: CMakeFiles/CSV.dir/Expression/Expression.cpp.obj
CSV\ Table\ Editor.exe: CMakeFiles/CSV.dir/Commands/Commands.cpp.obj
CSV\ Table\ Editor.exe: CMakeFiles/CSV.dir/StringNumber/StringNumber.cpp.obj
CSV\ Table\ Editor.exe: CMakeFiles/CSV.dir/Table_File/Table_File.cpp.obj
CSV\ Table\ Editor.exe: CMakeFiles/CSV.dir/build.make
CSV\ Table\ Editor.exe: CMakeFiles/CSV.dir/linklibs.rsp
CSV\ Table\ Editor.exe: CMakeFiles/CSV.dir/objects1.rsp
CSV\ Table\ Editor.exe: CMakeFiles/CSV.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\User\Desktop\Uni\Year 1\OOP\Git\Project\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable \"CSV Table Editor.exe\""
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\CSV.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CSV.dir/build: CSV\ Table\ Editor.exe
.PHONY : CMakeFiles/CSV.dir/build

CMakeFiles/CSV.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\CSV.dir\cmake_clean.cmake
.PHONY : CMakeFiles/CSV.dir/clean

CMakeFiles/CSV.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\User\Desktop\Uni\Year 1\OOP\Git\Project" "C:\Users\User\Desktop\Uni\Year 1\OOP\Git\Project" "C:\Users\User\Desktop\Uni\Year 1\OOP\Git\Project\cmake-build-debug" "C:\Users\User\Desktop\Uni\Year 1\OOP\Git\Project\cmake-build-debug" "C:\Users\User\Desktop\Uni\Year 1\OOP\Git\Project\cmake-build-debug\CMakeFiles\CSV.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/CSV.dir/depend
