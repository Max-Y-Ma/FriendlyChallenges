#!/bin/bash

echo "Compiling Files..."
gcc -Wall -Werror -std=c11 SubStringPalindrome.c main.c -o SubStringPalindrome
if [ $? -ne 0 ]
then
    echo "Compile Failed!"
    exit 1
else
    echo "Compile Success!"
fi
echo "Running Files..."
echo ""
./SubStringPalindrome
exit 0
