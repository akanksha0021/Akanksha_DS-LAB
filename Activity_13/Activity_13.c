#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure representing a binary tree
typedef struct BinaryTree {
    int data[MAX_SIZE];
    int size;
} BinaryTree;

// Function to create an empty binary tree
BinaryTree* createBinaryTree() {
    BinaryTree* tree = (BinaryTree*)malloc(sizeof(BinaryTree));
    tree->size = 0;
    return tree;
}

// Function to check if the binary tree is empty
int isEmpty(BinaryTree* tree) {
    return tree->size == 0;
}

// Function to get the index of the parent node of a given index
int getParentIndex(int index) {
    return (index - 1) / 2;
}

// Function to get the index of the left child node of a given index
int getLeftChildIndex(int index) {
    return (2 * index) + 1;
}

// Function to get the index of the right child node of a given index
int getRightChildIndex(int index) {
    return (2 * index) + 2;
}

// Function to perform in-order traversal of the binary tree
void inOrderTraversal(BinaryTree* tree, int index) {
    if (index >= tree->size)
        return;

    inOrderTraversal(tree, getLeftChildIndex(index));
    printf("%d ", tree->data[index]);
    inOrderTraversal(tree, getRightChildIndex(index));
}

// Function to perform pre-order traversal of the binary tree
void preOrderTraversal(BinaryTree* tree, int index) {
    if (index >= tree->size)
        return;

    printf("%d ", tree->data[index]);
    preOrderTraversal(tree, getLeftChildIndex(index));
    preOrderTraversal(tree, getRightChildIndex(index));
}

// Function to perform post-order traversal of the binary tree
void postOrderTraversal(BinaryTree* tree, int index) {
    if (index >= tree->size)
        return;

    postOrderTraversal(tree, getLeftChildIndex(index));
    postOrderTraversal(tree, getRightChildIndex(index));
    printf("%d ", tree->data[index]);
}

// Function to search for an element in the binary tree
int search(BinaryTree* tree, int element) {
    for (int i = 0; i < tree->size; i++) {
        if (tree->data[i] == element)
            return i;
    }
    return -1;
}

// Function to insert an element into the binary tree
void insert(BinaryTree* tree, int element) {
    if (tree->size >= MAX_SIZE) {
        printf("Binary tree is full. Cannot insert element.\n");
        return;
    }

    tree->data[tree->size] = element;
    tree->size++;

    printf("Inserted %d into the binary tree\n", element);
}

// Function to delete an element from the binary tree
void delete(BinaryTree* tree, int element) {
    if (isEmpty(tree)) {
        printf("Binary tree is empty. Cannot delete element.\n");
        return;
    }

    int index = search(tree, element);
    if (index == -1) {
        printf("Element %d not found in the binary tree\n", element);
        return;
    }

    int lastElement = tree->data[tree->size - 1];
    tree->data[index] = lastElement;
    tree->size--;

    printf("Deleted %d from the binary tree\n", element);
}

int main() {
    BinaryTree* tree = createBinaryTree();

    insert(tree, 10);
    insert(tree, 20);
    insert(tree, 30);
}