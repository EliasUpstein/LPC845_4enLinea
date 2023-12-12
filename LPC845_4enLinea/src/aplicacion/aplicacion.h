#ifndef APLICACION_H_
#define APLICACION_H_

#include "inicializarInfotronic.h"

#define TIEMPO_VICTORIA 40 	//Tiempo en décimas de segundo para el muestreo en caso de victoria o empate
#define TIEMPO_CAIDA 1		//Tiempo en décimas para la caída de la ficha

//Estados
#define ESPERA 0
#define JUGADOR 1
#define VICTORIA 2
#define CAIDA_FICHA 3

//Generalización de los valores de los pulsadores o botones (GUI)
#define IZQUIERDA 2
#define DERECHA 0
#define CONFIRMAR 1

extern bool startGame;

extern bool color1Flag;
extern bool color2Flag;

void game4enLinea(void);
void newGame(void);
void resetVictorias(void);
void actualizarJugador(uint8_t player, uint8_t ncolor);
void initGame(void);

#endif
