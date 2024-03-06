#include <stdio.h>
#include <stdlib.h>

int leeValor(void);

int main() {

	// Variables auxiliares
	int contadorLlamadas = 0;
	int valorActual = 0;
	int tamanoArrayUno = 0;
	int tamanoArrayDos = 0;
	int arrayUnoAux = 0;
	int arrayDosAux = 0;

	// Memoria dinámica
	int* arrayUno = NULL; // Los punteros se declaran a NULL
	int* arrayDos = NULL;
	if (((arrayUno = (int*)malloc(sizeof(int))) != NULL) && ((arrayDos = (int*)malloc(sizeof(int))) != NULL)) {
	} else {
		printf("Error reservando memoria");
	}

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

			tamanoArrayUno++; //Aumentamos en uno el contador que indica el tamaño del array

			// Reasignamos espacio
			if ( (arrayUno = (int*)realloc(arrayUno, tamanoArrayUno * sizeof(int))) != NULL) {
			} else {
				printf("Error modificando el bloque de memoria\n");
			}

			arrayUno[tamanoArrayUno - 1] = valorActual;

		}
		else if (arrayDosAux == 1) {

			tamanoArrayDos++;

			// Reasignamos espacio
			if ( (arrayDos = (int*)realloc(arrayDos, tamanoArrayDos * sizeof(int))) != NULL) {
			} else {
				printf("Error modificando el bloque de memoria\n");
			}

			arrayDos[tamanoArrayDos - 1] = valorActual;

		}

		// Aumentamos el registro de llamadas a la función
		contadorLlamadas++;
	}

	// Sacamos por pantalla
	printf("Los elementos del array 1 son: %d\n", tamanoArrayUno);
	for (int i = 0; i < tamanoArrayUno; i++) {
		printf("%d,", arrayUno[i]);
	}

	printf("\n\nLos elementos del array 2 son: %d\n", tamanoArrayDos);
	for (int i = 0; i < tamanoArrayDos; i++) {
		printf("%d,", arrayDos[i]);
	}

	free(arrayUno);
	free(arrayDos);

	printf("\n");

	return 0;
}