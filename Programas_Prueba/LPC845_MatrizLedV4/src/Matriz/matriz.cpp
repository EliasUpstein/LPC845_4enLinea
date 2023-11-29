#include "matriz.h"

MatrizLed::MatrizLed(uint8_t puerto, uint8_t bit, uint8_t nleds)
{
	out_matriz = new gpio(puerto, bit, gpio::pushpull, gpio::high, gpio::output);
	m_uart = nullptr;
	m_nleds = nleds;
    matriz = new Led_WS2812B[nleds];
    out_matriz->SetPin();
}

MatrizLed::MatrizLed(uart* uart, uint8_t nleds)
{
	m_uart = uart;
	out_matriz = nullptr;
    m_nleds = nleds;
    matriz = new Led_WS2812B[nleds];
    m_uart->Transmit((void*)'z', 1);
}

Led_WS2812B MatrizLed::color(uint8_t r, uint8_t g, uint8_t b)
{
	Led_WS2812B led_aux;

	led_aux.r = r;
	led_aux.g = g;
	led_aux.b = b;

	return led_aux;
}

void MatrizLed::setLed(uint8_t led, Led_WS2812B color)
{
	if (led < m_nleds && led >= 0)
		matriz[led] = color;
}

void MatrizLed::setLed(uint8_t led, uint8_t r, uint8_t g, uint8_t b)
{
	setLed(led, color(r,g,b));
}

void MatrizLed::setLeds(uint8_t first, uint8_t cant, Led_WS2812B color)
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

	for (uint32_t i = first; i < end; i++)
	{
		setLed(i, color);
	}
}

void MatrizLed::setLeds(uint8_t first, uint8_t cant, uint8_t r, uint8_t g, uint8_t b)
{
	setLeds(first, cant, color(r,g,b));
}

void MatrizLed::setAllLeds(Led_WS2812B color)
{
	setLeds(0, 0, color);
}

void MatrizLed::setAllLeds(uint8_t r, uint8_t g, uint8_t b)
{
	setLeds(0, 0, color(r,g,b));
}

void MatrizLed::clear(void)
{
	setLeds(0, 0, color(0,0,0));
}

MatrizLed::~MatrizLed()
{
	delete(out_matriz);
	delete(m_uart);
	delete(matriz);
}

void MatrizLed::show(void)
{
	if(out_matriz != nullptr && m_uart == nullptr)
		showCTIMER();
	else if(out_matriz == nullptr && m_uart != nullptr)
		showUART();
}

void MatrizLed::showUART(void)
{
	for(int i = 0; i < m_nleds; i++)
	{
		m_uart->Transmit((void*) &i, 1);
		//m_uart->Transmit((void*) &matriz[i], 3);
		m_uart->Transmit((void*) &matriz[i].r, 1);
		m_uart->Transmit((void*) &matriz[i].g, 1);
		m_uart->Transmit((void*) &matriz[i].b, 1);
	}
	return;
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
 * */
void MatrizLed::showCTIMER(void)
{
	volatile uint8_t estado = NIVEL_ALTO;
	volatile uint8_t nbit = 0;
	volatile uint8_t nled = 0;
	volatile uint8_t bit_actual_bajo;

	volatile uint32_t interrupt_state;
	volatile bool block = true;

	volatile uint32_t ticks_ant = 0;

	//Detener las interrupciones ajenas a la matriz (se reactivan al final de la rutina)
	interrupt_state = NVIC->ISER[0];			//Guarda en una variable el estado que tenía al momento del llamado
	NVIC->ICER[0] = 0xFFFFFFFF;					//Apaga todas las interrupciones
	SysTick->CTRL &=  ~(0x1UL << 1);			//Detiene interrupción del systick

	//Configurar valor para el primer bit (MSB) (tiempo 0, primer interrupción)
	(((matriz[0].r >> 7) & 0x1) == 0) ? (CTIMER0->MR[0] = TIEMPO_CORTO) : (CTIMER0->MR[0] = TIEMPO_LARGO);

	GPIO->CLR[1] = 1 << 0 ;												//Activar salida

	//Une función móvil del match0 al pio1_0
	SYSCON->SYSAHBCLKCTRL0 		|= SYSCON_SYSAHBCLKCTRL0_SWM_MASK;		// Habilita clock de SWM
	// Asigna MATCH0 a P1.0		Limpia los 8 bits que tenía cargados	   Establece el nuevo valor (PIO1_0)
	SWM0->PINASSIGN_DATA[13] = (SWM0->PINASSIGN_DATA[13] & ~(0xFFUL << 8)) | (32U << 8);
	SYSCON->SYSAHBCLKCTRL0 		&= ~SYSCON_SYSAHBCLKCTRL0_SWM_MASK;		// Deshabilita clock de SWM

	CTIMER0->TCR |= CTIMER_TCR_CEN_MASK;								// Arranque del contador

	//Bloqueo para que permanezca en la función
	while(block)
	{
		//Lectura del match (equivalente a la interrupción)
		//Si el TC es menor al margen y anterior es mayor al margen, significa que hubo un reset en el medio
		if((CTIMER0->TC < MARGEN_TICKS_MENOR) && (ticks_ant > MARGEN_TICKS_MAYOR))
		{
			//Lectura del bit actual
			bit_actual_bajo = ((matriz[nled] & (0x1 << (23 - nbit))) == 0);	//Desplazamiento de izquierda a derecha (MSB to LSB)

			switch (estado)
			{
				case NIVEL_ALTO:
					//Apagar salida (toggle del match)

					//Setea el match para el próximo valor
					bit_actual_bajo ? (CTIMER0->MR[0] = TIEMPO_LARGO) : (CTIMER0->MR[0] = TIEMPO_CORTO);
					estado = NIVEL_BAJO;        //La próxima vez que ingrese voy al otro case

					//Si sigo recorriendo el  mismo led paso al siguiente bit, sino vuelvo al bit cero
					if(nbit < 23)
						nbit++;
					else
					{
						nbit = 0;
						//Si sigo recorriendo la matriz paso al siguiente led, sino finalizo el show
						if (nled < (m_nleds - 1))
							nled++;
						else
							block = false;
					}
					break;
				case NIVEL_BAJO:
					//Encender salida (toggle del match)

					//Setea el match para el próximo valor (las variables se aumentaron en el case anterior)
					bit_actual_bajo ? (CTIMER0->MR[0] = TIEMPO_CORTO) : (CTIMER0->MR[0] = TIEMPO_LARGO);

					estado = NIVEL_ALTO;        //La próxima interrupción va a estar en alto
					break;
				default:
					block = false;
					break;
			}
		}
		ticks_ant = CTIMER0->TC;
	}

	//Finalizar envío de datos

	CTIMER0->TCR &= ~CTIMER_TCR_CEN_MASK;		//Frena el contador

	//Desaciocia función móvil del match0 con el pio1_0
	SYSCON->SYSAHBCLKCTRL0 		|= SYSCON_SYSAHBCLKCTRL0_SWM_MASK;		// Habilita clock de SWM
	// Asigna MATCH0 a P1.0		Limpia los 8 bits que tenía cargados	   Establece el nuevo valor (RESET)
	SWM0->PINASSIGN_DATA[13] = (SWM0->PINASSIGN_DATA[13] & ~(0xFFUL << 8)) | (0xffU << 8);
	SYSCON->SYSAHBCLKCTRL0 		&= ~SYSCON_SYSAHBCLKCTRL0_SWM_MASK;		// Deshabilita clock de SWM

	GPIO->SET[1] = 1 << 0 ;					//Apagado de la salida

	NVIC->ISER[0] |= interrupt_state;		//Reactivación de las interrupciones anteriores
	SysTick->CTRL |=  (0x1UL << 1);	    	//Activa interrupción del systick
}
