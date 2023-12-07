/***********************************************************************************************************************************
 *** MODULO
 **********************************************************************************************************************************/
#ifndef INICIALIZAR_H_
#define INICIALIZAR_H_

/***********************************************************************************************************************************
 *** INCLUDES GLOBALES
 **********************************************************************************************************************************/
using namespace std;

#include <vector>
#include <list>

#include "LPC845.h"
#include "dr_pll.h"
#include "systick.h"
#include "flash.h"

#include "gpio.h"
#include <digital_outputs.h>
#include "timer.h"
#include "teclado.h"
#include "uart.h"

#include "tablero.h"
#include "matriz.h"

/***********************************************************************************************************************************
 *** VARIABLES GLOBALES
 **********************************************************************************************************************************/
//!<	SALIDAS DIGITALES
//extern DigitalOutputs g_out0 ;
//extern DigitalOutputs g_out1 ;
//extern DigitalOutputs g_out2 ;

//!<	TECLADO
extern teclado *Teclado;

// 		UART
extern uart *uart0;

//		MATRIZ
#define NLEDS 64
extern MatrizLed matriz;

/***********************************************************************************************************************************
 *** PROTOTIPOS GLOBALES
 **********************************************************************************************************************************/
void InicializarInfotronic ( void ) ;
void systick_callback ( void  );

#endif /* INICIALIZAR_H_ */