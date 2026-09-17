#include <stdio.h>

int main() {
    int rows, columns;
    int i, j;
    int baseAddress, elementSize;
    int effectiveAddress;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &columns);

    printf("Enter the base address: ");
    scanf("%d", &baseAddress);

    printf("Enter the element size: ");
    scanf("%d", &elementSize);

    printf("Enter the row index: ");
    scanf("%d", &i);

    printf("Enter the column index: ");
    scanf("%d", &j);

    if (i < 0 || i >= rows || j < 0 || j >= columns) {
        printf("Invalid row or column index.\n");
        return 0;
    }

    effectiveAddress = baseAddress +
                       ((j * rows) + i) * elementSize;

    printf("The effective address is: %d\n", effectiveAddress);

    return 0;
}