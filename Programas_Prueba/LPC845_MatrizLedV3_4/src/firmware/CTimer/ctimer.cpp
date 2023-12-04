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
}
