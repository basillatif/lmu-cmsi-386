# CMSI 386 Homework 3

Name: Jackson Watkins and Basil Latif

## Problem 1

For A[0][0], we get the memory address 0x556ec98891c0. For A[3][7], we get the memory address 0x556ec98892e8. When we generate all the possible array locations from A[0][0] to A[3][7], we find out that 8 bits are allocated for each place within the two-dimensional array. For example,  we have A[0][0] (0x556ec98891c0), A[0][1] (0x556ec98891c8), A[0][2] (0x556ec98891d0), etc. which each take up 8 bits in memory each.

## Problem 2

The first declaration recognizes that a is a pointer to a location index n in the array.

The second declaration creates a pointer b of type double that points to an array of size n.

The third declaration creates a pointer c of type double that points to a location index n in an array and calls the function that is existent at the index.

## Problem 3

F is a pointer to a function that takes in 2 arguments. THe first argument is a pointer to an anonymous function that takes in a double and an array of doubles and returns a double. The second argument is a double. \*f is called with multiple arguments, the first being a double 
