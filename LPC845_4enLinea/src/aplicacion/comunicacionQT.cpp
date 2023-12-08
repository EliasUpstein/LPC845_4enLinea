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
				tablero.setColor1(INTENSIDAD, 0, 0);
				break;
			case 66:	//B (azul, jugador 1)
				tablero.setColor1(0, 0, INTENSIDAD);
				break;
			case 89:	//Y (amarillo, jugador 1)
				tablero.setColor1(INTENSIDAD, INTENSIDAD, 0);
				break;
			case 71:	//G (verde, jugador 1)
				tablero.setColor1(0, INTENSIDAD, 0);
				break;
			case 114:	//r (rojo, jugador 2)
				tablero.setColor2(INTENSIDAD, 0, 0);
				break;
			case 98:	//b (azul, jugador 2)
				tablero.setColor2(0, 0, INTENSIDAD);
				break;
			case 121:	//y (amarillo, jugador 2)
				tablero.setColor2(INTENSIDAD, INTENSIDAD, 0);
				break;
			case 103:	//g (verde, jugador 2)
				tablero.setColor2(0, INTENSIDAD, 0);
				break;
			case 83:
				startGame = true;
				break;
			default:
				break;
			}
		}
	}
}
