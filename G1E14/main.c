#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* . Crear un algoritmo en pseudo-código (similar a PASCAL o C) para pasar un string ASCII a un
integer, utilizando máscaras. (No utilizar funciones del lenguaje como StrToInt). */

void stringAInt(char [], int[]);
void printArray(int array[], int elem);

int main()
{
    char string[] = "Prueba";
    printf("%s\n", string);
    int respuesta[40];
    stringAInt(string, respuesta);
    printArray(respuesta, strlen(string));
    return 0;
}

void stringAInt(char string[], int entero[]) {
    int i = 0;
    char copia[40];
    strcpy(copia, string);
    while (i < strlen(string)) {
        entero[i] = 0;
        for (int j = 0; j < 8; j++) {
            entero[i] += (copia[i] & 10000000) / pow(10, j);
            copia[i] = copia[i] << 1;
        }
        i++;
    }
}

void printArray(int array[], int elem) {
    for (int i = 0; i < elem; i++)
        printf("\n%d", array[i]);
}
