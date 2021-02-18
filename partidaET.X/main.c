/*
 * File:   main.c
 * Author: João Vitor M dos Santos
 *
 * Created on 29 de Janeiro de 2021, 14:48
 */


#include <xc.h>
#include "config.h"

#define LIGA              PORTDbits.RD1
#define DESLIGA           PORTDbits.RD0

#define BOTAO_DESLIGA     TRISDbits.TRISD0
#define BOTAO_LIGA        TRISDbits.TRISD1
#define K3                TRISDbits.TRISD5
#define K2                TRISDbits.TRISD6
#define K1                TRISDbits.TRISD7

#define SUA_MAE           PORTDbits.RD7
#define TERTO             PORTDbits.RD6
#define CARLAO            PORTDbits.RD5

#define HORA_DO_LANCHINHO  __delay_ms (2000)
#define PANINHO            __delay_ms ( 50 )

void main(void) 
{
    BOTAO_DESLIGA = 1;
    BOTAO_LIGA = 1;
    K3 = 0;
    K2 = 0;
    K1 = 0;
    
    SUA_MAE = 0;
    TERTO  = 0; 
    CARLAO  = 0;
    
    while ( 1 )
    {    
        if ( LIGA == 1 )
        {    
             SUA_MAE = 1;
             TERTO = 1;
             CARLAO = 0;
             HORA_DO_LANCHINHO;
             TERTO  = 0;
             PANINHO;
             CARLAO = 1;
        }     
             
        if ( DESLIGA == 1 )
        {    
             SUA_MAE = 0;
             TERTO  = 0;
             CARLAO = 0;
        }     
    }
}
