#include <stdio.h>

int leeValor(void);

int main() {

	// Variables auxiliares
	int contadorLlamadas = 0;
	int valorActual = 0;
	int arrayUno[100] = { 0 };
	int posArrayUno = 0;
	int arrayDos[100] = { 0 };
	int posArrayDos = 0;
	int arrayUnoAux = 0;
	int arrayDosAux = 0;


	while (contadorLlamadas < 100) {

		// Registramos el valor que retorna la función
		valorActual = leeValor();

		// Cambio de array
		if (valorActual == -1) {
			// Array actual 1
			arrayUnoAux = 1;
			arrayDosAux = 0;
		}
		else if (valorActual == -2) {
			// Array actual 2
			arrayUnoAux = 0;
			arrayDosAux = 1;
		}

		// Almacenamos
		else if (arrayUnoAux == 1) {
			arrayUno[posArrayUno] = valorActual;
			posArrayUno++;
		}
		else if (arrayDosAux == 1) {
			arrayDos[posArrayDos] = valorActual;
			posArrayDos++;
		}

		// Aumentamos el registro de llamadas a la función
		contadorLlamadas++;
	}

	// Sacamos por pantalla
	printf("Los elementos del array 1 son: %d\n", posArrayUno);
	for (int i = 0; i < posArrayUno; i++) {
		printf("%d,", arrayUno[i]);
	}

	printf("\n\nLos elementos del array 2 son: %d\n", posArrayDos);
	for (int i = 0; i < posArrayDos; i++) {
		printf("%d,", arrayDos[i]);
	}

	printf("\n");

	return 0;
}