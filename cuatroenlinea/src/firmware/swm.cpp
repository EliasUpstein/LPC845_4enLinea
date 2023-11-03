/*******************************************************************************************************************************//**
 *
 * @file		swm.cpp
 * @brief		Descripcion del modulo
 * @date		12 sep. 2023
 * @author		Ing. Marcelo Trujillo
 *
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** INCLUDES
 **********************************************************************************************************************************/
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

/***********************************************************************************************************************************
 *** VARIABLES GLOBALES PRIVADAS AL MODULO
 **********************************************************************************************************************************/
int f;
/***********************************************************************************************************************************
 *** IMPLEMENTACION DE LOS METODODS DE LA CLASE
 **********************************************************************************************************************************/
void PINASSIGN_Config( uint8_t pin_movible , uint8_t port , uint8_t pin )
{
	if ( port == 1 )
		pin = pin + 32;

	PIN_ASSIGN[ pin_movible / 4 ] &= ~(0xff << (( pin_movible % 4 ) * 8 ));
	PIN_ASSIGN[ pin_movible / 4 ] |= pin << (( pin_movible % 4 ) * 8 );
}

void PINENABLE_Config( uint8_t pin_config , uint8_t enable )
{
	// TIENE LOGICA NEGADA, ES ACTIVO BAJO
	if ( !enable )
		PINENABLE[ pin_config / 32 ] |=  1 << ( pin_config % 32 ) ;
	else
		PINENABLE[ pin_config / 32 ] &= ~( 1 <<  ( pin_config % 32 ) );

}
