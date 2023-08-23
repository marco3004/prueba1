#include <stdio.h>

int main() {
    int filas;

    printf("Ingrese el número de filas: ");
    while (scanf("%d", &filas) != 1) {
        printf("Entrada inválida. Ingrese un número entero: ");
        while (getchar() != '\n'); // Limpiar el búfer de entrada
    }

    for (int i = 1; i <= filas; i++) {
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}

