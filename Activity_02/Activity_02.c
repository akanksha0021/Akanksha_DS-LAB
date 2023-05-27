#include <stdio.h>

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
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// Function to push an element onto the stack
int push(Stack* stack, int element) {
    if (isFull(stack)) {
        return 0; // Stack overflow
    }

    stack->top++;
    stack->arr[stack->top] = element;
    return 1; // Push successful
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        return -1; // Stack underflow
    }

    int element = stack->arr[stack->top];
    stack->top--;
    return element;
}

int main() {
    Stack myStack;
    initializeStack(&myStack);

    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);

    int poppedElement = pop(&myStack);
    if (poppedElement != -1) {
        printf("Popped element: %d\n", poppedElement); // Popped element: 30
    } else {
        printf("Stack is empty.\n");
    }

    return 0;
}
