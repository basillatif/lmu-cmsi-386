# CMSI 386 Homework 3

Name: Jackson Watkins and Basil Latif

## Problem 1

For A[0][0], we get the memory address 0x556ec98891c0. For A[3][7], we get the memory address 0x556ec98892e8. When we generate all the possible array locations from A[0][0] to A[3][7], we find out that 8 bits are allocated for each place within the two-dimensional array. For example,  we have A[0][0] (0x556ec98891c0), A[0][1] (0x556ec98891c8), A[0][2] (0x556ec98891d0), etc. which each take up 8 bits in memory each.

## Problem 2

The first declaration recognizes that a is a pointer to a location index n in the array.

The second declaration creates a pointer b of type double that points to an array of size n.

The third declaration creates a pointer c of type double that points to a location index n in an array and calls the function that is existent at the index.

## Problem 3

F is a pointer to a function that takes in 2 arguments. THe first argument is a pointer to an anonymous function that takes in a double and an array of doubles and returns a double. The second argument is a double. \*f is called with multiple arguments, the first being a double and the rest being unspecified

## Problem 4

The representation of the Derived object contains one b field. Even though a b field was declared in the Base class, the Derived class overwrites the existent b value with the new b value since they are the same variable. If the programmer creates an object from the Base class, accessing the b field of that class would return a string. If the programmer creates an object from the Derived class, accessing the b field of that class would return an int.

## Problem 5

Static scoping gives us the result of 2, 5, 2. A statically scoped language first searchs for local variables. If none are found, then it looks to the local variables of the calling function. If C++ used dynamic scoping we would get the answer of 5, 5, 2. 
