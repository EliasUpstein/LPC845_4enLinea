#ifndef APLICACION_H_
#define APLICACION_H_

#include "inicializarInfotronic.h"

#define TIEMPO_VICTORIA 50 //Tiempo en décimas de segundo

//Estados
#define ESPERA 0
#define JUGADOR 1
#define VICTORIA 2

#define IZQUIERDA 2
#define DERECHA 0
#define CONFIRMAR 1

extern bool startGame;

void game4enLinea(void);


#endif
