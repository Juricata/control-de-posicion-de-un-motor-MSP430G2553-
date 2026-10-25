/*
 * mensajes.c
 *
 *  Created on: 04/10/2026
 *      Author: Julia y Dania
 */
//Funciones de la lcd para cada mensaje:
#include <msp430.h>
#include "segundos.h"
#include "LCD.h"

#define GUION 0x2D
#define CERO 0x30
#define UNO 0x31
#define DOS 0x32
#define TRES 0x33
#define CUATRO 0x34
#define CINCO 0x35
#define SEIS 0x36
#define SIETE 0x37
#define OCHO 0x38
#define NUEVE 0x39
#define DOSPUNTOS 0x3A
#define A 0x41
#define B 0x42
#define CE 0x43
#define E 0x45
#define I 0x49
#define L 0x4C
#define M 0x4D
#define R 0x52
#define VE 0x56
#define X 0x58
#define a 0x61
#define c 0x63
#define d 0x64
#define e 0x65
#define g 0x67
#define i 0x69
#define j 0x6A
#define l 0x6C
#define m 0x6D
#define n 0x6E
#define o 0x6F
#define p 0x70
#define r 0x72
#define s 0x73
#define t 0x74
#define v 0x76
#define x 0x78

void mensaje_grados(void){
    lcd_limpiar();
    lcd_letra(g);
    lcd_letra(r);
    lcd_letra(a);
    lcd_letra(d);
    lcd_letra(o);
    lcd_letra(s);
    lcd_letra(DOSPUNTOS);
    lcd_letra(0x20);
}

void mensaje_numeros(int numero){
    int centenas = numero/100;
    int decenas = (numero-centenas*100)/10;
    int unidades= numero - centenas*100 - decenas*10;
    centenas=convertir_numeros(centenas);
    decenas=convertir_numeros(decenas);
    unidades=convertir_numeros(unidades);

    lcd_comando(0x89);
    lcd_letra(centenas);
    lcd_letra(decenas);
    lcd_letra(unidades);
}

int convertir_numeros(int numero){
    switch(numero){
    case 0:
        return CERO;
    case 1:
        return UNO;
    case 2:
        return DOS;
    case 3:
        return TRES;
    case 4:
        return CUATRO;
    case 5:
        return CINCO;
    case 6:
        return SEIS;
    case 7:
        return SIETE;
    case 8:
        return OCHO;
    default:
        return NUEVE;
    }
}

void mensaje_encendido(void){
    lcd_limpiar();
    lcd_letra(0x20);
    lcd_letra(B);
    lcd_letra(i);
    lcd_letra(e);
    lcd_letra(n);
    lcd_letra(v);
    lcd_letra(e);
    lcd_letra(n);
    lcd_letra(i);
    lcd_letra(d);
    lcd_letra(o);
    lcd_letra(DOSPUNTOS);

    lcd_comando(0xC0);
    lcd_letra(UNO);
    lcd_letra(GUION);
    lcd_letra(R);
    lcd_letra(M);
    lcd_letra(0x20);
    lcd_letra(DOS);
    lcd_letra(GUION);
    lcd_letra(L);
    lcd_letra(VE);
    lcd_letra(0x20);
    lcd_letra(TRES);
    lcd_letra(GUION);
    lcd_letra(E);
    lcd_letra(X);

    espera_init(1);
    espera(5);
    lcd_limpiar();

}

void mensaje_apagado(void){
    lcd_limpiar();
    lcd_letra(0x20);
    lcd_letra(0x20);
    lcd_letra(A);
    lcd_letra(p);
    lcd_letra(a);
    lcd_letra(g);
    lcd_letra(a);
    lcd_letra(d);
    lcd_letra(a);

    espera_init(1);
    espera(5);
    lcd_limpiar();
}

void mensaje_alto(void){
    lcd_limpiar();
    lcd_letra(0x20);
    lcd_letra(0x20);
    lcd_letra(VE);
    lcd_letra(e);
    lcd_letra(l);
    lcd_letra(DOSPUNTOS);
    lcd_letra(0x20);
    lcd_letra(A);
    lcd_letra(l);
    lcd_letra(t);
    lcd_letra(a);

    espera_init(1);
    espera(5);
    lcd_limpiar();
}

void mensaje_bajo(void){
    lcd_limpiar();
    lcd_letra(0x20);
    lcd_letra(0x20);
    lcd_letra(VE);
    lcd_letra(e);
    lcd_letra(l);
    lcd_letra(DOSPUNTOS);
    lcd_letra(0x20);
    lcd_letra(B);
    lcd_letra(a);
    lcd_letra(j);
    lcd_letra(a);

    espera_init(1);
    espera(5);
    lcd_limpiar();
}

void mensaje_remojado(void){
    lcd_limpiar();
    lcd_letra(0x20);
    lcd_letra(0x20);
    lcd_letra(I);
    lcd_letra(n);
    lcd_letra(i);
    lcd_letra(c);
    lcd_letra(i);
    lcd_letra(a);
    lcd_letra(n);
    lcd_letra(d);
    lcd_letra(o);
    lcd_letra(DOSPUNTOS);

    lcd_comando(0xC0);
    lcd_letra(R);
    lcd_letra(e);
    lcd_letra(m);
    lcd_letra(o);
    lcd_letra(j);
    lcd_letra(a);
    lcd_letra(d);
    lcd_letra(o);

    espera_init(1);
    espera(5);
    lcd_limpiar();
}

void mensaje_lavado(void){
    lcd_limpiar();
    lcd_letra(0x20);
    lcd_letra(0x20);
    lcd_letra(I);
    lcd_letra(n);
    lcd_letra(i);
    lcd_letra(c);
    lcd_letra(i);
    lcd_letra(a);
    lcd_letra(n);
    lcd_letra(d);
    lcd_letra(o);
    lcd_letra(DOSPUNTOS);

    lcd_comando(0xC0);
    lcd_letra(L);
    lcd_letra(a);
    lcd_letra(v);
    lcd_letra(a);
    lcd_letra(d);
    lcd_letra(o);

    espera_init(1);
    espera(5);
    lcd_limpiar();
}

void mensaje_exprimido(void){
    lcd_limpiar();
    lcd_letra(0x20);
    lcd_letra(0x20);
    lcd_letra(I);
    lcd_letra(n);
    lcd_letra(i);
    lcd_letra(c);
    lcd_letra(i);
    lcd_letra(a);
    lcd_letra(n);
    lcd_letra(d);
    lcd_letra(o);
    lcd_letra(DOSPUNTOS);

    lcd_comando(0xC0);
    lcd_letra(E);
    lcd_letra(x);
    lcd_letra(p);
    lcd_letra(r);
    lcd_letra(i);
    lcd_letra(m);
    lcd_letra(i);
    lcd_letra(d);
    lcd_letra(o);


    espera_init(1);
    espera(5);
    lcd_limpiar();
}

void mensaje_final_ciclo(void){
    lcd_limpiar();
    lcd_letra(0x20);
    lcd_letra(0x20);
    lcd_letra(CE);
    lcd_letra(i);
    lcd_letra(c);
    lcd_letra(l);
    lcd_letra(o);
    lcd_letra(0x20);
    lcd_letra(t);
    lcd_letra(e);
    lcd_letra(r);
    lcd_letra(m);
    lcd_letra(i);
    lcd_letra(n);
    lcd_letra(a);
    lcd_letra(d);
    lcd_letra(o);

    espera_init(1);
    espera(5);
    lcd_limpiar();
}




