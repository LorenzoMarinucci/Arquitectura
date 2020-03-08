#include <stdio.h>
#include <stdlib.h>

void printArray(int[], int);

int main()
{
    int a = 1;
    int bits[64];
    for(int i = 0; i < 64; i++) {
        bits[i] = a & 1;
        a = a >> 1;
    }
    printArray(bits, 64);
    return 0;
}

void printArray(int array[], int elem) {
    for (int i = elem - 1; i >= 0; i--)
        printf("%d", array[i]);
}
