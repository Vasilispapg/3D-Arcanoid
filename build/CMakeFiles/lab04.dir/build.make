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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\vasilispapg\Desktop\OpenGL_lab_04

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\vasilispapg\Desktop\OpenGL_lab_04\build

# Include any dependencies generated for this target.
include CMakeFiles/lab04.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/lab04.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/lab04.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab04.dir/flags.make

CMakeFiles/lab04.dir/main.cpp.obj: CMakeFiles/lab04.dir/flags.make
CMakeFiles/lab04.dir/main.cpp.obj: ../main.cpp
CMakeFiles/lab04.dir/main.cpp.obj: CMakeFiles/lab04.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\vasilispapg\Desktop\OpenGL_lab_04\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lab04.dir/main.cpp.obj"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab04.dir/main.cpp.obj -MF CMakeFiles\lab04.dir\main.cpp.obj.d -o CMakeFiles\lab04.dir\main.cpp.obj -c C:\Users\vasilispapg\Desktop\OpenGL_lab_04\main.cpp

CMakeFiles/lab04.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab04.dir/main.cpp.i"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\vasilispapg\Desktop\OpenGL_lab_04\main.cpp > CMakeFiles\lab04.dir\main.cpp.i

CMakeFiles/lab04.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab04.dir/main.cpp.s"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\vasilispapg\Desktop\OpenGL_lab_04\main.cpp -o CMakeFiles\lab04.dir\main.cpp.s

CMakeFiles/lab04.dir/visuals.cpp.obj: CMakeFiles/lab04.dir/flags.make
CMakeFiles/lab04.dir/visuals.cpp.obj: ../visuals.cpp
CMakeFiles/lab04.dir/visuals.cpp.obj: CMakeFiles/lab04.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\vasilispapg\Desktop\OpenGL_lab_04\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/lab04.dir/visuals.cpp.obj"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab04.dir/visuals.cpp.obj -MF CMakeFiles\lab04.dir\visuals.cpp.obj.d -o CMakeFiles\lab04.dir\visuals.cpp.obj -c C:\Users\vasilispapg\Desktop\OpenGL_lab_04\visuals.cpp

CMakeFiles/lab04.dir/visuals.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab04.dir/visuals.cpp.i"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\vasilispapg\Desktop\OpenGL_lab_04\visuals.cpp > CMakeFiles\lab04.dir\visuals.cpp.i

CMakeFiles/lab04.dir/visuals.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab04.dir/visuals.cpp.s"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\vasilispapg\Desktop\OpenGL_lab_04\visuals.cpp -o CMakeFiles\lab04.dir\visuals.cpp.s

# Object files for target lab04
lab04_OBJECTS = \
"CMakeFiles/lab04.dir/main.cpp.obj" \
"CMakeFiles/lab04.dir/visuals.cpp.obj"

# External object files for target lab04
lab04_EXTERNAL_OBJECTS =

lab04.exe: CMakeFiles/lab04.dir/main.cpp.obj
lab04.exe: CMakeFiles/lab04.dir/visuals.cpp.obj
lab04.exe: CMakeFiles/lab04.dir/build.make
lab04.exe: C:/Program\ Files/mingw-w64/x86_64-8.1.0-posix-seh-rt_v6-rev0/mingw64/lib/libfreeglut.a
lab04.exe: CMakeFiles/lab04.dir/linklibs.rsp
lab04.exe: CMakeFiles/lab04.dir/objects1.rsp
lab04.exe: CMakeFiles/lab04.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\vasilispapg\Desktop\OpenGL_lab_04\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable lab04.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\lab04.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab04.dir/build: lab04.exe
.PHONY : CMakeFiles/lab04.dir/build

CMakeFiles/lab04.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\lab04.dir\cmake_clean.cmake
.PHONY : CMakeFiles/lab04.dir/clean

CMakeFiles/lab04.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\vasilispapg\Desktop\OpenGL_lab_04 C:\Users\vasilispapg\Desktop\OpenGL_lab_04 C:\Users\vasilispapg\Desktop\OpenGL_lab_04\build C:\Users\vasilispapg\Desktop\OpenGL_lab_04\build C:\Users\vasilispapg\Desktop\OpenGL_lab_04\build\CMakeFiles\lab04.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lab04.dir/depend

