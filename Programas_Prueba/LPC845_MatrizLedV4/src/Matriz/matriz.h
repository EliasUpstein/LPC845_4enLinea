#ifndef MATRIZ_LED
#define MATRIZ_LED

#include "Led_WS2812B.h"
#include "gpio.h"
#include "uart.h"

#define NIVEL_ALTO 1
#define NIVEL_BAJO 0

//Mínima temporización alcanzada (24 - 15)
#define TIEMPO_LARGO 60000000
#define TIEMPO_CORTO 15000000

#define MARGEN_TICKS_MENOR 5
#define MARGEN_TICKS_MAYOR 10

class MatrizLed
{
private:
	gpio* out_matriz;
	uart* m_uart;
	uint8_t m_nleds;
	Led_WS2812B *matriz;

	void showCTIMER(void);
	void showUART(void);

public:
	MatrizLed (uint8_t puerto, uint8_t bit, uint8_t nleds = 1);			//Constructor para comunicación propia
	MatrizLed (uart* uart, uint8_t nleds = 1);							//Constructor para comunicación serie
	Led_WS2812B color(uint8_t r, uint8_t g, uint8_t b);
	void setLed(uint8_t led, Led_WS2812B color);
	void setLed(uint8_t led, uint8_t r, uint8_t g, uint8_t b);
	void setLeds(uint8_t first, uint8_t cant, Led_WS2812B color);
	void setLeds(uint8_t first, uint8_t cant, uint8_t r, uint8_t g, uint8_t b);
	void setAllLeds(Led_WS2812B color);
	void setAllLeds(uint8_t r, uint8_t g, uint8_t b);
	void clear(void);
	void show(void);

	int getLeds(void) const {return m_nleds;}

	~MatrizLed();
};

#endif
