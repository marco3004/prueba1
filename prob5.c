#include <stdio.h>

int main() {
    int opcion;
    float temperatura, resultado;

    printf("Seleccione una opción:\n");
    printf("1. Convertir de Celsius a Fahrenheit\n");
    printf("2. Convertir de Fahrenheit a Celsius\n");
    scanf("%d", &opcion);

    if (opcion != 1 && opcion != 2) {
        printf("Opción no válida. Ingrese 1 o 2.\n");
        return 1;
    }

    printf("Ingrese la temperatura: ");

    // Loop para solicitar una temperatura válida
    while (1) {
        if (scanf("%f", &temperatura) == 1) {
            break; // Salir del bucle si se ingresó una temperatura válida
        }
        printf("Entrada inválida. Ingrese una temperatura: ");
        while (getchar() != '\n'); // Limpiar el búfer de entrada
    }

    if (opcion == 1) {
        resultado = (temperatura * 9 / 5) + 32;
        printf("%.2f grados Celsius equivalen a %.2f grados Fahrenheit.\n", temperatura, resultado);
    } else {
        resultado = (temperatura - 32) * 5 / 9;
        printf("%.2f grados Fahrenheit equivalen a %.2f grados Celsius.\n", temperatura, resultado);
    }

    return 0;
}

