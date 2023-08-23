#include <stdio.h>

int main() {
    float millas_por_galon;

    printf("Ingrese la cantidad de millas por galón imperial: ");
    while (scanf("%f", &millas_por_galon) != 1) {
        printf("Entrada inválida. Ingrese una cantidad numérica: ");
        while (getchar() != '\n'); // Limpiar el búfer de entrada
    }

    float galon_imperial_a_litros = 4.54609188;
    float milla_a_kilometro = 1.609344;

    float kilometros_por_litro = (milla_a_kilometro / galon_imperial_a_litros) / millas_por_galon;

    printf("La cantidad de kilómetros por litro es: %.2f\n", kilometros_por_litro);

    return 0;
}

