#ifndef APLICACION_H_
#define APLICACION_H_

#include "inicializarInfotronic.h"

#define TIEMPO_VICTORIA 40 //Tiempo en décimas de segundo
#define TIEMPO_CAIDA 1

//Estados
#define ESPERA 0
#define JUGADOR 1
#define VICTORIA 2
#define CAIDA_FICHA 3

#define IZQUIERDA 2
#define DERECHA 0
#define CONFIRMAR 1

extern bool startGame;

void game4enLinea(void);
void resetGame(void);
void resetVictorias(void);


#endif
