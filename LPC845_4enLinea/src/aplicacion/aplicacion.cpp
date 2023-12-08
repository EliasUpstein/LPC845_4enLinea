#include "aplicacion.h"

bool startGame = false;

void game4enLinea(void)
{
	static uint8_t estado = ESPERA;
	static Timer t;
	uint8_t dato;

	switch (estado)
	{
	case ESPERA:
//		if(tecla == CONFIRMAR)
//		{
//			startGame = true;
//			dato = 255;
//			uart0->Transmit(&dato,1);
//		}
		if(startGame == true)
		{
			estado = JUGADOR;
			tablero.limpiarTablero();
			tablero.setColumnaActual(0);

			tablero.ocuparCasillero(0, tablero.getColumnaActual());
			matriz.show();
		}
		break;
	case JUGADOR:
		//Se presiona el pulsador de la izquierda y no está en la primer columna y la izquierda está libre
		if (((tecla == IZQUIERDA) || (button == IZQUIERDA)) && (tablero.getColumnaActual() != 0))
		{
			tablero.liberarCasillero(0, tablero.getColumnaActual());
			tablero.decrementarColumna(1);
			tablero.ocuparCasillero(0, tablero.getColumnaActual());
			matriz.show();
		}
		//Se presiona el pulsador de la derecha y no está en la última columna y la derecha está libre
		else if (((tecla == DERECHA) || (button == DERECHA)) && (tablero.getColumnaActual() != COLUMNAS-1))
		{
			tablero.liberarCasillero(0, tablero.getColumnaActual());
			tablero.incrementarColumna(1);
			tablero.ocuparCasillero(0, tablero.getColumnaActual());
			matriz.show();
		}
		else if (tecla == CONFIRMAR || button == CONFIRMAR)
		{
			tablero.tirarFicha(tablero.getColumnaActual());
			tablero.setColumnaActual(0);

			if (tablero.checkWinner())
			{
				estado = VICTORIA;
				tablero.llenarTablero();
				t = TIEMPO_VICTORIA;

				dato = tablero.getPlayer() + 48;
				uart0->Transmit(&dato,1);	//Envía para incrementar el contador de victorias
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
