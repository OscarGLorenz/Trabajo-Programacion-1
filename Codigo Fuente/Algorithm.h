/******************************************
* ARCHIVO:    algorithm.h
*
*DESCRIPCIÓN: 
* 		Funciones que ejecutan los distintos algoritmos de ordenación.
*AUTOR:
*		Alejandro Redondo.
********************************************/			

#ifndef ALGORITHM_H_
#define ALGORITHM_H_

#include "Benchmark.h"


/*Ordena por burbuja y guarda información en la estructura Experiment*/ 
   void bubble( int *lista ,int N, Experiment*experiment);

/*Ordena por inserción y guarda información en la estructura Experiment*/ 
   void insertion( int *lista, int N, Experiment*experiment);

/*Ordena por selección y guarda información en la estructura Experiment*/ 
   void selection( int*lista, int N, Experiment*experiment);
   
   /*Ejecuta la ordenación por Shell al array lista de N elementos y guarda información en la estructura Experiment*/ 
   void shell(int *lista, int N, Experiment * experiment);
   
/*Ordena por montículo y guarda información en la estructura Experiment*/ 
   void heapsort( int *lista, int N, Experiment * experiment);
   
/*Ordena por quicksort y guarda información en la estructura Experiment*/
   void quicksort(int *lista, int N,Experiment * experiment);
   
   #endif
