#include <stdio.h>


int main() {
    char cadena[1000];
    char resultado[2000]; // El resultado puede ser el doble del tamaño de la cadena original

    printf("Ingrese una cadena: ");

    // buce para solicitar una cadena válida
    while (1) {
        if (scanf("%s", cadena) == 1) {
            break; // Salir del bucle si se ingresó una cadena válida
        }
        printf("Entrada inválida. Ingrese una cadena: ");
        while (getchar() != '\n'); // Limpiar el búfer de entrada
    }

    int resultadoIndex = 0;
    for (int i = 0; cadena[i] != '\0'; i++) {
        resultado[resultadoIndex++] = cadena[i];
        resultado[resultadoIndex++] = cadena[i];
    }
    resultado[resultadoIndex] = '\0'; // Agregar el terminador de cadena

    printf("Resultado: %s\n", resultado);

    return 0;
}

