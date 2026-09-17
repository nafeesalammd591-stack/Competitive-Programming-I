// Write a C program to implement hashing using the separate chaining technique.
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct Node {
    int key;
    struct Node *next;
};

struct Node *hashTable[SIZE];

/* Hash function */
int hashFunction(int key) {
    return key % SIZE;
}

/* Insert a key */
void insert(int key) {
    int index = hashFunction(key);

    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->key = key;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

/* Display hash table */
void display() {
    int i;
    struct Node *temp;

    printf("\nHash Table using Separate Chaining:\n");

    for (i = 0; i < SIZE; i++) {
        printf("%d -> ", i);

        temp = hashTable[i];

        while (temp != NULL) {
            printf("%d -> ", temp->key);
            temp = temp->next;
        }

        printf("NULL\n");
    }
}

int main() {
    int n, key;
    int i;

    /* Initialize hash table */
    for (i = 0; i < SIZE; i++) {
        hashTable[i] = NULL;
    }

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");

    for (i = 0; i < n; i++) {
        scanf("%d", &key);
        insert(key);
    }

    display();

    return 0;
}