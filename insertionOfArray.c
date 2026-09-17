// 5. Insertion in Array at Any Arbitrary Position

#include <stdio.h>

int main() {
    int arr[100] = {10, 20, 30, 40, 50};

    int n = 5;
    int position = 2;
    int value = 25;

    int i;

    for (i = n; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    arr[position] = value;

    n++;

    printf("Array after insertion:\n");

    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}