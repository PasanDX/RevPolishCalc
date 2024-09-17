// Module 1: Stack Definitions
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#include <string.h>

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
int main() {
    char input[20];
    double num;

    printf("Enter instructions (? to push, + - * / for operations, = to display top, q to quit, test to run tests):\n");

    while (1) {
        printf("> ");
        scanf("%s", input);

        if (input[0] == '?') {
            // Push operand onto the stack
            scanf("%lf", &num);
            push(num);
        } else if (input[0] == '+' || input[0] == '-' || input[0] == '*' || input[0] == '/' || input[0] == '=') {
            // Perform the operation or display the top
            evaluate(input[0]);
        } else if (input[0] == 'q') {
            // Exit the program
            break;
        } else if (strcmp(input, "test") == 0) {
            // Run tests when 'test' is enteredt
            run_tests();
            break; // Exit after running tests
        } else {
            printf("Invalid input\n");
        }
    }




    return 0;
}

// Module 7: Final Test and Output
// Helper function to reset the stack for tests
void reset_stack() {
    top = -1;
}

// Helper function to check the top of the stack
void check_top(double expected) {
    if (top < 0) {
        printf("Stack is empty\n");
        exit(1);
    } else {
        double actual = stack[top];
        assert(actual == expected); // Validate the top of the stack
    }
}

// Function to test the entire RPN calculator functionality
void run_tests() {
    printf("Running tests...\n");

    // Test 1: Simple addition (5 + 10 = 15)
    reset_stack();
    push(5);
    push(10);
    evaluate('+');
    check_top(15);

    // Test 2: Addition and multiplication ((5 + 10) * 3 = 45)
    reset_stack();
    push(5);
    push(10);
    evaluate('+');
    push(3);
    evaluate('*');
    check_top(45);

    // Test 3: Division (15 / 3 = 5) 
    reset_stack();
    push(15);
    push(3);
    evaluate('/');
    check_top(5);

    // Test 4: Subtraction (10 - 3 = 7) 
    reset_stack();
    push(10);
    push(3);
    evaluate('-');
    check_top(7);

    // Test 5: Division by zero error (10 / 0)
    reset_stack();
    push(10);
    push(0);
    printf("Expecting Division by zero error:\n");
    evaluate('/'); // This should print an error message and exit
    
    // Additional tests can be added similarly...

    printf("All tests passed!\n");
}