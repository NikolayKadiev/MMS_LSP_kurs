#!/bin/bash

echo "compiling..."
gcc -c calc_main.c -o calc_main.o
gcc -c calc_sum.c -o calc_sum.o
echo "obj files created"
gcc calc_main.o calc_sum.o  -o $1
echo "file tipe: "
file $1
