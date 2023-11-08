#ifndef MATRIZ_LED
#define MATRIZ_LED

#include "Led_WS2812B.h"
#include "../../src/02-gpio/gpio.h"

#define uint8_t char

class MatrizLed: public gpio
{
    private:
        int m_nleds;
        int m_nBytes;
        //int m_nBits;
        Led_WS2812B *matriz;        //Se trabaja como vector reacorriendo a lo largo, no como matriz fila-columna

        void setBitHigh();
        void setBitLow();

    public:
        //Constructor
        MatrizLed (uint8_t puerto, uint8_t bit, int nleds = 1);

        //Destructor
        ~MatrizLed() {delete(matriz);}

        bool begin();
        void setLed(int led, Led_WS2812B color){};
        void setLeds(int first, int cant, Led_WS2812B color);
        void setAllLeds(Led_WS2812B color){};
        void clear(){};

        //Se encarga explícitamente de comunicarse con la matriz
        //Se utiliza sólo cuando es necesario escribirla
        void show();

        int getLeds(void) const {return m_nleds;}

    friend void MdE_Ctimer_Matriz(void);        
};

#endif


// bit = (*matriz >> bit_actual) & 1;

// bit = *matriz & (1 << bit_actual);