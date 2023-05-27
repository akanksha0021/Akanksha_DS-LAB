#include <stdio.h>
#include <stdlib.h>

// Structure representing a node in the circular linked list
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

// Function to insert a new node at the beginning of the circular linked list
void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
    } else {
        Node* last = *head;
        while (last->next != *head) {
            last = last->next;
        }
        newNode->next = *head;
        last->next = newNode;
        *head = newNode;
    }
    printf("Inserted %d at the beginning\n", data);
}

// Function to insert a new node at the end of the circular linked list
void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
    } else {
        Node* last = *head;
        while (last->next != *head) {
            last = last->next;
        }
        last->next = newNode;
        newNode->next = *head;
    }
    printf("Inserted %d at the end\n", data);
}

// Function to delete a node with the given key from the circular linked list
void deleteNode(Node** head, int key) {
    if (*head == NULL) {
        printf("The list is empty\n");
        return;
    }

    Node* current = *head;
    Node* prev = NULL;
    while (current->next != *head && current->data != key) {
        prev = current;
        current = current->next;
    }

    if (current->data != key) {
        printf("Node with key %d not found\n", key);
        return;
    }

    if (current == *head && current->next == *head) {
        *head = NULL;
    } else if (current == *head) {
        Node* last = *head;
        while (last->next != *head) {
            last = last->next;
        }
        *head = (*head)->next;
        last->next = *head;
    } else {
        prev->next = current->next;
    }

    free(current);
    printf("Deleted node with key %d\n", key);
}

// Function to search for a node with the given key in the circular linked list
void searchNode(Node* head, int key) {
    if (head == NULL) {
        printf("The list is empty\n");
        return;
    }

    Node* current = head;
    int position = 0;
    do {
        if (current->data == key) {
            printf("Node with key %d found at position %d\n", key, position);
            return;
        }
        current = current->next;
        position++;
    } while (current != head);

    printf("Node with key %d not found\n", key);
}

// Function to display the circular linked list
void displayList(Node* head) {
    if (head == NULL) {
        printf("The list
