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
 *** OBJETOS GLOBALES PUBLICOS
 *********************************************************************************************************************************/
list <Callback*> g_CallbackList;

//!<	SALIDAS DIGITALES
DigitalOutputs g_out0( gpio::port1 , 0 , gpio::pushpull , gpio::high, gpio::off );
DigitalOutputs g_out1( gpio::port1 , 1 , gpio::pushpull , gpio::high , gpio::off );
DigitalOutputs g_out2( gpio::port1 , 2 , gpio::pushpull , gpio::high , gpio::off );

//!<	TECLADO
vector <gpio *> scn;
vector <gpio *> ret;
teclado *Teclado;

// barrido
gpio *rst = (new gpio ( gpio::port0 ,  18 , gpio::pushpull ,  gpio::output , gpio::high )); // RST
gpio *clk = (new gpio ( gpio::port0 ,  19 , gpio::pushpull ,  gpio::output , gpio::high )); // CLK

//gpio *scn0 = new gpio ( gpio::port0 ,  27 , gpio::pushpull ,  gpio::output , gpio::high );
gpio *scn1 = new gpio ( gpio::port0 ,  28 , gpio::pushpull ,  gpio::output , gpio::high );

gpio *ret0 = new gpio ( gpio::port0 , 26 , gpio::pullup ,  gpio::input , gpio::low );
gpio *ret1 = new gpio ( gpio::port0 , 15 , gpio::pullup ,  gpio::input , gpio::low );
gpio *ret2 = new gpio ( gpio::port0 ,  8 , gpio::pullup ,  gpio::input , gpio::low );

uint8_t tecla;

// 		UART
uart *uart0;

//		MATRIZ
MatrizLed matriz(0, 29, NLEDS);

//		TABLERO
Tablero tablero(FILAS, COLUMNAS, matriz);

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
	Inic_OSC();

	// ## TECLADO ####################################################################################
//	scn.push_back( scn0 );
	scn.push_back( scn1 );

	ret.push_back( ret0 );
	ret.push_back( ret1 );
	ret.push_back( ret2 );

	Teclado = new teclado ( scn , ret );
	// ###############################################################################################

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
	// ###############################################################################################

	setFlashWaitStates(0);

	SysTick_CallBack_Install( systick_callback );
	Inicializar_SysTick( FREQ_SYSTICK );

	tablero.limpiarTablero();
	tablero.setColumnaActual(0);
	matriz.show();
}
