# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.27.4/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.27.4/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/anatolii/Desktop/OOP_MAI/OOP_hometasks/MAI_OOP_hometask_6

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/anatolii/Desktop/OOP_MAI/OOP_hometasks/MAI_OOP_hometask_6/build

# Include any dependencies generated for this target.
include CMakeFiles/lab_06.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/lab_06.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/lab_06.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab_06.dir/flags.make

CMakeFiles/lab_06.dir/main.cpp.o: CMakeFiles/lab_06.dir/flags.make
CMakeFiles/lab_06.dir/main.cpp.o: /Users/anatolii/Desktop/OOP_MAI/OOP_hometasks/MAI_OOP_hometask_6/main.cpp
CMakeFiles/lab_06.dir/main.cpp.o: CMakeFiles/lab_06.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/anatolii/Desktop/OOP_MAI/OOP_hometasks/MAI_OOP_hometask_6/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lab_06.dir/main.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab_06.dir/main.cpp.o -MF CMakeFiles/lab_06.dir/main.cpp.o.d -o CMakeFiles/lab_06.dir/main.cpp.o -c /Users/anatolii/Desktop/OOP_MAI/OOP_hometasks/MAI_OOP_hometask_6/main.cpp

CMakeFiles/lab_06.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/lab_06.dir/main.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/anatolii/Desktop/OOP_MAI/OOP_hometasks/MAI_OOP_hometask_6/main.cpp > CMakeFiles/lab_06.dir/main.cpp.i

CMakeFiles/lab_06.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/lab_06.dir/main.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/anatolii/Desktop/OOP_MAI/OOP_hometasks/MAI_OOP_hometask_6/main.cpp -o CMakeFiles/lab_06.dir/main.cpp.s

CMakeFiles/lab_06.dir/observer.cpp.o: CMakeFiles/lab_06.dir/flags.make
CMakeFiles/lab_06.dir/observer.cpp.o: /Users/anatolii/Desktop/OOP_MAI/OOP_hometasks/MAI_OOP_hometask_6/observer.cpp
CMakeFiles/lab_06.dir/observer.cpp.o: CMakeFiles/lab_06.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/anatolii/Desktop/OOP_MAI/OOP_hometasks/MAI_OOP_hometask_6/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/lab_06.dir/observer.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab_06.dir/observer.cpp.o -MF CMakeFiles/lab_06.dir/observer.cpp.o.d -o CMakeFiles/lab_06.dir/observer.cpp.o -c /Users/anatolii/Desktop/OOP_MAI/OOP_hometasks/MAI_OOP_hometask_6/observer.cpp

CMakeFiles/lab_06.dir/observer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/lab_06.dir/observer.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/anatolii/Desktop/OOP_MAI/OOP_hometasks/MAI_OOP_hometask_6/observer.cpp > CMakeFiles/lab_06.dir/observer.cpp.i

CMakeFiles/lab_06.dir/observer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/lab_06.dir/observer.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/anatolii/Desktop/OOP_MAI/OOP_hometasks/MAI_OOP_hometask_6/observer.cpp -o CMakeFiles/lab_06.dir/observer.cpp.s

CMakeFiles/lab_06.dir/factory.cpp.o: CMakeFiles/lab_06.dir/flags.make
CMakeFiles/lab_06.dir/factory.cpp.o: /Users/anatolii/Desktop/OOP_MAI/OOP_hometasks/MAI_OOP_hometask_6/factory.cpp
CMakeFiles/lab_06.dir/factory.cpp.o: CMakeFiles/lab_06.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/anatolii/Desktop/OOP_MAI/OOP_hometasks/MAI_OOP_hometask_6/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/lab_06.dir/factory.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab_06.dir/factory.cpp.o -MF CMakeFiles/lab_06.dir/factory.cpp.o.d -o CMakeFiles/lab_06.dir/factory.cpp.o -c /Users/anatolii/Desktop/OOP_MAI/OOP_hometasks/MAI_OOP_hometask_6/factory.cpp

CMakeFiles/lab_06.dir/factory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/lab_06.dir/factory.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/anatolii/Desktop/OOP_MAI/OOP_hometasks/MAI_OOP_hometask_6/factory.cpp > CMakeFiles/lab_06.dir/factory.cpp.i

CMakeFiles/lab_06.dir/factory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/lab_06.dir/factory.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/anatolii/Desktop/OOP_MAI/OOP_hometasks/MAI_OOP_hometask_6/factory.cpp -o CMakeFiles/lab_06.dir/factory.cpp.s

CMakeFiles/lab_06.dir/NPC.cpp.o: CMakeFiles/lab_06.dir/flags.make
CMakeFiles/lab_06.dir/NPC.cpp.o: /Users/anatolii/Desktop/OOP_MAI/OOP_hometasks/MAI_OOP_hometask_6/NPC.cpp
CMakeFiles/lab_06.dir/NPC.cpp.o: CMakeFiles/lab_06.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/anatolii/Desktop/OOP_MAI/OOP_hometasks/MAI_OOP_hometask_6/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/lab_06.dir/NPC.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab_06.dir/NPC.cpp.o -MF CMakeFiles/lab_06.dir/NPC.cpp.o.d -o CMakeFiles/lab_06.dir/NPC.cpp.o -c /Users/anatolii/Desktop/OOP_MAI/OOP_hometasks/MAI_OOP_hometask_6/NPC.cpp

CMakeFiles/lab_06.dir/NPC.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/lab_06.dir/NPC.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/anatolii/Desktop/OOP_MAI/OOP_hometasks/MAI_OOP_hometask_6/NPC.cpp > CMakeFiles/lab_06.dir/NPC.cpp.i

CMakeFiles/lab_06.dir/NPC.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/lab_06.dir/NPC.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/anatolii/Desktop/OOP_MAI/OOP_hometasks/MAI_OOP_hometask_6/NPC.cpp -o CMakeFiles/lab_06.dir/NPC.cpp.s

CMakeFiles/lab_06.dir/bear.cpp.o: CMakeFiles/lab_06.dir/flags.make
CMakeFiles/lab_06.dir/bear.cpp.o: /Users/anatolii/Desktop/OOP_MAI/OOP_hometasks/MAI_OOP_hometask_6/bear.cpp
CMakeFiles/lab_06.dir/bear.cpp.o: CMakeFiles/lab_06.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/anatolii/Desktop/OOP_MAI/OOP_hometasks/MAI_OOP_hometask_6/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/lab_06.dir/bear.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab_06.dir/bear.cpp.o -MF CMakeFiles/lab_06.dir/bear.cpp.o.d -o CMakeFiles/lab_06.dir/bear.cpp.o -c /Users/anatolii/Desktop/OOP_MAI/OOP_hometasks/MAI_OOP_hometask_6/bear.cpp

CMakeFiles/lab_06.dir/bear.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/lab_06.dir/bear.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/anatolii/Desktop/OOP_MAI/OOP_hometasks/MAI_OOP_hometask_6/bear.cpp > CMakeFiles/lab_06.dir/bear.cpp.i

CMakeFiles/lab_06.dir/bear.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/lab_06.dir/bear.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/anatolii/Desktop/OOP_MAI/OOP_hometasks/MAI_OOP_hometask_6/bear.cpp -o CMakeFiles/lab_06.dir/bear.cpp.s

CMakeFiles/lab_06.dir/thug.cpp.o: CMakeFiles/lab_06.dir/flags.make
CMakeFiles/lab_06.dir/thug.cpp.o: /Users/anatolii/Desktop/OOP_MAI/OOP_hometasks/MAI_OOP_hometask_6/thug.cpp
CMakeFiles/lab_06.dir/thug.cpp.o: CMakeFiles/lab_06.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/anatolii/Desktop/OOP_MAI/OOP_hometasks/MAI_OOP_hometask_6/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/lab_06.dir/thug.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab_06.dir/thug.cpp.o -MF CMakeFiles/lab_06.dir/thug.cpp.o.d -o CMakeFiles/lab_06.dir/thug.cpp.o -c /Users/anatolii/Desktop/OOP_MAI/OOP_hometasks/MAI_OOP_hometask_6/thug.cpp

CMakeFiles/lab_06.dir/thug.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/lab_06.dir/thug.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/anatolii/Desktop/OOP_MAI/OOP_hometasks/MAI_OOP_hometask_6/thug.cpp > CMakeFiles/lab_06.dir/thug.cpp.i

CMakeFiles/lab_06.dir/thug.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/lab_06.dir/thug.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/anatolii/Desktop/OOP_MAI/OOP_hometasks/MAI_OOP_hometask_6/thug.cpp -o CMakeFiles/lab_06.dir/thug.cpp.s

CMakeFiles/lab_06.dir/elf.cpp.o: CMakeFiles/lab_06.dir/flags.make
CMakeFiles/lab_06.dir/elf.cpp.o: /Users/anatolii/Desktop/OOP_MAI/OOP_hometasks/MAI_OOP_hometask_6/elf.cpp
CMakeFiles/lab_06.dir/elf.cpp.o: CMakeFiles/lab_06.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/anatolii/Desktop/OOP_MAI/OOP_hometasks/MAI_OOP_hometask_6/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/lab_06.dir/elf.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab_06.dir/elf.cpp.o -MF CMakeFiles/lab_06.dir/elf.cpp.o.d -o CMakeFiles/lab_06.dir/elf.cpp.o -c /Users/anatolii/Desktop/OOP_MAI/OOP_hometasks/MAI_OOP_hometask_6/elf.cpp

CMakeFiles/lab_06.dir/elf.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/lab_06.dir/elf.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/anatolii/Desktop/OOP_MAI/OOP_hometasks/MAI_OOP_hometask_6/elf.cpp > CMakeFiles/lab_06.dir/elf.cpp.i

CMakeFiles/lab_06.dir/elf.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/lab_06.dir/elf.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/anatolii/Desktop/OOP_MAI/OOP_hometasks/MAI_OOP_hometask_6/elf.cpp -o CMakeFiles/lab_06.dir/elf.cpp.s

# Object files for target lab_06
lab_06_OBJECTS = \
"CMakeFiles/lab_06.dir/main.cpp.o" \
"CMakeFiles/lab_06.dir/observer.cpp.o" \
"CMakeFiles/lab_06.dir/factory.cpp.o" \
"CMakeFiles/lab_06.dir/NPC.cpp.o" \
"CMakeFiles/lab_06.dir/bear.cpp.o" \
"CMakeFiles/lab_06.dir/thug.cpp.o" \
"CMakeFiles/lab_06.dir/elf.cpp.o"

# External object files for target lab_06
lab_06_EXTERNAL_OBJECTS =

lab_06: CMakeFiles/lab_06.dir/main.cpp.o
lab_06: CMakeFiles/lab_06.dir/observer.cpp.o
lab_06: CMakeFiles/lab_06.dir/factory.cpp.o
lab_06: CMakeFiles/lab_06.dir/NPC.cpp.o
lab_06: CMakeFiles/lab_06.dir/bear.cpp.o
lab_06: CMakeFiles/lab_06.dir/thug.cpp.o
lab_06: CMakeFiles/lab_06.dir/elf.cpp.o
lab_06: CMakeFiles/lab_06.dir/build.make
lab_06: CMakeFiles/lab_06.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/anatolii/Desktop/OOP_MAI/OOP_hometasks/MAI_OOP_hometask_6/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable lab_06"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab_06.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab_06.dir/build: lab_06
.PHONY : CMakeFiles/lab_06.dir/build

CMakeFiles/lab_06.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab_06.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab_06.dir/clean

CMakeFiles/lab_06.dir/depend:
	cd /Users/anatolii/Desktop/OOP_MAI/OOP_hometasks/MAI_OOP_hometask_6/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/anatolii/Desktop/OOP_MAI/OOP_hometasks/MAI_OOP_hometask_6 /Users/anatolii/Desktop/OOP_MAI/OOP_hometasks/MAI_OOP_hometask_6 /Users/anatolii/Desktop/OOP_MAI/OOP_hometasks/MAI_OOP_hometask_6/build /Users/anatolii/Desktop/OOP_MAI/OOP_hometasks/MAI_OOP_hometask_6/build /Users/anatolii/Desktop/OOP_MAI/OOP_hometasks/MAI_OOP_hometask_6/build/CMakeFiles/lab_06.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/lab_06.dir/depend
