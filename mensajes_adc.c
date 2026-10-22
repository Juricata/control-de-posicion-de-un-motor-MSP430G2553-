/*
 * mensajes_adc.c
 * Funciones de texto basadas en los valores del ADC para la LCD
 */

#include <msp430.h>
#include "LCD.h"
#include "mensajes_adc.h"

void mostrar_angulo_adc(unsigned int valor_adc) {
    lcd_limpiar();
    
    //  potenciómetro en 4 rangos para mostrar en la pantalla
    if (valor_adc < 250) {
        lcd_letra('0');
        lcd_letra(' ');
        lcd_letra('G');
        lcd_letra('R');
        lcd_letra('A');
        lcd_letra('D');
        lcd_letra('O');
        lcd_letra('S');
    } 
    else if (valor_adc >= 250 && valor_adc < 500) {
        lcd_letra('9');
        lcd_letra('0');
        lcd_letra(' ');
        lcd_letra('G');
        lcd_letra('R');
        lcd_letra('A');
        lcd_letra('D');
        lcd_letra('O');
        lcd_letra('S');
    } 
    else if (valor_adc >= 500 && valor_adc < 750) {
        lcd_letra('1');
        lcd_letra('8');
        lcd_letra('0');
        lcd_letra(' ');
        lcd_letra('G');
        lcd_letra('R');
        lcd_letra('A');
        lcd_letra('D');
    } 
    else {
        lcd_letra('3');
        lcd_letra('6');
        lcd_letra('0');
        lcd_letra(' ');
        lcd_letra('M');
        lcd_letra('A');
        lcd_letra('X');
    }
}
