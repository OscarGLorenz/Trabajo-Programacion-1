/******************************************************************************
* ARCHIVO :  Datacreator.c
*
* DESCRIPCION: Contiene las funciones de inicializacion del vector de datos
*
* AUTOR :    Mario Music� Cort�s
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "Datacreator.h"

/*  --------------------------------------------------------------------------------
*	void swap(): 		Conmuta 2 valores por referencia
*	a: 					puntero al valor 1
*	b: 					puntero al valor 2
*/
static void swap(int * a, int * b){
  int aux = *a;
  *a = *b;
  *b = aux;
}

/*  --------------------------------------------------------------------------------
*	void startVector(): Rellena el array de datos con valores ascendentes
*	datavector: 		puntero al vector de datos
*	datasize: 			tama�o del vector de datos
*	dataspacing:		0 = consecutivos; 1 = incremento aleatorio
*/
static void startVector(int * datavector, int datasize, int dataspacing){
	int i;
	srand(clock());
	datavector[0] = 1 + dataspacing * (rand() % datasize);
	if(datasize > 1){
		for (i = 1; i < datasize; i++){
			datavector[i] = datavector[i - 1] + 1 + dataspacing * (rand() % datasize);
		}
	}
}

/*  --------------------------------------------------------------------------------
*	void invertVector(): Invierte el orden de un vector
*	datavector: 		puntero al vector de datos
*	datasize: 			tama�o del vector de datos
*/
static void invertVector(int * datavector, int datasize){
	int i, j;
	for (i = 0, j = datasize - 1; i < j; i++, j--){
		swap(datavector + i, datavector + j);
	}
}

/*  --------------------------------------------------------------------------------
*	void randomize():	Aleatoriza un array dado realizando tantas pasadas de swaps como su tama�o
*	datavector: 		puntero al vector de datos
*	datasize: 			tama�o del vector de datos
*/
static void randomize(int * datavector, int datasize){
	int i, j;
	srand(clock());
	for(j = 0; j < datasize; j++){
		for(i=0; i < datasize; i++){
			swap(datavector + i, datavector + (rand() % datasize));
		}
	}
}

/*  --------------------------------------------------------------------------------
*	void duplicate():	Modifica array en un numero aleatorio de posiciones, duplicando posiciones tambi�n aleatorias
*	datavector: 		puntero al vector de datos
*	datasize: 			tama�o del vector de datos
*/
static void duplicate(int * datavector, int datasize){
	int i, j;
	srand(clock());
	j = rand() % datasize;
	if (j < 2) j = 2;
	for(i = 0; i < j; i++){
		*(datavector + rand()%datasize) = *(datavector + rand()%datasize);
	}
}

void dataCreator(int * datavector, int datasize, dataType dataorder, int dataspacing){
	startVector(datavector, datasize, dataspacing);
	switch(dataorder){
		case INCREASING:
			break;
		case DECREASING:
			invertVector(datavector, datasize);
			break;
		case RANDOM:
			randomize(datavector, datasize);
			break;
		case REPEATED:
			randomize(datavector, datasize);
			duplicate(datavector, datasize);
			break;
	}
}
