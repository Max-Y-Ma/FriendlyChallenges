#!/bin/bash
echo "Compiling Palindrome.cpp..."
g++ -Wall -Werror -std=c++11 Palindrom.cpp -o Palindrom
if [ $? -ne 0 ]
then
    echo "Compile Failed!"
    exit 1
else
    echo "Compile Success!"
fi
echo "Running Palindrome.cpp..."
echo ""
./Palindrom
exit 0
