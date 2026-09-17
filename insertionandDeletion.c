#include <stdio.h>

#define MAX 100

int main() {
    int arr[MAX];
    int n, i;
    int position, value, choice;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n < 0 || n > MAX) {
        printf("Invalid number of elements.\n");
        return 0;
    }

    printf("Enter the elements:\n");

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\n1. Insertion\n");
    printf("2. Deletion\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    /* Insertion */
    if (choice == 1) {

        if (n == MAX) {
            printf("Array is full. Insertion is not possible.\n");
            return 0;
        }

        printf("Enter the position for insertion (0 to %d): ", n);
        scanf("%d", &position);

        if (position < 0 || position > n) {
            printf("Invalid position.\n");
            return 0;
        }

        printf("Enter the value to insert: ");
        scanf("%d", &value);

        for (i = n; i > position; i--) {
            arr[i] = arr[i - 1];
        }

        arr[position] = value;
        n++;

        printf("\nArray after insertion:\n");

        for (i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
    }

    /* Deletion */
    else if (choice == 2) {

        if (n == 0) {
            printf("Array is empty. Deletion is not possible.\n");
            return 0;
        }

        printf("Enter the position for deletion (0 to %d): ", n - 1);
        scanf("%d", &position);

        if (position < 0 || position >= n) {
            printf("Invalid position.\n");
            return 0;
        }

        for (i = position; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }

        n--;

        printf("\nArray after deletion:\n");

        for (i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
    }

    else {
        printf("Invalid choice.\n");
    }

    printf("\n");

    return 0;
}