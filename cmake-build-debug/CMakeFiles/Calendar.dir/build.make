# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = C:\Users\ACER\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\201.6668.126\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\ACER\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\201.6668.126\bin\cmake\win\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\C++PROJECTS\OOP\Projects\Calendar2.0

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\C++PROJECTS\OOP\Projects\Calendar2.0\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Calendar.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Calendar.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Calendar.dir/flags.make

CMakeFiles/Calendar.dir/main.cpp.obj: CMakeFiles/Calendar.dir/flags.make
CMakeFiles/Calendar.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\C++PROJECTS\OOP\Projects\Calendar2.0\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Calendar.dir/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Calendar.dir\main.cpp.obj -c D:\C++PROJECTS\OOP\Projects\Calendar2.0\main.cpp

CMakeFiles/Calendar.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Calendar.dir/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\C++PROJECTS\OOP\Projects\Calendar2.0\main.cpp > CMakeFiles\Calendar.dir\main.cpp.i

CMakeFiles/Calendar.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Calendar.dir/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\C++PROJECTS\OOP\Projects\Calendar2.0\main.cpp -o CMakeFiles\Calendar.dir\main.cpp.s

# Object files for target Calendar
Calendar_OBJECTS = \
"CMakeFiles/Calendar.dir/main.cpp.obj"

# External object files for target Calendar
Calendar_EXTERNAL_OBJECTS =

Calendar.exe: CMakeFiles/Calendar.dir/main.cpp.obj
Calendar.exe: CMakeFiles/Calendar.dir/build.make
Calendar.exe: CMakeFiles/Calendar.dir/linklibs.rsp
Calendar.exe: CMakeFiles/Calendar.dir/objects1.rsp
Calendar.exe: CMakeFiles/Calendar.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\C++PROJECTS\OOP\Projects\Calendar2.0\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Calendar.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Calendar.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Calendar.dir/build: Calendar.exe

.PHONY : CMakeFiles/Calendar.dir/build

CMakeFiles/Calendar.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Calendar.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Calendar.dir/clean

CMakeFiles/Calendar.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\C++PROJECTS\OOP\Projects\Calendar2.0 D:\C++PROJECTS\OOP\Projects\Calendar2.0 D:\C++PROJECTS\OOP\Projects\Calendar2.0\cmake-build-debug D:\C++PROJECTS\OOP\Projects\Calendar2.0\cmake-build-debug D:\C++PROJECTS\OOP\Projects\Calendar2.0\cmake-build-debug\CMakeFiles\Calendar.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Calendar.dir/depend

