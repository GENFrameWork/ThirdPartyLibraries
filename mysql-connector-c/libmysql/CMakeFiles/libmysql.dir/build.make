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
include libmysql/CMakeFiles/libmysql.dir/depend.make

# Include the progress variables for this target.
include libmysql/CMakeFiles/libmysql.dir/progress.make

# Include the compile flags for this target's objects.
include libmysql/CMakeFiles/libmysql.dir/flags.make

libmysql/CMakeFiles/libmysql.dir/libmysql_exports_file.cc.o: libmysql/CMakeFiles/libmysql.dir/flags.make
libmysql/CMakeFiles/libmysql.dir/libmysql_exports_file.cc.o: libmysql/libmysql_exports_file.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /mnt/GENFrameWork/ThirdPartyLibraries/mysql-connector-c/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object libmysql/CMakeFiles/libmysql.dir/libmysql_exports_file.cc.o"
	cd /mnt/GENFrameWork/ThirdPartyLibraries/mysql-connector-c/libmysql && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/libmysql.dir/libmysql_exports_file.cc.o -c /mnt/GENFrameWork/ThirdPartyLibraries/mysql-connector-c/libmysql/libmysql_exports_file.cc

libmysql/CMakeFiles/libmysql.dir/libmysql_exports_file.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libmysql.dir/libmysql_exports_file.cc.i"
	cd /mnt/GENFrameWork/ThirdPartyLibraries/mysql-connector-c/libmysql && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /mnt/GENFrameWork/ThirdPartyLibraries/mysql-connector-c/libmysql/libmysql_exports_file.cc > CMakeFiles/libmysql.dir/libmysql_exports_file.cc.i

libmysql/CMakeFiles/libmysql.dir/libmysql_exports_file.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libmysql.dir/libmysql_exports_file.cc.s"
	cd /mnt/GENFrameWork/ThirdPartyLibraries/mysql-connector-c/libmysql && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /mnt/GENFrameWork/ThirdPartyLibraries/mysql-connector-c/libmysql/libmysql_exports_file.cc -o CMakeFiles/libmysql.dir/libmysql_exports_file.cc.s

libmysql/CMakeFiles/libmysql.dir/libmysql_exports_file.cc.o.requires:
.PHONY : libmysql/CMakeFiles/libmysql.dir/libmysql_exports_file.cc.o.requires

libmysql/CMakeFiles/libmysql.dir/libmysql_exports_file.cc.o.provides: libmysql/CMakeFiles/libmysql.dir/libmysql_exports_file.cc.o.requires
	$(MAKE) -f libmysql/CMakeFiles/libmysql.dir/build.make libmysql/CMakeFiles/libmysql.dir/libmysql_exports_file.cc.o.provides.build
.PHONY : libmysql/CMakeFiles/libmysql.dir/libmysql_exports_file.cc.o.provides

libmysql/CMakeFiles/libmysql.dir/libmysql_exports_file.cc.o.provides.build: libmysql/CMakeFiles/libmysql.dir/libmysql_exports_file.cc.o

# Object files for target libmysql
libmysql_OBJECTS = \
"CMakeFiles/libmysql.dir/libmysql_exports_file.cc.o"

# External object files for target libmysql
libmysql_EXTERNAL_OBJECTS =

libmysql/libmysqlclient.so.18.4.: libmysql/CMakeFiles/libmysql.dir/libmysql_exports_file.cc.o
libmysql/libmysqlclient.so.18.4.: libmysql/CMakeFiles/libmysql.dir/build.make
libmysql/libmysqlclient.so.18.4.: libmysql/libclientlib.a
libmysql/libmysqlclient.so.18.4.: dbug/libdbug.a
libmysql/libmysqlclient.so.18.4.: strings/libstrings.a
libmysql/libmysqlclient.so.18.4.: vio/libvio.a
libmysql/libmysqlclient.so.18.4.: mysys/libmysys.a
libmysql/libmysqlclient.so.18.4.: mysys_ssl/libmysys_ssl.a
libmysql/libmysqlclient.so.18.4.: zlib/libzlib.a
libmysql/libmysqlclient.so.18.4.: extra/yassl/libyassl.a
libmysql/libmysqlclient.so.18.4.: extra/yassl/taocrypt/libtaocrypt.a
libmysql/libmysqlclient.so.18.4.: dbug/libdbug.a
libmysql/libmysqlclient.so.18.4.: mysys/libmysys.a
libmysql/libmysqlclient.so.18.4.: dbug/libdbug.a
libmysql/libmysqlclient.so.18.4.: mysys/libmysys.a
libmysql/libmysqlclient.so.18.4.: strings/libstrings.a
libmysql/libmysqlclient.so.18.4.: zlib/libzlib.a
libmysql/libmysqlclient.so.18.4.: libmysql/CMakeFiles/libmysql.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared library libmysqlclient.so"
	cd /mnt/GENFrameWork/ThirdPartyLibraries/mysql-connector-c/libmysql && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/libmysql.dir/link.txt --verbose=$(VERBOSE)
	cd /mnt/GENFrameWork/ThirdPartyLibraries/mysql-connector-c/libmysql && $(CMAKE_COMMAND) -E cmake_symlink_library libmysqlclient.so.18.4. libmysqlclient.so.18 libmysqlclient.so

libmysql/libmysqlclient.so.18: libmysql/libmysqlclient.so.18.4.

libmysql/libmysqlclient.so: libmysql/libmysqlclient.so.18.4.

# Rule to build all files generated by this target.
libmysql/CMakeFiles/libmysql.dir/build: libmysql/libmysqlclient.so
.PHONY : libmysql/CMakeFiles/libmysql.dir/build

libmysql/CMakeFiles/libmysql.dir/requires: libmysql/CMakeFiles/libmysql.dir/libmysql_exports_file.cc.o.requires
.PHONY : libmysql/CMakeFiles/libmysql.dir/requires

libmysql/CMakeFiles/libmysql.dir/clean:
	cd /mnt/GENFrameWork/ThirdPartyLibraries/mysql-connector-c/libmysql && $(CMAKE_COMMAND) -P CMakeFiles/libmysql.dir/cmake_clean.cmake
.PHONY : libmysql/CMakeFiles/libmysql.dir/clean

libmysql/CMakeFiles/libmysql.dir/depend:
	cd /mnt/GENFrameWork/ThirdPartyLibraries/mysql-connector-c && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/GENFrameWork/ThirdPartyLibraries/mysql-connector-c /mnt/GENFrameWork/ThirdPartyLibraries/mysql-connector-c/libmysql /mnt/GENFrameWork/ThirdPartyLibraries/mysql-connector-c /mnt/GENFrameWork/ThirdPartyLibraries/mysql-connector-c/libmysql /mnt/GENFrameWork/ThirdPartyLibraries/mysql-connector-c/libmysql/CMakeFiles/libmysql.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : libmysql/CMakeFiles/libmysql.dir/depend

