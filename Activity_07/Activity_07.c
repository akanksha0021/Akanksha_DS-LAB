#include <stdio.h>
#include <stdlib.h>

// Structure representing a node in the linked list
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

// Function to insert a new node at the beginning of the linked list
void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
    printf("Inserted %d at the beginning\n", data);
}

// Function to insert a new node at the end of the linked list
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
    }
    printf("Inserted %d at the end\n", data);
}

// Function to delete a node with the given key from the linked list
void deleteNode(Node** head, int key) {
    Node* prev = NULL;
    Node* current = *head;

    if (current != NULL && current->data == key) {
        *head = current->next;
        free(current);
        printf("Deleted node with key %d\n", key);
        return;
    }

    while (current != NULL && current->data != key) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Node with key %d not found\n", key);
        return;
    }

    prev->next = current->next;
    free(current);
    printf("Deleted node with key %d\n", key);
}

// Function to search for a node with the given key in the linked list
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

// Function to display the linked list
void displayList(Node* head) {
    Node* current = head;
    if (current == NULL) {
        printf("The list is empty\n");
    } else {
        printf("The list contains: ");
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtBeginning(&head, 5);
    displayList(head);

    deleteNode(&head, 20);
    searchNode(head, 10);
    searchNode(head, 20);
    displayList(head);

    return 0;
}
