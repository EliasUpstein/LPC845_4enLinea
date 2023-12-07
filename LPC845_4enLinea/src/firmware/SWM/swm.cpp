/*
 * swm.cpp
 *
 *  Created on: 25 sep. 2023
 *      Author: Gabriel Soccodato
 */

#include "inicializarInfotronic.h"
#include "swm.h"

/*!
 * Asignación de periféricos digitales a los pines.
 *
 * Esta función elige un pin (Designado por su números de GPIO port y bit) para una función.
 *
 * param dirección base de SWM.
 * param función móvil.
 * param swm_port_pin cualquier pin con GPIO port y bit number.
 */

/**
	\fn  	void SWM_SetMovablePinSelect(swm_select_movable_t func, swm_port_pin_type_t swm_port_pin)
	\brief 	Asignación de función
 	\author Ing. Gabriel Soccodato
 	\date 	19 de Setiembre de 2022
 	\param 	swm_select_movable_t func, es un enum función
 			swm_port_pin_type_t swm_port_pin
 	\return void
*/
void SWM_SetMovablePinSelect(swm_select_movable_t func, swm_port_pin_type_t swm_port_pin)
{
    uint32_t temp;
    uint32_t pinassign = 0;
    uint32_t shifter   = 0;

    pinassign = (uint32_t)func / 4U;
    shifter   = ((uint32_t)func % 4U) * 8U;

    temp = SWM0->PINASSIGN_DATA[pinassign];
    temp &= ~(0xFFUL << (shifter));
    temp |= ((uint32_t)swm_port_pin << shifter);
    SWM0->PINASSIGN_DATA[pinassign] = temp;
}

//////////////////////////////////////////////////////////////////////////////////

int f;

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

