/*
===============================================================================
 Name        : main.c
 Author      : 
 Description :
===============================================================================
*/
#include "inicializarInfotronic.h"

#define TIEMPO_VICTORIA 50 //Tiempo en décimas de segundo

#define FILAS 8
#define COLUMNAS 8

//Estados
#define JUGADOR 0
#define VICTORIA 1

int  main(void)
{
	uint8_t tecla;
	Timer t;

	uint8_t estado = JUGADOR;
	Tablero tablero(FILAS, COLUMNAS, matriz);

	InicializarInfotronic();
	tablero.limpiarTablero();
	tablero.setColumnaActual(0);

	tablero.ocuparCasillero(0, tablero.getColumnaActual());
	matriz.show();

	while ( 1 ){

		tecla = Teclado->GetKey( );

		switch (estado)
		{
		case JUGADOR:
			//Se presiona el pulsador de la izquierda y no está en la primer columna y la izquierda está libre
			if ((tecla ==5) && (tablero.getColumnaActual() != 0))
			{
				tablero.liberarCasillero(0, tablero.getColumnaActual());
				tablero.decrementarColumna(1);
				tablero.ocuparCasillero(0, tablero.getColumnaActual());
				matriz.show();
			}
			//Se presiona el pulsador de la derecha y no está en la última columna y la derecha está libre
			else if ((tecla ==3) && (tablero.getColumnaActual() != COLUMNAS-1))
			{
				tablero.liberarCasillero(0, tablero.getColumnaActual());
				tablero.incrementarColumna(1);
				tablero.ocuparCasillero(0, tablero.getColumnaActual());
				matriz.show();
			}
			else if (tecla ==4)
			{
				tablero.tirarFicha(tablero.getColumnaActual());
				tablero.setColumnaActual(0);

				if (tablero.checkWinner())
				{
					estado = VICTORIA;
					tablero.llenarTablero();
					t = TIEMPO_VICTORIA;
				}
				else
				{
					tablero.changePlayer();
					tablero.ocuparCasillero(0, tablero.getColumnaActual());
				}
				matriz.show();
			}
			break;
		case VICTORIA:
			if(t)
			{
				tablero.limpiarTablero();
				tablero.changePlayer();
				tablero.ocuparCasillero(0, tablero.getColumnaActual());
				estado = JUGADOR;
				matriz.show();
			}
			break;
		default:
			tablero.limpiarTablero();
			matriz.show();
			tablero.setColumnaActual(0);
			estado = JUGADOR;
			break;
		}
	}
	return  0;
}
