# Almost all CMake files should start with this
# You should always specify a range with the newest
# and oldest tested versions of CMake. This will ensure
# you pick up the best policies.
cmake_minimum_required(VERSION 3.10)

# Need to explicitly state in the CMake code that it should use the correct flags. 
# One way to enable support for a specific C++ standard in CMake is by using the CMAKE_CXX_STANDARD variable. 
# Set the CMAKE_CXX_STANDARD variable in the CMakeLists.txt file to 11 and CMAKE_CXX_STANDARD_REQUIRED to True. 
# *** Make sure to add the CMAKE_CXX_STANDARD declarations above the call to add_executable(). ***
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# project command as follows to set the project name
project(DateComparator C CXX)

set(SOURCES
	src/DateComparator.cpp
	src/main.cpp
)

# Add the executable files that defined as SOURCES above
add_executable(${PROJECT_NAME} ${SOURCES})

# Include the header files
target_include_directories(${PROJECT_NAME} 
	PRIVATE
	# PROJECT_SOURCE_DIR is the source directory of the last call to the project command made 
	# in the current directory scope or one of its parents. Note, it is not affected by calls to project
	# made within a child directory scope (i.e. from within a call to add_subdirectory() from the current scope).
	${PROJECT_SOURCE_DIR}/include
)

# For example, if C++ 11 features are used extensively in a project's header files, 
# then clients must use a compiler mode that is no less than C++ 11.
# This can be requested with this line
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_11)


# This is a "default" library, and will match the *** variable setting.
# Other common choices are STATIC, SHARED, and MODULE
# Including header files here helps IDEs but is not required.
# Output libname matches target name, with the usual extensions on your system
# add_library(example simple_lib.cpp simple_lib.hpp)
