# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2022.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2022.2.4\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\talia\OneDrive\Documents\2022_Fall\COMP_SCI_211\TJ_final_project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\talia\OneDrive\Documents\2022_Fall\COMP_SCI_211\TJ_final_project\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/game.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/game.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/game.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/game.dir/flags.make

CMakeFiles/game.dir/src/model.cxx.obj: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/model.cxx.obj: CMakeFiles/game.dir/includes_CXX.rsp
CMakeFiles/game.dir/src/model.cxx.obj: ../src/model.cxx
CMakeFiles/game.dir/src/model.cxx.obj: CMakeFiles/game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\talia\OneDrive\Documents\2022_Fall\COMP_SCI_211\TJ_final_project\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/game.dir/src/model.cxx.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/game.dir/src/model.cxx.obj -MF CMakeFiles\game.dir\src\model.cxx.obj.d -o CMakeFiles\game.dir\src\model.cxx.obj -c C:\Users\talia\OneDrive\Documents\2022_Fall\COMP_SCI_211\TJ_final_project\src\model.cxx

CMakeFiles/game.dir/src/model.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/model.cxx.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\talia\OneDrive\Documents\2022_Fall\COMP_SCI_211\TJ_final_project\src\model.cxx > CMakeFiles\game.dir\src\model.cxx.i

CMakeFiles/game.dir/src/model.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/model.cxx.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\talia\OneDrive\Documents\2022_Fall\COMP_SCI_211\TJ_final_project\src\model.cxx -o CMakeFiles\game.dir\src\model.cxx.s

CMakeFiles/game.dir/src/view.cxx.obj: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/view.cxx.obj: CMakeFiles/game.dir/includes_CXX.rsp
CMakeFiles/game.dir/src/view.cxx.obj: ../src/view.cxx
CMakeFiles/game.dir/src/view.cxx.obj: CMakeFiles/game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\talia\OneDrive\Documents\2022_Fall\COMP_SCI_211\TJ_final_project\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/game.dir/src/view.cxx.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/game.dir/src/view.cxx.obj -MF CMakeFiles\game.dir\src\view.cxx.obj.d -o CMakeFiles\game.dir\src\view.cxx.obj -c C:\Users\talia\OneDrive\Documents\2022_Fall\COMP_SCI_211\TJ_final_project\src\view.cxx

CMakeFiles/game.dir/src/view.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/view.cxx.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\talia\OneDrive\Documents\2022_Fall\COMP_SCI_211\TJ_final_project\src\view.cxx > CMakeFiles\game.dir\src\view.cxx.i

CMakeFiles/game.dir/src/view.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/view.cxx.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\talia\OneDrive\Documents\2022_Fall\COMP_SCI_211\TJ_final_project\src\view.cxx -o CMakeFiles\game.dir\src\view.cxx.s

CMakeFiles/game.dir/src/controller.cxx.obj: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/controller.cxx.obj: CMakeFiles/game.dir/includes_CXX.rsp
CMakeFiles/game.dir/src/controller.cxx.obj: ../src/controller.cxx
CMakeFiles/game.dir/src/controller.cxx.obj: CMakeFiles/game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\talia\OneDrive\Documents\2022_Fall\COMP_SCI_211\TJ_final_project\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/game.dir/src/controller.cxx.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/game.dir/src/controller.cxx.obj -MF CMakeFiles\game.dir\src\controller.cxx.obj.d -o CMakeFiles\game.dir\src\controller.cxx.obj -c C:\Users\talia\OneDrive\Documents\2022_Fall\COMP_SCI_211\TJ_final_project\src\controller.cxx

CMakeFiles/game.dir/src/controller.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/controller.cxx.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\talia\OneDrive\Documents\2022_Fall\COMP_SCI_211\TJ_final_project\src\controller.cxx > CMakeFiles\game.dir\src\controller.cxx.i

CMakeFiles/game.dir/src/controller.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/controller.cxx.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\talia\OneDrive\Documents\2022_Fall\COMP_SCI_211\TJ_final_project\src\controller.cxx -o CMakeFiles\game.dir\src\controller.cxx.s

CMakeFiles/game.dir/src/main.cxx.obj: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/main.cxx.obj: CMakeFiles/game.dir/includes_CXX.rsp
CMakeFiles/game.dir/src/main.cxx.obj: ../src/main.cxx
CMakeFiles/game.dir/src/main.cxx.obj: CMakeFiles/game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\talia\OneDrive\Documents\2022_Fall\COMP_SCI_211\TJ_final_project\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/game.dir/src/main.cxx.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/game.dir/src/main.cxx.obj -MF CMakeFiles\game.dir\src\main.cxx.obj.d -o CMakeFiles\game.dir\src\main.cxx.obj -c C:\Users\talia\OneDrive\Documents\2022_Fall\COMP_SCI_211\TJ_final_project\src\main.cxx

CMakeFiles/game.dir/src/main.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/main.cxx.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\talia\OneDrive\Documents\2022_Fall\COMP_SCI_211\TJ_final_project\src\main.cxx > CMakeFiles\game.dir\src\main.cxx.i

CMakeFiles/game.dir/src/main.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/main.cxx.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\talia\OneDrive\Documents\2022_Fall\COMP_SCI_211\TJ_final_project\src\main.cxx -o CMakeFiles\game.dir\src\main.cxx.s

# Object files for target game
game_OBJECTS = \
"CMakeFiles/game.dir/src/model.cxx.obj" \
"CMakeFiles/game.dir/src/view.cxx.obj" \
"CMakeFiles/game.dir/src/controller.cxx.obj" \
"CMakeFiles/game.dir/src/main.cxx.obj"

# External object files for target game
game_EXTERNAL_OBJECTS =

game.exe: CMakeFiles/game.dir/src/model.cxx.obj
game.exe: CMakeFiles/game.dir/src/view.cxx.obj
game.exe: CMakeFiles/game.dir/src/controller.cxx.obj
game.exe: CMakeFiles/game.dir/src/main.cxx.obj
game.exe: CMakeFiles/game.dir/build.make
game.exe: .cs211/lib/ge211/src/libge211.a
game.exe: C:/MinGW/lib/libSDL2.dll.a
game.exe: C:/MinGW/lib/libSDL2_image.dll.a
game.exe: C:/MinGW/lib/libSDL2_mixer.dll.a
game.exe: C:/MinGW/lib/libSDL2_ttf.dll.a
game.exe: CMakeFiles/game.dir/linklibs.rsp
game.exe: CMakeFiles/game.dir/objects1.rsp
game.exe: CMakeFiles/game.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\talia\OneDrive\Documents\2022_Fall\COMP_SCI_211\TJ_final_project\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable game.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\game.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/game.dir/build: game.exe
.PHONY : CMakeFiles/game.dir/build

CMakeFiles/game.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\game.dir\cmake_clean.cmake
.PHONY : CMakeFiles/game.dir/clean

CMakeFiles/game.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\talia\OneDrive\Documents\2022_Fall\COMP_SCI_211\TJ_final_project C:\Users\talia\OneDrive\Documents\2022_Fall\COMP_SCI_211\TJ_final_project C:\Users\talia\OneDrive\Documents\2022_Fall\COMP_SCI_211\TJ_final_project\cmake-build-debug C:\Users\talia\OneDrive\Documents\2022_Fall\COMP_SCI_211\TJ_final_project\cmake-build-debug C:\Users\talia\OneDrive\Documents\2022_Fall\COMP_SCI_211\TJ_final_project\cmake-build-debug\CMakeFiles\game.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/game.dir/depend

