# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.0

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
CMAKE_SOURCE_DIR = /mnt/GENFrameWork/ThirdPartyLibraries/mysql-connector-c

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/GENFrameWork/ThirdPartyLibraries/mysql-connector-c

# Include any dependencies generated for this target.
include testclients/CMakeFiles/mysql_client_test.dir/depend.make

# Include the progress variables for this target.
include testclients/CMakeFiles/mysql_client_test.dir/progress.make

# Include the compile flags for this target's objects.
include testclients/CMakeFiles/mysql_client_test.dir/flags.make

testclients/CMakeFiles/mysql_client_test.dir/mysql_client_test.c.o: testclients/CMakeFiles/mysql_client_test.dir/flags.make
testclients/CMakeFiles/mysql_client_test.dir/mysql_client_test.c.o: testclients/mysql_client_test.c
	$(CMAKE_COMMAND) -E cmake_progress_report /mnt/GENFrameWork/ThirdPartyLibraries/mysql-connector-c/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object testclients/CMakeFiles/mysql_client_test.dir/mysql_client_test.c.o"
	cd /mnt/GENFrameWork/ThirdPartyLibraries/mysql-connector-c/testclients && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/mysql_client_test.dir/mysql_client_test.c.o   -c /mnt/GENFrameWork/ThirdPartyLibraries/mysql-connector-c/testclients/mysql_client_test.c

testclients/CMakeFiles/mysql_client_test.dir/mysql_client_test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mysql_client_test.dir/mysql_client_test.c.i"
	cd /mnt/GENFrameWork/ThirdPartyLibraries/mysql-connector-c/testclients && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /mnt/GENFrameWork/ThirdPartyLibraries/mysql-connector-c/testclients/mysql_client_test.c > CMakeFiles/mysql_client_test.dir/mysql_client_test.c.i

testclients/CMakeFiles/mysql_client_test.dir/mysql_client_test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mysql_client_test.dir/mysql_client_test.c.s"
	cd /mnt/GENFrameWork/ThirdPartyLibraries/mysql-connector-c/testclients && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /mnt/GENFrameWork/ThirdPartyLibraries/mysql-connector-c/testclients/mysql_client_test.c -o CMakeFiles/mysql_client_test.dir/mysql_client_test.c.s

testclients/CMakeFiles/mysql_client_test.dir/mysql_client_test.c.o.requires:
.PHONY : testclients/CMakeFiles/mysql_client_test.dir/mysql_client_test.c.o.requires

testclients/CMakeFiles/mysql_client_test.dir/mysql_client_test.c.o.provides: testclients/CMakeFiles/mysql_client_test.dir/mysql_client_test.c.o.requires
	$(MAKE) -f testclients/CMakeFiles/mysql_client_test.dir/build.make testclients/CMakeFiles/mysql_client_test.dir/mysql_client_test.c.o.provides.build
.PHONY : testclients/CMakeFiles/mysql_client_test.dir/mysql_client_test.c.o.provides

testclients/CMakeFiles/mysql_client_test.dir/mysql_client_test.c.o.provides.build: testclients/CMakeFiles/mysql_client_test.dir/mysql_client_test.c.o

# Object files for target mysql_client_test
mysql_client_test_OBJECTS = \
"CMakeFiles/mysql_client_test.dir/mysql_client_test.c.o"

# External object files for target mysql_client_test
mysql_client_test_EXTERNAL_OBJECTS =

testclients/mysql_client_test: testclients/CMakeFiles/mysql_client_test.dir/mysql_client_test.c.o
testclients/mysql_client_test: testclients/CMakeFiles/mysql_client_test.dir/build.make
testclients/mysql_client_test: libmysql/libmysqlclient.a
testclients/mysql_client_test: testclients/CMakeFiles/mysql_client_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable mysql_client_test"
	cd /mnt/GENFrameWork/ThirdPartyLibraries/mysql-connector-c/testclients && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mysql_client_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
testclients/CMakeFiles/mysql_client_test.dir/build: testclients/mysql_client_test
.PHONY : testclients/CMakeFiles/mysql_client_test.dir/build

testclients/CMakeFiles/mysql_client_test.dir/requires: testclients/CMakeFiles/mysql_client_test.dir/mysql_client_test.c.o.requires
.PHONY : testclients/CMakeFiles/mysql_client_test.dir/requires

testclients/CMakeFiles/mysql_client_test.dir/clean:
	cd /mnt/GENFrameWork/ThirdPartyLibraries/mysql-connector-c/testclients && $(CMAKE_COMMAND) -P CMakeFiles/mysql_client_test.dir/cmake_clean.cmake
.PHONY : testclients/CMakeFiles/mysql_client_test.dir/clean

testclients/CMakeFiles/mysql_client_test.dir/depend:
	cd /mnt/GENFrameWork/ThirdPartyLibraries/mysql-connector-c && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/GENFrameWork/ThirdPartyLibraries/mysql-connector-c /mnt/GENFrameWork/ThirdPartyLibraries/mysql-connector-c/testclients /mnt/GENFrameWork/ThirdPartyLibraries/mysql-connector-c /mnt/GENFrameWork/ThirdPartyLibraries/mysql-connector-c/testclients /mnt/GENFrameWork/ThirdPartyLibraries/mysql-connector-c/testclients/CMakeFiles/mysql_client_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : testclients/CMakeFiles/mysql_client_test.dir/depend

