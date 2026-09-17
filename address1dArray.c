// Write a C program to find out the effective address of an element stored in a 1D array.
#include <stdio.h>

int main() {
    int index;
    int elementSize, baseAddress;
    int effectiveAddress;

    printf("Enter the index of the array element: ");
    scanf("%d", &index);

    printf("Enter the element size: ");
    scanf("%d", &elementSize);

    printf("Enter the base address: ");
    scanf("%d", &baseAddress);

    effectiveAddress = baseAddress + (index * elementSize);

    printf("The effective address is: %d\n", effectiveAddress);

    return 0;
}