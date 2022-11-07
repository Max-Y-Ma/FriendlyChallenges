#!/bin/bash

#Testing for Valid Parameters
if test -f "$1" && test -f "$2"
then
    echo Comparing $1 to $2...
else
    echo -e "\n!!!Invalid Parameters!!!"
    exit 0
fi

#Comparing The Files
if cmp -s "$1" "$2"
then
    echo -e "\nTest Case $1 Passed!"
else
    echo -e "\nTest Case $1 Failed!"
fi