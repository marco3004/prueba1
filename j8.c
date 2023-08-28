#include <stdio.h>
#include <stdlib.h>

int es_numero(const char *cadena) {
    int i = 0;
    while (cadena[i] != '\0') {
        if (cadena[i] < '0' || cadena[i] > '9') {
            return 0;
        }
        i++;
    }
    return 1;
}

int main() {
    srand(123); // Semilla fija para la generación de números aleatorios
    int opcion = 1;
    FILE *archivo = fopen("salida.txt", "a+");
    
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }
    
    fprintf(archivo, "Historial de datos del juego Gran 8:\n");
    
    while (opcion == 1) {
        int dado1 = rand() % 6 + 1; // Genera un número aleatorio entre 1 y 6
        int dado2 = rand() % 6 + 1;
        
        int suma = dado1 + dado2;
        
        if (suma == 8) {
            printf("¡Ganaste! La suma es 8.\n");
            fprintf(archivo, "Ganaste: %d + %d = %d\n", dado1, dado2, suma);
        } else if (suma == 7) {
            printf("Perdiste. La suma es 7.\n");
            fprintf(archivo, "Perdiste: %d + %d = %d\n", dado1, dado2, suma);
        } else {
            printf("Sigue lanzando los dados.\n");
            fprintf(archivo, "Sigue lanzando: %d + %d = %d\n", dado1, dado2, suma);
        }
        
        char entrada[10];
        int valido = 0;
        
        while (!valido) {
            printf("¿Quieres lanzar los dados de nuevo? (1 para sí, otro número para no): ");
            scanf("%s", entrada);
            
            if (es_numero(entrada)) {
                opcion = atoi(entrada);
                valido = 1;
            } else {
                printf("Opción no válida. Por favor, ingresa una opción válida.\n");
                scanf("%*s"); // Limpiar el búfer de entrada
            }
        }
        
        if (opcion != 1) {
            printf("Fin del juego.\n");
            break;
        }
    }
    
    fclose(archivo);
    
    // Visualizar historial de datos
    archivo = fopen("salida.txt", "r");
    if (archivo != NULL) {
        char caracter;
        while ((caracter = fgetc(archivo)) != EOF) {
            printf("%c", caracter);
        }
        fclose(archivo);
    }
    
    return 0;
}


