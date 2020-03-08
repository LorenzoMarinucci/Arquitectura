#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Crear un algoritmo en pseudo-código (similar a PASCAL o C) para decodificar un String en formato
ASCII el cual esconde una palabra que se obtiene combinando el bit menos significativo de cada
byte del String. */

void obtenerMensaje(char[], int[]);
void printArray(int array[], int elem);

int main()
{
    char string[] = "Nosenoseab";
    int codificado[31];
    obtenerMensaje(string, codificado);
    printArray(codificado, 2);
    return 0;
}

void obtenerMensaje(char string[], int codificado[]){
    int i = 0, j = -1, actual;
    while (i < strlen(string)) {
        if (i % 8 == 0) {
            if (j!= -1)
                codificado[j] = actual;
            j++;
            actual = string[i] & 1;
        }
        else {
            actual = actual << 1;
            actual = actual | (string[i] & 1);
        }
        i++;
    }
    codificado[j] = actual;
}

void printArray(int array[], int elem) {
    for (int i = 0; i < elem; i++)
        printf("\n%d", array[i]);
}
