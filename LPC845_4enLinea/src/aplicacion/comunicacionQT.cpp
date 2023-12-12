#include "comunicacionQT.h"

uint8_t button = BUTTON_ERROR;		//Variable que almacena el botón presionado en la GUI

/*Si recibe un dato por el puerto serie, realiza la acción correspondiente.
	Recibe '0', '1' y '2' para los botones "IZQUIERDA", "DERECHA" Y "CONFIRMAR".
	Recibe 'R', 'B', 'G', 'Y', 'P', 'L', 'V', 'O' para cambier el color de un jugador,
	si se recibe en mayúscula afectan al jugador 1, en minúscula al jugador 2.
	Recibe 'S' para iniciar el juego
	Recibe 'F' para reiniciar
	Recibe 'Z' para resetear los contadores de victoria
*/
void comunicacionQT(void)
{
	static uint8_t dato;

	if(uart0->Message(&dato, 1) != nullptr)
	{
		switch(dato)
		{
		//BOTONES INTERFAZ
		case 48:	//0
			button = DERECHA;
			break;
		case 49:	//1
			button = CONFIRMAR;
			break;
		case 50:	//2
			button = IZQUIERDA;
			break;
		//COLORES INTERFAZ
		case 82:	//R (rojo, jugador 1)
			actualizarJugador(Tablero::JUGADOR1, nROJO);
			break;
		case 66:	//B (azul, jugador 1)
			actualizarJugador(Tablero::JUGADOR1, nAZUL);
			break;
		case 71:	//G (verde, jugador 1)
			actualizarJugador(Tablero::JUGADOR1, nVERDE);
			break;
		case 89:	//Y (amarillo, jugador 1)
			actualizarJugador(Tablero::JUGADOR1, nAMARILLO);
			break;
		case 80:	//P (rosa, jugador 1)
			actualizarJugador(Tablero::JUGADOR1, nROSA);
			break;
		case 76:	//L (celeste, jugador 1)
			actualizarJugador(Tablero::JUGADOR1, nCELESTE);
			break;
		case 86:	//V (violeta, jugador 1)
			actualizarJugador(Tablero::JUGADOR1, nVIOLETA);
			break;
		case 79:	//O (naranja, jugador 1)
			actualizarJugador(Tablero::JUGADOR1, nNARANJA);
			break;
		case 114:	//r (rojo, jugador 2)
			actualizarJugador(Tablero::JUGADOR2, nROJO);
			break;
		case 98:	//b (azul, jugador 2)
			actualizarJugador(Tablero::JUGADOR2, nAZUL);
			break;
		case 103:	//g (verde, jugador 2)
			actualizarJugador(Tablero::JUGADOR2, nVERDE);
			break;
		case 121:	//y (amarillo, jugador 2)
			actualizarJugador(Tablero::JUGADOR2, nAMARILLO);
			break;
		case 112:	//p (rosa, jugador 2)
			actualizarJugador(Tablero::JUGADOR2, nROSA);
			break;
		case 108:	//l (celeste, jugador 2)
			actualizarJugador(Tablero::JUGADOR2, nCELESTE);
			break;
		case 118:	//v (violeta, jugador 2)
			actualizarJugador(Tablero::JUGADOR2, nVIOLETA);
			break;
		case 111:	//o (naranja, jugador 2)
			actualizarJugador(Tablero::JUGADOR2, nNARANJA);
			break;
		//START INTERFAZ
		case 83:	//S (startGame)
			startGame = true;
			break;
		//RESET INTERFAZ
		case 70:	//F (Reset)
			initGame();
			break;
		//RESET VICTORIAS
		case 90:	//Z (Resetear vicorias)
			resetVictorias();
			break;
		default:
			button = BUTTON_ERROR;
			break;
		}
	}
	else						//Cuando no recibe nada resetea el BUTTON_ERROR
		button = BUTTON_ERROR;
}
