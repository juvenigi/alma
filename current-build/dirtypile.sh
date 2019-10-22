#!/bin/bash

read name

g++ -Wall -Wpedantic -o $name ../src/$name.cpp -lm

./current-build/$name
