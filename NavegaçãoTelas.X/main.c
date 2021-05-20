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
    char estado_senha = 0;
    char senha[4] = { 0, 0, 0, 0};
    char senha_correta[4] =  {'2', '0', '0', '3'};
    char cont_senha = 0;
    char senhaOK = 1;
    
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
                    dispLCD(0,0,"Oh, OI        ");
                    delay( 3000 );
                    estado = 10;
                    break;
            case 10:
                    dispLCD(0,0,"Senai...      ");
                    dispLCD(1,0,"1:Download C:cdg");
                    if ( tecla == '1' )
                        estado = 20;
                    if ( tecla == 'C' )
                        estado = 30;
                    break;
            case 20:
                    dispLCD(0,0,"DOWNLOAD...     ");
                    dispLCD(1,0,"                ");
                    if ( tecla == '*' )
                        estado = 10;
                    break;
            case 30:
                    dispLCD(0,0,"SENHA:           ");
                    dispLCD(1,0,"                 ");
                    estado = 32;
                    break;
            case 32:
                   dispLCD(0,7, senha );
                    if ( estado_senha == 100 )
                       estado = 39;
                    if ( estado_senha == 90 )
                       estado = 38;
                    break;
            case 38:
                    dispLCD(0,0,"Senha Incorreta!");
                    if ( tecla == '*')
                        estado = 10;
                    break;
            case 39:
                    dispLCD(0,0,"Senha Correta!  ");
                    if ( tecla == '*')
                        estado = 10;
                    break;
 
        } 
        
        switch ( estado_senha )
        {
            case 0:
                if ( estado == 30 )
                    estado_senha = 10;
                break;
            case 10:
                cont_senha = 0;
                senha[0] = 0;
                senha[1] = 0;
                senha[2] = 0;
                senha[3] = 0;
                senhaOK = 1;
                estado_senha = 12;
                break;
            case 12:
                if ( tecla >= '0' && tecla <= '9')
                    estado_senha = 14;
                break;
            case 14:
                senha[cont_senha] = tecla;
                estado_senha = 15;
                break;
            case 15:
                if( !tecla )
                    estado_senha = 16;
                break;
            case 16:
                ++cont_senha;
                if ( cont_senha < 4 )
                    estado_senha = 12;
                else
                    estado_senha = 20;
                break;
            case 20:
                senhaOK = 1;
                for ( cont_senha = 0; cont_senha<4; cont_senha++ )
                {
                    if ( senhaOK )
                        senhaOK = senha[ cont_senha ] == senha_correta[ cont_senha ];
                }    
                if ( senhaOK )
                    estado_senha = 100;
                else
                    estado_senha = 90;
                break;
            case 90:
                if ( estado == 38 )
                    estado_senha = 0;
                break;
            case 100:
                if ( estado == 39 )
                    estado_senha = 0;
                break;
        }        
    }       
}


