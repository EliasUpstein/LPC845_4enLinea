#include "comunicacionQT.h"

uint8_t button = BUTTON_ERROR;

void comunicacionQT(void)
{
	static uint8_t dato;

	if(uart0->Message(&dato, 1) != nullptr)
	{
		if(startGame)
		{
			switch(dato)
			{
			case 48:	//0
				button = DERECHA;
				break;
			case 49:	//1
				button = CONFIRMAR;
				break;
			case 50:	//2
				button = IZQUIERDA;
				break;
			default:
				button = BUTTON_ERROR;
				break;
			}
		}
		else
		{
			switch(dato)
			{
			case 82:	//R (rojo, jugador 1)
				tablero.setColor1(ROJO);
				break;
			case 66:	//B (azul, jugador 1)
				tablero.setColor1(AZUL);
				break;
			case 89:	//Y (amarillo, jugador 1)
				tablero.setColor1(AMARILLO);
				break;
			case 71:	//G (verde, jugador 1)
				tablero.setColor1(VERDE);
				break;
			case 80:	//P (rosa, jugador 1)
				tablero.setColor1(ROSA);
				break;
			case 76:	//L (celeste, jugador 1)
				tablero.setColor1(CELESTE);
				break;
			case 86:	//V (violeta, jugador 1)
				tablero.setColor1(VIOLETA);
				break;
			case 79:	//O (naranja, jugador 1)
				tablero.setColor1(NARANJA);
				break;
			case 114:	//r (rojo, jugador 2)
				tablero.setColor2(ROJO);
				break;
			case 98:	//b (azul, jugador 2)
				tablero.setColor2(AZUL);
				break;
			case 121:	//y (amarillo, jugador 2)
				tablero.setColor2(AMARILLO);
				break;
			case 103:	//g (verde, jugador 2)
				tablero.setColor2(VERDE);
				break;
			case 112:	//p (rosa, jugador 2)
				tablero.setColor2(ROSA);
				break;
			case 108:	//l (celeste, jugador 2)
				tablero.setColor2(CELESTE);
				break;
			case 118:	//v (violeta, jugador 2)
				tablero.setColor2(VIOLETA);
				break;
			case 111:	//o (naranja, jugador 2)
				tablero.setColor2(NARANJA);
				break;
			case 83:	//S (startGame)
				startGame = true;
				break;
			default:
				break;
			}
		}
	}
	else						//Cuando no recibe nada recetea el button
		button = BUTTON_ERROR;
}
