#include <stdio.h>

int main(){
int n, i, suma = 0, multiplicacion = 1;
	char operacion;

	printf("Ingrese la cantidad de factores a ingresar: ");
	if (scanf("%d", &n) != 1 || n <= 0) {
          printf("Cantidad de numeros no valida. Ingrese un valor numerico.\n");
        return 1;
    }

    printf("Ingrese la operacion a realizar (s/m): ");
	if (scanf(" %c", &operacion) != 1 || (operacion != 's' && operacion != 'm')) {
          printf("Operacion no valida. Por favor, ingrese 's' para suma o 'm' para multiplicacion.\n");
        return 1;
    }

	for (i = 1; i <= n; i++) {
           int numero;
              printf("Ingrese el numero %d: ", i);
        if (scanf("%d", &numero) != 1) {
           printf("Valor no valido. Ingrese un factor entero.\n");
        return 1;
        }

	if (operacion == 's') {
            suma += numero;
          }else if (operacion == 'm') {
            multiplicacion *= numero;
        }
    }

	if (operacion == 's') {
          printf("La suma de los factores es: %d\n", suma);
          }else if (operacion == 'm') {
          printf("La multiplicacion de los factores es: %d\n", multiplicacion);
    }

  return 0;
  
}
