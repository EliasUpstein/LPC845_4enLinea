#include "inicializarInfotronic.h"

/*
 * 	• Set the appropriate bit to enable the clock to timer: CTIMER in the AHBCLKCTRL0
	register (Section 8.6.22).
	• Pins: Select timer pins through switch matrix.
	Interrupts: See register MCR (Table 377) and CCR (Table 379) for match and capture
	events. Interrupts are enabled in the NVIC using the appropriate Interrupt Set Enable
	register. For interrupt connections, see Table 108.
	• DMA: Some timer match conditions can be used to generate timed DMA requests,
	see Table 296.
 *
 * **/

//Sólo configura, no le da arranque (se hace desde el show de matriz)
void inicializarCtimer(void){
	SYSCON->SYSAHBCLKCTRL0 		|= SYSCON_SYSAHBCLKCTRL0_CTIMER_MASK;		// Habilita clock de CTIMER
	SYSCON->PRESETCTRL0			|= SYSCON_PRESETCTRL0_CTIMER_RST_N_MASK;	// Limpia Reset del periferico
	CTIMER0->PR = 0;														// Preescaler de timer 0, 30MHz
	CTIMER0->MCR |= CTIMER_MCR_MR0R_MASK | CTIMER_MCR_MR0I_MASK;			// Reset e Interrupción del timer ante evento de match0
	CTIMER0->EMR = CTIMER_EMR_EMC0(0x03);									// Toggle pin on match
}


void CTIMER0_IRQHandler(void){
	CTIMER0->IR |= CTIMER_IR_MR0INT_MASK;									//Reinicia Interrupción

	//Máquina de Estado para el envío de datos

	static volatile uint8_t estado = NIVEL_ALTO;
	static volatile uint8_t nbit = 0;
	static volatile uint8_t nled = 0;
	static volatile uint8_t bit_actual_bajo;

	//Lectura del bit actual
	bit_actual_bajo = ((matriz[nled] & (0x1 << (23 - nbit))) == 0);	//Desplazamiento de izquierda a derecha (MSB to LSB)

	switch (estado)
	{
	case NIVEL_ALTO:
		//Apagar salida (toggle de la interrupción)

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
			if (nled < (nleds - 1))
				nled++;
			else
			{
				nled = 0;
				estado = FINALIZAR_CTIMER;        //La próxima interrupción será la última
			}
		}
		break;
	case NIVEL_BAJO:
		//Encender salida (toggle de la interrupción)

		//Setea el match para el próximo valor (las variables se aumentaron en el case anterior)
		bit_actual_bajo ? (CTIMER0->MR[0] = TIEMPO_CORTO) : (CTIMER0->MR[0] = TIEMPO_LARGO);

		estado = NIVEL_ALTO;        //La próxima interrupción va a estar en alto
		break;
	case FINALIZAR_CTIMER:
		//Activación de interrupciones (previas) y apagado de salida

		// Deshabilita interrupción de CTIMER0 y frena el contador
		NVIC->ICER[0] |= ISE_CT32B0;
		CTIMER0->TCR &= ~CTIMER_TCR_CEN_MASK;

		//Desaciocia función móvil del match0 con el pio1_0
		SYSCON->SYSAHBCLKCTRL0 		|= SYSCON_SYSAHBCLKCTRL0_SWM_MASK;		// Habilita clock de SWM
		// Asigna MATCH0 a P1.0		Limpia los 8 bits que tenía cargados	   Establece el nuevo valor (RESET)
		SWM0->PINASSIGN_DATA[13] = (SWM0->PINASSIGN_DATA[13] & ~(0xFFUL << 8)) | (0xffU << 8);
		SYSCON->SYSAHBCLKCTRL0 		&= ~SYSCON_SYSAHBCLKCTRL0_SWM_MASK;		// Deshabilita clock de SWM

		NVIC->ISER[0] |= interrupt_state;		//Reactivación de las interrupciones anteriores
		SysTick->CTRL |=  (0x1UL << 1);	    	//Activa interrupción del systick
		USART0->INTENSET |= ( 1 << 0 );			//Habilita interrupcion USART0 en RX

		GPIO->SET[1] = 1 << 0 ;					//Apagado de la salida

		estado = NIVEL_ALTO;        //Seteo para el próximo show (las variables nbit, ncolor y nled ya deberían estar en 0)
		break;
	default:						//Reseteo de todas las variales y frena interrupciones
		//Desaciocia función móvil del match0 con el pio1_0
		SYSCON->SYSAHBCLKCTRL0 		|= SYSCON_SYSAHBCLKCTRL0_SWM_MASK;		// Habilita clock de SWM
		// Asigna MATCH0 a P1.0		Limpia los 8 bits que tenía cargados	   Establece el nuevo valor (RESET)
		SWM0->PINASSIGN_DATA[13] = (SWM0->PINASSIGN_DATA[13] & ~(0xFFUL << 8)) | (0xffU << 8);
		SYSCON->SYSAHBCLKCTRL0 		&= ~SYSCON_SYSAHBCLKCTRL0_SWM_MASK;		// Deshabilita clock de SWM

		// Deshabilita interrupción de CTIMER0 y frena el contador
		NVIC->ICER[0] |= ISE_CT32B0;
		CTIMER0->TCR &= ~CTIMER_TCR_CEN_MASK;


		NVIC->ISER[0] |= interrupt_state;		//Reactivación de las interrupciones anteriores

		nbit = 0;
		nled = 0;
		estado = NIVEL_ALTO;
		break;
	}
}
