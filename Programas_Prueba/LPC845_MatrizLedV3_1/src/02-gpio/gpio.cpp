/*******************************************************************************************************************************//**
 *
 * @file		gpio.cpp
 * @brief		Descripcion del modulo
 * @date		22 jun. 2022
 * @author		Ing. Marcelo Trujillo
 *
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** INCLUDES
 **********************************************************************************************************************************/
#include "LPC845.h"
#include "gpio.h"

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
const uint8_t IOCON_INDEX_PIO0[] = { 17,11,6,5,4,3,16,15,4,13,8,7,2,1,18,10,9,0,30,29,28,27,26,25,24,23,22,21,20,0,0,35};
const uint8_t IOCON_INDEX_PIO1[] = { 36,37,3,41,42,43,46,49,31,32,55,54,33,34,39,40,44,45,47,48,52,53,0,0,0,0,0,0,0,50,51};

/***********************************************************************************************************************************
 *** VARIABLES GLOBALES PUBLICAS
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** VARIABLES GLOBALES PRIVADAS AL MODULO
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** IMPLEMENTACION DE LOS METODODS DE LA CLASE
 **********************************************************************************************************************************/
gpio::gpio ( uint8_t port , uint8_t bit , uint8_t mode , uint8_t activity , uint8_t direction ) :
m_port ( port) , m_bit ( bit ) , m_mode ( mode ) , m_direction ( direction ) , m_activity ( activity )
{
	m_error = ok;

	if ( m_port > port1 )
		m_error = error;
	if ( m_port == port0 && m_bit > b_port0 )
		m_error = error;
	if ( m_port == port1 && m_bit > b_port1 )
		m_error = error;

	if ( m_error == ok)
	{

		SYSCON->SYSAHBCLKCTRL0 |= (1 << 7);								// 7 = SWM
		SYSCON->SYSAHBCLKCTRL0 |= (1 << 6) | (1 << 20) | (1 << 18);		// 6 = GPIO0	20 = GPIO1	18 = IOCON

		if ( m_direction == gpio::output )
		{
			SetPinMode_OUT ( );
			SetDirOutputs ( );
		}
		else
		{
			SetDirInputs ( );
			SetPinMode_IN();
		}
	}

}

uint8_t gpio::SetPin ( void )
{
	if ( m_error == ok )
	{
		if ( m_activity == high )
			GPIO->SET[ m_port ] = 1 << m_bit ;
		else
			GPIO->CLR[ m_port ] = 1 << m_bit ;
	}

	return m_error;
}

uint8_t gpio::ClrPin ( void )
{
	if ( m_error == ok )
	{
		if ( m_activity == high )
			GPIO->CLR[ m_port ] = 1 << m_bit ;
		else
			GPIO->SET[ m_port ] = 1 << m_bit ;
	}
	return m_error;
}

uint8_t gpio::SetTogglePin ( void )
{
	if ( m_error == ok )
		GPIO->NOT[m_port] |= ( 1 << m_bit );

	return m_error;
}

uint8_t gpio::SetDirOutputs ( void )
{
	if ( m_error == ok )
	{
		m_direction = output ;
		GPIO->DIRSET[ m_port ] = 1 << m_bit ;
	}

	return m_error ;
}

uint8_t gpio::SetDirInputs ( void )
{
	if ( m_error == ok )
	{
		m_direction = input ;
		GPIO->DIRCLR[ m_port ] = 1 << m_bit ;
	}

	return m_error ;
}

uint8_t gpio::SetToggleDir ( void )
{
	if ( m_error == ok )
		GPIO->DIRNOT[m_port] |= ( 1 << m_bit );

	return m_error;
}

uint8_t gpio::GetPin ( void ) const
{
	if ( m_error == ok )
		return (m_activity == high ) ? GPIO->B[m_port][m_bit] : !GPIO->B[m_port][m_bit];
	return m_error;
}

uint8_t gpio::SetPinMode_OUT ( void ) {
    uint8_t Indice_PortPin ;	//auxiliar
    if ( m_error == ok ) {
		if ( m_port )
			Indice_PortPin = IOCON_INDEX_PIO1[m_bit];  	 //PUERTO1
		else
			Indice_PortPin = IOCON_INDEX_PIO0[m_bit]; 	//PUERTO0

	IOCON->PIO [Indice_PortPin] =   IOCON_PIO_OD (m_mode);
	}
	return m_error;
}

uint8_t gpio::SetPinMode_IN ( void )
{
	uint8_t Indice_PortPin ;

	if ( m_error == ok )
	{
		if ( m_port )
		    Indice_PortPin = IOCON_INDEX_PIO1[m_bit];  	 //PUERTO1
		else
		    Indice_PortPin = IOCON_INDEX_PIO0[m_bit]; 

		IOCON->PIO [Indice_PortPin] = IOCON_PIO_MODE(m_mode);
		// IOCON->PIO[Indice_PortPin] &= ~0x18;
		// IOCON->PIO[Indice_PortPin] |= m_mode << 3;
	}
	return m_error;
}
