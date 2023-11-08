/*
===============================================================================
 Name        : main.c
 Author      : 
 Description : Primer programa de prueba del TPO para el juego 4 en línea.
 Comunicación serie con un Arduino UNO para el manejo de la matriz led y uso
 del teclado para movimiento de los jugadores.
===============================================================================
*/
#include "inicializarInfotronic.h"

#define PULSADOR_IZQUIERDA (Teclado->GetKey( ) == 3)
#define PULSADOR_DERECHA (Teclado->GetKey( ) == 5)
#define PULSADOR_CONFIRMAR (Teclado->GetKey( ) == 4)
#define TIEMPO_VICTORIA 50 //Tiempo en décimas de segundo

#define FILAS 8
#define COLUMNAS 8
#define LIBRE 10

enum {JUGADOR1, JUGADOR2, JUGADOR, VICTORIA};

//Prototipos de funciones:
void limpiarTablero(void);
void limpiarMatriz(void);
void llenarMatriz(void);
void liberarCasillero(int fila, int columna);
void ocuparCasillero(int fila, int columna, int jugador);
bool checkWinner(void);

uint8_t estado = JUGADOR;

uint8_t tablero[FILAS][COLUMNAS];
uint8_t columna_actual = 0;

uint8_t jugador_actual = JUGADOR1;

uint8_t tecla;

Timer t;


int  main(void)
{
	InicializarInfotronic();
	
	limpiarTablero();	//Inicializa las posiciones de la matriz en LIBRE
	limpiarMatriz();

	ocuparCasillero(0, columna_actual, jugador_actual);

	while ( 1 ){

		tecla = Teclado->GetKey( );

		switch (estado)
		{
		case JUGADOR:
			//Se presiona el pulsador de la izquierda y no está en la primer columna y la izquierda está libre
			if ((tecla ==5) && (columna_actual != 0) && (tablero[0][columna_actual-1] == LIBRE))
			{
				liberarCasillero(0, columna_actual);
				columna_actual--;
				ocuparCasillero(0, columna_actual, jugador_actual);
			}
			//Se presiona el pulsador de la derecha y no está en la última columna y la derecha está libre
			else if ((tecla ==3) && (columna_actual != COLUMNAS-1) && (tablero[0][columna_actual+1] == LIBRE))
			{
				liberarCasillero(0, columna_actual);
				columna_actual++;
				ocuparCasillero(0, columna_actual, jugador_actual);
			}
			else if (PULSADOR_CONFIRMAR)
			{
				//Validar hasta donde baja utilizando la columna (de abajo hacia arriba)
				for (int fila = FILAS - 1; fila >= 0; fila--)
				{
					if(tablero[fila][columna_actual] == LIBRE)
					{
						liberarCasillero(0, columna_actual);
						ocuparCasillero(fila, columna_actual, jugador_actual);
						columna_actual = 0;
						break;
					}
				}

				if (checkWinner())
				{
					estado = VICTORIA;
					llenarMatriz();
					t = TIEMPO_VICTORIA;
				}
				else{
					//!jugador_actual;    //Cambio de turno
					jugador_actual == JUGADOR1 ? jugador_actual = JUGADOR2 : jugador_actual = JUGADOR1;
					ocuparCasillero(0, columna_actual, jugador_actual);
				}

			}
			break;
		case VICTORIA:
			if(t)
			{
				limpiarTablero();
				limpiarMatriz();
				estado = JUGADOR;
			}
			break;
		default:
			limpiarTablero();
			limpiarMatriz();

			estado = JUGADOR;
			break;
		}
	}
	return  0;
}


void limpiarTablero(void)
{
    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLUMNAS; j++)
        {
            tablero[i][j] = LIBRE;
        }
    }
}

void limpiarMatriz(void)
{
	uint8_t dato = 122;		//z en ASCII
	uart1->Transmit(&dato,1);
}

void llenarMatriz(void)
{
	uint8_t dato = 121;		//y en ASCII
	uart1->Transmit(&dato,1);
}

void liberarCasillero(int fila, int columna)
{
	uint8_t dato;

    tablero[fila][columna] = LIBRE;

    dato = columna + fila * FILAS;
    uart1->Transmit(&dato,1);
    dato = 200; 		//Envía valor cualquiera que apaga el led
    uart1->Transmit(&dato,1);
}

void ocuparCasillero(int fila, int columna, int jugador)
{
	uint8_t dato;

    tablero[fila][columna] = jugador;

    dato = columna + fila * FILAS;
	uart1->Transmit(&dato,1);
	dato = jugador;
	uart1->Transmit(&dato,1);
}

bool checkWinner(void)
{
    // Verifica horizontal
    for (int fila = 0; fila < FILAS; fila++) {
        for (int columna = 0; columna <= COLUMNAS - 4; columna++) {
            if (tablero[fila][columna] == jugador_actual &&
                tablero[fila][columna + 1] == jugador_actual &&
                tablero[fila][columna + 2] == jugador_actual &&
                tablero[fila][columna + 3] == jugador_actual) {
                return true;
            }
        }
    }

    // Verifica vertical
    for (int columna = 0; columna < COLUMNAS; columna++) {
        for (int fila = 0; fila <= FILAS - 4; fila++) {
            if (tablero[fila][columna] == jugador_actual &&
                tablero[fila + 1][columna] == jugador_actual &&
                tablero[fila + 2][columna] == jugador_actual &&
                tablero[fila + 3][columna] == jugador_actual) {
                return true;
            }
        }
    }

    // Verifica diagonal descendente (de izquierda a derecha)
    for (int fila = 3; fila < FILAS; fila++) {
        for (int columna = 0; columna <= COLUMNAS - 4; columna++) {
            if (tablero[fila][columna] == jugador_actual &&
                tablero[fila - 1][columna + 1] == jugador_actual &&
                tablero[fila - 2][columna + 2] == jugador_actual &&
                tablero[fila - 3][columna + 3] == jugador_actual) {
                return true;
            }
        }
    }

    // Verifica diagonal ascendente (de izquierda a derecha)
    for (int fila = 0; fila <= FILAS - 4; fila++) {
        for (int columna = 0; columna <= COLUMNAS - 4; columna++) {
            if (tablero[fila][columna] == jugador_actual &&
                tablero[fila + 1][columna + 1] == jugador_actual &&
                tablero[fila + 2][columna + 2] == jugador_actual &&
                tablero[fila + 3][columna + 3] == jugador_actual) {
                return true;
            }
        }
    }

    return false;
}

