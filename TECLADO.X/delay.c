/*
 * File:   delay.c
 * Author: 20185561
 *
 * Created on 3 de Fevereiro de 2021, 17:47
 */



#include <xc.h>
#include "delay.h"

void delay (unsigned int t)
{
    while( t )
    {
        --t;
        __delay_ms(1);
    }
}