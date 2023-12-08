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

//!<	SALIDAS DIGITALES (leds de la placa)
DigitalOutputs g_out0( gpio::port1 , 0 , gpio::pushpull , gpio::high, gpio::off );
DigitalOutputs g_out1( gpio::port1 , 1 , gpio::pushpull , gpio::high , gpio::off );
DigitalOutputs g_out2( gpio::port1 , 2 , gpio::pushpull , gpio::high , gpio::off );

//!<	ENTRADAS DIGITALES
DigitalInputs g_in0( gpio::port0 ,  4 , gpio::pullup , gpio::low );

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

// DISPLAY
vector <gpio *> bcd;
vector <gpio *> cnt;
vector <gruposdedigitos *> grupos;
I4017 *i4017 ;
I4511 *i4511 ;
uint8_t	PosicionRelativa[] = {2,1,0,5,4,3};
Display7Segmentos *Display;

gpio *bcdA = (new gpio ( gpio::port0 ,  23 , gpio::pushpull ,  gpio::output , gpio::high ));
gpio *bcdB = (new gpio ( gpio::port0 ,  22 , gpio::pushpull ,  gpio::output , gpio::high ));
gpio *bcdC = (new gpio ( gpio::port0 ,  21 , gpio::pushpull ,  gpio::output , gpio::high ));
gpio *bcdD = (new gpio ( gpio::port0 ,  20 , gpio::pushpull ,  gpio::output , gpio::high ));
gpio *dp   = (new gpio ( gpio::port0 ,  12 , gpio::pushpull ,  gpio::output , gpio::high ));


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

	// ## DISPLAY 7 SEGMENTOS ########################################################################
	// segmentos - Integrado 4051 --------------------------------------------------------------------
	bcd.push_back( bcdA );
	bcd.push_back( bcdB );
	bcd.push_back( bcdC );
	bcd.push_back( bcdD );
	bcd.push_back( dp );
	i4511 = new I4511( bcd );

	// Driver de digitos - Integrado 4017 ------------------------------------------------------------
	cnt.push_back( rst );
	cnt.push_back( clk );
	i4017 = new I4017( cnt , 6 );

	// Configuracion del formato del display ---------------------------------------------------------
	//                                    posicion relativa    cantidad
	grupos.push_back(new gruposdedigitos (       0 ,              3     ));
	grupos.push_back(new gruposdedigitos (       3 ,              3     ));
	//  display de 7 segmentos -----------------------------------------------------------------------
	//                      		  digitos
	//                               agrupados segmentos   barrido    correccion       codificacion
	Display = new Display7Segmentos ( grupos ,  i4511 ,      i4017 , PosicionRelativa , Digito::BCD );

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

	resetVictorias();

	tablero.limpiarTablero();
	tablero.setColumnaActual(0);
	tablero.ocuparFila(0, 2);	//Llena toda la primer fila en blanco
	matriz.show();
}
