/*
===============================================================================
 Name        : main.c
 Author      : 
 Description : 
===============================================================================
*/
#include "inicializarInfotronic.h"

#define NLEDS 64
#define RED 0
#define GREEN 0
#define BLUE 50

int  main(void)
{
	uint8_t dato;

	InicializarInfotronic();
	
	MatrizLed matriz(0, 29, NLEDS);
	matriz.setAllLeds(RED, GREEN, BLUE);

	while ( 1 ){
		if(uart0->Message(&dato, 1))
		{
			uart0->Transmit("Recibi: ");
			uart0->Transmit(&dato, 1);
			uart0->Transmit("\r\n");

			if(dato == 115)					// "s"
			{
				uart0->Transmit("OK\r\n");
				matriz.show();
			}

			else if(dato == 97)				// "a"
			{
				uart0->Transmit("PRENDIDO\r\n");
				matriz.setAllLeds(RED, GREEN, BLUE);
			}
			else if(dato == 112)			// "p"
			{
				uart0->Transmit("APAGADO\r\n");
				matriz.clear();
			}
			else if(dato == 98)				// "b"
			{
				uart0->Transmit("0 AL 7\r\n");
				matriz.setLeds(0, 8, RED, GREEN, BLUE);
			}
		}
	}
	return  0;
}


