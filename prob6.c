#include <stdio.h>

int main() {
    int numeroInicial, numeroFinal;

    printf("Ingrese un número inicial: ");

    // Bucle para solicitar un número inicial válido
    while (1) {
        if (scanf("%d", &numeroInicial) == 1) {
            break; // Salir del bucle si se ingresó un número válido
        }
        printf("Entrada inválida. Ingrese un número inicial: ");
        while (getchar() != '\n'); // Limpiar 
    }

    printf("Ingrese un número final: ");

    // bucle para solicitar un número final válido
    while (1) {
        if (scanf("%d", &numeroFinal) == 1) {
            break; // Salir del bucle si se ingresó un número válido
        }
        printf("Entrada inválida. Ingrese un número final: ");
        while (getchar() != '\n'); // Limpiar 
    }

    int cantidadPares = 0;

    // Contar la cantidad de números pares en el rango dado
    for (int i = numeroInicial; i <= numeroFinal; i++) {
        if (i % 2 == 0) {
            cantidadPares++;
        }
    }

    printf("La cantidad de números pares en el rango [%d, %d] es: %d\n", numeroInicial, numeroFinal, cantidadPares);

    return 0;
}

