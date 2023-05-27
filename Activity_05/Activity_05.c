#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 100

// Structure representing the stack
typedef struct {
    char arr[MAX_SIZE];
    int top;
} Stack;

// Function to initialize the stack
void initializeStack(Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// Function to push an element onto the stack
void push(Stack* stack, char element) {
    if (isFull(stack)) {
        printf("Stack overflow: Cannot push element %c\n", element);
    } else {
        stack->top++;
        stack->arr[stack->top] = element;
    }
}

// Function to pop an element from the stack
char pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow: Cannot pop element from an empty stack\n");
        return '\0'; // Stack underflow
    } else {
        char element = stack->arr[stack->top];
        stack->top--;
        return element;
    }
}

// Function to get the precedence of an operator
int getPrecedence(char operator) {
    if (operator == '*' || operator == '/')
        return 2;
    else if (operator == '+' || operator == '-')
        return 1;
    else
        return 0;
}

// Function to convert infix expression to postfix expression
void infixToPostfix(char* infix, char* postfix) {
    Stack stack;
    initializeStack(&stack);

    int i, j;
    i = j = 0;

    while (infix[i] != '\0') {
        if (isdigit(infix[i])) {
            postfix[j++] = infix[i++];
        } else if (infix[i] == '(') {
            push(&stack, infix[i++]);
        } else if (infix[i] == ')') {
            while (!isEmpty(&stack) && stack.arr[stack.top] != '(') {
                postfix[j++] = pop(&stack);
            }
            if (!isEmpty(&stack) && stack.arr[stack.top] == '(') {
                pop(&stack);
            }
            i++;
        } else {
            while (!isEmpty(&stack) && getPrecedence(infix[i]) <= getPrecedence(stack.arr[stack.top])) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, infix[i++]);
        }
    }

    while (!isEmpty(&stack)) {
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0';
}

// Function to convert infix expression to prefix expression
void infixToPrefix(char* infix, char* prefix) {
    Stack stack;
    initializeStack(&stack);

    int i, j;
    i = j = 0;

    int len = strlen(infix);

    // Reverse the infix expression
    for (i = len - 1; i >= 0; i--) {
        if (infix[i] == '(') {
            infix[i] = ')';
        } else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }

    while (infix[i] != '\0') {
        if (isdigit(infix[i])) {
            prefix[j++] = infix[i++];
        }
