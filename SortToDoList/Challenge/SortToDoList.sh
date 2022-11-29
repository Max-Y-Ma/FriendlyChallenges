#!/bin/bash
if test $2 == "Priority"
then
    (head -n 2 <$1> && tail -n +3 <$1> | sort -k 5 -n $1) > Result.txt
    #sort -k 5 -n $1 > Result.txt
    
elif test $2 == "Category"
then
    (head -n 2 <$1> && tail -n +3 <$1> | sort -k 6 $1) > Result.txt
    #sort -k 6 $1 > Result.txt
elif test $2 == "Progress"
then
    (head -n 2 <$1> && tail -n +3 <$1> | sort -k 7 -r -n $1) > Result.txt
    #sort -k 7 -r -n $1 > Result.txt
fi


