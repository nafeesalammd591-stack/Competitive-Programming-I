// Write a C program to perform hashing using a hash table.
#include <stdio.h>

#define SIZE 10
#define N 5

int main() {
    int hashTable[SIZE];
    int key, index;
    int i, j;

    /* Initialize hash table */
    for (i = 0; i < SIZE; i++) {
        hashTable[i] = -1;
    }

    printf("Enter %d numbers:\n", N);

    /* Insert elements */
    for (i = 0; i < N; i++) {

        scanf("%d", &key);

        index = key % SIZE;

        if (index < 0) {
            index = index + SIZE;
        }

        /* Linear probing */
        for (j = 0; j < SIZE; j++) {

            int newIndex = (index + j) % SIZE;

            if (hashTable[newIndex] == -1) {
                hashTable[newIndex] = key;
                break;
            }
        }

        if (j == SIZE) {
            printf("Hash table is full. Cannot insert %d\n", key);
        }
    }

    /* Display hash table */
    printf("\nHash Table:\n");

    for (i = 0; i < SIZE; i++) {
        printf("%d -> %d\n", i, hashTable[i]);
    }

    return 0;
}
