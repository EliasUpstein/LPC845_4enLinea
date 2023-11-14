/*
===============================================================================
 Name        : main.c
 Author      : 
 Description : 
===============================================================================
*/
#include "inicializarInfotronic.h"

#define NLEDS 1		//Para hacer pruebas visibles

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

//	static volatile uint8_t bit_actual_bajo;
//	int i = 0;

	while ( 1 ){
		if(uart0->Message(&dato, 1))
		{
			uart0->Transmit("Recibi: ");
			uart0->Transmit(&dato, 1);
			uart0->Transmit("\r\n");

			if(dato == 115)					// "s", valor aleatorio para probar la transmisión
			{
				uart0->Transmit("OK\r\n");		//Confirma recepción

				show();						//Inicia la transmisión
			}

			else if(dato == 97)				// "a", valor aleatorio para probar la transmisión
			{
				uart0->Transmit("PRENDIDO\r\n");		//Confirma recepción
				out_matriz.ClrPin();
			}
			else if(dato == 112)			// "p", valor aleatorio para probar la transmisión
			{
				uart0->Transmit("APAGADO\r\n");	//Confirma recepción
				out_matriz.SetPin();
			}
		}

//		if(uart0->Message(&dato, 1))
//		{
//			bit_actual_bajo = ((matriz[0] & (0x1 << (23 - i))) == 0);	//Desplazamiento de izquierda a derecha (MSB to LSB)
//
//			bit_actual_bajo ? uart0->Transmit("BAJO\r\n") : uart0->Transmit("ALTO\r\n");
//
//			(i < 24) ? i++ : i = 0;
//		}
	}
	return  0;
}


