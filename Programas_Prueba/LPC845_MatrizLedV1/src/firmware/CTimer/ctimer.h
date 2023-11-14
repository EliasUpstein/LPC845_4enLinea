#ifndef CTIMER_H_
#define CTIMER_H_

void inicializarCtimer(void);

/***********************************************************************************************************************************
 *** COMPATIBILIDAD CON C PARA CTIMER0_IRQHandler PROPIA
 **********************************************************************************************************************************/
#if defined (__cplusplus)
	extern "C" {
	void CTIMER0_IRQHandler(void);
	}
#endif

#endif /* CTIMER_H_ */
