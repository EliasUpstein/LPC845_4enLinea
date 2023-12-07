#ifndef MATRIZ_LED
#define MATRIZ_LED

#include "Led_WS2812B.h"
#include "gpio.h"
#include "uart.h"

#define PORT 0
#define PIN 29

#define DELAY_ASM __asm volatile("nop;" "nop;" "nop;" "nop;" "nop;" "nop;" "nop;" "nop;" "nop;" "nop;" "nop;" "nop;" "nop;" "nop;" "nop;" "nop;" "nop;" "nop;");

class MatrizLed
{
private:
	gpio* out_matriz;
	uart* m_uart;
	uint8_t m_nleds;
	Led_WS2812B *matriz;

	void showGPIO(void);
	void showUART(void);
//	void send24Bits(uint32_t data, uint8_t port, uint8_t pin);
	void send24Bits(uint32_t data);

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
	void clearLed(uint8_t led);
	void show(void);

	int getLeds(void) const {return m_nleds;}

	~MatrizLed();
};

#endif
