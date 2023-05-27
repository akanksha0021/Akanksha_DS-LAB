#include <stdio.h>
#include <stdlib.h>

// Structure representing a node in the doubly linked list
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Function to create a new node with the given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the doubly linked list
void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
    printf("Inserted %d at the beginning\n", data);
}

// Function to insert a new node at the end of the doubly linked list
void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
    printf("Inserted %d at the end\n", data);
}

// Function to delete a node with the given key from the doubly linked list
void deleteNode(Node** head, int key) {
    if (*head == NULL) {
        printf("The list is empty\n");
        return;
    }

    Node* current = *head;
    while (current != NULL && current->data != key) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Node with key %d not found\n", key);
        return;
    }

    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        *head = current->next;
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    free(current);
    printf("Deleted node with key %d\n", key);
}

// Function to search for a node with the given key in the doubly linked list
void searchNode(Node* head, int key) {
    Node* current = head;
    int position = 0;
    while (current != NULL) {
        if (current->data == key) {
            printf("Node with key %d found at position %d\n", key, position);
            return;
        }
        current = current->next;
        position++;
    }
    printf("Node with key %d not found\n", key);
}

// Function to display the doubly linked list in forward direction
void displayForward(Node* head) {
    Node* current = head;
    if (current == NULL) {
        printf("The list is empty\n");
    } else {
        printf("The list in forward direction: ");
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

// Function to display the doubly linked list in reverse direction
void displayReverse(Node* head) {
    Node* current = head;
    if (current == NULL) {
        printf("The list is empty\n
