/*
===============================================================================
 Name        : main.c
 Author      : Grupo 3 - R2001 - CL2023
 Description : TPO - 4 en Línea
===============================================================================
*/
#include "inicializarInfotronic.h"

int  main(void)
{
	InicializarInfotronic();			//Inicialización del kit Infotronic
	initGame();							//Inicialización del juego (objetos y variables)

	while ( 1 ){
		tecla = Teclado->GetKey( );		//Lectura del teclado

		comunicacionQT();				//Lectura del puerto serie proveniente de la GUI
		game4enLinea();					//Lógica del juego
	}
	return  0;
}
