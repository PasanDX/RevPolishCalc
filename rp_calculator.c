// Module 1: Stack Definitions
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100 // Maximum size of the stack

// Stack to hold operands
double stack[MAX];
int top = -1; // Stack pointer

// Module 2: Push Function
// Function to push a number onto the stack
void push(double value) {
    if (top >= MAX - 1) {
        printf("Stack overflow\n");
        exit(1);
    } else {
        stack[++top] = value;
    }
}

// Module 3: Pop Function

// Module 4: Display Top of Stack

// Module 6: Main Function

// Module 7: Final Test and Output