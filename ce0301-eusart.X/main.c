/*
 * File:   main.c
 * Author: curtaeletronica
 *
 * Created on 02 de Outubro de 2019, 20:22
 * 
 * IDE:         MPLAB X IDE v3.15
 * Compiler:    XC8 v1.45
 * OS:          Deepin 15.11 X86_64
 * Kernel:      4.15.0-30deepin-generic
 * 
 * Objetivo: 
 *      Apresentar mensagens em display LCD atrav�s de barramento de 8 vias.
 * 
 * Pinos    |n�     |Conex�o
 *  VDD     |11,32  | Alimenta��o (Vcc/+5V)
 *  VSS     |12,31  | Alimenta��o (GND/0V)
 * 
*/

//***************** Bibliotecas
#include <xc.h>
#include "config.h"
#include "lcd4bitBus.h"
#include "keyboard.h"
#include "eusart.h"


//***************** Programa Principal
void main(void)
{
    unsigned char vetor[2] = " ";
    initLCD();
    initKeyboard();
    initEUSART();
    
    lcd(0,0, "Curta Eletronica");
    
    while( 1 )                      // La�o de repeti��o infinita.
    {
        keyboardScan();
        
        if( currentKey() && !previousKey() )
        {
            vetor[0] = currentKey();
            lcd(0,1, vetor );
        }

    }
    return;
}
//***************** Fim do Programa Principal
