/*******************************************************************************************************************************//**
 *
 * @file		uart.cpp
 * @brief		Descripcion del modulo
 * @date		5 oct. 2022
 * @author		Ing. Marcelo Trujillo
 *
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** INCLUDES
 **********************************************************************************************************************************/
#include "uart.h"
#include "swm.h"

/***********************************************************************************************************************************
 *** DEFINES PRIVADOS AL MODULO
 **********************************************************************************************************************************/

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
 *** VARIABLES GLOBALES PUBLICAS
 **********************************************************************************************************************************/
uart *g_usart[ 5 ];

/***********************************************************************************************************************************
 *** VARIABLES GLOBALES PRIVADAS AL MODULO
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** IMPLEMENTACION DE LOS METODODS DE LA CLASE
 **********************************************************************************************************************************/
uart::uart(
		uint8_t portTx ,			// Puerto en el queremos a la Tx
		uint8_t pinTx ,				// Bit del puerto el queremos a la Tx
		uint8_t portRx ,			// Puerto en el queremos a la Rx
		uint8_t pinRx ,				// Bit del puerto el queremos a la Tx
		USART_Type * usart ,		// USART seleccionada
		uint32_t baudrate,			// velocidad de transmisión
		bits_de_datos BitsDeDatos,	// Cantidad de bits de datos
		paridad_t paridad ,			// Tipo de paridad
		uint32_t maxRx ,			// Tamaño del buffer de RX
		uint32_t maxTx)				// Tamaño del buffer de RX
{
	uint8_t iser ;
	m_usart = usart;					// USART seleccionada

	m_bufferRX = new uint8_t[ maxRx ];	// buffer de Rx
	m_inxRxIn = m_inxRxOut = 0;			// indices del bufer e Rx
	m_maxRx = maxRx;					// tamaño del buffer de Rx

	m_bufferTX = new uint8_t[maxTx];	// buffer de Tx
	m_inxTxIn = m_inxTxOut = 0;			// indices del bufer e Tx
	m_maxTx = maxTx;					// tamaño del buffer de Tx

	m_flagTx = false ;					// flag de fin de Tx

	if ( usart == USART0 )
		g_usart[ 0 ] = this ;

	if ( usart == USART1 )
		g_usart[ 1 ] = this ;

	if ( usart == USART2 )
		g_usart[ 2 ] = this ;

	if ( usart == USART3 )
		g_usart[ 3 ] = this ;

	if ( usart == USART4 )
		g_usart[ 4 ] = this ;


	if ( usart == USART0 )
	{
		SYSCON->SYSAHBCLKCTRL0 |= ( 1 << 14 );
		iser = 3 ;
	}
	if ( usart == USART1 )
	{
		SYSCON->SYSAHBCLKCTRL0 |= ( 1 << 15 );
		iser = 4 ;
	}
	if ( usart == USART2 )
	{
		SYSCON->SYSAHBCLKCTRL0 |= ( 1 << 16 );
		iser = 5 ;
	}
	if ( usart == USART3 )
	{
		SYSCON->SYSAHBCLKCTRL0 |= ( 1 << 30 );
		iser = 30 ;
	}
	if ( usart == USART4 )
	{
		SYSCON->SYSAHBCLKCTRL0 |= ( 1 << 31 );
		iser = 31 ;
	}

	//  selecciono clock ppal.: FCLKSEL
	if ( usart == USART0 )
		SYSCON->FCLKSEL[ 0 ] = 1;
	if ( usart == USART1 )
		SYSCON->FCLKSEL[ 1 ] = 1;
	if ( usart == USART2 )
		SYSCON->FCLKSEL[ 2 ] = 1;
	if ( usart == USART3 )
		SYSCON->FCLKSEL[ 3 ] = 1;
	if ( usart == USART4 )
		SYSCON->FCLKSEL[ 4 ] = 1;

	if ( usart == USART0 )
	{
		PINASSIGN_Config(PA_U0_TXD, portTx, pinTx);
		PINASSIGN_Config(PA_U0_RXD, portRx, pinRx);
	}
	if ( usart == USART1 )
	{
		PINASSIGN_Config(PA_U1_TXD, portTx, pinTx);
		PINASSIGN_Config(PA_U1_RXD, portRx, pinRx);
	}
	if ( usart == USART2 )
	{
		PINASSIGN_Config(PA_U2_TXD, portTx, pinTx);
		PINASSIGN_Config(PA_U2_RXD, portRx, pinRx);
	}
	if ( usart == USART3 )
	{
		PINASSIGN_Config(PA_U3_TXD, portTx, pinTx);
		PINASSIGN_Config(PA_U3_RXD, portRx, pinRx);
	}
	if ( usart == USART4 )
	{
		PINASSIGN_Config(PA_U4_TXD, portTx, pinTx);
		PINASSIGN_Config(PA_U4_RXD, portRx, pinRx);
	}

	usart->CFG = ( 0 << 0 )				// 0=DISABLE 1=ENABLE
				| ( BitsDeDatos << 2 )	// 0=7BITS 1=8BITS 2=9BITS
				| ( paridad << 4 )		// 0=NOPARITY 2=PAR 3=IMPAR
				| ( 0 << 6 )			// 0=1BITSTOP 1=2BITSTOP
				| ( 0 << 9 )			// 0=NOFLOWCONTROL 1=FLOWCONTROL
				| ( 0 << 11 );			// 0=ASINCRONICA 1=SINCRONICA
				//| ( 1 << 15 );	// LOOP

	// OSR vale por default 16
		usart->BRG = (( FREQ_CLOCK / baudrate ) / (usart->OSR + 1)) - 1;
	//	usart->BRG = (( 48000000UL / baudrate ) / (usart->OSR + 1)) - 1;

	usart->INTENSET |= ( 1 << 0 );		// RX interrupcion

	NVIC->ISER[0] |= ( 1 << iser ); 	// habilitamos UART_IRQ

	usart->CFG |= 	( 1 << 0 );			// habilitamos USART
}

uart::~uart() {
	// TODO Auto-generated destructor stub
}

void uart::pushRx ( uint8_t dato )
{
	m_bufferRX[ m_inxRxIn ] = dato;
	m_inxRxIn ++;
	m_inxRxIn %= m_maxRx;
}

uint8_t uart::popRx (uint8_t * dato )
{
	if ( m_inxRxIn != m_inxRxOut )
	{
		*dato = m_bufferRX[ m_inxRxOut ] ;
		m_inxRxOut ++;
		m_inxRxOut %= m_maxRx;
		return 1;
	}
	return 0;
}

void uart::pushTx ( uint8_t dato )
{
	m_bufferTX[ m_inxTxIn ] = dato;
	m_inxTxIn ++;
	m_inxTxIn %= m_maxTx;
}

uint8_t uart::popTx (uint8_t * dato )
{
	if ( m_inxTxIn != m_inxTxOut )
	{
		*dato = m_bufferTX[ m_inxTxOut ] ;
		m_inxTxOut ++;
		m_inxTxOut %= m_maxTx;
		return 1;
	}
	return 0;
}

void uart::Transmit ( const char * msg)
{
	while ( *msg )
	{
		pushTx ( *msg );
		msg++;

		if ( m_flagTx == false )
		{
			m_flagTx = true ;
			Tx_EnableInterupt (  );
		}
	}
}

void uart::Transmit ( void * msg , uint32_t n )
{
	for ( uint32_t i = 0 ; i < n ; i++ )
	{
		pushTx ( ((uint8_t*)msg)[ i ] );

		if ( m_flagTx == false )
		{
			m_flagTx = true ;
			Tx_EnableInterupt (  );
		}
	}
}

void* uart:: Message ( void * msg , uint32_t n )
{
	uint8_t dato;
	static uint32_t cont = 0;
	char * p = ( char *) msg;

	if ( popRx ( &dato ) )
	{
		p[ cont ] = dato ;
		cont ++;

		if ( cont >= n || p[ cont ] == '\n' )
		{
			cont = 0;
			return (void*) p;
		}
	}
	return nullptr;
}

void uart::Tx_EnableInterupt (  void )
{
	m_usart->INTENSET = (1 << 2);
}

void uart::Tx_DisableInterupt (  void )
{
	m_usart->INTENCLR = (1 << 2);
}

void uart::UART_IRQHandler ( void )
{
	uint8_t terminar ;
	uint8_t dato ;
	uint32_t stat = m_usart->STAT ;

	if( stat & ( 1 << 0 ) )
	{
		dato = ( uint8_t ) m_usart->RXDAT ;
		pushRx( dato );
	}

	if( stat & (1 << 2) )
	{
		terminar = popTx ( &dato );

		if( terminar )
			m_usart->TXDAT = ( uint8_t ) dato ;
		else
		{
			Tx_DisableInterupt ( );
			m_flagTx = false ;
		}
	}
}

void UART0_IRQHandler ( void )
{
	g_usart[ 0 ]->UART_IRQHandler();
}
void UART1_IRQHandler ( void )
{
	g_usart[ 1 ]->UART_IRQHandler();
}
void UART2_IRQHandler ( void )
{
	g_usart[ 2 ]->UART_IRQHandler();
}
void PININT6_IRQHandler ( void )
{
	g_usart[ 3 ]->UART_IRQHandler();
}
void  PININT7_IRQHandler ( void )
{
	g_usart[ 4 ]->UART_IRQHandler();
}



//								TX                             RX
//	if ( usart == USART0 )
//		SWM0->PINASSIGN.PINASSIGN0 =
//				( (pinTx + portTx * 0x20 ) << 0 ) | ((pinRx + portRx * 0x20 ) << 8 );
//	if ( usart == USART1 )
//		SWM0->PINASSIGN.PINASSIGN1 =
//				( (pinTx + portTx * 0x20 ) << 8 ) | ((pinRx + portRx * 0x20 ) << 16 );
//	if ( usart == USART2 )
//		SWM0->PINASSIGN.PINASSIGN2 =
//				( (pinTx + portTx * 0x20 ) << 16 ) | ((pinRx + portRx * 0x20 ) << 24 );
//	if ( usart == USART3 )
//	{
//		SWM0->PINASSIGN.PINASSIGN11 = ( (pinTx + portTx * 0x20 ) << 24 ) ;
//		SWM0->PINASSIGN.PINASSIGN12 = ( (pinRx + portRx * 0x20 ) << 0 ) ;
//	}
//	if ( usart == USART4 )
//		SWM0->PINASSIGN.PINASSIGN12 =
//				( (pinTx + portTx * 0x20 ) << 16 ) | ((pinRx + portRx * 0x20 ) << 24 );
