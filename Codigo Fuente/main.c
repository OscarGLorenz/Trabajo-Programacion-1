/******************************************************************************
* ARCHIVO :  Main.c
*
* DESCRIPCION: Archivo principal del programa. 
*		Sintetizado en llamadas a funciones de las librerias y declaracion de tipos
*
* AUTOR :    Mario Musicò Cortés y Óscar García Lorenz
******************************************************************************/

#include "Benchmark.h"

#include <stdio.h>
#include <string.h>

#include "TUI.h"
#include "Dataorganizer.h"
#include "Algorithm.h"


//****************************************************************************
// Declaración e inicializacion de variables de tipos

// Nombres de los algoritmos a ejecutar
algorithm_ptr algorithmTypes[] = {bubble,insertion,selection,shell,heapsort,quicksort};
// Nombres de los algoritmos a visualizar
char algorithmNames[][NAMESIZE] = {"Burbuja  ", "Insercion", "Seleccion", "Shell    ", "Monticulo", "Quicksort"};
// Número de algoritmos						(i)
int n_algorithms = sizeof(algorithmNames) / sizeof(algorithmNames[0]);

// Nombres de los tipos de datos a utilizar
dataType dataTypes[] = {INCREASING, DECREASING, RANDOM, REPEATED};
// Nombres de los tipos de datos a visualizar
char dataNames[][NAMESIZE] = {"Creciente", "Decreciente", "Aleatorio", "Repetidos"};
// Número de tipos de datos					(j)
int n_data = sizeof(dataNames) / sizeof(dataNames[0]);

// Nombres de los costes
char costNames[][NAMESIZE] = {"Comparaciones", "Movimientos  ", "Tiempo (ms)  "};
// Número de costes							(k)

// Cantidades de datos con las que se iteran
int dataSizes[] = {10, 100, 1000, 2000, 3000, 4000};
// Número de iteraciones por experimento	(l)
int iterations = sizeof(dataSizes) / sizeof(dataSizes[0]);
//****************************************************************************


/*  --------------------------------------------------------------------------------
*	void runExperiment(): 	Ejecuta el modo EXPERIMENTO
*/
void runExperiment(){
	char mode = experimentMode(iterations, dataSizes);
	int run_algorithmID;
	dataType run_dataType;
	
	char **** results;
	switch (mode){
		case 'a':		// En modo automatico, comparar todos los algoritmos con todos los tipos de datos
			results = calculateTable(dataSizes, iterations, algorithmTypes, n_algorithms, dataTypes, n_data);
			resultVisualizer(results, algorithmNames, n_algorithms, dataNames, n_data, costNames);
			break;
		case 'b':		// Comparar la velocidad de un algoritmo para diferentes tipos de datos
			run_algorithmID = algorithmMode(n_algorithms, algorithmNames);
			n_algorithms = 1;
			results = calculateTable(dataSizes, iterations, &algorithmTypes[run_algorithmID], n_algorithms, dataTypes, n_data);
			resultVisualizer(results, &algorithmNames[run_algorithmID], n_algorithms, dataNames, n_data, costNames);
			break;
		case 'c':	;	// Comparar diferentes algoritmos dado un tipo de dato
			run_dataType = dataTypeMode(n_data, dataNames);
			n_data = 1;
			results = calculateTable(dataSizes, iterations, algorithmTypes, n_algorithms, &dataTypes[run_dataType], n_data);
			resultVisualizer(results, algorithmNames, n_algorithms, &dataNames[run_dataType], n_data, costNames);
			break;
	}
	freeTable(results, n_algorithms, n_data, COSTS);
}

/*  --------------------------------------------------------------------------------
*	void runOrganizer(): 	Ejecuta el modo ORDENADOR
*/
void runOrganizer(){
	int datasize;
	FILE* datafile;
	char filename[FILESIZE];
	char**** results;
	char datamode = dataInputMode();
	char run_dataType[NAMESIZE] = "Usuario";
	n_data = 1;
	switch (datamode){
		case 'a':
			printf("\nNumero de elementos que desea introducir: ");
			scanf("%d", &datasize);
			strcpy(filename, "Datos.txt");
			break;
		case 'b':
			datasize = fileOpener(&datafile, filename);
			break;
	}
	int datavector[datasize];
	switch (datamode){
		case 'a':
			inputData(datavector, datasize);
			break;
		case 'b':
			fileReader(datavector, datasize, datafile);
			break;
	}
	results = multiSorter(datavector, datasize, algorithmTypes, n_algorithms, filename);
	resultVisualizer(results, algorithmNames, n_algorithms, &run_dataType, n_data, costNames);
	freeTable(results, n_algorithms, n_data, COSTS);
}

/*  --------------------------------------------------------------------------------
*	int main(): 	Llama al selector de modo y despues a la funcion del modo seleccionado
*/
int main(int argc, char const *argv[]){
	char mode = programMode();
	switch (mode){
		case 'a':
			runExperiment();
			break;
		case 'b':
			runOrganizer();
			break;
	}
	return 0;
}
