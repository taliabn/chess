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
include CMakeFiles/chess.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/chess.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/chess.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/chess.dir/flags.make

CMakeFiles/chess.dir/src/model.cxx.obj: CMakeFiles/chess.dir/flags.make
CMakeFiles/chess.dir/src/model.cxx.obj: CMakeFiles/chess.dir/includes_CXX.rsp
CMakeFiles/chess.dir/src/model.cxx.obj: ../src/model.cxx
CMakeFiles/chess.dir/src/model.cxx.obj: CMakeFiles/chess.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\talia\OneDrive\Documents\2022_Fall\COMP_SCI_211\TJ_final_project\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/chess.dir/src/model.cxx.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/chess.dir/src/model.cxx.obj -MF CMakeFiles\chess.dir\src\model.cxx.obj.d -o CMakeFiles\chess.dir\src\model.cxx.obj -c C:\Users\talia\OneDrive\Documents\2022_Fall\COMP_SCI_211\TJ_final_project\src\model.cxx

CMakeFiles/chess.dir/src/model.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chess.dir/src/model.cxx.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\talia\OneDrive\Documents\2022_Fall\COMP_SCI_211\TJ_final_project\src\model.cxx > CMakeFiles\chess.dir\src\model.cxx.i

CMakeFiles/chess.dir/src/model.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chess.dir/src/model.cxx.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\talia\OneDrive\Documents\2022_Fall\COMP_SCI_211\TJ_final_project\src\model.cxx -o CMakeFiles\chess.dir\src\model.cxx.s

CMakeFiles/chess.dir/src/player.cxx.obj: CMakeFiles/chess.dir/flags.make
CMakeFiles/chess.dir/src/player.cxx.obj: CMakeFiles/chess.dir/includes_CXX.rsp
CMakeFiles/chess.dir/src/player.cxx.obj: ../src/player.cxx
CMakeFiles/chess.dir/src/player.cxx.obj: CMakeFiles/chess.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\talia\OneDrive\Documents\2022_Fall\COMP_SCI_211\TJ_final_project\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/chess.dir/src/player.cxx.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/chess.dir/src/player.cxx.obj -MF CMakeFiles\chess.dir\src\player.cxx.obj.d -o CMakeFiles\chess.dir\src\player.cxx.obj -c C:\Users\talia\OneDrive\Documents\2022_Fall\COMP_SCI_211\TJ_final_project\src\player.cxx

CMakeFiles/chess.dir/src/player.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chess.dir/src/player.cxx.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\talia\OneDrive\Documents\2022_Fall\COMP_SCI_211\TJ_final_project\src\player.cxx > CMakeFiles\chess.dir\src\player.cxx.i

CMakeFiles/chess.dir/src/player.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chess.dir/src/player.cxx.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\talia\OneDrive\Documents\2022_Fall\COMP_SCI_211\TJ_final_project\src\player.cxx -o CMakeFiles\chess.dir\src\player.cxx.s

CMakeFiles/chess.dir/src/position_set.cxx.obj: CMakeFiles/chess.dir/flags.make
CMakeFiles/chess.dir/src/position_set.cxx.obj: CMakeFiles/chess.dir/includes_CXX.rsp
CMakeFiles/chess.dir/src/position_set.cxx.obj: ../src/position_set.cxx
CMakeFiles/chess.dir/src/position_set.cxx.obj: CMakeFiles/chess.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\talia\OneDrive\Documents\2022_Fall\COMP_SCI_211\TJ_final_project\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/chess.dir/src/position_set.cxx.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/chess.dir/src/position_set.cxx.obj -MF CMakeFiles\chess.dir\src\position_set.cxx.obj.d -o CMakeFiles\chess.dir\src\position_set.cxx.obj -c C:\Users\talia\OneDrive\Documents\2022_Fall\COMP_SCI_211\TJ_final_project\src\position_set.cxx

CMakeFiles/chess.dir/src/position_set.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chess.dir/src/position_set.cxx.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\talia\OneDrive\Documents\2022_Fall\COMP_SCI_211\TJ_final_project\src\position_set.cxx > CMakeFiles\chess.dir\src\position_set.cxx.i

CMakeFiles/chess.dir/src/position_set.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chess.dir/src/position_set.cxx.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\talia\OneDrive\Documents\2022_Fall\COMP_SCI_211\TJ_final_project\src\position_set.cxx -o CMakeFiles\chess.dir\src\position_set.cxx.s

CMakeFiles/chess.dir/src/board.cxx.obj: CMakeFiles/chess.dir/flags.make
CMakeFiles/chess.dir/src/board.cxx.obj: CMakeFiles/chess.dir/includes_CXX.rsp
CMakeFiles/chess.dir/src/board.cxx.obj: ../src/board.cxx
CMakeFiles/chess.dir/src/board.cxx.obj: CMakeFiles/chess.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\talia\OneDrive\Documents\2022_Fall\COMP_SCI_211\TJ_final_project\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/chess.dir/src/board.cxx.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/chess.dir/src/board.cxx.obj -MF CMakeFiles\chess.dir\src\board.cxx.obj.d -o CMakeFiles\chess.dir\src\board.cxx.obj -c C:\Users\talia\OneDrive\Documents\2022_Fall\COMP_SCI_211\TJ_final_project\src\board.cxx

CMakeFiles/chess.dir/src/board.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chess.dir/src/board.cxx.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\talia\OneDrive\Documents\2022_Fall\COMP_SCI_211\TJ_final_project\src\board.cxx > CMakeFiles\chess.dir\src\board.cxx.i

CMakeFiles/chess.dir/src/board.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chess.dir/src/board.cxx.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\talia\OneDrive\Documents\2022_Fall\COMP_SCI_211\TJ_final_project\src\board.cxx -o CMakeFiles\chess.dir\src\board.cxx.s

CMakeFiles/chess.dir/src/view.cxx.obj: CMakeFiles/chess.dir/flags.make
CMakeFiles/chess.dir/src/view.cxx.obj: CMakeFiles/chess.dir/includes_CXX.rsp
CMakeFiles/chess.dir/src/view.cxx.obj: ../src/view.cxx
CMakeFiles/chess.dir/src/view.cxx.obj: CMakeFiles/chess.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\talia\OneDrive\Documents\2022_Fall\COMP_SCI_211\TJ_final_project\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/chess.dir/src/view.cxx.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/chess.dir/src/view.cxx.obj -MF CMakeFiles\chess.dir\src\view.cxx.obj.d -o CMakeFiles\chess.dir\src\view.cxx.obj -c C:\Users\talia\OneDrive\Documents\2022_Fall\COMP_SCI_211\TJ_final_project\src\view.cxx

CMakeFiles/chess.dir/src/view.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chess.dir/src/view.cxx.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\talia\OneDrive\Documents\2022_Fall\COMP_SCI_211\TJ_final_project\src\view.cxx > CMakeFiles\chess.dir\src\view.cxx.i

CMakeFiles/chess.dir/src/view.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chess.dir/src/view.cxx.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\talia\OneDrive\Documents\2022_Fall\COMP_SCI_211\TJ_final_project\src\view.cxx -o CMakeFiles\chess.dir\src\view.cxx.s

CMakeFiles/chess.dir/src/controller.cxx.obj: CMakeFiles/chess.dir/flags.make
CMakeFiles/chess.dir/src/controller.cxx.obj: CMakeFiles/chess.dir/includes_CXX.rsp
CMakeFiles/chess.dir/src/controller.cxx.obj: ../src/controller.cxx
CMakeFiles/chess.dir/src/controller.cxx.obj: CMakeFiles/chess.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\talia\OneDrive\Documents\2022_Fall\COMP_SCI_211\TJ_final_project\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/chess.dir/src/controller.cxx.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/chess.dir/src/controller.cxx.obj -MF CMakeFiles\chess.dir\src\controller.cxx.obj.d -o CMakeFiles\chess.dir\src\controller.cxx.obj -c C:\Users\talia\OneDrive\Documents\2022_Fall\COMP_SCI_211\TJ_final_project\src\controller.cxx

CMakeFiles/chess.dir/src/controller.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chess.dir/src/controller.cxx.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\talia\OneDrive\Documents\2022_Fall\COMP_SCI_211\TJ_final_project\src\controller.cxx > CMakeFiles\chess.dir\src\controller.cxx.i

CMakeFiles/chess.dir/src/controller.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chess.dir/src/controller.cxx.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\talia\OneDrive\Documents\2022_Fall\COMP_SCI_211\TJ_final_project\src\controller.cxx -o CMakeFiles\chess.dir\src\controller.cxx.s

CMakeFiles/chess.dir/src/main.cxx.obj: CMakeFiles/chess.dir/flags.make
CMakeFiles/chess.dir/src/main.cxx.obj: CMakeFiles/chess.dir/includes_CXX.rsp
CMakeFiles/chess.dir/src/main.cxx.obj: ../src/main.cxx
CMakeFiles/chess.dir/src/main.cxx.obj: CMakeFiles/chess.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\talia\OneDrive\Documents\2022_Fall\COMP_SCI_211\TJ_final_project\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/chess.dir/src/main.cxx.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/chess.dir/src/main.cxx.obj -MF CMakeFiles\chess.dir\src\main.cxx.obj.d -o CMakeFiles\chess.dir\src\main.cxx.obj -c C:\Users\talia\OneDrive\Documents\2022_Fall\COMP_SCI_211\TJ_final_project\src\main.cxx

CMakeFiles/chess.dir/src/main.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chess.dir/src/main.cxx.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\talia\OneDrive\Documents\2022_Fall\COMP_SCI_211\TJ_final_project\src\main.cxx > CMakeFiles\chess.dir\src\main.cxx.i

CMakeFiles/chess.dir/src/main.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chess.dir/src/main.cxx.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\talia\OneDrive\Documents\2022_Fall\COMP_SCI_211\TJ_final_project\src\main.cxx -o CMakeFiles\chess.dir\src\main.cxx.s

# Object files for target chess
chess_OBJECTS = \
"CMakeFiles/chess.dir/src/model.cxx.obj" \
"CMakeFiles/chess.dir/src/player.cxx.obj" \
"CMakeFiles/chess.dir/src/position_set.cxx.obj" \
"CMakeFiles/chess.dir/src/board.cxx.obj" \
"CMakeFiles/chess.dir/src/view.cxx.obj" \
"CMakeFiles/chess.dir/src/controller.cxx.obj" \
"CMakeFiles/chess.dir/src/main.cxx.obj"

# External object files for target chess
chess_EXTERNAL_OBJECTS =

chess.exe: CMakeFiles/chess.dir/src/model.cxx.obj
chess.exe: CMakeFiles/chess.dir/src/player.cxx.obj
chess.exe: CMakeFiles/chess.dir/src/position_set.cxx.obj
chess.exe: CMakeFiles/chess.dir/src/board.cxx.obj
chess.exe: CMakeFiles/chess.dir/src/view.cxx.obj
chess.exe: CMakeFiles/chess.dir/src/controller.cxx.obj
chess.exe: CMakeFiles/chess.dir/src/main.cxx.obj
chess.exe: CMakeFiles/chess.dir/build.make
chess.exe: .cs211/lib/ge211/src/libge211.a
chess.exe: C:/MinGW/lib/libSDL2.dll.a
chess.exe: C:/MinGW/lib/libSDL2_image.dll.a
chess.exe: C:/MinGW/lib/libSDL2_mixer.dll.a
chess.exe: C:/MinGW/lib/libSDL2_ttf.dll.a
chess.exe: CMakeFiles/chess.dir/linklibs.rsp
chess.exe: CMakeFiles/chess.dir/objects1.rsp
chess.exe: CMakeFiles/chess.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\talia\OneDrive\Documents\2022_Fall\COMP_SCI_211\TJ_final_project\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable chess.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\chess.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/chess.dir/build: chess.exe
.PHONY : CMakeFiles/chess.dir/build

CMakeFiles/chess.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\chess.dir\cmake_clean.cmake
.PHONY : CMakeFiles/chess.dir/clean

CMakeFiles/chess.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\talia\OneDrive\Documents\2022_Fall\COMP_SCI_211\TJ_final_project C:\Users\talia\OneDrive\Documents\2022_Fall\COMP_SCI_211\TJ_final_project C:\Users\talia\OneDrive\Documents\2022_Fall\COMP_SCI_211\TJ_final_project\cmake-build-debug C:\Users\talia\OneDrive\Documents\2022_Fall\COMP_SCI_211\TJ_final_project\cmake-build-debug C:\Users\talia\OneDrive\Documents\2022_Fall\COMP_SCI_211\TJ_final_project\cmake-build-debug\CMakeFiles\chess.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/chess.dir/depend

