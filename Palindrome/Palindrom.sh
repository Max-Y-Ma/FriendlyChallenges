#!/bin/bash
echo "Compiling Palindrome.cpp..."
g++ -g -Wall -Werror -std=c++11 Palindrom.cpp -o Palindrom.out
if [ $? -ne 0 ]
then
    echo "Compile Failed!"
    exit 1
else
    echo "Compile Success!"
fi
echo "Running Palindrome.cpp..."
echo ""
./Palindrom.out
exit 0
