#include <stdio.h>

int main() {
	char cadena[100]; 

	printf("Ingresa una cadena de texto: ");
	if (scanf("%99[^\n]", cadena) != 1) {
	   fprintf(stderr, "Error: No se pudo leer la cadena correctamente.\n");
        return 1;
    }

	int cantidad_caracteres = 0;
	while (cadena[cantidad_caracteres] != '\0') {
	cantidad_caracteres++;
    }

	printf("La cadena ingresada tiene %d caracteres.\n", cantidad_caracteres);

return 0;

}
