#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Crear un algoritmo en pseudo-c�digo (similar a PASCAL o C) para pasar un string ASCII a
may�sculas, utilizando m�scaras y aprovechando la codificaci�n ASCII. (No utilizar la funci�n
UpCase) */

void upCase(char[]);

int main()
{
    char string[] = "Prueba";
    printf("%s", string);
    upCase(string);
    printf("\n%s", string);
    return 0;
}

void upCase(char string[]) {
    int i = 0;
    while (i < strlen(string)) {
        string[i] = string[i] & 0xDF;
        i++;
    }
}
