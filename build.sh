#!/bin/bash

set -e
set -x

rm -rf build
mkdir build
pushd build

conan install .. --build=missing -s build_type=Debug
cmake .. -DCMAKE_BUILD_TYPE=Debug
cmake --build . -j8
