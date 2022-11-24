#!/usr/bin/python3

#Imports
import math as m

#Pascal Triangle Class
class PascalTriangle:
    def __init__(self, start, end):
        self.start = start - 1
        self.end = end - 1

    def compute_triangle(self):
        # For Each Row
        length = self.end - self.start
        for i in range(length + 1):
            # For Each Column In Row
            for j in range(i + self.start + 1):
                print(m.comb((i + self.start), j), end=" ")
            print()

# Take User Input
input_start = input("Enter Start Row: ")
input_end = input("Enter End Row: ")

# Create PascalTriangle Object
p = PascalTriangle(int(input_start), int(input_end))
p.compute_triangle()
