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
#include "digital_inputs.h"
#include <digital_outputs.h>
#include "timer.h"
#include "teclado.h"
#include "uart.h"
#include "I4017.h"
#include "I4511.h"
#include "display7Segmentos.h"

#include "matriz.h"
#include "colors.h"
#include "tablero.h"

#include "aplicacion.h"
#include "comunicacionQT.h"

/***********************************************************************************************************************************
 *** VARIABLES GLOBALES
 **********************************************************************************************************************************/
//!<	ENTRADAS DIGITALES
extern DigitalInputs 	g_in0 ;

//!<	TECLADO
extern teclado *Teclado;
extern uint8_t tecla;

//!<    DISPLAY
extern Display7Segmentos *Display;

// 		UART
extern uart *uart0;

//		MATRIZ
#define NLEDS 64
extern MatrizLed matriz;

//		TABLERO
#define FILAS 8
#define COLUMNAS 8
extern Tablero tablero;

/***********************************************************************************************************************************
 *** PROTOTIPOS GLOBALES
 **********************************************************************************************************************************/
void InicializarInfotronic ( void ) ;
void systick_callback ( void  );

#endif /* INICIALIZAR_H_ */
