#include <stdio.h>
#include <stdlib.h>

// Structure representing a node in the priority queue
typedef struct Node {
    int data;
    int priority;
    struct Node* next;
} Node;

// Structure representing the priority queue
typedef struct PriorityQueue {
    Node* front;
} PriorityQueue;

// Function to create a new node with the given data and priority
Node* createNode(int data, int priority) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

// Function to create an empty priority queue
PriorityQueue* createPriorityQueue() {
    PriorityQueue* queue = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    queue->front = NULL;
    return queue;
}

// Function to check if the priority queue is empty
int isEmpty(PriorityQueue* queue) {
    return queue->front == NULL;
}

// Function to enqueue an element into the priority queue
void enqueue(PriorityQueue* queue, int data, int priority) {
    Node* newNode = createNode(data, priority);

    if (isEmpty(queue) || priority < queue->front->priority) {
        newNode->next = queue->front;
        queue->front = newNode;
    } else {
        Node* current = queue->front;
        while (current->next != NULL && current->next->priority <= priority) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    printf("Enqueued %d with priority %d\n", data, priority);
}

// Function to dequeue an element from the priority queue
int dequeue(PriorityQueue* queue) {
    if (isEmpty(queue)) {
        printf("Priority queue is empty\n");
        return -1;
    }

    Node* temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;
    free(temp);

    printf("Dequeued %d\n", data);
    return data;
}

// Function to display the priority queue
void displayPriorityQueue(PriorityQueue* queue) {
    if (isEmpty(queue)) {
        printf("Priority queue is empty\n");
        return;
    }

    printf("Priority queue contains: ");
    Node* current = queue->front;
    while (current != NULL) {
        printf("(%d, %d) ", current->data, current->priority);
        current = current->next;
    }
    printf("\n");
}

int main() {
    PriorityQueue* queue = createPriorityQueue();

    enqueue(queue, 10, 2);
    enqueue(queue, 20, 1);
    enqueue(queue, 30, 3);
    displayPriorityQueue(queue);

    dequeue(queue);
    displayPriorityQueue(queue);

    dequeue(queue);
    dequeue(queue);
    dequeue(queue);

    return 0;
}
