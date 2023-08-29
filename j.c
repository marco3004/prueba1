#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void jugarAdivinanzas();
void verHistorial();
void borrarHistorial();
void guardarHistorial(char *nombre, int puntaje);

int main() {
    int opcion;

    do {
        printf("Menú:\n");
        printf("1. Jugar a las adivinanzas\n");
        printf("2. Ver historial de jugadores\n");
        printf("3. Borrar historial de jugadores\n");
        printf("4. Salir\n");
        printf("Selecciona una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                jugarAdivinanzas();
                break;
            case 2:
                verHistorial();
                break;
            case 3:
                borrarHistorial();
                break;
            case 4:
                printf("fin de juego\n");
                break;
            default:
                printf("Opción inválida. Ingresa una opción válida.\n");
        }
    } while (opcion != 4);

    return 0;
}

void jugarAdivinanzas() {
    char nombre[50];
    int puntaje = 0;

    printf("\n¡Bienvenido a las adivinanzas!\n");
    printf("Responde las siguientes adivinanzas:\n");

    // Adivinanzas y respuestas
    char *adivinanzas[5] = {
        "Puedo volar sin tener alas, y doy sombra sin ser sombrilla. ¿Quién soy?",
        "Soy redondo y amarillo por fuera, blanco por dentro, y me gusta estar en un plato caliente. ¿Qué soy?",
        "Tengo patas y no camino, tengo brazos y no abrazo. ¿Qué soy?",
        "Tengo agujas pero no coso, tengo números pero no cuento. ¿Qué soy?",
        "Si me nombras, dejo de existir. ¿Qué soy?"
    };
    char *respuestas[5] = {
        "nube",
        "huevo",
        "silla",
        "reloj",
        "secreto"
    };

    for (int i = 0; i < 5; i++) {
        printf("\nAdivinanza %d: %s\n", i+1, adivinanzas[i]);
        char respuestaUsuario[50];
        printf("Ingresa tu respuesta: ");
        scanf(" %[^\n]", respuestaUsuario);

        if (strcmp(respuestaUsuario, respuestas[i]) == 0) {
            printf("¡Respuesta correcta!\n");
            puntaje++;
        } else {
            printf("Respuesta incorrecta. La respuesta correcta es: %s\n", respuestas[i]);
        }
    }

    printf("\n¡Juego terminado!\n");
    printf("Ingresa tu nombre: ");
    scanf(" %[^\n]", nombre);

    guardarHistorial(nombre, puntaje);
}

void verHistorial() {
    printf("\nHistorial de jugadores:\n");
    FILE *archivo = fopen("historial.txt", "r");
    if (archivo == NULL) {
        printf("No hay historial disponible.\n");
        return;
    }

    char nombre[50];
    int puntaje;
    while (fscanf(archivo, "%s %d", nombre, &puntaje) != EOF) {
        printf("Nombre: %s, Puntaje: %d\n", nombre, puntaje);
    }

    fclose(archivo);
}

void borrarHistorial() {
    FILE *archivo = fopen("historial.txt", "w");
    if (archivo == NULL) {
        printf("Error al borrar el historial.\n");
        return;
    }
    fclose(archivo);
    printf("\nHistorial de jugadores borrado.\n");
}

void guardarHistorial(char *nombre, int puntaje) {
    FILE *archivo = fopen("historial.txt", "a");
    if (archivo == NULL) {
        printf("Error al guardar el historial.\n");
        return;
    }
    fprintf(archivo, "%s %d\n", nombre, puntaje);
    fclose(archivo);
    printf("Historial guardado exitosamente.\n");
}


