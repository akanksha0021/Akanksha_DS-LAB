#include <stdio.h>
#include <stdlib.h>

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

// Function to check if the given expression is properly parenthesized
int isParenthesized(char* expression) {
    Stack stack;
    initializeStack(&stack);

    // Iterate through the expression
    for (int i = 0; expression[i] != '\0'; i++) {
        char currentChar = expression[i];

        if (currentChar == '(') {
            push(&stack, currentChar);
        } else if (currentChar == ')') {
            if (isEmpty(&stack)) {
                return 0; // Unbalanced closing parenthesis
            } else {
                pop(&stack);
            }
        }
    }

    return isEmpty(&stack); // If the stack is empty, the expression is properly parenthesized
}

int main() {
    char expression[MAX_SIZE];

    printf("Enter an expression: ");
    fgets(expression, sizeof(expression), stdin);

    // Remove newline character if present
    if (expression[strlen(expression) - 1] == '\n') {
        expression[strlen(expression) - 1] = '\0';
    }

    if (isParenthesized(expression)) {
        printf("The expression is properly parenthesized.\n");
    } else {
        printf("The expression is not properly parenthesized.\n");
    }

    return 0;
}
