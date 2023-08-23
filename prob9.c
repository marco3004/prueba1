#include <stdio.h>

int main() {
    int n;

    printf("Ingrese la cantidad de términos de la serie de Fibonacci que desea mostrar: ");

    // Loop para solicitar un número válido
    while (1) {
        if (scanf("%d", &n) == 1) {
            break; // Salir del bucle si se ingresó un número válido
        }
        printf("Entrada inválida. Ingrese un número: ");
        while (getchar() != '\n'); // Limpiar el búfer de entrada
    }

    int primerTermino = 0;
    int segundoTermino = 1;

    printf("Serie de Fibonacci con %d términos:\n", n);

    if (n >= 1) {
        printf("%d ", primerTermino);
    }
    if (n >= 2) {
        printf("%d ", segundoTermino);
    }

    for (int i = 3; i <= n; i++) {
        int siguienteTermino = primerTermino + segundoTermino;
        printf("%d ", siguienteTermino);
        primerTermino = segundoTermino;
        segundoTermino = siguienteTermino;
    }

    printf("\n");

    return 0;
}

