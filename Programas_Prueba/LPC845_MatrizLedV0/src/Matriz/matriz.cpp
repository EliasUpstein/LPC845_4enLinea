#include "matriz.h"

//Configuración del pin de salida
gpio out_matriz( gpio::port1 , 0 , gpio::pushpull ,  gpio::output , gpio::high );

// Varibles (atributos del objeto)
uint32_t nleds;
//uint32_t nBytes;
//uint32_t m_nBits;

Led_WS2812B *matriz;        //Se trabaja como vector recorriendo a lo largo, NO como matriz fila-columna


//Implementación de funciones

//bool begin(void){
//	if (m_error == ok)
//	    return ClrPin();
//	else
//		return m_error;
//}

//Previo a constructor de objeto
void MatrizLed(int leds)
{
	nleds = leds;
	matriz = new (Led_WS2812B[nleds]);
}

void setLed(uint32_t led, Led_WS2812B color)
{
	if (led < nleds && led >= 0)
	        matriz[led] = color;
}

void setLeds(uint32_t first, uint32_t cant, Led_WS2812B color)
{
	uint16_t end;

	if (first >= nleds || first < 0)
		return;

	// Si se recibe 0, rellena hasta el final, sino chequea no excederse
	if (cant == 0)
		end = nleds;
	else
	{
		end = first + cant;
		if (end > nleds)
			end = nleds;
	}

	for (uint32_t i = first; i < end; i++)
	{
		setLed(i, color);
	}
}

void setAllLeds(Led_WS2812B color)
{
	setLeds(0, 0, color);
}

void clear(void)
{
	//Limpia componente a componente de cada color de cada led
	for (uint32_t i = 0; i < nleds; i++)
	{
		matriz[i].r = 0;
		matriz[i].g = 0;
		matriz[i].b = 0;
	}
	//Evaluar usar setAllLeds con color nulo
}

Led_WS2812B Color(uint8_t r, uint8_t g, uint8_t b)
{
	Led_WS2812B led_aux;

	led_aux.r = r;
	led_aux.g = g;
	led_aux.b = b;

	return led_aux;
}

//////////////////////////Complicado

/* Tiempo de comunicación promedio:

1,25us (por bit) * 8 (por byte) * 3 (por led) = 30us por led
30us * 64 (leds de nuestra matriz) = 1920us = 1.92 ms => aprox 2ms	*/
void show(void)
{
	pauseInterrupt(true);		//Detener las interrupciones ajenas a la matriz (se reactivan en la rutina de interrupcion cuando ingresa por ultima vez)

	//Configurar valor para el primer bit (tiempo 0, primer interrupción)
	(((matriz[0].r >> 0) & 0x1) == 0) ? setMatch0CTimer(TIEMPO_CORTO) : setMatch0CTimer(TIEMPO_LARGO);

	out_matriz.SetPin();		//Activar salida

	enableCTimer(true);			//Habilitar interrupción del CTIMER
}

/*
	Se inicializa el ciclo desde el método show del objeto MatrizLed
	La primera interrupción siempre ingresa a NIVEL_ALTO ya que los datos siempre inician en alto
	Evalua el valor del bit actual para setear el timer, el toggle del pin se configura desde el registro
	Se aumenta el bit, color, y/o led según corresponda y se cambia de estado para la siguiente interrución
	En NIVEL_BAJO, ya está incrementado el bit por lo que ya se está leyendo el siguiente dato
	El encendido de la salida se realiza desde el toggle del registro. La siguiente interrupción la hará en NIVEL_AlTO

	Cuando no tenga más leds en la matriz para recorrer, finaliza la interrupción del ctimer, inicializa la interrupciones
	que estaban habilitadas antes del show, se asegura de apagar la salida.
*/
void MdE_Ctimer_Matriz (void)
{
    static volatile uint8_t estado = NIVEL_ALTO;
    static volatile uint8_t nbit = 0;
    static volatile uint8_t ncolor = 0;
    static volatile uint8_t nled = 0;
    static volatile uint8_t bit_actual_bajo;

    //Lectura del bit actual (guardo color, desplazo para sellecionar el bit, y evaluo estado
    if(ncolor == 0)
    	bit_actual_bajo = matriz[nled].r;
	else if (ncolor == 1)
		bit_actual_bajo = matriz[nled].g;
	else if (ncolor == 2)
		bit_actual_bajo = matriz[nled].b;
	else 	//error
		bit_actual_bajo = false;

	bit_actual_bajo = (((bit_actual_bajo >> nbit) & 0x1) == 0);

    switch (estado)
    {
    case NIVEL_ALTO:
        //Apagar salida (toggle de la interrupción)

        //Setea el match para el próximo valor
    	bit_actual_bajo ? setMatch0CTimer(TIEMPO_LARGO) : setMatch0CTimer(TIEMPO_CORTO);

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
                if (nled < (nleds - 1))
                    nled++;
                else
                {
                    nled = 0;
                    estado = FINALIZAR_CTIMER;        //La próxima interrupción será la última
                }
            }
        }
        break;
    case NIVEL_BAJO:
        //Encender salida (toggle de la interrupción)

    	//Setea el match para el próximo valor (las variables se aumentaron en el case anterior)
    	bit_actual_bajo ? setMatch0CTimer(TIEMPO_CORTO) : setMatch0CTimer(TIEMPO_LARGO);

        estado = NIVEL_ALTO;        //La próxima interrupción va a estar en alto
        break;
    case FINALIZAR_CTIMER:
    	//Activación de interrupciones (previas) y apagado de salida
    	enableCTimer(false);
    	pauseInterrupt(false);
    	out_matriz.ClrPin();

    	estado = NIVEL_ALTO;        //Seteo para el próximo show (las variables nbit, ncolor y nled ya deberían estar en 0)
    	break;
    default:
        //Evaluar qué hacer en caso de error
        break;
    }
}


////////////////BAJO NIVEL

//Escritura del registro contador del ctimer	 (debería ir a parar a la carpeta CTimer)
void setMatch0CTimer(uint32_t valor)
{
	CTIMER0->MR[0] = valor;						//Actualiza el valor del match
}

//Pausa todas las interrupciones desde el NVIC
void pauseInterrupt(bool flag)
{
	static uint32_t interrupt_state;

	//Si se quiere pausar las interrupciones
	if(flag)
	{
		interrupt_state = NVIC->ISER[0];		//Guarda en una variable el estado que tenían al momento del llamado

		NVIC->ICER[0] = 0xFFFFFFFF;				//Apaga todas las interrupciones
	}
	else
		NVIC->ISER[0] |= interrupt_state;		//Reactivación de las interrupciones anteriores
}

void enableCTimer(bool flag)
{
	if(flag)
		NVIC->ISER[0] |= ISE_CT32B0;			// Habilita interrupción de CTIMER0
	else
		NVIC->ICER[0] |= ISE_CT32B0;			// Deshabilita interrupción de CTIMER0	//Requiere reinicio la deshabilitación (TCR -> CRST)?

	CTIMER0->TCR |= CTIMER_TCR_CEN(flag);		// Habilita/Deshabilita (según el flag) contador de timer
}
