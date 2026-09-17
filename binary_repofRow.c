#include <stdio.h>

int main() {
    int base = 1000;
    int i = 2;
    int j = 3;
    int columns = 4;
    int size = 4;

    int address = base + ((i * columns) + j) * size;

    printf("Address = %d\n", address);

    return 0;
}
