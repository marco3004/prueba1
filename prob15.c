#include <stdio.h>
#include <ctype.h>

int main() {
    char mensaje[100];
    int desplazamiento;

    printf("Ingrese un mensaje en mayúsculas (sin espacios ni caracteres especiales): ");
    while (scanf("%s", mensaje) != 1) {
        printf("Entrada inválida. Ingrese un mensaje en mayúsculas: ");
        while (getchar() != '\n'); // Limpiar el búfer de entrada
    }

    // Verificar que el mensaje solo contiene letras mayúsculas
    for (int i = 0; mensaje[i] != '\0'; i++) {
        if (!isupper(mensaje[i])) {
            printf("El mensaje debe contener solo letras mayúsculas.\n");
            return 1;
        }
    }

    printf("Ingrese el número fijo de desplazamiento: ");
    while (scanf("%d", &desplazamiento) != 1) {
        printf("Entrada inválida. Ingrese un número entero: ");
        while (getchar() != '\n'); // Limpiar el búfer de entrada
    }

    // Realizar la encriptación César
    for (int i = 0; mensaje[i] != '\0'; i++) {
        mensaje[i] = (mensaje[i] - 'A' + desplazamiento) % 26 + 'A';
    }

    printf("Mensaje encriptado: %s\n", mensaje);

    return 0;
}

