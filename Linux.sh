#!/bin/bash

# output directory

target="Targets/$1"

# FSerate cmake build files

cmake -S . -B $target -DCMAKE_BUILD_TYPE=$1

# compile cmake build files

cmake --build $target --config $1
