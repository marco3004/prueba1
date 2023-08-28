#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void ordenar_calificaciones(int calificaciones[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (calificaciones[j] > calificaciones[j + 1]) {
                int temp = calificaciones[j];
                calificaciones[j] = calificaciones[j + 1];
                calificaciones[j + 1] = temp;
            }
        }
    }
}

float calcular_media(int calificaciones[], int n) {
    float suma = 0;
    for (int i = 0; i < n; i++) {
        suma += calificaciones[i];
    }
    return suma / n;
}

float calcular_mediana(int calificaciones[], int n) {
    if (n % 2 == 0) {
        return (calificaciones[n / 2 - 1] + calificaciones[n / 2]) / 2.0;
    } else {
        return calificaciones[n / 2];
    }
}

int calcular_moda(int calificaciones[], int n) {
    int moda = calificaciones[0];
    int frecuencia_maxima = 1;
    int frecuencia_actual = 1;

    for (int i = 1; i < n; i++) {
        if (calificaciones[i] == calificaciones[i - 1]) {
            frecuencia_actual++;
        } else {
            frecuencia_actual = 1;
        }

        if (frecuencia_actual > frecuencia_maxima) {
            frecuencia_maxima = frecuencia_actual;
            moda = calificaciones[i];
        }
    }

    return moda;
}

int main() {
    int calificaciones[5];
    int opcion;
    char entrada[10];

    do {
        printf("Menú:\n");
        printf("1. Ingresar calificaciones\n");
        printf("2. Calcular estadísticas descriptivas\n");
        printf("3. Mostrar historial de datos\n");
        printf("4. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%s", entrada);
        opcion = atoi(entrada);

        switch (opcion) {
            case 1:
                printf("Ingrese cinco calificaciones (entre 0 y 100):\n");
                for (int i = 0; i < 5; i++) {
                    printf("Calificación %d: ", i + 1);
                    scanf("%s", entrada);
                    calificaciones[i] = atoi(entrada);
                    if (calificaciones[i] < 0 || calificaciones[i] > 100) {
                        printf("Calificación fuera de rango. Ingrese una calificación entre 0 y 100.\n");
                        i--;
                    }
                }
                break;

            case 2:
                if (calificaciones[0] == 0) {
                    printf("Debe ingresar calificaciones primero.\n");
                } else {
                    ordenar_calificaciones(calificaciones, 5);
                    float media = calcular_media(calificaciones, 5);
                    float mediana = calcular_mediana(calificaciones, 5);
                    int moda = calcular_moda(calificaciones, 5);
                    int rango = calificaciones[4] - calificaciones[0];
                    float sum_diff_squared = 0;
                    for (int i = 0; i < 5; i++) {
                        sum_diff_squared += pow(calificaciones[i] - media, 2);
                    }
                    float varianza = sum_diff_squared / 5;
                    float desviacion_estandar = sqrt(varianza);

                    FILE *archivo = fopen("salida.txt", "w");
                    if (archivo != NULL) {
                        fprintf(archivo, "Calificaciones ingresadas: ");
                        for (int i = 0; i < 5; i++) {
                            fprintf(archivo, "%d ", calificaciones[i]);
                        }
                        fprintf(archivo, "\nMedia: %.2f\n", media);
                        fprintf(archivo, "Mediana: %.2f\n", mediana);
                        fprintf(archivo, "Moda: %d\n", moda);
                        fprintf(archivo, "Rango: %d\n", rango);
                        fprintf(archivo, "Desviación Estándar: %.2f\n", desviacion_estandar);
                        fprintf(archivo, "Varianza: %.2f\n", varianza);
                        fclose(archivo);
                        printf("Resultados almacenados en salida.txt\n");
                    } else {
                        printf("Error al abrir el archivo para escritura.\n");
                    }
                }
                break;

            case 3:
                printf("Historial de datos:\n");
                char caracter;
                FILE *archivo = fopen("salida.txt", "r");
                if (archivo != NULL) {
                    while ((caracter = fgetc(archivo)) != EOF) {
                        printf("%c", caracter);
                    }
                    fclose(archivo);
                } else {
                    printf("Error al abrir el archivo para lectura.\n");
                }
                break;

            case 4:
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("Opción inválida. Por favor, seleccione una opción válida.\n");
        }

    } while (opcion != 4);

    return 0;
}


