/*******************************************************************************************************************************//**
 *
 * @file		Timers.h
 * @brief		Clase para creacion de temporizadores
 * @date		4 may. 2022
 * @author		Ing. Marcelo Trujillo
 *
 **********************************************************************************************************************************/
#ifndef TIMER_H
#define TIMER_H

/***********************************************************************************************************************************
 *** INCLUDES GLOBALES
 **********************************************************************************************************************************/
#include "systick.h"
#include "tipos.h"

/***********************************************************************************************************************************
 *** DEFINES GLOBALES
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** MACROS GLOBALES
 **********************************************************************************************************************************/
/***********************************************************************************************************************************
 *** TIPO DE DATOS GLOBALES
 **********************************************************************************************************************************/
typedef void (*Timer_Handler)(void);

/***********************************************************************************************************************************
 *** IMPLANTACION DE LA CLASE
 **********************************************************************************************************************************/
class Timer : public Callback
{
	protected:
		volatile uint32_t 	m_TmrRun;
		volatile bool  		m_TmrEvent;
		void   				(* m_TmrHandler ) (void);
		volatile bool  		m_TmrStandBy ;
		volatile uint8_t  	m_TmrBase ;
	public:
		enum 		bases_t 			{ DEC , SEG , MIN , HOR };
		enum 		ticks_t 			{ DECIMAS = 100 , SEGUNDOS = 10 , MINUTOS  = 60, HORAS  = 60 };
		enum 		erroresTimers_t 	{ errorTimer , OKtimers };
		enum 		standby_t 			{ RUN , PAUSE };

		Timer( ) ;
		Timer(const Timer_Handler handler , const bases_t base );
		Timer( const bases_t base );

		void 		TimerStart( uint32_t time, const Timer_Handler handler , const bases_t base );
		void 		SetTimer(  uint32_t time );
		void 		GetTimer(  uint32_t &time) const;
		void 		StandByTimer( const standby_t accion );
		void 		TimerStop( void );
		void 		TimerStart( uint32_t time );
		void 		TmrEvent ( void );
		uint32_t	GetTmrRun( )  { return m_TmrRun; }
		void  		SetTmrEvent( ) { m_TmrEvent = 1; }
		void  		ClrTmrEvent( ) { m_TmrEvent = 0; }
		bool  		GetTmrEvent( ) { return m_TmrEvent ; }
		bool  		GetStandByTmr( ) { return m_TmrStandBy ;}
		void  		SetStandByTmr( uint8_t accion) { m_TmrStandBy = accion ;}
		void		SetTmrHandler( ) { m_TmrHandler( ); }

		Timer& 		operator=( uint32_t t );
		bool 		operator!( );
		bool 		operator==( uint32_t t );
		friend bool operator==( uint32_t t , Timer &T );
		explicit 	operator bool () ;
		void 		callback( void );

		virtual 	~Timer();
};

#endif /* TIMER_H */
