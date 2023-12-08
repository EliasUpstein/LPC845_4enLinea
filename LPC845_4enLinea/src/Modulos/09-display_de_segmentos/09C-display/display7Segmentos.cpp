/*******************************************************************************************************************************//**
 *
 * @file		display.cpp
 * @brief		Descripcion del modulo
 * @date		26 jul. 2022
 * @author		Ing. Marcelo Trujillo
 *
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** INCLUDES
 **********************************************************************************************************************************/
#include "display7Segmentos.h"

/***********************************************************************************************************************************
 *** DEFINES PRIVADOS AL MODULO
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** MACROS PRIVADAS AL MODULO
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** TIPOS DE DATOS PRIVADOS AL MODULO
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** TABLAS PRIVADAS AL MODULO
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** VARIABLES GLOBALES PUBLICAS
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** VARIABLES GLOBALES PRIVADAS AL MODULO
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** IMPLEMENTACION DE LOS METODODS DE LA CLASE
 **********************************************************************************************************************************/
Display7Segmentos::Display7Segmentos( vector <gruposdedigitos * > g ,Segmentos * s , Barrido * b , const uint8_t *PosicionRelativa,const Digito::codigo_t  sistema):
			m_grupos ( g ) , m_seg ( s ) , m_dig ( b ) , m_PosicionRelativa(PosicionRelativa),m_sistema(sistema)
{
	m_ticks = 1;

	m_maxdigitos = 0 ;

	for ( uint8_t j = 0 ; j < m_grupos.size() ; j++)
	{
		m_maxdigitos += m_grupos[j]->m_cantidad ;

		for ( uint8_t i = 0 ; i < m_grupos[ j ]->m_cantidad ; i++)
			m_bufferdisplay.push_back( new Digito( m_sistema , Digito::APAGAR ) ) ;
	}
	m_inx = 0;
	g_CallbackList.push_back( this );
}

Display7Segmentos::~Display7Segmentos() {
	// TODO Auto-generated destructor stub
}

void Display7Segmentos::callback ( )
{
	m_ticks--;
	if ( !m_ticks )
	{
		m_seg->SetSegmentos(Digito::APAGAR);
		m_ticks = 2;
		m_dig->SetDigito();
		m_seg->SetSegmentos( m_bufferdisplay[m_inx]->Get( ) );
		m_inx ++;
		m_inx %= m_maxdigitos;
	}
}

void Display7Segmentos::Set( uint32_t valor , uint8_t dsp )
{
	uint8_t aux[ m_maxdigitos ];

	for (uint8_t i = 0 ; i < m_grupos[ dsp ]->m_cantidad  ; i ++ , valor /= 10 )
		aux[ i ] = valor % 10 ;

	for (uint8_t i = 0 ; i < m_grupos[ dsp ]->m_cantidad  ; i ++ )
		m_bufferdisplay[ m_PosicionRelativa[i + m_grupos[ dsp ]->m_comienzo ]]->Set( aux[ i ] );
}

// /*
//  * funcion para hacer parpadear el Display
//  * Arbitrariamente definimos que si el bit 8 de dsp esta en 1 quiero parpadear, sino no.
//  * */
// void Display7Segmentos::Set( uint32_t valor , uint8_t dsp )
// {
// 	uint8_t aux[ m_maxdigitos ];

// 	if (!(dsp & 0x80)){	//si bit8 NO esta en 1.... operamos normalmente
// 		for (uint8_t i = 0 ; i < m_grupos[ dsp ]->m_cantidad  ; i ++ , valor /= 10 )
// 			aux[ i ] = valor % 10 ;
// 	}
// 	else{	//sino, APAGAMOS el display usando la combinación 0xFF (Digito::APAGAR) en el 4511
// //¡pero si APAGAMOS no parpadeamos!! El parpadeo lo produce el efecto de la variable flag en main
// 		dsp = dsp & 0x7F;
// 		for (uint8_t i = 0 ; i < m_grupos[ dsp ]->m_cantidad  ; i ++  )
// 				aux[ i ] = Digito::APAGAR ;
// 	}
// 	for (uint8_t i = 0 ; i < m_grupos[ dsp ]->m_cantidad  ; i ++ )
// 		m_bufferdisplay[ m_PosicionRelativa[i + m_grupos[ dsp ]->m_comienzo ]]->Set( aux[ i ] );
// }
