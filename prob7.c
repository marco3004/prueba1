#include <stdio.h>

int main() {
    int numero;
    long long factorial = 1;

    printf("Ingrese un número para calcular su factorial: ");

    // bucle para solicitar un número válido
    while (1) {
        if (scanf("%d", &numero) == 1) {
            break; // Salir del bucle si se ingresó un número válido
        }
        printf("Entrada inválida. Ingrese un número: ");
        while (getchar() != '\n'); // Limpiar el búfer de entrada
    }

    if (numero < 0) {
        printf("No se puede calcular el factorial de un número negativo.\n");
    } else {
        for (int i = 1; i <= numero; i++) {
            factorial *= i;
        }
        printf("El factorial de %d es: %lld\n", numero, factorial);
    }

    return 0;
}

