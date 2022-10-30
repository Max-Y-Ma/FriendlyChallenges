#!/bin/bash

echo "Compiling Code..."
g++ -Wall -Werror -std=c++11 srand_demo.cpp -o srand_demo
./srand_demo