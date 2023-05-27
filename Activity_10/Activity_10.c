#include <stdio.h>
#include <stdlib.h>

// Structure representing a node in the stack
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node with the given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to check if the stack is empty
int isEmpty(Node* top) {
    return top == NULL;
}

// Function to push an element onto the stack
void push(Node** top, int data) {
    Node* newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
    printf("Pushed %d onto the stack\n", data);
}

// Function to pop an element from the stack
int pop(Node** top) {
    if (isEmpty(*top)) {
        printf("Stack is empty\n");
        return -1;
    }

    Node* temp = *top;
    int data = temp->data;
    *top = (*top)->next;
    free(temp);
    printf("Popped %d from the stack\n", data);
    return data;
}

// Function to display the stack
void displayStack(Node* top) {
    if (isEmpty(top)) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack contains: ");
    Node* current = top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* top = NULL;

    push(&top, 10);
    push(&top, 20);
    push(&top, 30);
    displayStack(top);

    pop(&top);
    displayStack(top);

    pop(&top);
    pop(&top);
    pop(&top);

    return 0;
}
