#include <stdio.h>

int main() {
    int numero;

    printf("Ingrese un número: ");
    while (scanf("%d", &numero) != 1) {
        printf("Entrada inválida. Ingrese un número entero: ");
        while (getchar() != '\n'); // Limpiar el búfer de entrada
    }

    if (numero % 2 == 0) {
        printf("El número %d es par.\n", numero);
    } else {
        printf("El número %d es impar.\n", numero);
    }

    return 0;
}

