# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/koloumpras/Development/Database Implementation/Final"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/koloumpras/Development/Database Implementation/Final/build"

# Include any dependencies generated for this target.
include CMakeFiles/main.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.dir/flags.make

CMakeFiles/main.dir/main.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/main.cpp.o: ../main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report "/home/koloumpras/Development/Database Implementation/Final/build/CMakeFiles" $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/main.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/main.dir/main.cpp.o -c "/home/koloumpras/Development/Database Implementation/Final/main.cpp"

CMakeFiles/main.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E "/home/koloumpras/Development/Database Implementation/Final/main.cpp" > CMakeFiles/main.dir/main.cpp.i

CMakeFiles/main.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S "/home/koloumpras/Development/Database Implementation/Final/main.cpp" -o CMakeFiles/main.dir/main.cpp.s

CMakeFiles/main.dir/main.cpp.o.requires:
.PHONY : CMakeFiles/main.dir/main.cpp.o.requires

CMakeFiles/main.dir/main.cpp.o.provides: CMakeFiles/main.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/main.dir/main.cpp.o.provides

CMakeFiles/main.dir/main.cpp.o.provides.build: CMakeFiles/main.dir/main.cpp.o

CMakeFiles/main.dir/STORM_BufferManager.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/STORM_BufferManager.cpp.o: ../STORM_BufferManager.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report "/home/koloumpras/Development/Database Implementation/Final/build/CMakeFiles" $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/main.dir/STORM_BufferManager.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/main.dir/STORM_BufferManager.cpp.o -c "/home/koloumpras/Development/Database Implementation/Final/STORM_BufferManager.cpp"

CMakeFiles/main.dir/STORM_BufferManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/STORM_BufferManager.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E "/home/koloumpras/Development/Database Implementation/Final/STORM_BufferManager.cpp" > CMakeFiles/main.dir/STORM_BufferManager.cpp.i

CMakeFiles/main.dir/STORM_BufferManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/STORM_BufferManager.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S "/home/koloumpras/Development/Database Implementation/Final/STORM_BufferManager.cpp" -o CMakeFiles/main.dir/STORM_BufferManager.cpp.s

CMakeFiles/main.dir/STORM_BufferManager.cpp.o.requires:
.PHONY : CMakeFiles/main.dir/STORM_BufferManager.cpp.o.requires

CMakeFiles/main.dir/STORM_BufferManager.cpp.o.provides: CMakeFiles/main.dir/STORM_BufferManager.cpp.o.requires
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/STORM_BufferManager.cpp.o.provides.build
.PHONY : CMakeFiles/main.dir/STORM_BufferManager.cpp.o.provides

CMakeFiles/main.dir/STORM_BufferManager.cpp.o.provides.build: CMakeFiles/main.dir/STORM_BufferManager.cpp.o

CMakeFiles/main.dir/STORM_FileHandle.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/STORM_FileHandle.cpp.o: ../STORM_FileHandle.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report "/home/koloumpras/Development/Database Implementation/Final/build/CMakeFiles" $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/main.dir/STORM_FileHandle.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/main.dir/STORM_FileHandle.cpp.o -c "/home/koloumpras/Development/Database Implementation/Final/STORM_FileHandle.cpp"

CMakeFiles/main.dir/STORM_FileHandle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/STORM_FileHandle.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E "/home/koloumpras/Development/Database Implementation/Final/STORM_FileHandle.cpp" > CMakeFiles/main.dir/STORM_FileHandle.cpp.i

CMakeFiles/main.dir/STORM_FileHandle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/STORM_FileHandle.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S "/home/koloumpras/Development/Database Implementation/Final/STORM_FileHandle.cpp" -o CMakeFiles/main.dir/STORM_FileHandle.cpp.s

CMakeFiles/main.dir/STORM_FileHandle.cpp.o.requires:
.PHONY : CMakeFiles/main.dir/STORM_FileHandle.cpp.o.requires

CMakeFiles/main.dir/STORM_FileHandle.cpp.o.provides: CMakeFiles/main.dir/STORM_FileHandle.cpp.o.requires
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/STORM_FileHandle.cpp.o.provides.build
.PHONY : CMakeFiles/main.dir/STORM_FileHandle.cpp.o.provides

CMakeFiles/main.dir/STORM_FileHandle.cpp.o.provides.build: CMakeFiles/main.dir/STORM_FileHandle.cpp.o

CMakeFiles/main.dir/STORM_Frame.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/STORM_Frame.cpp.o: ../STORM_Frame.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report "/home/koloumpras/Development/Database Implementation/Final/build/CMakeFiles" $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/main.dir/STORM_Frame.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/main.dir/STORM_Frame.cpp.o -c "/home/koloumpras/Development/Database Implementation/Final/STORM_Frame.cpp"

CMakeFiles/main.dir/STORM_Frame.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/STORM_Frame.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E "/home/koloumpras/Development/Database Implementation/Final/STORM_Frame.cpp" > CMakeFiles/main.dir/STORM_Frame.cpp.i

CMakeFiles/main.dir/STORM_Frame.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/STORM_Frame.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S "/home/koloumpras/Development/Database Implementation/Final/STORM_Frame.cpp" -o CMakeFiles/main.dir/STORM_Frame.cpp.s

CMakeFiles/main.dir/STORM_Frame.cpp.o.requires:
.PHONY : CMakeFiles/main.dir/STORM_Frame.cpp.o.requires

CMakeFiles/main.dir/STORM_Frame.cpp.o.provides: CMakeFiles/main.dir/STORM_Frame.cpp.o.requires
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/STORM_Frame.cpp.o.provides.build
.PHONY : CMakeFiles/main.dir/STORM_Frame.cpp.o.provides

CMakeFiles/main.dir/STORM_Frame.cpp.o.provides.build: CMakeFiles/main.dir/STORM_Frame.cpp.o

CMakeFiles/main.dir/STORM_PageHandle.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/STORM_PageHandle.cpp.o: ../STORM_PageHandle.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report "/home/koloumpras/Development/Database Implementation/Final/build/CMakeFiles" $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/main.dir/STORM_PageHandle.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/main.dir/STORM_PageHandle.cpp.o -c "/home/koloumpras/Development/Database Implementation/Final/STORM_PageHandle.cpp"

CMakeFiles/main.dir/STORM_PageHandle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/STORM_PageHandle.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E "/home/koloumpras/Development/Database Implementation/Final/STORM_PageHandle.cpp" > CMakeFiles/main.dir/STORM_PageHandle.cpp.i

CMakeFiles/main.dir/STORM_PageHandle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/STORM_PageHandle.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S "/home/koloumpras/Development/Database Implementation/Final/STORM_PageHandle.cpp" -o CMakeFiles/main.dir/STORM_PageHandle.cpp.s

CMakeFiles/main.dir/STORM_PageHandle.cpp.o.requires:
.PHONY : CMakeFiles/main.dir/STORM_PageHandle.cpp.o.requires

CMakeFiles/main.dir/STORM_PageHandle.cpp.o.provides: CMakeFiles/main.dir/STORM_PageHandle.cpp.o.requires
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/STORM_PageHandle.cpp.o.provides.build
.PHONY : CMakeFiles/main.dir/STORM_PageHandle.cpp.o.provides

CMakeFiles/main.dir/STORM_PageHandle.cpp.o.provides.build: CMakeFiles/main.dir/STORM_PageHandle.cpp.o

CMakeFiles/main.dir/STORM_StorageManager.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/STORM_StorageManager.cpp.o: ../STORM_StorageManager.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report "/home/koloumpras/Development/Database Implementation/Final/build/CMakeFiles" $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/main.dir/STORM_StorageManager.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/main.dir/STORM_StorageManager.cpp.o -c "/home/koloumpras/Development/Database Implementation/Final/STORM_StorageManager.cpp"

CMakeFiles/main.dir/STORM_StorageManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/STORM_StorageManager.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E "/home/koloumpras/Development/Database Implementation/Final/STORM_StorageManager.cpp" > CMakeFiles/main.dir/STORM_StorageManager.cpp.i

CMakeFiles/main.dir/STORM_StorageManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/STORM_StorageManager.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S "/home/koloumpras/Development/Database Implementation/Final/STORM_StorageManager.cpp" -o CMakeFiles/main.dir/STORM_StorageManager.cpp.s

CMakeFiles/main.dir/STORM_StorageManager.cpp.o.requires:
.PHONY : CMakeFiles/main.dir/STORM_StorageManager.cpp.o.requires

CMakeFiles/main.dir/STORM_StorageManager.cpp.o.provides: CMakeFiles/main.dir/STORM_StorageManager.cpp.o.requires
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/STORM_StorageManager.cpp.o.provides.build
.PHONY : CMakeFiles/main.dir/STORM_StorageManager.cpp.o.provides

CMakeFiles/main.dir/STORM_StorageManager.cpp.o.provides.build: CMakeFiles/main.dir/STORM_StorageManager.cpp.o

CMakeFiles/main.dir/REM_RecordFileHandle.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/REM_RecordFileHandle.cpp.o: ../REM_RecordFileHandle.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report "/home/koloumpras/Development/Database Implementation/Final/build/CMakeFiles" $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/main.dir/REM_RecordFileHandle.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/main.dir/REM_RecordFileHandle.cpp.o -c "/home/koloumpras/Development/Database Implementation/Final/REM_RecordFileHandle.cpp"

CMakeFiles/main.dir/REM_RecordFileHandle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/REM_RecordFileHandle.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E "/home/koloumpras/Development/Database Implementation/Final/REM_RecordFileHandle.cpp" > CMakeFiles/main.dir/REM_RecordFileHandle.cpp.i

CMakeFiles/main.dir/REM_RecordFileHandle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/REM_RecordFileHandle.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S "/home/koloumpras/Development/Database Implementation/Final/REM_RecordFileHandle.cpp" -o CMakeFiles/main.dir/REM_RecordFileHandle.cpp.s

CMakeFiles/main.dir/REM_RecordFileHandle.cpp.o.requires:
.PHONY : CMakeFiles/main.dir/REM_RecordFileHandle.cpp.o.requires

CMakeFiles/main.dir/REM_RecordFileHandle.cpp.o.provides: CMakeFiles/main.dir/REM_RecordFileHandle.cpp.o.requires
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/REM_RecordFileHandle.cpp.o.provides.build
.PHONY : CMakeFiles/main.dir/REM_RecordFileHandle.cpp.o.provides

CMakeFiles/main.dir/REM_RecordFileHandle.cpp.o.provides.build: CMakeFiles/main.dir/REM_RecordFileHandle.cpp.o

CMakeFiles/main.dir/REM_RecordFileManager.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/REM_RecordFileManager.cpp.o: ../REM_RecordFileManager.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report "/home/koloumpras/Development/Database Implementation/Final/build/CMakeFiles" $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/main.dir/REM_RecordFileManager.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/main.dir/REM_RecordFileManager.cpp.o -c "/home/koloumpras/Development/Database Implementation/Final/REM_RecordFileManager.cpp"

CMakeFiles/main.dir/REM_RecordFileManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/REM_RecordFileManager.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E "/home/koloumpras/Development/Database Implementation/Final/REM_RecordFileManager.cpp" > CMakeFiles/main.dir/REM_RecordFileManager.cpp.i

CMakeFiles/main.dir/REM_RecordFileManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/REM_RecordFileManager.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S "/home/koloumpras/Development/Database Implementation/Final/REM_RecordFileManager.cpp" -o CMakeFiles/main.dir/REM_RecordFileManager.cpp.s

CMakeFiles/main.dir/REM_RecordFileManager.cpp.o.requires:
.PHONY : CMakeFiles/main.dir/REM_RecordFileManager.cpp.o.requires

CMakeFiles/main.dir/REM_RecordFileManager.cpp.o.provides: CMakeFiles/main.dir/REM_RecordFileManager.cpp.o.requires
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/REM_RecordFileManager.cpp.o.provides.build
.PHONY : CMakeFiles/main.dir/REM_RecordFileManager.cpp.o.provides

CMakeFiles/main.dir/REM_RecordFileManager.cpp.o.provides.build: CMakeFiles/main.dir/REM_RecordFileManager.cpp.o

CMakeFiles/main.dir/REM_RecordFileScan.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/REM_RecordFileScan.cpp.o: ../REM_RecordFileScan.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report "/home/koloumpras/Development/Database Implementation/Final/build/CMakeFiles" $(CMAKE_PROGRESS_9)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/main.dir/REM_RecordFileScan.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/main.dir/REM_RecordFileScan.cpp.o -c "/home/koloumpras/Development/Database Implementation/Final/REM_RecordFileScan.cpp"

CMakeFiles/main.dir/REM_RecordFileScan.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/REM_RecordFileScan.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E "/home/koloumpras/Development/Database Implementation/Final/REM_RecordFileScan.cpp" > CMakeFiles/main.dir/REM_RecordFileScan.cpp.i

CMakeFiles/main.dir/REM_RecordFileScan.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/REM_RecordFileScan.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S "/home/koloumpras/Development/Database Implementation/Final/REM_RecordFileScan.cpp" -o CMakeFiles/main.dir/REM_RecordFileScan.cpp.s

CMakeFiles/main.dir/REM_RecordFileScan.cpp.o.requires:
.PHONY : CMakeFiles/main.dir/REM_RecordFileScan.cpp.o.requires

CMakeFiles/main.dir/REM_RecordFileScan.cpp.o.provides: CMakeFiles/main.dir/REM_RecordFileScan.cpp.o.requires
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/REM_RecordFileScan.cpp.o.provides.build
.PHONY : CMakeFiles/main.dir/REM_RecordFileScan.cpp.o.provides

CMakeFiles/main.dir/REM_RecordFileScan.cpp.o.provides.build: CMakeFiles/main.dir/REM_RecordFileScan.cpp.o

CMakeFiles/main.dir/REM_RecordHandle.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/REM_RecordHandle.cpp.o: ../REM_RecordHandle.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report "/home/koloumpras/Development/Database Implementation/Final/build/CMakeFiles" $(CMAKE_PROGRESS_10)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/main.dir/REM_RecordHandle.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/main.dir/REM_RecordHandle.cpp.o -c "/home/koloumpras/Development/Database Implementation/Final/REM_RecordHandle.cpp"

CMakeFiles/main.dir/REM_RecordHandle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/REM_RecordHandle.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E "/home/koloumpras/Development/Database Implementation/Final/REM_RecordHandle.cpp" > CMakeFiles/main.dir/REM_RecordHandle.cpp.i

CMakeFiles/main.dir/REM_RecordHandle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/REM_RecordHandle.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S "/home/koloumpras/Development/Database Implementation/Final/REM_RecordHandle.cpp" -o CMakeFiles/main.dir/REM_RecordHandle.cpp.s

CMakeFiles/main.dir/REM_RecordHandle.cpp.o.requires:
.PHONY : CMakeFiles/main.dir/REM_RecordHandle.cpp.o.requires

CMakeFiles/main.dir/REM_RecordHandle.cpp.o.provides: CMakeFiles/main.dir/REM_RecordHandle.cpp.o.requires
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/REM_RecordHandle.cpp.o.provides.build
.PHONY : CMakeFiles/main.dir/REM_RecordHandle.cpp.o.provides

CMakeFiles/main.dir/REM_RecordHandle.cpp.o.provides.build: CMakeFiles/main.dir/REM_RecordHandle.cpp.o

CMakeFiles/main.dir/REM_RecordID.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/REM_RecordID.cpp.o: ../REM_RecordID.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report "/home/koloumpras/Development/Database Implementation/Final/build/CMakeFiles" $(CMAKE_PROGRESS_11)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/main.dir/REM_RecordID.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/main.dir/REM_RecordID.cpp.o -c "/home/koloumpras/Development/Database Implementation/Final/REM_RecordID.cpp"

CMakeFiles/main.dir/REM_RecordID.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/REM_RecordID.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E "/home/koloumpras/Development/Database Implementation/Final/REM_RecordID.cpp" > CMakeFiles/main.dir/REM_RecordID.cpp.i

CMakeFiles/main.dir/REM_RecordID.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/REM_RecordID.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S "/home/koloumpras/Development/Database Implementation/Final/REM_RecordID.cpp" -o CMakeFiles/main.dir/REM_RecordID.cpp.s

CMakeFiles/main.dir/REM_RecordID.cpp.o.requires:
.PHONY : CMakeFiles/main.dir/REM_RecordID.cpp.o.requires

CMakeFiles/main.dir/REM_RecordID.cpp.o.provides: CMakeFiles/main.dir/REM_RecordID.cpp.o.requires
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/REM_RecordID.cpp.o.provides.build
.PHONY : CMakeFiles/main.dir/REM_RecordID.cpp.o.provides

CMakeFiles/main.dir/REM_RecordID.cpp.o.provides.build: CMakeFiles/main.dir/REM_RecordID.cpp.o

CMakeFiles/main.dir/retcodes.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/retcodes.cpp.o: ../retcodes.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report "/home/koloumpras/Development/Database Implementation/Final/build/CMakeFiles" $(CMAKE_PROGRESS_12)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/main.dir/retcodes.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/main.dir/retcodes.cpp.o -c "/home/koloumpras/Development/Database Implementation/Final/retcodes.cpp"

CMakeFiles/main.dir/retcodes.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/retcodes.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E "/home/koloumpras/Development/Database Implementation/Final/retcodes.cpp" > CMakeFiles/main.dir/retcodes.cpp.i

CMakeFiles/main.dir/retcodes.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/retcodes.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S "/home/koloumpras/Development/Database Implementation/Final/retcodes.cpp" -o CMakeFiles/main.dir/retcodes.cpp.s

CMakeFiles/main.dir/retcodes.cpp.o.requires:
.PHONY : CMakeFiles/main.dir/retcodes.cpp.o.requires

CMakeFiles/main.dir/retcodes.cpp.o.provides: CMakeFiles/main.dir/retcodes.cpp.o.requires
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/retcodes.cpp.o.provides.build
.PHONY : CMakeFiles/main.dir/retcodes.cpp.o.provides

CMakeFiles/main.dir/retcodes.cpp.o.provides.build: CMakeFiles/main.dir/retcodes.cpp.o

CMakeFiles/main.dir/UTILS_misc.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/UTILS_misc.cpp.o: ../UTILS_misc.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report "/home/koloumpras/Development/Database Implementation/Final/build/CMakeFiles" $(CMAKE_PROGRESS_13)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/main.dir/UTILS_misc.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/main.dir/UTILS_misc.cpp.o -c "/home/koloumpras/Development/Database Implementation/Final/UTILS_misc.cpp"

CMakeFiles/main.dir/UTILS_misc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/UTILS_misc.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E "/home/koloumpras/Development/Database Implementation/Final/UTILS_misc.cpp" > CMakeFiles/main.dir/UTILS_misc.cpp.i

CMakeFiles/main.dir/UTILS_misc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/UTILS_misc.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S "/home/koloumpras/Development/Database Implementation/Final/UTILS_misc.cpp" -o CMakeFiles/main.dir/UTILS_misc.cpp.s

CMakeFiles/main.dir/UTILS_misc.cpp.o.requires:
.PHONY : CMakeFiles/main.dir/UTILS_misc.cpp.o.requires

CMakeFiles/main.dir/UTILS_misc.cpp.o.provides: CMakeFiles/main.dir/UTILS_misc.cpp.o.requires
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/UTILS_misc.cpp.o.provides.build
.PHONY : CMakeFiles/main.dir/UTILS_misc.cpp.o.provides

CMakeFiles/main.dir/UTILS_misc.cpp.o.provides.build: CMakeFiles/main.dir/UTILS_misc.cpp.o

CMakeFiles/main.dir/SYSM_DBM.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/SYSM_DBM.cpp.o: ../SYSM_DBM.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report "/home/koloumpras/Development/Database Implementation/Final/build/CMakeFiles" $(CMAKE_PROGRESS_14)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/main.dir/SYSM_DBM.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/main.dir/SYSM_DBM.cpp.o -c "/home/koloumpras/Development/Database Implementation/Final/SYSM_DBM.cpp"

CMakeFiles/main.dir/SYSM_DBM.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/SYSM_DBM.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E "/home/koloumpras/Development/Database Implementation/Final/SYSM_DBM.cpp" > CMakeFiles/main.dir/SYSM_DBM.cpp.i

CMakeFiles/main.dir/SYSM_DBM.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/SYSM_DBM.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S "/home/koloumpras/Development/Database Implementation/Final/SYSM_DBM.cpp" -o CMakeFiles/main.dir/SYSM_DBM.cpp.s

CMakeFiles/main.dir/SYSM_DBM.cpp.o.requires:
.PHONY : CMakeFiles/main.dir/SYSM_DBM.cpp.o.requires

CMakeFiles/main.dir/SYSM_DBM.cpp.o.provides: CMakeFiles/main.dir/SYSM_DBM.cpp.o.requires
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/SYSM_DBM.cpp.o.provides.build
.PHONY : CMakeFiles/main.dir/SYSM_DBM.cpp.o.provides

CMakeFiles/main.dir/SYSM_DBM.cpp.o.provides.build: CMakeFiles/main.dir/SYSM_DBM.cpp.o

CMakeFiles/main.dir/SSQLM_DDL.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/SSQLM_DDL.cpp.o: ../SSQLM_DDL.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report "/home/koloumpras/Development/Database Implementation/Final/build/CMakeFiles" $(CMAKE_PROGRESS_15)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/main.dir/SSQLM_DDL.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/main.dir/SSQLM_DDL.cpp.o -c "/home/koloumpras/Development/Database Implementation/Final/SSQLM_DDL.cpp"

CMakeFiles/main.dir/SSQLM_DDL.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/SSQLM_DDL.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E "/home/koloumpras/Development/Database Implementation/Final/SSQLM_DDL.cpp" > CMakeFiles/main.dir/SSQLM_DDL.cpp.i

CMakeFiles/main.dir/SSQLM_DDL.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/SSQLM_DDL.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S "/home/koloumpras/Development/Database Implementation/Final/SSQLM_DDL.cpp" -o CMakeFiles/main.dir/SSQLM_DDL.cpp.s

CMakeFiles/main.dir/SSQLM_DDL.cpp.o.requires:
.PHONY : CMakeFiles/main.dir/SSQLM_DDL.cpp.o.requires

CMakeFiles/main.dir/SSQLM_DDL.cpp.o.provides: CMakeFiles/main.dir/SSQLM_DDL.cpp.o.requires
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/SSQLM_DDL.cpp.o.provides.build
.PHONY : CMakeFiles/main.dir/SSQLM_DDL.cpp.o.provides

CMakeFiles/main.dir/SSQLM_DDL.cpp.o.provides.build: CMakeFiles/main.dir/SSQLM_DDL.cpp.o

CMakeFiles/main.dir/SSQLM_DML.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/SSQLM_DML.cpp.o: ../SSQLM_DML.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report "/home/koloumpras/Development/Database Implementation/Final/build/CMakeFiles" $(CMAKE_PROGRESS_16)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/main.dir/SSQLM_DML.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/main.dir/SSQLM_DML.cpp.o -c "/home/koloumpras/Development/Database Implementation/Final/SSQLM_DML.cpp"

CMakeFiles/main.dir/SSQLM_DML.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/SSQLM_DML.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E "/home/koloumpras/Development/Database Implementation/Final/SSQLM_DML.cpp" > CMakeFiles/main.dir/SSQLM_DML.cpp.i

CMakeFiles/main.dir/SSQLM_DML.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/SSQLM_DML.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S "/home/koloumpras/Development/Database Implementation/Final/SSQLM_DML.cpp" -o CMakeFiles/main.dir/SSQLM_DML.cpp.s

CMakeFiles/main.dir/SSQLM_DML.cpp.o.requires:
.PHONY : CMakeFiles/main.dir/SSQLM_DML.cpp.o.requires

CMakeFiles/main.dir/SSQLM_DML.cpp.o.provides: CMakeFiles/main.dir/SSQLM_DML.cpp.o.requires
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/SSQLM_DML.cpp.o.provides.build
.PHONY : CMakeFiles/main.dir/SSQLM_DML.cpp.o.provides

CMakeFiles/main.dir/SSQLM_DML.cpp.o.provides.build: CMakeFiles/main.dir/SSQLM_DML.cpp.o

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/main.cpp.o" \
"CMakeFiles/main.dir/STORM_BufferManager.cpp.o" \
"CMakeFiles/main.dir/STORM_FileHandle.cpp.o" \
"CMakeFiles/main.dir/STORM_Frame.cpp.o" \
"CMakeFiles/main.dir/STORM_PageHandle.cpp.o" \
"CMakeFiles/main.dir/STORM_StorageManager.cpp.o" \
"CMakeFiles/main.dir/REM_RecordFileHandle.cpp.o" \
"CMakeFiles/main.dir/REM_RecordFileManager.cpp.o" \
"CMakeFiles/main.dir/REM_RecordFileScan.cpp.o" \
"CMakeFiles/main.dir/REM_RecordHandle.cpp.o" \
"CMakeFiles/main.dir/REM_RecordID.cpp.o" \
"CMakeFiles/main.dir/retcodes.cpp.o" \
"CMakeFiles/main.dir/UTILS_misc.cpp.o" \
"CMakeFiles/main.dir/SYSM_DBM.cpp.o" \
"CMakeFiles/main.dir/SSQLM_DDL.cpp.o" \
"CMakeFiles/main.dir/SSQLM_DML.cpp.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

main: CMakeFiles/main.dir/main.cpp.o
main: CMakeFiles/main.dir/STORM_BufferManager.cpp.o
main: CMakeFiles/main.dir/STORM_FileHandle.cpp.o
main: CMakeFiles/main.dir/STORM_Frame.cpp.o
main: CMakeFiles/main.dir/STORM_PageHandle.cpp.o
main: CMakeFiles/main.dir/STORM_StorageManager.cpp.o
main: CMakeFiles/main.dir/REM_RecordFileHandle.cpp.o
main: CMakeFiles/main.dir/REM_RecordFileManager.cpp.o
main: CMakeFiles/main.dir/REM_RecordFileScan.cpp.o
main: CMakeFiles/main.dir/REM_RecordHandle.cpp.o
main: CMakeFiles/main.dir/REM_RecordID.cpp.o
main: CMakeFiles/main.dir/retcodes.cpp.o
main: CMakeFiles/main.dir/UTILS_misc.cpp.o
main: CMakeFiles/main.dir/SYSM_DBM.cpp.o
main: CMakeFiles/main.dir/SSQLM_DDL.cpp.o
main: CMakeFiles/main.dir/SSQLM_DML.cpp.o
main: CMakeFiles/main.dir/build.make
main: CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main.dir/build: main
.PHONY : CMakeFiles/main.dir/build

CMakeFiles/main.dir/requires: CMakeFiles/main.dir/main.cpp.o.requires
CMakeFiles/main.dir/requires: CMakeFiles/main.dir/STORM_BufferManager.cpp.o.requires
CMakeFiles/main.dir/requires: CMakeFiles/main.dir/STORM_FileHandle.cpp.o.requires
CMakeFiles/main.dir/requires: CMakeFiles/main.dir/STORM_Frame.cpp.o.requires
CMakeFiles/main.dir/requires: CMakeFiles/main.dir/STORM_PageHandle.cpp.o.requires
CMakeFiles/main.dir/requires: CMakeFiles/main.dir/STORM_StorageManager.cpp.o.requires
CMakeFiles/main.dir/requires: CMakeFiles/main.dir/REM_RecordFileHandle.cpp.o.requires
CMakeFiles/main.dir/requires: CMakeFiles/main.dir/REM_RecordFileManager.cpp.o.requires
CMakeFiles/main.dir/requires: CMakeFiles/main.dir/REM_RecordFileScan.cpp.o.requires
CMakeFiles/main.dir/requires: CMakeFiles/main.dir/REM_RecordHandle.cpp.o.requires
CMakeFiles/main.dir/requires: CMakeFiles/main.dir/REM_RecordID.cpp.o.requires
CMakeFiles/main.dir/requires: CMakeFiles/main.dir/retcodes.cpp.o.requires
CMakeFiles/main.dir/requires: CMakeFiles/main.dir/UTILS_misc.cpp.o.requires
CMakeFiles/main.dir/requires: CMakeFiles/main.dir/SYSM_DBM.cpp.o.requires
CMakeFiles/main.dir/requires: CMakeFiles/main.dir/SSQLM_DDL.cpp.o.requires
CMakeFiles/main.dir/requires: CMakeFiles/main.dir/SSQLM_DML.cpp.o.requires
.PHONY : CMakeFiles/main.dir/requires

CMakeFiles/main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main.dir/clean

CMakeFiles/main.dir/depend:
	cd "/home/koloumpras/Development/Database Implementation/Final/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/koloumpras/Development/Database Implementation/Final" "/home/koloumpras/Development/Database Implementation/Final" "/home/koloumpras/Development/Database Implementation/Final/build" "/home/koloumpras/Development/Database Implementation/Final/build" "/home/koloumpras/Development/Database Implementation/Final/build/CMakeFiles/main.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/main.dir/depend

