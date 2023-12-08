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

	while ( 1 ){

		tecla = Teclado->GetKey( );

		comunicacionQT();
		game4enLinea();
	}
	return  0;
}
