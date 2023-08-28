#include <stdio.h>
#include <stdlib.h>

float calcular_impuesto(float precio, float iva) {
    return precio * iva;
}

float calcular_precio_sin_impuesto(float precio, float impuesto) {
    return precio - impuesto;
}

int main() {
    float precio;
    float iva = 0.12;
    char entrada[20];
    int opcion;
    FILE *archivo;

    do {
        printf("Menú:\n");
        printf("1. Calcular impuesto y precio sin impuesto\n");
        printf("2. Mostrar historial de cálculos\n");
        printf("3. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%s", entrada);
        opcion = atoi(entrada);

        switch (opcion) {
            case 1:
                printf("Ingrese el precio en quetzales: ");
                scanf("%s", entrada);
                if (sscanf(entrada, "%f", &precio) != 1) {
                    printf("Entrada inválida. Ingrese un precio válido.\n");
                    break;
                }
                float impuesto = calcular_impuesto(precio, iva);
                float precio_sin_impuesto = calcular_precio_sin_impuesto(precio, impuesto);

                printf("Impuesto al Valor Agregado (IVA): %.2f quetzales\n", impuesto);
                printf("Precio sin impuesto: %.2f quetzales\n", precio_sin_impuesto);

                archivo = fopen("historial.txt", "a");
                if (archivo != NULL) {
                    fprintf(archivo, "Precio ingresado: %.2f quetzales - IVA: %.2f quetzales - Precio sin impuesto: %.2f quetzales\n", precio, impuesto, precio_sin_impuesto);
                    fclose(archivo);
                } else {
                    printf("Error al abrir el archivo para escritura.\n");
                }
                break;

            case 2:
                printf("Historial de cálculos:\n");
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

