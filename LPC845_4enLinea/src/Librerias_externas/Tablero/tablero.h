#ifndef TABLERO_H_
#define TABLERO_H_

#include "tipos.h"
#include "matriz.h"
#include "colors.h"

//Abstracción de un tablero de juego
class Tablero
{
private:
	uint8_t** m_tablero;			//Matriz de datos del tablero
	uint8_t m_filas, m_columnas;
	MatrizLed& m_matriz;			//Referencia a la matriz de leds que visualiza al tablero
	Led_WS2812B color[3];

	uint8_t m_jugadorActual;
	uint8_t m_columnaActual;

public:
	enum player{JUGADOR1, JUGADOR2, LIBRE};

	Tablero(uint8_t filas, uint8_t columnas, MatrizLed& matriz);

	void iniciarTablero(void);

	void limpiarTablero(void);
	void llenarTablero(void);
	void llenarTablero(uint8_t player);
	void liberarCasillero(uint8_t fila, uint8_t columna);
	void ocuparCasillero(uint8_t fila, uint8_t columna);
	void ocuparCasillero(uint8_t fila, uint8_t columna, uint8_t player);
	void ocuparFila(uint8_t fila, uint8_t player);
	void tirarFicha(uint8_t columna);
	bool checkWinner(void);
	bool checkFullBoard(void);
	bool checkFullRow(uint8_t fila);
	bool checkFullColumn(uint8_t columna);

	Led_WS2812B getColor1(void);
	void setColor1(uint8_t r, uint8_t g, uint8_t b);
	void setColor1(Led_WS2812B colour);
	Led_WS2812B getColor2(void);
	void setColor2(uint8_t r, uint8_t g, uint8_t b);
	void setColor2(Led_WS2812B colour);

	Led_WS2812B getColor(uint8_t player);
	void setColor(uint8_t player, uint8_t r, uint8_t g, uint8_t b);
	void setColor(uint8_t player, Led_WS2812B colour);

	void setPlayer(uint8_t player);
	uint8_t getPlayer(void);
	void changePlayer(void);

	void setColumnaActual(uint8_t column);
	uint8_t getColumnaActual(void);
	bool incrementarColumna(uint8_t increment);
	bool decrementarColumna(uint8_t decrement);

	uint8_t lastRowFree(uint8_t column);

	~Tablero();
};

#endif
