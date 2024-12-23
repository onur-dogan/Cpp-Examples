#!/bin/bash

project_name="TreeNode"

echo "Creating a build folder for..."
[ -d build ] || mkdir build

cd build

echo "CMake building process has started..."

cmake ..
make
if [[ $? -ne 0 ]] ; then
    echo "Some issues have occurred in the building process!"
    exit 1
fi

echo "CMake Building processes are done successfully for Tree Node Class Examples!"

# If the first parameter sent as fortest, then shouldn't run the functions. It is just for testing build process
first_arg=$1
if [ "$first_arg" != "fortest" ]; then
    ./${project_name}
fi