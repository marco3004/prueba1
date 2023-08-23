#include <stdio.h>

int main() {
    int opcion;

    printf("Seleccione una opción:\n");
    printf("1. Calcular volumen de un cubo\n");
    printf("2. Calcular volumen de una esfera\n");
    printf("3. Calcular volumen de una pirámide de base triangular\n");
    printf("4. Calcular volumen de una pirámide de base cuadrada\n");
    scanf("%d", &opcion);

    if (opcion < 1 || opcion > 4) {
        printf("Opción no válida. Ingrese una opción del 1 al 4.\n");
        return 1;
    }

    float resultado;

    switch (opcion) {
        case 1: // Cubo
            {
                int lado;
                printf("Ingrese el lado del cubo: ");
                while (scanf("%d", &lado) != 1) {
                    printf("Entrada inválida. Ingrese un número entero: ");
                    while (getchar() != '\n'); // Limpiar el búfer de entrada
                }
                resultado = lado * lado * lado;
                break;
            }
        case 2: // Esfera
            {
                int radio;
                printf("Ingrese el radio de la esfera: ");
                while (scanf("%d", &radio) != 1) {
                    printf("Entrada inválida. Ingrese un número entero: ");
                    while (getchar() != '\n'); // Limpiar el búfer de entrada
                }
                resultado = 4.0 / 3.0 * 3.14159 * radio * radio * radio;
                break;
            }
        case 3: // Pirámide de base triangular
            {
                int base, altura;
                printf("Ingrese la base de la pirámide de base triangular: ");
                while (scanf("%d", &base) != 1) {
                    printf("Entrada inválida. Ingrese un número entero: ");
                    while (getchar() != '\n'); // Limpiar el búfer de entrada
                }
                printf("Ingrese la altura de la pirámide de base triangular: ");
                while (scanf("%d", &altura) != 1) {
                    printf("Entrada inválida. Ingrese un número entero: ");
                    while (getchar() != '\n'); // Limpiar el búfer de entrada
                }
                resultado = 1.0 / 3.0 * base * altura;
                break;
            }
        case 4: // Pirámide de base cuadrada
            {
                int lado, altura;
                printf("Ingrese el lado de la pirámide de base cuadrada: ");
                while (scanf("%d", &lado) != 1) {
                    printf("Entrada inválida. Ingrese un número entero: ");
                    while (getchar() != '\n'); // Limpiar el búfer de entrada
                }
                printf("Ingrese la altura de la pirámide de base cuadrada: ");
                while (scanf("%d", &altura) != 1) {
                    printf("Entrada inválida. Ingrese un número entero: ");
                    while (getchar() != '\n'); // Limpiar el búfer de entrada
                }
                resultado = 1.0 / 3.0 * lado * lado * altura;
                break;
            }
    }

    printf("El volumen es: %.2f\n", resultado);

    return 0;
}

