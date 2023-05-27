#include <stdio.h>

#define MAX_SIZE 100

// Structure representing the queue
typedef struct {
    int arr[MAX_SIZE];
    int front;
    int rear;
} Queue;

// Function to initialize the queue
void initializeQueue(Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(Queue* queue) {
    return queue->front == -1;
}

// Function to check if the queue is full
int isFull(Queue* queue) {
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}

// Function to enqueue an element into the queue
void enqueue(Queue* queue, int element) {
    if (isFull(queue)) {
        printf("Queue overflow: Cannot enqueue element %d\n", element);
    } else {
        if (isEmpty(queue)) {
            queue->front = 0;
        }
        queue->rear = (queue->rear + 1) % MAX_SIZE;
        queue->arr[queue->rear] = element;
        printf("Enqueued element %d\n", element);
    }
}

// Function to dequeue an element from the queue
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue underflow: Cannot dequeue element from an empty queue\n");
        return -1; // Queue underflow
    } else {
        int element = queue->arr[queue->front];
        if (queue->front == queue->rear) {
            // Reset the queue when the last element is dequeued
            initializeQueue(queue);
        } else {
            queue->front = (queue->front + 1) % MAX_SIZE;
        }
        printf("Dequeued element %d\n", element);
        return element;
    }
}

int main() {
    Queue myQueue;
    initializeQueue(&myQueue);

    enqueue(&myQueue, 10);
    enqueue(&myQueue, 20);
    enqueue(&myQueue, 30);

    int dequeuedElement = dequeue(&myQueue);
    if (dequeuedElement != -1) {
        printf("Dequeued element: %d\n", dequeuedElement);
    }

    return 0;
}
