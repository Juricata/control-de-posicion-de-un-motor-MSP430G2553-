#include <msp430.h>
#include "adc.h"
#include "lcd.h"
#include "segundos.h"
#include "motor.h"
#include "mensajes.h"

unsigned int gradosanterior = 0;
unsigned int grados = 0; 
unsigned int pasosmotor = 0;
unsigned int posicion_actual_motor = 0;


int main(void){
    WDTCTL = WDTPW | WDTHOLD;  // Detener watchdog
    lcd_init();
    mensaje_grados();

    int i;//lcd
    unsigned int pasos_objetivo = 0;//mot


    for(i=100;i>=70;i-=5){
        mensaje_numeros(i);
        espera_init(1);
        espera(1);
    }
    //ADC y Motor a pasos
    adc_init();
    motor_init();
    espera_init(2);

    __bis_SR_register(GIE);


    while (1){
        if (nuevaLectura){
            nuevaLectura = 0; //limpiar la bandera inmediatamente

            gradosanterior = grados;
            grados = lecturaADC; // Guardamos la lectura del potenciómetro

            // Mapear el valor del potenciómetro (0 a 1023) a los pasos del motor 512
            pasos_objetivo = (grados * 512L) / 1023L;// ADC de la MSP430 = 10 bits (2^10 = 1024)
            int diferencia = (int)pasos_objetivo - (int)posicion_actual_motor;

            // 6 pasos para el ruido del potenciómetro
            // zona muerta: se ignoran variaciones menores a 6 pasos
            // para evitar que el ruido eléctrico haga vibrar el motor
            if (diferencia > 6) {
                pasosmotor = diferencia;
                motor_derecha(pasosmotor, 8);
                posicion_actual_motor += pasosmotor;
            }
            else if (diferencia < -6) {
                pasosmotor = -diferencia;
                motor_izquierda(pasosmotor, 8);
                posicion_actual_motor -= pasosmotor;
            }
        }
    }
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



int main(void){
    WDTCTL = WDTPW | WDTHOLD;  // Detener watchdog
    adc_init();
    motor_init();
    espera_init(2);

    while(1){
        motor_derecha(512, 8);  // Debe dar una vuelta completa a la derecha
        espera(2);              // Espera 2 segundos
        motor_izquierda(512, 8); // Debe regresar a la izquierda
        espera(2);              // Espera 2 segundos
    }
}
*/

