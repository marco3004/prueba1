#include <stdio.h>

int main() {
    float numero;

    printf("Ingresa un número para mostrar su tabla de multiplicar: ");

    // Bucle para solicitar un número válido
    while (1) {
        if (scanf("%f", &numero) == 1) {
            break; // Salir del bucle si se ingresó un número válido
        }
        printf("Entrada inválida. Ingresa un número: ");
        while (getchar() != '\n'); // Limpiar el búfer de entrada
    }

    // Mostrar la tabla de multiplicar
    printf("Tabla de multiplicar del %.2f:\n", numero);

    for (int i = 1; i <= 10; i++) {
        printf("%.2f x %d = %.2f\n", numero, i, numero * i);
    }

    return 0;
}

