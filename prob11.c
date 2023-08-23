#include <stdio.h>

void eliminarDuplicados(int arreglo[], int *n) {
    int i, j, k;

    for (i = 0; i < *n; i++) {
        for (j = i + 1; j < *n; j++) {
            if (arreglo[i] == arreglo[j]) {
                for (k = j; k < *n - 1; k++) {
                    arreglo[k] = arreglo[k + 1];
                }
                (*n)--;
                j--;
            }
        }
    }
}

int main() {
    int n;

    printf("Ingrese el tamaño de la matriz: ");
    while (scanf("%d", &n) != 1 || n <= 0) {
        printf("Entrada inválida. Ingrese un número entero positivo: ");
        while (getchar() != '\n'); // Limpiar el búfer de entrada
    }

    int matriz[n];

    for (int i = 0; i < n; i++) {
        printf("Ingrese el número en la posición %d: ", i);
        while (scanf("%d", &matriz[i]) != 1) {
            printf("Entrada inválida. Ingrese un número entero: ");
            while (getchar() != '\n'); // Limpiar el búfer de entrada
        }
    }

    eliminarDuplicados(matriz, &n);

    printf("Matriz sin duplicados:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", matriz[i]);
    }
    printf("\n");

    return 0;
}

