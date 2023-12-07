/*
===============================================================================
 Name        : main.c
 Author      : 
 Description :
===============================================================================
*/
#include "inicializarInfotronic.h"

int  main(void)
{
	InicializarInfotronic();
	tablero.limpiarTablero();
	tablero.setColumnaActual(0);

	tablero.ocuparCasillero(0, tablero.getColumnaActual());
	matriz.show();

	while ( 1 ){

		tecla = Teclado->GetKey( );
//		button = comunicacionQT();

		game4enLinea();

	}
	return  0;
}
