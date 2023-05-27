#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Structure representing the stack
typedef struct {
    int arr[MAX_SIZE];
    int top;
} Stack;

// Function to initialize the stack
void initializeStack(Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
bool isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// Function to push an element onto the stack
void push(Stack* stack, int element) {
    if (isFull(stack)) {
        printf("Stack overflow: Cannot push element %d\n", element);
    } else {
        stack->top++;
        stack->arr[stack->top] = element;
    }
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow: Cannot pop element from an empty stack\n");
        return -1; // Stack underflow
    } else {
        int element = stack->arr[stack->top];
        stack->top--;
        return element;
    }
}

// Function to evaluate a postfix expression
int evaluatePostfix(char* expression) {
    Stack stack;
    initializeStack(&stack);

    // Iterate through the expression
    for (int i = 0; expression[i] != '\0'; i++) {
        char currentChar = expression[i];

        if (isdigit(currentChar)) {
            int operand = currentChar - '0';
            push(&stack, operand);
        } else {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);

            switch (currentChar) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    push(&stack, operand1 / operand2);
                    break;
                case '%':
                    push(&stack, operand1 % operand2);
                    break;
            }
        }
    }

    return pop(&stack); // Result of the expression
}

// Function to evaluate a prefix expression
int evaluatePrefix(char* expression) {
    Stack stack;
    initializeStack(&stack);

    int len = strlen(expression);

    // Iterate through the expression in reverse
    for (int i = len - 1; i >= 0; i--) {
        char currentChar = expression[i];

        if (isdigit(currentChar)) {
            int operand = currentChar - '0';
            push(&stack, operand);
        } else {
            int operand1 = pop(&stack);
            int operand2 = pop(&stack);

            switch (currentChar) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    push(&stack, operand1 / operand2);
                    break;
                case '%':
                    push(&stack, operand1 % operand2);
                    break;
            }
        }
    }

    return pop(&stack); // Result of the expression
}

// Function to evaluate an infix expression
