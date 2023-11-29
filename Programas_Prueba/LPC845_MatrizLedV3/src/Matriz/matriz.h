#ifndef MATRIZ_LED
#define MATRIZ_LED

#include "inicializarInfotronic.h"

#include "Led_WS2812B.h"

extern gpio out_matriz;

extern uint32_t nleds;
extern uint32_t nBytes;
//extern uint32_t m_nBits;

extern Led_WS2812B *matriz;

//Prototipo de funciones
void MatrizLed(int leds);
//bool begin(void);
void setLed(int led, Led_WS2812B color);
void setLeds(int first, int cant, Led_WS2812B color);
void setAllLeds(Led_WS2812B color);
void clear(void);
Led_WS2812B Color(uint8_t r, uint8_t g, uint8_t b);
void show(void);


#define NIVEL_ALTO 1
#define NIVEL_BAJO 0
//#define FINALIZAR_CTIMER 2

//Mínima temporización alcanzada
#define TIEMPO_LARGO 60000000
#define TIEMPO_CORTO 15000000

#define MARGEN_TICKS_MENOR 5
#define MARGEN_TICKS_MAYOR 10
#define MARGEN_TICKS 3

#endif
