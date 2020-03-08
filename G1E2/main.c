#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* Un número entero a String binario.
b. Un String binario a un número entero.
c. Un número entero a String en en base b (pasado por parámetro)
d. Un String que representa un número en base b a un número entero */

void stringABinario(int, char[]);
void conversionABinario(int, char[], int*);

int binarioAEntero(char[]);

void enteroABase(int, char[], int);
void conversionABase(int, char[], int, int*, char[]);

int baseAEntero(char[], int);
int buscaDigito(char, char[]);

int main()
{
    int numero = 16;
    char resultado[21];
    stringABinario(numero, resultado);
    printf("%s %d", resultado, binarioAEntero(resultado));
    enteroABase(numero, resultado, 16);
    printf("\n%s %d", resultado, baseAEntero(resultado, 16));
    return 0;
}

void stringABinario(int numero, char resultado[]){
    int pos = 0;
    conversionABinario(numero, resultado, &pos);
    resultado[pos] = '\0';
}

void conversionABinario(int numero, char resultado[], int* pos){
    if (numero > 0) {
        conversionABinario(numero/2, resultado, pos);
        resultado[(*pos)++] = numero % 2 + '0';
    }
}

int binarioAEntero(char binario[]) {
    int i = 0, decimal = 0;
    while (i < strlen(binario)) {
        decimal += (binario[i] - '0') * pow(2, strlen(binario) - i - 1);
        i++;
    }
    return decimal;
}

void enteroABase(int numero, char resultado[], int base) {
    int pos = 0;
    char digitos[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    conversionABase(numero, resultado, base, &pos, digitos);
    resultado[pos] = '\0';
}

void conversionABase(int numero, char resultado[], int base, int* pos, char digitos[]) {
    if (numero > 0) {
        conversionABase(numero/base, resultado, base, pos, digitos);
        resultado[(*pos)++] = digitos[numero % base];
    }
}

int baseAEntero(char numero[], int base) {
    int i = 0, decimal = 0;
    char digitos[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    while (i < strlen(numero)) {
        decimal += (buscaDigito(numero[i], digitos)) * pow(base, strlen(numero) - i - 1);
        i++;
    }
    return decimal;
}

int buscaDigito(char numero, char digitos[]) {
    int i = 0;
    while (numero != digitos[i])
        i++;
    return i;
}
