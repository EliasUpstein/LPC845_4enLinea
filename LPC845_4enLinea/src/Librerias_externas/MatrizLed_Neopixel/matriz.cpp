#include "matriz.h"

//Constructor para GPIO
MatrizLed::MatrizLed(uint8_t puerto, uint8_t bit, uint8_t nleds)
{
	out_matriz = new gpio(puerto, bit, gpio::pushpull, gpio::high, gpio::output);
	m_uart = nullptr;
	m_nleds = nleds;
    matriz = new Led_WS2812B[nleds];		//Declaración del vector de leds
    out_matriz->ClrPin();
}

//Constructor para controlar por comunicación serie
MatrizLed::MatrizLed(uart* uart, uint8_t nleds)
{
	m_uart = uart;
	out_matriz = nullptr;
    m_nleds = nleds;
    matriz = new Led_WS2812B[nleds];
    m_uart->Transmit((void*)'z', 1);		//Apaga la matriz en la recepción
}

//Recibe las componentes r, g y b y devuelve la estructura led correspondiente
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
	uint16_t end;		//Variable para calcular el final del seteo

	if (first >= m_nleds || first < 0)	//Validación
		return;

	// Si se recibe 0, rellena hasta el final, sino chequea no excederse
	if (cant == 0)
		end = m_nleds;
	else
	{
		end = first + cant;
		if (end > m_nleds)		//Valida límite
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

void MatrizLed::clearLed(uint8_t led)
{
	setLed(led, 0, 0, 0);
}

MatrizLed::~MatrizLed()
{
	delete(out_matriz);
	delete(m_uart);
	delete(matriz);
}


//Ejecuta la función correspondiente en caso de comunicar por GPIO o por Serie
void MatrizLed::show(void)
{
	if(out_matriz != nullptr && m_uart == nullptr)
		showGPIO();
	else if(out_matriz == nullptr && m_uart != nullptr)
		showUART();
}

//Envía número de led y componente de cada color para todos los leds de la matriz
//Según la velocidad del protocolo la comunicación es LENTA
void MatrizLed::showUART(void)
{
	for(int i = 0; i < m_nleds; i++)
	{
		m_uart->Transmit((void*) &i, 1);
		m_uart->Transmit((void*) &matriz[i].r, 1);
		m_uart->Transmit((void*) &matriz[i].g, 1);
		m_uart->Transmit((void*) &matriz[i].b, 1);
	}
	return;
}


/* Tiempo de comunicación promedio:

1,25us (por bit) * 8 (por byte) * 3 (por led) = 30us por led
30us * 64 (leds de nuestra matriz) = 1920us = 1.92 ms => aprox 2ms	*/
void MatrizLed::showGPIO(void)
{
	volatile uint32_t interrupt_state;		//Almacena las interrupciones activas al momento del llamado

	//Setea el wait states en 0 (programación defensiva en caso de que se haya cambiado este registro)
	FLASH_CTRL->FLASHCFG = ((FLASH_CTRL->FLASHCFG)&~FLASH_CTRL_FLASHCFG_FLASHTIM_MASK) | 0x0;

	//Detener las interrupciones ajenas a la matriz (se reactivan al final de la rutina)
	interrupt_state = NVIC->ISER[0];			//Guarda en una variable el estado que tenía al momento del llamado
	NVIC->ICER[0] = 0xFFFFFFFF;					//Apaga todas las interrupciones
	SysTick->CTRL &=  ~(0x1UL << 1);			//Detiene interrupción del systick

	GPIO->CLR[0] = 1 << 29 ;					//Se asegura que el pin esté el LOW

	//Bucle para leds
	for(uint8_t nled=0; nled<m_nleds; nled++)
	{
//		send24Bits(matriz[nled], 0, 29);		//Función para optimizar manejo de memoria
		send24Bits(matriz[nled]);
	}
	//Finalizar envío de datos
	GPIO->CLR[0] = 1 << 29 ;				//Se assegura que la salida quede en bajo

	NVIC->ISER[0] |= interrupt_state;		//Reactivación de las interrupciones anteriores
	SysTick->CTRL |=  (0x1UL << 1);	    	//Activa interrupción del systick
}

//Envía bit a bit los 24 que recibe de data
//Según el valor del bit, genera la temporazación correspondiente (datasheet)
//Los 400ns se consumen en la propia ejecución del micro
//Los 800ns se logran con un "delay" en assembler ("nop;")
void MatrizLed::send24Bits(uint32_t data)
{
	//Bit 0
	GPIO->SET[PORT] = 1 << PIN ;	//Encendido del PIN
	//Si el bit es 1 => T1H = 800ns + T1L = 450ns
	if(data & (0x1 << (23 - 0)))
	{
		DELAY_ASM
		GPIO->CLR[PORT] = 1 << PIN;
	}
	//Si el bit es 0 => TOH = 400ns + TOL = 850ns
	else
	{
		GPIO->CLR[PORT] = 1 << PIN;
		DELAY_ASM
	}

	//Bit 1
	GPIO->SET[PORT] = 1 << PIN ;
	if(data & (0x1 << (23 - 1)))
	{
		DELAY_ASM
		GPIO->CLR[PORT] = 1 << PIN;
	}
	else
	{
		GPIO->CLR[PORT] = 1 << PIN;
		DELAY_ASM
	}

	//Bit 2
	GPIO->SET[PORT] = 1 << PIN ;
	if(data & (0x1 << (23 - 2)))
	{
		DELAY_ASM
		GPIO->CLR[PORT] = 1 << PIN;
	}
	else
	{
		GPIO->CLR[PORT] = 1 << PIN;
		DELAY_ASM
	}

	//Bit 3
	GPIO->SET[PORT] = 1 << PIN ;
	if(data & (0x1 << (23 - 3)))
	{
		DELAY_ASM
		GPIO->CLR[PORT] = 1 << PIN;
	}
	else
	{
		GPIO->CLR[PORT] = 1 << PIN;
		DELAY_ASM
	}

	//Bit 4
	GPIO->SET[PORT] = 1 << PIN ;
	if(data & (0x1 << (23 - 4)))
	{
		DELAY_ASM
		GPIO->CLR[PORT] = 1 << PIN;
	}
	else
	{
		GPIO->CLR[PORT] = 1 << PIN;
		DELAY_ASM
	}

	//Bit 5
	GPIO->SET[PORT] = 1 << PIN ;
	if(data & (0x1 << (23 - 5)))
	{
		DELAY_ASM
		GPIO->CLR[PORT] = 1 << PIN;
	}
	else
	{
		GPIO->CLR[PORT] = 1 << PIN;
		DELAY_ASM
	}

	//Bit 6
	GPIO->SET[PORT] = 1 << PIN ;
	if(data & (0x1 << (23 - 6)))
	{
		DELAY_ASM
		GPIO->CLR[PORT] = 1 << PIN;
	}
	else
	{
		GPIO->CLR[PORT] = 1 << PIN;
		DELAY_ASM
	}

	//Bit 7
	GPIO->SET[PORT] = 1 << PIN ;
	if(data & (0x1 << (23 - 7)))
	{
		DELAY_ASM
		GPIO->CLR[PORT] = 1 << PIN;
	}
	else
	{
		GPIO->CLR[PORT] = 1 << PIN;
		DELAY_ASM
	}

	//Bit 8
	GPIO->SET[PORT] = 1 << PIN ;
	if(data & (0x1 << (23 - 8)))
	{
		DELAY_ASM
		GPIO->CLR[PORT] = 1 << PIN;
	}
	else
	{
		GPIO->CLR[PORT] = 1 << PIN;
		DELAY_ASM
	}

	//Bit 9
	GPIO->SET[PORT] = 1 << PIN ;
	if(data & (0x1 << (23 - 9)))
	{
		DELAY_ASM
		GPIO->CLR[PORT] = 1 << PIN;
	}
	else
	{
		GPIO->CLR[PORT] = 1 << PIN;
		DELAY_ASM
	}

	//Bit 10
	GPIO->SET[PORT] = 1 << PIN ;
	if(data & (0x1 << (23 - 10)))
	{
		DELAY_ASM
		GPIO->CLR[PORT] = 1 << PIN;
	}
	else
	{
		GPIO->CLR[PORT] = 1 << PIN;
		DELAY_ASM
	}

	//Bit 11
	GPIO->SET[PORT] = 1 << PIN ;
	if(data & (0x1 << (23 - 11)))
	{
		DELAY_ASM
		GPIO->CLR[PORT] = 1 << PIN;
	}
	else
	{
		GPIO->CLR[PORT] = 1 << PIN;
		DELAY_ASM
	}

	//Bit 12
	GPIO->SET[PORT] = 1 << PIN ;
	if(data & (0x1 << (23 - 12)))
	{
		DELAY_ASM
		GPIO->CLR[PORT] = 1 << PIN;
	}
	else
	{
		GPIO->CLR[PORT] = 1 << PIN;
		DELAY_ASM
	}

	//Bit 13
	GPIO->SET[PORT] = 1 << PIN ;
	if(data & (0x1 << (23 - 13)))
	{
		DELAY_ASM
		GPIO->CLR[PORT] = 1 << PIN;
	}
	else
	{
		GPIO->CLR[PORT] = 1 << PIN;
		DELAY_ASM
	}

	//Bit 14
	GPIO->SET[PORT] = 1 << PIN ;
	if(data & (0x1 << (23 - 14)))
	{
		DELAY_ASM
		GPIO->CLR[PORT] = 1 << PIN;
	}
	else
	{
		GPIO->CLR[PORT] = 1 << PIN;
		DELAY_ASM
	}

	//Bit 15
	GPIO->SET[PORT] = 1 << PIN ;
	if(data & (0x1 << (23 - 15)))
	{
		DELAY_ASM
		GPIO->CLR[PORT] = 1 << PIN;
	}
	else
	{
		GPIO->CLR[PORT] = 1 << PIN;
		DELAY_ASM
	}

	//Bit 16
	GPIO->SET[PORT] = 1 << PIN ;
	if(data & (0x1 << (23 - 16)))
	{
		DELAY_ASM
		GPIO->CLR[PORT] = 1 << PIN;
	}
	else
	{
		GPIO->CLR[PORT] = 1 << PIN;
		DELAY_ASM
	}

	//Bit 17
	GPIO->SET[PORT] = 1 << PIN ;
	if(data & (0x1 << (23 - 17)))
	{
		DELAY_ASM
		GPIO->CLR[PORT] = 1 << PIN;
	}
	else
	{
		GPIO->CLR[PORT] = 1 << PIN;
		DELAY_ASM
	}

	//Bit 18
	GPIO->SET[PORT] = 1 << PIN ;
	if(data & (0x1 << (23 - 18)))
	{
		DELAY_ASM
		GPIO->CLR[PORT] = 1 << PIN;
	}
	else
	{
		GPIO->CLR[PORT] = 1 << PIN;
		DELAY_ASM
	}

	//Bit 19
	GPIO->SET[PORT] = 1 << PIN ;
	if(data & (0x1 << (23 - 19)))
	{
		DELAY_ASM
		GPIO->CLR[PORT] = 1 << PIN;
	}
	else
	{
		GPIO->CLR[PORT] = 1 << PIN;
		DELAY_ASM
	}

	//Bit 20
	GPIO->SET[PORT] = 1 << PIN ;
	if(data & (0x1 << (23 - 20)))
	{
		DELAY_ASM
		GPIO->CLR[PORT] = 1 << PIN;
	}
	else
	{
		GPIO->CLR[PORT] = 1 << PIN;
		DELAY_ASM
	}

	//Bit 21
	GPIO->SET[PORT] = 1 << PIN ;
	if(data & (0x1 << (23 - 21)))
	{
		DELAY_ASM
		GPIO->CLR[PORT] = 1 << PIN;
	}
	else
	{
		GPIO->CLR[PORT] = 1 << PIN;
		DELAY_ASM
	}

	//Bit 22
	GPIO->SET[PORT] = 1 << PIN ;
	if(data & (0x1 << (23 - 22)))
	{
		DELAY_ASM
		GPIO->CLR[PORT] = 1 << PIN;
	}
	else
	{
		GPIO->CLR[PORT] = 1 << PIN;
		DELAY_ASM
	}

	//Bit 23
	GPIO->SET[PORT] = 1 << PIN ;
	if(data & (0x1 << (23 - 23)))
	{
		DELAY_ASM
		GPIO->CLR[PORT] = 1 << PIN;
	}
	else
	{
		GPIO->CLR[PORT] = 1 << PIN;
		DELAY_ASM
	}
}
