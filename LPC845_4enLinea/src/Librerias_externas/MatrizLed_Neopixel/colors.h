#ifndef COLORS
#define COLORS

#include "matriz.h"

#define INTENSIDAD 100

#define CANT_COLORS 8

#define ROJO MatrizLed::color(INTENSIDAD,0,0)
#define VERDE MatrizLed::color(0,INTENSIDAD,0)
#define AZUL MatrizLed::color(0,0,INTENSIDAD)
#define AMARILLO MatrizLed::color(INTENSIDAD,INTENSIDAD,0)
#define ROSA MatrizLed::color(INTENSIDAD,0,INTENSIDAD)
#define CELESTE MatrizLed::color(0,INTENSIDAD,INTENSIDAD)
#define VIOLETA MatrizLed::color(100,0,255)
#define NARANJA MatrizLed::color(255,100,0)
#define BLANCO MatrizLed::color(INTENSIDAD/5,INTENSIDAD/5, INTENSIDAD/5)
#define OFF MatrizLed::color(0,0,0)

const Led_WS2812B colours[] = { ROJO, AZUL, VERDE, AMARILLO, ROSA, CELESTE, VIOLETA, NARANJA };

enum nColours{ nROJO, nAZUL, nVERDE, nAMARILLO, nROSA, nCELESTE, nVIOLETA, nNARANJA };

#endif
