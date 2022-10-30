#!/bin/bash

echo "Compiling Files..."
g++ -Wall -Werror -std=c++11 GreaterWordPerm.cpp -o GreaterWordPerm
if [ $? -ne 0 ]
then
    echo "Compile Failed!"
    exit 1
else
    echo "Compile Success!"
fi
echo "Running Files..."
echo ""
./GreaterWordPerm
exit 0