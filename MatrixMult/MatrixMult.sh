#!/bin/bash

echo "Compiling Files..."
g++ -Wall -Werror -std=c++11 MatrixMult.cpp -o MatrixMult
if [ $? -ne 0 ]
then
    echo "Compile Failed!"
    exit 1
else
    echo "Compile Success!"
fi
echo "Running Files..."
echo ""
./MatrixMult
exit 0