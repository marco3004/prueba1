#include <stdio.h>
#include <stdlib.h>

int es_primo(int numero) {
    if (numero <= 1) {
        return 0; // No es primo
    }
    for (int i = 2; i * i <= numero; i++) {
        if (numero % i == 0) {
            return 0; // No es primo
        }
    }
    return 1; // Es primo
}

int main() {
    int numero;
    char entrada[20];
    int opcion;
    FILE *archivo;

    do {
        printf("Menú:\n");
        printf("1. Verificar si un número es primo o compuesto\n");
        printf("2. Mostrar historial de verificaciones\n");
        printf("3. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%s", entrada);
        opcion = atoi(entrada);

        switch (opcion) {
            case 1:
                printf("Ingrese un número: ");
                scanf("%s", entrada);
                if (sscanf(entrada, "%d", &numero) != 1) {
                    printf("Entrada inválida. Ingrese un número válido.\n");
                    break;
                }
                if (es_primo(numero)) {
                    printf("%d es un número primo.\n", numero);
                } else {
                    printf("%d es un número compuesto.\n", numero);
                }

                archivo = fopen("historial.txt", "a");
                if (archivo != NULL) {
                    fprintf(archivo, "Número ingresado: %d - Es primo: %s\n", numero, es_primo(numero) ? "Sí" : "No");
                    fclose(archivo);
                } else {
                    printf("Error al abrir el archivo para escritura.\n");
                }
                break;

            case 2:
                printf("Historial de verificaciones:\n");
                char caracter;
                archivo = fopen("historial.txt", "r");
                if (archivo != NULL) {
                    while ((caracter = fgetc(archivo)) != EOF) {
                        printf("%c", caracter);
                    }
                    fclose(archivo);
                } else {
                    printf("Error al abrir el archivo para lectura.\n");
                }
                break;

            case 3:
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("Opción inválida. Por favor, seleccione una opción válida.\n");
        }

    } while (opcion != 3);

    return 0;
}

