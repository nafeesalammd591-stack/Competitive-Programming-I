// Deletion of Array
#include <stdio.h>

int main() {
    int arr[100] = {10, 20, 30, 40, 50};
    int n = 5;
    int position;
    int i;

    printf("Enter position to delete: ");
    scanf("%d", &position);

    // Check whether position is valid
    if (position < 0 || position >= n) {
        printf("Invalid position");
        return 0;
    }

    
    for (i = position; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    
    n--;

    printf("Array after deletion:\n");

    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}