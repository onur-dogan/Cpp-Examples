#!/bin/bash

# Show cmake version as initial
cmake --version

# Path of this(build_test) script
CURRENT_SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"

# First, move to the path of this script 
cd $CURRENT_SCRIPT_DIR
# Change path to root to get the example folders
cd ..

# The directory name which includes the class examples
CLASS_EXAMPLES_DIR="ClassExamples"

# The directories that will build
BUILD_DIRS=( )

# Get the folders under the root
EXAMPLE_DIRS="*/";

# Loop the folders under the root
for EXAMPLE_DIR in $EXAMPLE_DIRS
do
    # The folders **start with** GeneralExample are the folders that will be built
    if [[ $EXAMPLE_DIR == GeneralExample* ]]; then
        BUILD_DIRS+=($EXAMPLE_DIR)
    fi
done

# Insert the example folders which are under the class examples directory to the build list 
for CLASS_EXAMPLE_DIR in "${CLASS_EXAMPLES_DIR}/*"
do
    BUILD_DIRS+=($CLASS_EXAMPLE_DIR)
done

echo "Build tests are running..."
echo ""

# Counter for the successfully built
success_counter=0

# Test for each build folder
for BUILD_DIR in ${BUILD_DIRS[*]}
do      
    echo ""
    echo "Running test for $BUILD_DIR..."
    
    # Change path to path of the current sprint
    cd $CURRENT_SCRIPT_DIR
    # Change path to the root of the related build folder
    cd ../$BUILD_DIR

    # Check whether the related folder has a build folder already. If exists, remove it first
    if [ -d "build" ]; then
        echo "Existing $BUILD_DIR/build folder is deleting..."
        rm -r build
    fi
    
    # Check whether the related folder has a build sh file to run build processes. 
    # If it doesn't exist, print the error message and continue with the next build process 
    if [ ! -f "build.sh" ]; then
        echo "Build script doesn't exist for $BUILD_DIR !"
        continue
    fi

     # Run build script with an argument
     bash build.sh fortest

     if [ $? -ne 0 ]; then
        echo "Building test is failed for $BUILD_DIR !"
        continue
     fi

    # Increase counter for each successfully build process
    # let keyword usage is the same as success_counter=$((success_counter+1)) or just ((success_counter++)) 
    let success_counter++
done

# Printing the elements in a list methods by using asterisk(*) or at(@) symbols
# It returns each element as one element  
# for BUILD_DIR in "${BUILD_DIRS[*]}"; do echo "ARG['*']: '$BUILD_DIR'"; done

# It splits each element by space and returns the splitted elements as a list (Same as using asterisk(@))
# for BUILD_DIR in ${BUILD_DIRS[*]}; do echo "ARG[*]: '$BUILD_DIR'"; done

# It returns each element in the list as how they are
# for BUILD_DIR in "${BUILD_DIRS[@]}"; do echo "ARG['@']: '$BUILD_DIR'"; done

# It splits each element by space and returns the splitted elements as a list (Same as using asterisk(*))
# for BUILD_DIR in ${BUILD_DIRS[@]}; do echo "ARG[@]: '$BUILD_DIR'"; done

echo ""
# Using hash(#) returns the length of the list
echo "Congratulations!!! Tests are completed for ${success_counter}/${#BUILD_DIRS[@]}"