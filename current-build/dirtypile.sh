

#read name

g++ -Wall -Wpedantic -o $1 ../src/$1.cpp -lm -lncurses

# run script
./$1
