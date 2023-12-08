#include "aplicacion.h"

bool startGame = false;

void game4enLinea(void)
{
	static uint8_t estado = ESPERA;
	static Timer t;
	uint8_t dato;

	static uint8_t filaAux = 0;

	//Para el caso del reset
	if(!startGame)
		estado = ESPERA;

	switch (estado)
	{
	case ESPERA:
		if(tecla == CONFIRMAR)
		{
			startGame = true;
			uart0->Transmit("S");
		}
		if(startGame == true)	//Se cambia desde la comunicación o desde el if de arriba
		{
			resetGame();
			estado = JUGADOR;
		}
		break;
	case JUGADOR:
		//Se presiona el pulsador de la izquierda y no está en la primer columna y la izquierda está libre
		if ((tecla == IZQUIERDA) || (button == IZQUIERDA))
		{
			tablero.ocuparCasillero(0, tablero.getColumnaActual(), 2);		//Pinta de blanco la celda que libera

			if(!tablero.decrementarColumna(1))
				tablero.setColumnaActual(COLUMNAS - 1);

			tablero.ocuparCasillero(0, tablero.getColumnaActual());
			matriz.show();
		}
		//Se presiona el pulsador de la derecha y no está en la última columna y la derecha está libre
		else if ((tecla == DERECHA) || (button == DERECHA))
		{
			tablero.ocuparCasillero(0, tablero.getColumnaActual(), 2);		//Pinta de blanco la celda que libera

			if(!tablero.incrementarColumna(1))
				tablero.setColumnaActual(0);

			tablero.ocuparCasillero(0, tablero.getColumnaActual());
			matriz.show();
		}
		else if (tecla == CONFIRMAR || button == CONFIRMAR)
		{
			//En caso de empate
			if(tablero.checkFullBoard())
			{
				tablero.llenarTablero(2);		//Llena el tablero con blanco
				tablero.setColumnaActual(0);
				matriz.show();
				t = TIEMPO_VICTORIA;

				estado = VICTORIA;
			}
			//Chequea que no se llene la fila superior
			else if(tablero.lastRowFree(tablero.getColumnaActual()) > 0)
			{
				t = TIEMPO_CAIDA;
				estado = CAIDA_FICHA;
			}
		}
		break;
	case CAIDA_FICHA:
		//Cada vez que vence el timer
		if(t)
		{
			//Mientras no haya alcanzado la última fila
			if(filaAux < tablero.lastRowFree(tablero.getColumnaActual()))
			{
				tablero.liberarCasillero(filaAux, tablero.getColumnaActual());		//Libera el casillero ocupado actual

				//Pinta en blanco la celda que libera
				if(filaAux == 0)
					tablero.ocuparCasillero(filaAux, tablero.getColumnaActual(), 2);

				filaAux++;															//Baja una fila
				tablero.ocuparCasillero(filaAux, tablero.getColumnaActual());		//Enciende el siguiente casillero
				t = TIEMPO_CAIDA;
			}
			else
			{
				filaAux = 0;
				tablero.setColumnaActual(0);

				if (tablero.checkWinner())
				{
					tablero.llenarTablero();
					dato = tablero.getPlayer() + 48;	//Suma 48 para enviar el número como caracter ASCII
					uart0->Transmit(&dato,1);	//Envía para incrementar el contador de victorias

					t = TIEMPO_VICTORIA;
					estado = VICTORIA;
				}
				else
				{
					tablero.changePlayer();
					tablero.ocuparCasillero(0, tablero.getColumnaActual());
					estado = JUGADOR;
				}
			}
			matriz.show();
		}
		break;
	case VICTORIA:
		if(t)
		{
			tablero.changePlayer();
			resetGame();
			estado = JUGADOR;
		}
		break;
	default:
		resetGame();
		estado = JUGADOR;
		break;
	}
}

void resetGame(void)
{
	tablero.limpiarTablero();
	tablero.setColumnaActual(0);
	tablero.ocuparFila(0, 2);									//Llena toda la primer fila en blanco
	tablero.ocuparCasillero(0, tablero.getColumnaActual());
	matriz.show();
}
