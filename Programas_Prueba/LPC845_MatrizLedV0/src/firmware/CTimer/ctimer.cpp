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
	SYSCON->SYSAHBCLKCTRL0 		|= SYSCON_SYSAHBCLKCTRL0_SWM_MASK;			// Habilita clock de SWM
	SYSCON->PRESETCTRL1			|= SYSCON_PRESETCTRL0_CTIMER_RST_N_MASK;	// Limpia Reset del periferico
	SWM_SetMovablePinSelect(kSWM_T0_MAT_CHN0, kSWM_PortPin_P1_0);			// Asigna MATCH0 a P1.0
	CTIMER0->PR = 0;														// Preescaler de timer 0, 30MHz
	CTIMER0->MCR |= CTIMER_MCR_MR0R_MASK | CTIMER_MCR_MR0I_MASK;			// Reset e Interrupción del timer ante evento de match0
	CTIMER0->EMR = CTIMER_EMR_EMC0(0x03);									// Toggle pin on match
	SYSCON->SYSAHBCLKCTRL0 		&= ~SYSCON_SYSAHBCLKCTRL0_SWM_MASK;			// Deshabilita clock de SWM
}


void CTIMER0_IRQHandler(void){
	CTIMER0->IR |= CTIMER_IR_MR0INT_MASK;									//Reinicia Interrupción

	MdE_Ctimer_Matriz();													//Máquina de Estado para el envío de datos
}
