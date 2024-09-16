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
// Function to display the top of the stack without popping it
void display_top() {
    if (top < 0) {
        printf("Stack is empty\n");
    } else {
        printf("Top of the stack: %.2f\n", stack[top]);
    }
}

// Module 4: Display Top of Stack
// Function to display the top of the stack without popping it
void display_top() {
    if (top < 0) {
        printf("Stack is empty\n");
    } else {
        printf("Top of the stack: %.2f\n", stack[top]);
    }
}

// Module 5: Evaluate Function
// Function to evaluate the Reverse Polish expression
void evaluate(char operator) {
    double operand1, operand2;
    
    switch (operator) {
        case '+':
            operand2 = pop();
            operand1 = pop();
            push(operand1 + operand2);
            break;
        case '-':
            operand2 = pop();
            operand1 = pop();
            push(operand1 - operand2);
            break;
        case '*':
            operand2 = pop();
            operand1 = pop();
            push(operand1 * operand2);
            break;
        case '/':
            operand2 = pop();
            operand1 = pop();
            if (operand2 != 0) {
                push(operand1 / operand2);
            } else {
                printf("Error: Division by zero\n");
                exit(1);
            }
            break;
        case '=':
            display_top();
            break;
        default:
            printf("Invalid operator\n");
            exit(1);
    }
}

// Module 6: Main Function
// Module 7: Final Test and Output