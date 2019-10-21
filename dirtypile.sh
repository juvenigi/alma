#!/bin/bash

read name

g++ -Wall -Wpedantic -o current-build/$name src/$name.cpp -lm

./current-build/$name
