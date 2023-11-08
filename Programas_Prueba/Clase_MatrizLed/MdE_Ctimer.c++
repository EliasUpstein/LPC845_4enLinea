//Función a colocar en la interrupción del Ctimer

#define NIVEL_ALTO 1
#define NIVEL_BAJO 0

/*
Se inicializa el ciclo desde el método show del objeto MatrizLed
La primera interrupción siempre ingresa a NIVEL_ALTO ya que los datos siempre inician en alto
Evalua el valor del bit actual para setear el timer, el toggle del pin se configura desde el registro
Se aumenta el bit, color, y/o led según corresponda y se cambia de estado para la siguiente interrución
En NIVEL_BAJO, ya está incrementado el bit por lo que ya se está leyendo el siguiente dato
El encendido de la salida se realiza dedes el toggle del registro. La siguiente interrupción la hará en NIVEL_AlTO

Cuando no tenga más leds en la matriz para recorrer, finaliza la interrupción del ctimer, inicializa la interrupciones
que estaban habilitadas antes del show, se asegura de apagar la salida.
*/
void MdE_Ctimer_Matriz (void)
{
    static volatile uint8_t estado = NIVEL_ALTO;
    static volatile uint8_t nbit = 0;
    static volatile uint8_t ncolor = 0;
    static volatile uint8_t nled = 0;

    switch (estado)
    {
    case NIVEL_ALTO:
        //Apagar salida (toggle de la interrupción)

        //Lectura del bit actual
        if(ncolor == 0)
            ((((Tablero.matriz[nled].r) >> nbit) & 0x1) == 0) ? establecerCTimer(24) : establecerCTimer(15);
        else if (ncolor == 1)
            ((((Tablero.matriz[nled].g) >> nbit) & 0x1) == 0) ? establecerCTimer(24) : establecerCTimer(15);
        else if (ncolor == 2)
            ((((Tablero.matriz[nled].b) >> nbit) & 0x1) == 0) ? establecerCTimer(24) : establecerCTimer(15);

        estado = NIVEL_BAJO;        //La próxima vez que ingrese voy al otro case

        //Si sigo recorriendo el mismo color del mismo led paso al siguiente bit, sino vuelvo al bit cero
        if(nbit < 7) 
            nbit++;
        else
        {
            nbit = 0;
            //Si sigo recorriendo el mismo led paso al siguiente color, sino vuelvo al color inicial
            if (ncolor < 2)
                ncolor++;
            else
            {
                ncolor = 0;
                //Si sigo recorriendo la matriz paso al siguiente led, sino finalizo el show
                if (nled < (Tablero.m_nleds - 1))
                    nled++;
                else
                {
                    nled = 0;
                    estado = NIVEL_ALTO;        //Seteo para el próximo show
                    //FINALIZAR (activación de interrupciones y apagado de salida)
                }
            }
        }
        break;
    case NIVEL_BAJO:
        //Encender salida (toggle de la interrupción)

        //Lectura del bit del siguiente dato (las variables se aumentaron en el case anterior)
        if(ncolor == 0)
            ((((Tablero.matriz[nled].r) >> nbit) & 0x1) == 0) ? establecerCTimer(15) : establecerCTimer(24);
        else if (ncolor == 1)
            ((((Tablero.matriz[nled].g) >> nbit) & 0x1) == 0) ? establecerCTimer(15) : establecerCTimer(24);
        else if (ncolor == 2)
            ((((Tablero.matriz[nled].b) >> nbit) & 0x1) == 0) ? establecerCTimer(15) : establecerCTimer(24);
        break;

        estado = NIVEL_ALTO;        //La próxima interrupción va a estar en alto
    default:
        //Evaluar qué hacer en caso de error
        break;
    }
}


//Escritura del registro contador del ctimer
void establecerCTimer(uint16_t valor)
{
    //establecer en el Ctimer el valor
}