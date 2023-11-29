/*******************************************************************************************************************************//**
 *
 * @file		inicializar.h
 * @brief		Breve descripción del objetivo del Módulo
 * @date		5 jul. 2022
 * @author		Ing. Marcelo Trujillo
 *
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** MODULO
 **********************************************************************************************************************************/

#ifndef INICIALIZAR_H_
#define INICIALIZAR_H_

/***********************************************************************************************************************************
 *** INCLUDES GLOBALES
 **********************************************************************************************************************************/

#include <vector>
#include <list>

#include "LPC845.h"
#include "dr_pll.h"
#include "systick.h"
#include "gpio.h"
#include <digital_outputs.h>
#include "uart.h"

#include "swm.h"
#include "ctimer.h"

#include "matriz.h"

using namespace std;

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

//!<	SALIDAS DIGITALES
// extern gpio g_out0 ;
// extern gpio g_out1 ;
// extern gpio g_out2 ;

extern DigitalOutputs g_out0 ;
extern DigitalOutputs g_out1 ;
extern DigitalOutputs g_out2 ;

// 		UART
extern uart *uart0 ;
//extern uart *uart1 ;

/***********************************************************************************************************************************
 *** PROTOTIPOS GLOBALES
 **********************************************************************************************************************************/
void InicializarInfotronic ( void ) ;
void systick_callback ( void  );

#endif /* INICIALIZAR_H_ */
