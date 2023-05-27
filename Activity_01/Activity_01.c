#include <stdio.h>

#define MAX_SIZE 100

// Structure representing the list
typedef struct {
    int arr[MAX_SIZE];
    int length;
} List;

// Function to initialize the list
void initializeList(List* list) {
    list->length = 0;
}

// Function to insert an element at a specified position
int insertElement(List* list, int position, int element) {
    if (position < 0 || position > list->length || list->length == MAX_SIZE) {
        return 0; // Insertion not possible
    }

    // Shift elements to the right to make space for the new element
    for (int i = list->length - 1; i >= position; i--) {
        list->arr[i + 1] = list->arr[i];
    }

    list->arr[position] = element;
    list->length++;
    return 1; // Insertion successful
}

// Function to delete an element from a specified position
int deleteElement(List* list, int position) {
    if (position < 0 || position >= list->length) {
        return 0; // Deletion not possible
    }

    // Shift elements to the left to fill the gap left by the deleted element
    for (int i = position; i < list->length - 1; i++) {
        list->arr[i] = list->arr[i + 1];
    }

    list->length--;
    return 1; // Deletion successful
}

// Function to perform linear search on the list
int linearSearch(List* list, int target) {
    for (int i = 0; i < list->length; i++) {
        if (list->arr[i] == target) {
            return i; // Target found at position i
        }
    }
    
    return -1; // Target not found
}

// Function to print the elements of the list
void printList(List* list) {
    printf("List: ");
    for (int i = 0; i < list->length; i++) {
        printf("%d ", list->arr[i]);
    }
    printf("\n");
}

int main() {
    List myList;
    initializeList(&myList);

    insertElement(&myList, 0, 10);
    insertElement(&myList, 1, 20);
    insertElement(&myList, 2, 30);

    printList(&myList); // List: 10 20 30

    deleteElement(&myList, 1);

    printList(&myList); // List: 10 30

    int index = linearSearch(&myList, 30);
    if (index != -1) {
        printf("Found at index: %d\n", index); // Found at index: 1
    } else {
        printf("Not found.\n");
    }

    return 0;
}
