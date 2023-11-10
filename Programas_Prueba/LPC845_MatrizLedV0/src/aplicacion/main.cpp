/*
===============================================================================
 Name        : main.c
 Author      : 
 Description : 
===============================================================================
*/
#include "inicializarInfotronic.h"

#define NLEDS 3		//Para hacer pruebas visibles

int  main(void)
{
	uint8_t dato;

	InicializarInfotronic();
	
	//Creo un led auxiliar en un color determinado
	Led_WS2812B led_aux;
	led_aux.r = 0;
	led_aux.g = 100;
	led_aux.b = 0;

	//Inicializo la matriz con la cantidad de leds y guardo en cada uno el color led_aux
	MatrizLed(NLEDS);
	for(int i=0; i < NLEDS; i++)
		matriz[i] = led_aux;

	while ( 1 ){
		if(uart0->Message(&dato, 1))
		{
			uart0->Transmit("Recibi: ");
			uart0->Transmit(&dato, 1);
			uart0->Transmit("\r\n");

			if(dato == 115)					// "s", valor aleatorio para probar la transmisión
			{
				uart0->Transmit("OK");		//Confirma recepción

				show();						//Inicia la transmisión
			}
		}
	}
	return  0;
}


