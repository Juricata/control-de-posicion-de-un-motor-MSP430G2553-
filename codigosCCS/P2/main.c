#include <msp430.h>
#include "adc.h"
#include "lcd.h"
#include "segundos.h"
#include "motor.h"
#include "mensajes.h"

unsigned int gradosanterior = 0;
unsigned int grados = 0;
unsigned int pasosmotor = 0;

int main(void){
    WDTCTL = WDTPW | WDTHOLD;  // Detener watchdog
    adc_init();
    motor_init();
                motor_derecha(512,8);
                motor_izquierda(512,8);
}
/*
int main(void){
    WDTCTL = WDTPW | WDTHOLD;  // Detener watchdog
    adc_init();
    motor_init();

    __bis_SR_register(GIE);

    while (1){
        if (nuevaLectura){

            gradosanterior=grados;
            grados =lecturaADC; // grados del potenciometro verificar
            pasosmotor=(grados*512)/90;

            if(grados>gradosanterior){
                motor_derecha(pasosmotor,8);
            }else {
                motor_izquierda(pasosmotor,8);
            }

            nuevaLectura = 0;

        }
        __bis_SR_register(LPM0_bits);
    }
}
*/
