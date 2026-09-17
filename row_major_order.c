#include <stdio.h>

int main() {
    int arr[3][3] = {
        {10, 20, 30},
        {40, 50, 60},
        {70, 80, 90}
    };

    int i, j;

    printf("Array in Row Major Order:\n");

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", arr[i][j]);
        }
    }

    return 0;
}