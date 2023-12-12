#include "aplicacion.h"

bool startGame = false;		//Estado del juego
uint32_t victorias1 = 0;	//Contador de victorias del jugador 1
uint32_t victorias2 = 0;	//Contador de victorias del jugador 2

bool color1Flag = true;		//Bandera para evaluar si se puede modificar el color
bool color2Flag = true;
uint8_t color1Index = 0;	//Índice del color de cada jugador
uint8_t color2Index = 1;

/*
	Lógica del juego. Lectura de pulsadores o botones, posibilidad de victoria
	o empate, cambio de color de los jugadores, reseteo del juego y decuencia de caída de la ficha.
*/
void game4enLinea(void)
{
	static uint8_t estado = ESPERA;
	static Timer t;
	uint8_t dato;

	static uint8_t filaAux = 0;		//Auxiliar para saber en qué fila está la ficha cuando está cayendo

	//Cuando se oprime el reset y está iniciado el juego
	if(g_in0 && startGame)
	{
		initGame();					//Reinica el juego
		uart0->Transmit("F");		//Avisa a la GUI para volver al menú anterior
	}

	//Para el caso del reset desde la GUI o el pulsador (incluye el if anterior)
	if(!startGame)
		estado = ESPERA;

	switch (estado)
	{
	case ESPERA:
		//Se presiona la tecla izquierda y está habilitado el cambio de color de jugador 1
		if(tecla == IZQUIERDA && color1Flag)
		{
			color1Index++;	//Cambio de color

			if(color1Index >= CANT_COLORS) color1Index = 0;			//Evaluar límite
			if(color1Index == color2Index)							//Evaluar coincidencia con jugador 2
			{
				color1Index++;										//En caso de coincidencia, salteo el color
				if(color1Index >= CANT_COLORS) color1Index = 0;		//Vuelve a chequear límite
			}

			tablero.setColor1(colours[color1Index]);
			tablero.ocuparCasillero(0,0,Tablero::JUGADOR1);		//Coloca el color del primer jugador en el primer led de la primer fila
			matriz.show();										//Ejecuta el cambio en la matriz
		}
		else if(tecla == DERECHA && color2Flag)					//Idem anterior para el jugador 2
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
			uart0->Transmit("S");		//Avisa a la GUI para pasar al siguiente menú
		}

		if(startGame == true)	//Se cambia desde la comunicación o desde el if de arriba
		{
			resetVictorias();	//Al iniciar el juego, resetea los contadores y limpia la matriz
			newGame();
			estado = JUGADOR;
		}
		break;
	case JUGADOR:
		//Se presiona el pulsador de la izquierda o se desplaza por la GUI
		if ((tecla == IZQUIERDA) || (button == IZQUIERDA))
		{
			tablero.ocuparCasillero(0, tablero.getColumnaActual(), Tablero::LIBRE);		//Pinta de blanco la celda que libera

			if(!tablero.decrementarColumna(1))					//Se desplaza a la izquierda la columna
				tablero.setColumnaActual(COLUMNAS - 1);			//En el caso límite, va al otro extremo haciéndolo circular

			tablero.ocuparCasillero(0, tablero.getColumnaActual());		//Ocupa la posición correspondiente
			matriz.show();												//Efectúa los cambios en la matriz
		}
		//Se presiona el pulsador de la derecha o se desplaza por la GUI. Idem anterior para el otro lado.
		else if ((tecla == DERECHA) || (button == DERECHA))
		{
			tablero.ocuparCasillero(0, tablero.getColumnaActual(), Tablero::LIBRE);

			if(!tablero.incrementarColumna(1))
				tablero.setColumnaActual(0);

			tablero.ocuparCasillero(0, tablero.getColumnaActual());
			matriz.show();
		}
		else if (tecla == CONFIRMAR || button == CONFIRMAR)			//Si se quiere confirmar la caída de la ficha
		{
			//En caso de empate
			if(tablero.checkFullBoard())
			{
				tablero.llenarTablero(Tablero::LIBRE);		//Llena el tablero con blanco
				tablero.setColumnaActual(0);
				matriz.show();
				t = TIEMPO_VICTORIA;						//Dispara el timer

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

				//Pinta en blanco la posición liberada para la primer fila
				if(filaAux == 0)
					tablero.ocuparCasillero(filaAux, tablero.getColumnaActual(), Tablero::LIBRE);

				filaAux++;															//Baja una fila
				tablero.ocuparCasillero(filaAux, tablero.getColumnaActual());		//Enciende el siguiente casillero
				t = TIEMPO_CAIDA;													//Reinicia el timer
			}
			else	//Cuando alcanza la última fila
			{
				filaAux = 0;					//Resetea la variable auxiliar y la columna
				tablero.setColumnaActual(0);

				if (tablero.checkWinner())
				{
					tablero.llenarTablero();

					dato = tablero.getPlayer() + 48;	//Suma 48 para enviar el número como caracter ASCII
					uart0->Transmit(&dato,1);	//Envía para incrementar el contador de victorias

					if(tablero.getPlayer())		///Incrementa el contador correspondiente
						victorias1++;
					else
						victorias2++;

					Display->Set(victorias1, DSP1);
					Display->Set(victorias2, DSP0);

					t = TIEMPO_VICTORIA;
					estado = VICTORIA;
				}
				else		//Si no hay ganador
				{
					tablero.changePlayer();
					tablero.ocuparCasillero(0, tablero.getColumnaActual());	//Posiciona la ficha nueva en el inicio
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
			newGame();					//Inicia una nueva partida
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

//Inicia las variables del juego
void initGame(void)
{
	startGame = false;
	color1Flag = true;
	color2Flag = true;
	resetVictorias();
	tablero.iniciarTablero();
	matriz.show();
}

//Prepara para una nueva partida
void newGame(void)
{
	tablero.limpiarTablero();
	tablero.setColumnaActual(0);
	tablero.ocuparFila(0, 2);									//Llena toda la primer fila en blanco
	tablero.ocuparCasillero(0, tablero.getColumnaActual());
	matriz.show();
}

//Resetea los contadores y actualiza los dislplay
void resetVictorias(void)
{
	victorias1 = 0;
	victorias2 = 0;

	Display->Set(0, DSP0);
	Display->Set(0, DSP1);
}

/*	Actualiza el color del jugador cuando se lo manda desde la GUI,
	inhabilitando el cambio de ese jugador posteriormente.
	Recibe el jugador a cambiar y el índice del color 	*/
void actualizarJugador(uint8_t player, uint8_t ncolor)
{
	if(player == Tablero::JUGADOR1)
	{
		color1Flag = false;										//Bloquea el cambio de color
		color1Index = ncolor;									//Setea el nuevo color

		if(color1Index == color2Index)							//En caso de coincidencia con el jugador 2
		{
			color2Index++;										//Cambia el color del jugador 2
			if(color2Index == 8) color2Index = 0;				//Valida el límite
			tablero.setColor2(colours[color2Index]);
			tablero.ocuparCasillero(0,7,Tablero::JUGADOR2);		//Coloca el color del segundo jugador en el último led de la primer fila
		}

		tablero.setColor1(colours[ncolor]);
		tablero.ocuparCasillero(0,0,player);		//Coloca el color del primer jugador en el primer led de la primer fila
	}
	else if(player == Tablero::JUGADOR2)			//Idem anterior para el jugador 2
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
