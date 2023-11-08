#include "MatrizLed.h"

MatrizLed::MatrizLed(uint8_t puerto, uint8_t bit, int nleds = 1)
    : gpio(puerto, bit, gpio::pushpull, gpio::high, gpio::output)
{
    m_nleds = nleds;
    m_nBytes = nleds * 3;
    // m_nBits = m_nBytes * 8;
    matriz = new (Led_WS2812B[nleds]);
}

/*Si no hubo errores en la inicialización del pin, se pone en bajo la salida*/
bool MatrizLed::begin()
{
    if (m_error == ok)
        return ClrPin();
    else
        return m_error;
}

void MatrizLed::setLed(int led, Led_WS2812B color)
{
    if (led < m_nleds && led >= 0)
        matriz[led] = color;
}

void MatrizLed::setLeds(int first, int cant, Led_WS2812B color)
{
    uint16_t end;

    if (first >= m_nleds || first < 0)
        return; 

    // Si se recibe 0, rellena hasta el final, sino chequea no excederse
    if (cant == 0)
        end = m_nleds;
    else
    {
        end = first + cant;
        if (end > m_nleds)
            end = m_nleds;
    }

    for (int i = first; i < end; i++)
    {
        setLed(i, color);
    }
}

//Para llenar toda la matriz, se llama al método setLeds reutilizando código
void MatrizLed::setAllLeds(Led_WS2812B color)
{
    setLeds(0, 0, color);
}

void MatrizLed::clear()
{
    //Limpia componente a componente de cada color de cada led
    for (int i = 0; i < m_nleds; i++)
    {
        matriz[i].r = 0;
        matriz[i].g = 0;
        matriz[i].b = 0;
    }
}

void MatrizLed::show()
{
    if (!matriz)
        return;

    //Detener las interrupciones ajenas a la matriz (implementar funcion que reciba booleano)

    
    //Configurar valor para el primer bit e inicializar variables
    //Activar salida
    //Habilitar interrupción del CTIMER (implementar funcion que reciba valor)

    //Las interrupciones se reactivan en la rutina de interrupcion cuando ingresa por ultima vez

    /*
    Detener las interrupciones ajenas a la matriz
    Recorrer bit a bit todo el vector
    para cada bit, enviar la señal correspondiente
    
    Como la señal de cada bit siempre empieza en alto, siempre se debe
    invertir la salida al finalizar cada tiempo.

    Para el ultimo led, mantener la salida en bajo.

    Una vez recorrido el vector, reactivar las interrupciones
    
    Tiempo de comunicación promedio:

    1,25us (por bit) * 8 (por byte) * 3 (por led) = 30us por led
    30us * 64 (leds de nuestra matriz) = 1920us = 1.92 ms => aprox 2ms

    */

//    Bit_WS2812B bits;

//    for (int i = 0; i < m_nleds; i++)
//    {
//         //Referencia led?

//         bits.led = matriz[i];

//         for (int j = 0; j < 3; j++)
//         {
//             (bits.color[j].b0) == 0 ? setBitLow() : setBitHigh();
//             (bits.color[j].b1) == 0 ? setBitLow() : setBitHigh();

//         }
        
//    }
   
   //preder pin
   //cambiar valor del match
    //apagar pin
    //cambiar valor del match
    //

    //led actual (i)
    //color_led acutal (j)
    //bit actual
}