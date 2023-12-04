#include "matriz.h"

//Configuración del pin de salida
gpio out_matriz( gpio::port0 , 29 , gpio::pushpull ,  gpio::high , gpio::output );

// Varibles (atributos del objeto)
uint32_t nleds;
//uint32_t nBytes;
//uint32_t m_nBits;

Led_WS2812B *matriz;        //Se trabaja como vector recorriendo a lo largo, NO como matriz fila-columna



//Implementación de funciones

//bool begin(void){
//	if (m_error == ok)
//	    return ClrPin();
//	else
//		return m_error;
//}

//Previo a constructor de objeto
void MatrizLed(int leds)
{
	nleds = leds;
	matriz = new Led_WS2812B[nleds];
	out_matriz.ClrPin();
}

void setLed(uint32_t led, Led_WS2812B color)
{
	if (led < nleds && led >= 0)
	        matriz[led] = color;
}

void setLeds(uint32_t first, uint32_t cant, Led_WS2812B color)
{
	uint16_t end;

	if (first >= nleds || first < 0)
		return;

	// Si se recibe 0, rellena hasta el final, sino chequea no excederse
	if (cant == 0)
		end = nleds;
	else
	{
		end = first + cant;
		if (end > nleds)
			end = nleds;
	}

	for (uint32_t i = first; i < end; i++)
	{
		setLed(i, color);
	}
}

void setAllLeds(Led_WS2812B color)
{
	setLeds(0, 0, color);
}

void clear(void)
{
	//Limpia componente a componente de cada color de cada led
	for (uint32_t i = 0; i < nleds; i++)
	{
		matriz[i].r = 0;
		matriz[i].g = 0;
		matriz[i].b = 0;
	}
	//Evaluar usar setAllLeds con color nulo
}

Led_WS2812B Color(uint8_t r, uint8_t g, uint8_t b)
{
	Led_WS2812B led_aux;

	led_aux.r = r;
	led_aux.g = g;
	led_aux.b = b;

	return led_aux;
}

//////////////////////////Complicado

/* Tiempo de comunicación promedio:

1,25us (por bit) * 8 (por byte) * 3 (por led) = 30us por led
30us * 64 (leds de nuestra matriz) = 1920us = 1.92 ms => aprox 2ms	*/

/*
	Se inicializa el ciclo desde el método show del objeto MatrizLed
	La primera interrupción siempre ingresa a NIVEL_ALTO ya que los datos siempre inician en alto
	Evalua el valor del bit actual para setear el timer, el toggle del pin se configura desde el registro
	Se aumenta el bit, color, y/o led según corresponda y se cambia de estado para la siguiente interrución
	En NIVEL_BAJO, ya está incrementado el bit por lo que ya se está leyendo el siguiente dato
	El encendido de la salida se realiza desde el toggle del registro. La siguiente interrupción la hará en NIVEL_AlTO

	Cuando no tenga más leds en la matriz para recorrer, finaliza la interrupción del ctimer, inicializa la interrupciones
	que estaban habilitadas antes del show, se asegura de apagar la salida.
*/

/*
 * Implementación de la función por pooling
 * Uso de doble for, simplifica el codigo

 * Siempre que el tiempo sea corto, el tiempo se consume por la propia ejecución del micro
 * */
void show(void)
{
	volatile uint32_t interrupt_state;

	//Detener las interrupciones ajenas a la matriz (se reactivan al final de la rutina)
	interrupt_state = NVIC->ISER[0];			//Guarda en una variable el estado que tenía al momento del llamado
	NVIC->ICER[0] = 0xFFFFFFFF;					//Apaga todas las interrupciones
	SysTick->CTRL &=  ~(0x1UL << 1);			//Detiene interrupción del systick

	//Bucle para leds
	for(uint8_t nled=0; nled<nleds; nled++)
	{
		//Bucle para bit
		for(uint8_t nbit=0; nbit<24; nbit++)
		{
			//Si el bit es 1 => T1H = 800ns + T1L = 450ns
			if(matriz[nled] & (0x1 << (23 - nbit)))
			{
				GPIO->SET[0] = 1 << 29 ;
				DELAY_ASM
				GPIO->CLR[0] = 1 << 29 ;
			}
			//Si el bit es 0 => TOH = 400ns + TOL = 850ns
			else
			{
				GPIO->SET[0] = 1 << 29 ;
				GPIO->CLR[0] = 1 << 29 ;
				DELAY_ASM
			}
		}
	}
	//Finalizar envío de datos
	GPIO->CLR[0] = 1 << 29 ;					//Apagado de la salida

	NVIC->ISER[0] |= interrupt_state;		//Reactivación de las interrupciones anteriores
	SysTick->CTRL |=  (0x1UL << 1);	    	//Activa interrupción del systick
}
