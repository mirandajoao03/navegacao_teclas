/*
 * File:   main.c
 * Author: 20185561
 *
 * Created on 3 de Fevereiro de 2021, 14:58
 */

#include <xc.h>
#include "config.h"
#include "delay.h"
#include "contatores.h"
#include "botoes.h"

void main ( void )
{
    int estado = 0;
    int t;
    
    while ( 1 )
    {    
        switch ( estado )
        {
            case 0:
                    estado = 1;
                    break;
            case 1:
                    contatores_init();
                    botoes_init();
                    estado = 2;
                    break;
            case 2:
                    if ( S1() == 1 && K1status() == 0 )
                        estado = 3;
                    break;
            case 3:
                    K1(1);
                    K2(1);
                    K3(0);
                    estado = 4;
                    break;    
            case 4:
                    t = 3000;
                    estado = 5;    
                    break;    
            case 5:
                    delay(1);
                    --t;
                    if (t <= 0 )
                    estado = 6;
                    break;
            case 6:
                    K1(1);
                    K2(0);
                    K3(1);
                    estado = 7;
                    break;
            case 7:
                if ( S0() == 1 )
                    estado = 8;
                    break;
            case 8:
                    K1(0);
                    K2(0);
                    K3(0);
                    estado = 2;
                    break;
        }        

    }    
}


