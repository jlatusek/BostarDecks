#!/bin/bash

set -e
set -x

if [ ! -d build ]; then
    mkdir build
    pushd build

    conan install .. --build=missing -s build_type=Debug --profile clang
    cmake .. -DCMAKE_BUILD_TYPE=Debug -DCMAKE_C_COMPILER=/usr/bin/clang -DCMAKE_CXX_COMPILER=/usr/bin/clang++
    popd
fi
cmake --build build -j11
