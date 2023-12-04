/*******************************************************************************************************************************//**
 *
 * @file		inicializar.cpp
 * @brief		Descripcion del modulo
 * @date		5 jul. 2022
 * @author		Ing. Marcelo Trujillo
 *
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** INCLUDES
 **********************************************************************************************************************************/
#include "inicializarInfotronic.h"

/***********************************************************************************************************************************
 *** DEFINES PRIVADOS AL MODULO
 **********************************************************************************************************************************/
#define KIT2023
#define FREQ_SYSTICK	(1)		// en ms

/***********************************************************************************************************************************
 *** MACROS PRIVADAS AL MODULO
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** TIPOS DE DATOS PRIVADOS AL MODULO
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** TABLAS PRIVADAS AL MODULO
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** OBJETOS GLOBALES PUBLICOS
 *********************************************************************************************************************************/
list <Callback*> g_CallbackList;

//!< GPIO ENTRADAS SALIDAS DE PROPOSITO GENERAL
// gpio g_out0( gpio::port1 , 0 , gpio::pushpull ,  gpio::output , gpio::high );
// gpio g_out1( gpio::port1 , 1 , gpio::pushpull ,  gpio::output , gpio::high );
// gpio g_out2( gpio::port1 , 2 , gpio::pushpull ,  gpio::output , gpio::high );

//!<	SALIDAS DIGITALES
DigitalOutputs g_out0( gpio::port1 , 0 , gpio::pushpull , gpio::high, gpio::off );
DigitalOutputs g_out1( gpio::port1 , 1 , gpio::pushpull , gpio::high , gpio::off );
DigitalOutputs g_out2( gpio::port1 , 2 , gpio::pushpull , gpio::high , gpio::off );


uart *uart0 ;
//uart *uart1 ;


/***********************************************************************************************************************************
 *** VARIABLES GLOBALES PUBLICAS
 **********************************************************************************************************************************/
void systick_callback ( void  )
{
	for (Callback* q : g_CallbackList )
		q->callback();
}

static void setFlashWaitStates(uint8_t nofWaits) {
  /* Configure the FLASHCFG with the FLASHTIM (Flash memory access time).
   * Latest NXP SDK provides the function IAP_ConfigAccessFlashTime() to do a similar thing.
   * By default after reset, the LPC845 sets it to 0x2 which is 3 system clock access time.
   * NOTE: if getting for higher clock speeds a hardfault, then add some wait states. The LPC845 just runs fine with zero wait states and maximum clock speed for me :-).
   */
  uint32_t val;

  val = (FLASH_CTRL->FLASHCFG)&~FLASH_CTRL_FLASHCFG_FLASHTIM_MASK; /* do not touch the other bits! */
  switch(nofWaits) {
    default:
    case 0: val |= 0x0; break;  /* 1 system clock access time */
    case 1: val |= 0x1; break;  /* 2 system clock access time */
    case 2: val |= 0x2; break;  /* 3 system clock access time */
  }
  FLASH_CTRL->FLASHCFG = val; /* write back settings */
}

void InicializarInfotronic ( void )
{
//	Inicializar_PLL( );
	Inic_OSC();

	// salida a RS232 - terminal MCUXpresso
	uart0 = new uart(
						0 , 				// PortTx
			            25, 				// Pin Tx
						0 ,					// PortRx
						24, 				// Pin Rx
						USART0 ,			// uart seleccionada
						9600 ,				// baudios
						uart::ocho_bits ,	// bits de datos
						uart::NoParidad ,	// tipo de paridad
						64,					// tamaño de buffer de Rx
						64 );				// tamaño de buffer de Tx
	// salida a RS485
	/*uart1 = new uart(   0 , 				// PortTx
			            16, 				// Pin Tx
						0 ,					// PortRx
						17, 				// Pin Rx
						USART1 ,			// uart seleccionada
						9600 ,				// baudios
						uart::ocho_bits ,	// bits de datos
						uart::NoParidad ,	// tipo de paridad
						64,					// tamaño de buffer de Rx
						64 );				// tamaño de buffer de Tx*/

	// ###############################################################################################
	SysTick_CallBack_Install( systick_callback );

	// por precaucion lo ultimo es el systick
	Inicializar_SysTick( FREQ_SYSTICK );

	//Observar fro en pin de salida
//	SYSCON->CLKOUTSEL |= (1 << 0);
//	SYSCON->CLKOUTDIV |= (1 << 0);
//	SWM_SetMovablePinSelect(kSWM_CLKOUT, kSWM_PortPin_P0_29);

	setFlashWaitStates(0);
}
