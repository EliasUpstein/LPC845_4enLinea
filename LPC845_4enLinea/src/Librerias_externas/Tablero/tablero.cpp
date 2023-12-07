#include "tablero.h"

Tablero::Tablero(uint8_t filas, uint8_t columnas, MatrizLed& matriz)
: m_matriz(matriz)
{
	m_filas = filas;
	m_columnas = columnas;
	m_jugadorActual = JUGADOR1;
	m_columnaActual = 0;
	color[JUGADOR1] = matriz.color(0,0, 100);
	color[JUGADOR2] = matriz.color(100,0, 0);

	// Declarar la matriz utilizando new
	m_tablero = new uint8_t*[filas];  // Crear un array de punteros a int (filas)
	// Para cada fila, crear un array de int (columnas)
	for (int i = 0; i < filas; ++i)
		m_tablero[i] = new uint8_t[columnas];
}

void Tablero::limpiarTablero(void)
{
    for (int i = 0; i < m_filas; i++)
    {
        for (int j = 0; j < m_columnas; j++)
        {
        	m_tablero[i][j] = LIBRE;
        }
    }

    m_matriz.clear();
}

void Tablero::llenarTablero(void)
{
	for (int i = 0; i < m_filas; i++)
	{
		for (int j = 0; j < m_columnas; j++)
		{
			m_tablero[i][j] = m_jugadorActual;
		}
	}

	m_matriz.setAllLeds(color[m_jugadorActual]);
}

void Tablero::liberarCasillero(uint8_t fila, uint8_t columna)
{
	m_tablero[fila][columna] = LIBRE;
	m_matriz.clearLed(columna + fila * m_filas);
}

void Tablero::ocuparCasillero(uint8_t fila, uint8_t columna)
{
	m_tablero[fila][columna] = m_jugadorActual;
	m_matriz.setLed(columna + fila * m_filas, color[m_jugadorActual]);
}

void Tablero::tirarFicha(uint8_t columna)
{
	//Validar hasta donde baja utilizando la columna (de abajo hacia arriba)
	for (int fila = m_filas - 1; fila >= 0; fila--)
	{
		if(m_tablero[fila][columna] == LIBRE)
		{
			liberarCasillero(0, columna);
			ocuparCasillero(fila, columna);
			break;
		}
	}
}

Led_WS2812B Tablero::getColor1(void)
{
	return color[0];
}

void Tablero::setColor1(uint8_t r, uint8_t g, uint8_t b)
{
	color[0] = m_matriz.color(r,g,b);
}

Led_WS2812B Tablero::getColor2(void)
{
	return color[1];
}

void Tablero::setColor2(uint8_t r, uint8_t g, uint8_t b)
{
	color[1] = m_matriz.color(r,g,b);
}

void Tablero::setPlayer(uint8_t player)
{
	m_jugadorActual = player;
}

uint8_t Tablero::getPlayer(void)
{
	return m_jugadorActual;
}

void Tablero::changePlayer(void)
{
	m_jugadorActual = (m_jugadorActual == JUGADOR1 ? JUGADOR2 : JUGADOR1);
}

void Tablero::setColumnaActual(uint8_t column)
{
	m_columnaActual = column;
}

uint8_t Tablero::getColumnaActual(void)
{
	return m_columnaActual;
}

void Tablero::incrementarColumna(uint8_t increment)
{
	m_columnaActual += increment;
}

void Tablero::decrementarColumna(uint8_t decrement)
{
	m_columnaActual -= decrement;
}

bool Tablero::checkWinner(void)
{
    // Verifica horizontal
    for (int fila = 0; fila < m_filas; fila++) {
        for (int columna = 0; columna <= m_columnas - 4; columna++) {
            if (m_tablero[fila][columna] == m_jugadorActual &&
                m_tablero[fila][columna + 1] == m_jugadorActual &&
                m_tablero[fila][columna + 2] == m_jugadorActual &&
                m_tablero[fila][columna + 3] == m_jugadorActual) {
                return true;
            }
        }
    }

    // Verifica vertical
    for (int columna = 0; columna < m_columnas; columna++) {
        for (int fila = 0; fila <= m_filas - 4; fila++) {
            if (m_tablero[fila][columna] == m_jugadorActual &&
                m_tablero[fila + 1][columna] == m_jugadorActual &&
                m_tablero[fila + 2][columna] == m_jugadorActual &&
                m_tablero[fila + 3][columna] == m_jugadorActual) {
                return true;
            }
        }
    }

    // Verifica diagonal descendente (de izquierda a derecha)
    for (int fila = 3; fila < m_filas; fila++) {
        for (int columna = 0; columna <= m_columnas - 4; columna++) {
            if (m_tablero[fila][columna] == m_jugadorActual &&
                m_tablero[fila - 1][columna + 1] == m_jugadorActual &&
                m_tablero[fila - 2][columna + 2] == m_jugadorActual &&
                m_tablero[fila - 3][columna + 3] == m_jugadorActual) {
                return true;
            }
        }
    }

    // Verifica diagonal ascendente (de izquierda a derecha)
    for (int fila = 0; fila <= m_filas - 4; fila++) {
        for (int columna = 0; columna <= m_columnas - 4; columna++) {
            if (m_tablero[fila][columna] == m_jugadorActual &&
                m_tablero[fila + 1][columna + 1] == m_jugadorActual &&
                m_tablero[fila + 2][columna + 2] == m_jugadorActual &&
                m_tablero[fila + 3][columna + 3] == m_jugadorActual) {
                return true;
            }
        }
    }

    return false;
}

Tablero::~Tablero(){
	for (int i = 0; i < m_filas; ++i)
		delete[] m_tablero[i];

	delete[] m_tablero;
}
