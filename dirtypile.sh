deps=$(find src/deps/*.cpp)

g++ -Wall -Wpedantic -I src/deps/ -o build/$1 src/$1.cpp $deps -lm -lncurses -ggdb

# run script
#/$1
