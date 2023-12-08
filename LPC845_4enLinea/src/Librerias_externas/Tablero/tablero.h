#ifndef TABLERO_H_
#define TABLERO_H_

#include "tipos.h"
#include "matriz.h"

class Tablero
{
private:
	uint8_t** m_tablero;
	uint8_t m_filas, m_columnas;
	MatrizLed& m_matriz;
	Led_WS2812B color[2];

	uint8_t m_jugadorActual;
	uint8_t m_columnaActual;

	enum player{JUGADOR1, JUGADOR2, LIBRE};
public:
	Tablero(uint8_t filas, uint8_t columnas, MatrizLed& matriz);
	void limpiarTablero(void);
	void llenarTablero(void);
	void liberarCasillero(uint8_t fila, uint8_t columna);
	void ocuparCasillero(uint8_t fila, uint8_t columna);
	void tirarFicha(uint8_t columna);
	bool checkWinner(void);

	Led_WS2812B getColor1(void);
	void setColor1(uint8_t r, uint8_t g, uint8_t b);
	Led_WS2812B getColor2(void);
	void setColor2(uint8_t r, uint8_t g, uint8_t b);

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
