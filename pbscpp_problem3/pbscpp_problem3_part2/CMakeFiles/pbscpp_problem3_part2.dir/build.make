# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/nikita/Рабочий стол/pbscpp_problem3/git/pbscpp_problem3/pbscpp_problem3_part2"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/nikita/Рабочий стол/pbscpp_problem3/git/pbscpp_problem3/pbscpp_problem3_part2"

# Include any dependencies generated for this target.
include CMakeFiles/pbscpp_problem3_part2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/pbscpp_problem3_part2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pbscpp_problem3_part2.dir/flags.make

CMakeFiles/pbscpp_problem3_part2.dir/main.cpp.o: CMakeFiles/pbscpp_problem3_part2.dir/flags.make
CMakeFiles/pbscpp_problem3_part2.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/nikita/Рабочий стол/pbscpp_problem3/git/pbscpp_problem3/pbscpp_problem3_part2/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pbscpp_problem3_part2.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pbscpp_problem3_part2.dir/main.cpp.o -c "/home/nikita/Рабочий стол/pbscpp_problem3/git/pbscpp_problem3/pbscpp_problem3_part2/main.cpp"

CMakeFiles/pbscpp_problem3_part2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pbscpp_problem3_part2.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/nikita/Рабочий стол/pbscpp_problem3/git/pbscpp_problem3/pbscpp_problem3_part2/main.cpp" > CMakeFiles/pbscpp_problem3_part2.dir/main.cpp.i

CMakeFiles/pbscpp_problem3_part2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pbscpp_problem3_part2.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/nikita/Рабочий стол/pbscpp_problem3/git/pbscpp_problem3/pbscpp_problem3_part2/main.cpp" -o CMakeFiles/pbscpp_problem3_part2.dir/main.cpp.s

CMakeFiles/pbscpp_problem3_part2.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/pbscpp_problem3_part2.dir/main.cpp.o.requires

CMakeFiles/pbscpp_problem3_part2.dir/main.cpp.o.provides: CMakeFiles/pbscpp_problem3_part2.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/pbscpp_problem3_part2.dir/build.make CMakeFiles/pbscpp_problem3_part2.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/pbscpp_problem3_part2.dir/main.cpp.o.provides

CMakeFiles/pbscpp_problem3_part2.dir/main.cpp.o.provides.build: CMakeFiles/pbscpp_problem3_part2.dir/main.cpp.o


CMakeFiles/pbscpp_problem3_part2.dir/src/IProduct.cpp.o: CMakeFiles/pbscpp_problem3_part2.dir/flags.make
CMakeFiles/pbscpp_problem3_part2.dir/src/IProduct.cpp.o: src/IProduct.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/nikita/Рабочий стол/pbscpp_problem3/git/pbscpp_problem3/pbscpp_problem3_part2/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/pbscpp_problem3_part2.dir/src/IProduct.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pbscpp_problem3_part2.dir/src/IProduct.cpp.o -c "/home/nikita/Рабочий стол/pbscpp_problem3/git/pbscpp_problem3/pbscpp_problem3_part2/src/IProduct.cpp"

CMakeFiles/pbscpp_problem3_part2.dir/src/IProduct.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pbscpp_problem3_part2.dir/src/IProduct.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/nikita/Рабочий стол/pbscpp_problem3/git/pbscpp_problem3/pbscpp_problem3_part2/src/IProduct.cpp" > CMakeFiles/pbscpp_problem3_part2.dir/src/IProduct.cpp.i

CMakeFiles/pbscpp_problem3_part2.dir/src/IProduct.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pbscpp_problem3_part2.dir/src/IProduct.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/nikita/Рабочий стол/pbscpp_problem3/git/pbscpp_problem3/pbscpp_problem3_part2/src/IProduct.cpp" -o CMakeFiles/pbscpp_problem3_part2.dir/src/IProduct.cpp.s

CMakeFiles/pbscpp_problem3_part2.dir/src/IProduct.cpp.o.requires:

.PHONY : CMakeFiles/pbscpp_problem3_part2.dir/src/IProduct.cpp.o.requires

CMakeFiles/pbscpp_problem3_part2.dir/src/IProduct.cpp.o.provides: CMakeFiles/pbscpp_problem3_part2.dir/src/IProduct.cpp.o.requires
	$(MAKE) -f CMakeFiles/pbscpp_problem3_part2.dir/build.make CMakeFiles/pbscpp_problem3_part2.dir/src/IProduct.cpp.o.provides.build
.PHONY : CMakeFiles/pbscpp_problem3_part2.dir/src/IProduct.cpp.o.provides

CMakeFiles/pbscpp_problem3_part2.dir/src/IProduct.cpp.o.provides.build: CMakeFiles/pbscpp_problem3_part2.dir/src/IProduct.cpp.o


CMakeFiles/pbscpp_problem3_part2.dir/src/IShop.cpp.o: CMakeFiles/pbscpp_problem3_part2.dir/flags.make
CMakeFiles/pbscpp_problem3_part2.dir/src/IShop.cpp.o: src/IShop.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/nikita/Рабочий стол/pbscpp_problem3/git/pbscpp_problem3/pbscpp_problem3_part2/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/pbscpp_problem3_part2.dir/src/IShop.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pbscpp_problem3_part2.dir/src/IShop.cpp.o -c "/home/nikita/Рабочий стол/pbscpp_problem3/git/pbscpp_problem3/pbscpp_problem3_part2/src/IShop.cpp"

CMakeFiles/pbscpp_problem3_part2.dir/src/IShop.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pbscpp_problem3_part2.dir/src/IShop.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/nikita/Рабочий стол/pbscpp_problem3/git/pbscpp_problem3/pbscpp_problem3_part2/src/IShop.cpp" > CMakeFiles/pbscpp_problem3_part2.dir/src/IShop.cpp.i

CMakeFiles/pbscpp_problem3_part2.dir/src/IShop.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pbscpp_problem3_part2.dir/src/IShop.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/nikita/Рабочий стол/pbscpp_problem3/git/pbscpp_problem3/pbscpp_problem3_part2/src/IShop.cpp" -o CMakeFiles/pbscpp_problem3_part2.dir/src/IShop.cpp.s

CMakeFiles/pbscpp_problem3_part2.dir/src/IShop.cpp.o.requires:

.PHONY : CMakeFiles/pbscpp_problem3_part2.dir/src/IShop.cpp.o.requires

CMakeFiles/pbscpp_problem3_part2.dir/src/IShop.cpp.o.provides: CMakeFiles/pbscpp_problem3_part2.dir/src/IShop.cpp.o.requires
	$(MAKE) -f CMakeFiles/pbscpp_problem3_part2.dir/build.make CMakeFiles/pbscpp_problem3_part2.dir/src/IShop.cpp.o.provides.build
.PHONY : CMakeFiles/pbscpp_problem3_part2.dir/src/IShop.cpp.o.provides

CMakeFiles/pbscpp_problem3_part2.dir/src/IShop.cpp.o.provides.build: CMakeFiles/pbscpp_problem3_part2.dir/src/IShop.cpp.o


# Object files for target pbscpp_problem3_part2
pbscpp_problem3_part2_OBJECTS = \
"CMakeFiles/pbscpp_problem3_part2.dir/main.cpp.o" \
"CMakeFiles/pbscpp_problem3_part2.dir/src/IProduct.cpp.o" \
"CMakeFiles/pbscpp_problem3_part2.dir/src/IShop.cpp.o"

# External object files for target pbscpp_problem3_part2
pbscpp_problem3_part2_EXTERNAL_OBJECTS =

pbscpp_problem3_part2: CMakeFiles/pbscpp_problem3_part2.dir/main.cpp.o
pbscpp_problem3_part2: CMakeFiles/pbscpp_problem3_part2.dir/src/IProduct.cpp.o
pbscpp_problem3_part2: CMakeFiles/pbscpp_problem3_part2.dir/src/IShop.cpp.o
pbscpp_problem3_part2: CMakeFiles/pbscpp_problem3_part2.dir/build.make
pbscpp_problem3_part2: lib/libgtest.a
pbscpp_problem3_part2: CMakeFiles/pbscpp_problem3_part2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/nikita/Рабочий стол/pbscpp_problem3/git/pbscpp_problem3/pbscpp_problem3_part2/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable pbscpp_problem3_part2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pbscpp_problem3_part2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pbscpp_problem3_part2.dir/build: pbscpp_problem3_part2

.PHONY : CMakeFiles/pbscpp_problem3_part2.dir/build

CMakeFiles/pbscpp_problem3_part2.dir/requires: CMakeFiles/pbscpp_problem3_part2.dir/main.cpp.o.requires
CMakeFiles/pbscpp_problem3_part2.dir/requires: CMakeFiles/pbscpp_problem3_part2.dir/src/IProduct.cpp.o.requires
CMakeFiles/pbscpp_problem3_part2.dir/requires: CMakeFiles/pbscpp_problem3_part2.dir/src/IShop.cpp.o.requires

.PHONY : CMakeFiles/pbscpp_problem3_part2.dir/requires

CMakeFiles/pbscpp_problem3_part2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pbscpp_problem3_part2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pbscpp_problem3_part2.dir/clean

CMakeFiles/pbscpp_problem3_part2.dir/depend:
	cd "/home/nikita/Рабочий стол/pbscpp_problem3/git/pbscpp_problem3/pbscpp_problem3_part2" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/nikita/Рабочий стол/pbscpp_problem3/git/pbscpp_problem3/pbscpp_problem3_part2" "/home/nikita/Рабочий стол/pbscpp_problem3/git/pbscpp_problem3/pbscpp_problem3_part2" "/home/nikita/Рабочий стол/pbscpp_problem3/git/pbscpp_problem3/pbscpp_problem3_part2" "/home/nikita/Рабочий стол/pbscpp_problem3/git/pbscpp_problem3/pbscpp_problem3_part2" "/home/nikita/Рабочий стол/pbscpp_problem3/git/pbscpp_problem3/pbscpp_problem3_part2/CMakeFiles/pbscpp_problem3_part2.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/pbscpp_problem3_part2.dir/depend

