#!/bin/bash -xe
cat support/header.cc $1 | clang -x c++ -std=c++11 -Wall -
