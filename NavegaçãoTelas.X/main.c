/*
 * File:   main.c
 * Author: 20185561
 *
 * Created on 14 de Maio de 2021, 16:16
 */

#include "config.h"
#include <xc.h>
#include "LCD4vias.h"
#include "TECLADO.h"
#include "delay.h"

void main(void) 
{
    char estado = 0;
    char tecla = 0;
    Teclado_init();
    dispLCD_init();
    
    while( 1 )
    {
        tecla = Teclado();
        switch ( estado )
        {
            case 0:
                    estado = 1;
                    break;
            case 1:
                    dispLCD(0,0,"Oh, Boa Veinho  ");
                    delay( 3000 );
                    estado = 10;
                    break;
            case 10:
                    dispLCD(0,0,"OFC SIMAS TURBO ");
                    dispLCD(1,0,"1:Operacao C:cfg");
                    if ( tecla == '1' )
                        estado = 20;
                    if ( tecla == 'C' )
                        estado =100;
                    break;
            case 20:
                    dispLCD(0,0,"Operando...     ");
                    dispLCD(1,0,"                ");
                    if ( tecla == '*' )
                        estado = 10;
                    break;
            case 100:
                   dispLCD(0,0,"Carregando cfg...");
                   dispLCD(1,0,"                 ");
                   if ( tecla == '*' )
                       estado = 10;
                    break;
        }        
        
    }
        
}

