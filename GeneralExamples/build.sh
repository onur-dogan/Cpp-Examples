#!/bin/bash

project_name="GeneralExamples"

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

echo "CMake Building processes are done successfully for General Examples!"

./${project_name}