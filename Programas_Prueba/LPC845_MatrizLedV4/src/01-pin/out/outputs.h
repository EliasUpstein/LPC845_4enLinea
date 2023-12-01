/*******************************************************************************************************************************//**
 *
 * @file		pin.h
 * @brief		Clase Abstracta Pura
 * @date		22 jun. 2022
 * @author		Ing. Marcelo Trujillo
 *
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** MODULO
 **********************************************************************************************************************************/

#ifndef OUTPUTS_H_
#define OUTPUTS_H_

/***********************************************************************************************************************************
 *** INCLUDES GLOBALES
 **********************************************************************************************************************************/
#include "tipos.h"

/***********************************************************************************************************************************
 *** DEFINES GLOBALES
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** MACROS GLOBALES
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** TIPO DE DATOS GLOBALES
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** VARIABLES GLOBALES
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** IMPLANTACION DE LA CLASE
 **********************************************************************************************************************************/
class outputs
{
	public:
		outputs () {};
		virtual uint8_t SetPin ( void ) = 0;
		virtual uint8_t ClrPin ( void ) = 0;
		virtual uint8_t SetTogglePin ( void ) = 0;
		virtual uint8_t SetDirOutputs ( void ) = 0;
		virtual uint8_t SetPinMode_IN ( void )  = 0;
		virtual ~outputs(){};
};
#endif /* OUTPUTS_H_ */