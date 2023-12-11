#include "aplicacion.h"

bool startGame = false;
uint32_t victorias1 = 0;
uint32_t victorias2 = 0;

bool color1Flag = true;
bool color2Flag = true;
uint8_t color1Index = 0;
uint8_t color2Index = 1;

void game4enLinea(void)
{
	static uint8_t estado = ESPERA;
	static Timer t;
	uint8_t dato;

	static uint8_t filaAux = 0;

	//Cuando se oprime el reset y está iniciado el juego
	if(g_in0 && startGame)
	{
		initGame();
		uart0->Transmit("F");
	}

	//Para el caso del reset (incluye el if anterior)
	if(!startGame)
		estado = ESPERA;

	switch (estado)
	{
	case ESPERA:

		if(tecla == IZQUIERDA && color1Flag)
		{
			color1Index++;

			if(color1Index >= CANT_COLORS) color1Index = 0;
			if(color1Index == color2Index)
			{
				color1Index++;
				if(color1Index >= CANT_COLORS) color1Index = 0;
			}

			tablero.setColor1(colours[color1Index]);
			tablero.ocuparCasillero(0,0,Tablero::JUGADOR1);		//Coloca el color del primer jugador en el primer led de la primer fila
			matriz.show();
		}
		else if(tecla == DERECHA && color2Flag)
		{
			color2Index++;

			if(color2Index >= CANT_COLORS) color2Index = 0;
			if(color1Index == color2Index)
			{
				color2Index++;
				if(color2Index >= CANT_COLORS) color2Index = 0;
			}

			tablero.setColor2(colours[color2Index]);
			tablero.ocuparCasillero(0,7,Tablero::JUGADOR2);		//Coloca el color del segundo jugador en el último led de la primer fila
			matriz.show();
		}
		else if(tecla == CONFIRMAR)
		{
			startGame = true;
			uart0->Transmit("S");
		}

		if(startGame == true)	//Se cambia desde la comunicación o desde el if de arriba
		{
			resetVictorias();
			newGame();
			estado = JUGADOR;
		}
		break;
	case JUGADOR:
		//Se presiona el pulsador de la izquierda y no está en la primer columna y la izquierda está libre
		if ((tecla == IZQUIERDA) || (button == IZQUIERDA))
		{
			tablero.ocuparCasillero(0, tablero.getColumnaActual(), Tablero::LIBRE);		//Pinta de blanco la celda que libera

			if(!tablero.decrementarColumna(1))
				tablero.setColumnaActual(COLUMNAS - 1);

			tablero.ocuparCasillero(0, tablero.getColumnaActual());
			matriz.show();
		}
		//Se presiona el pulsador de la derecha y no está en la última columna y la derecha está libre
		else if ((tecla == DERECHA) || (button == DERECHA))
		{
			tablero.ocuparCasillero(0, tablero.getColumnaActual(), Tablero::LIBRE);		//Pinta de blanco la celda que libera

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
				tablero.llenarTablero(Tablero::LIBRE);		//Llena el tablero con blanco
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
					tablero.ocuparCasillero(filaAux, tablero.getColumnaActual(), Tablero::LIBRE);

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

					if(tablero.getPlayer())
						victorias1++;
					else
						victorias2++;

					Display->Set(victorias1, DSP1);
					Display->Set(victorias2, DSP0);

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
			newGame();
			estado = JUGADOR;
		}
		break;
	default:
		resetVictorias();
		newGame();
		estado = JUGADOR;
		break;
	}
}

void initGame(void)
{
	startGame = false;
	color1Flag = true;
	color2Flag = true;
	resetVictorias();
	tablero.iniciarTablero();
	matriz.show();
}

void newGame(void)
{
	tablero.limpiarTablero();
	tablero.setColumnaActual(0);
	tablero.ocuparFila(0, 2);									//Llena toda la primer fila en blanco
	tablero.ocuparCasillero(0, tablero.getColumnaActual());
	matriz.show();
}

void resetVictorias(void)
{
	victorias1 = 0;
	victorias2 = 0;

	Display->Set(0, DSP0);
	Display->Set(0, DSP1);
}

void actualizarJugador(uint8_t player, uint8_t ncolor)
{
	if(player == Tablero::JUGADOR1)
	{
		color1Flag = false;
		color1Index = ncolor;

		if(color1Index == color2Index)
		{
			color2Index++;
			if(color2Index == 8) color2Index = 0;
			tablero.setColor2(colours[color2Index]);
			tablero.ocuparCasillero(0,7,Tablero::JUGADOR2);		//Coloca el color del segundo jugador en el último led de la primer fila
		}

		tablero.setColor1(colours[ncolor]);
		tablero.ocuparCasillero(0,0,player);		//Coloca el color del primer jugador en el primer led de la primer fila

	}
	else if(player == Tablero::JUGADOR2)
	{
		color2Flag = false;
		color2Index = ncolor;

		if(color1Index == color2Index)
		{
			color1Index++;
			if(color1Index == 8) color1Index = 0;
			tablero.setColor1(colours[color1Index]);
			tablero.ocuparCasillero(0,0,Tablero::JUGADOR1);		//Coloca el color del segundo jugador en el último led de la primer fila
		}

		tablero.setColor2(colours[ncolor]);
		tablero.ocuparCasillero(0,7,player);		//Coloca el color del segundo jugador en el último led de la primer fila
	}
	matriz.show();
}
