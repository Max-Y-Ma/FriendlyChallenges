#!/bin/bash

# Jason Stop Reading This You Cheater!

echo "Sorting File: $1" #Input File
echo "Sorting File by: $2" #Input Property

#Check To Do List is Valid: ToDoList1.txt, ToDoList2.txt
if test "$1" != "../Tests/ToDoList1" && test "$1" != "../Tests/ToDoList2"
then
    echo -e "\n!!!Invalid To Do List!!!"
    exit 0
fi
#Check Property is Valid: Date, Priority, Category, and Progress
if test "$2" != "Priority" && test "$2" != "Category" && test "$2" != "Progress"
then
    echo -e "\n!!!Invalid Property!!!"
    exit 1
fi

filePath=$1_Golden_$2.txt
#Create File
if [ -f "$filePath" ] 
then
    echo $filePath Exists!
else
    echo "$filePath Doesn't Exists! Creating Now!"
    touch $filePath
fi

#Processing File
tempFile=temp.txt
touch $tempFile # Temp File used for Sorting
flag=1 # Used to Skip First Line
while IFS= read -r line
do
    if test $flag == 1 
    then
        flag=0
        echo "$line" > $filePath
        continue
    fi
    echo "$line" >> $tempFile
done < "$1"

#Sorting Files
case $2 in 
    "Priority")
        echo -e "\n...Sorting by Priority"
        sort -k 5 -n $tempFile >> $filePath
        ;;
    "Category")
        echo -e "\n...Sorting by Category"
        sort -k 6 $tempFile >> $filePath
        ;;
    "Progress")
        echo -e "\n...Sorting by Progress"
        sort -k 7 -r -n $tempFile >> $filePath
        ;;
    "*")
        echo "!!!Invalid Sorting!!!"
        exit 2
        ;;
esac

rm $tempFile # Remove Temp File





