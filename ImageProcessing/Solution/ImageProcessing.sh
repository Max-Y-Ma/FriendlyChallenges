#!/bin/bash

logfile="./Output/log.txt"
rm $logfile
touch $logfile
echo "Image Being Processed: $1" >> $logfile

echo -e "\nCompiling Files..." >> $logfile
g++ -Wall -Werror -std=c++11 ImageProcessing.cpp main.cpp -o ImageProcessing
if [ $? -ne 0 ]
then
    echo "Compile Failed!" >> $logfile
    exit 1
else
    echo "Compile Success!" >> $logfile
fi
echo -e "\nRunning Files..." >> $logfile

./ImageProcessing $1 >> $logfile
exit 0