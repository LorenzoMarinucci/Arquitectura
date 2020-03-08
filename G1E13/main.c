#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Crear un algoritmo en pseudo-código (similar a PASCAL o C) para pasar un string ASCII a
mayúsculas, utilizando máscaras y aprovechando la codificación ASCII. (No utilizar la función
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
