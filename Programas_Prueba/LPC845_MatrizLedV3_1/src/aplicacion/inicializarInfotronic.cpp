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

	inicializarCtimer();
}
