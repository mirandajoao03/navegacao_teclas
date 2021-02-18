/*
 * File:   botoes.c
 * Author: 20185561
 *
 * Created on 3 de Fevereiro de 2021, 17:47
 */


#include <xc.h>

void botoes_init ( void )
{
    TRISDbits.TRISD0 = 1;
    TRISDbits.TRISD1 = 1;
}

int S1 ( void )
{
    return ( PORTDbits.RD1 );
}

int S0 ( void )
{
    return ( PORTDbits.RD0 );
}
