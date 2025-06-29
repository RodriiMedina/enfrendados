#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <iostream>
#include <time.h>
#include <ctime>


const int MAX_DADOS=12;

void juego();

int tiradaDadosObjetivo();

int tiradaDadosStock();

int tiradaDeTurno(int dados[], int stock[], int jugadorActual, char jugadores[2][50], int sumaObjetivo);

#endif // FUNCIONES_H_INCLUDED
