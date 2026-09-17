// Write a C program to implement hashing using the quadratic probing technique.
#include <stdio.h>

#define SIZE 10

int hashTable[SIZE];

/* Hash function */
int hashFunction(int key) {
    return key % SIZE;
}

/* Insert an element */
void insert(int key) {
    int index;
    int i;

    index = hashFunction(key);

    for (i = 0; i < SIZE; i++) {
        int newIndex = (index + i * i) % SIZE;

        if (hashTable[newIndex] == -1) {
            hashTable[newIndex] = key;
            return;
        }
    }

    printf("Hash table is full. Cannot insert %d\n", key);
}

/* Display hash table */
void display() {
    int i;

    printf("\nHash Table using Quadratic Probing:\n");

    for (i = 0; i < SIZE; i++) {
        if (hashTable[i] == -1)
            printf("%d -> Empty\n", i);
        else
            printf("%d -> %d\n", i, hashTable[i]);
    }
}

int main() {
    int n, key;
    int i;

    /* Initialize hash table */
    for (i = 0; i < SIZE; i++) {
        hashTable[i] = -1;
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