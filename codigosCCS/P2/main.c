#include <msp430.h>
#include "adc.h"
#include "lcd.h"
#include "segundos.h"
#include "motor.h"
#include "mensajes.h"

unsigned int grados = 0;
unsigned int pasosmotor = 0;
unsigned int posicion_actual_motor = 0;


int main(void){
    WDTCTL = WDTPW | WDTHOLD;  // Detener watchdog
    unsigned int pasos_objetivo = 0;//mot
    //ADC y Motor a pasos
    adc_init();
    motor_init();
    lcd_init();
    mensaje_grados(); // Mensaje inicial de grados

    __bis_SR_register(GIE);


    while (1){
        if (nuevaLectura){
            nuevaLectura = 0; //limpiar la bandera inmediatamente

            grados = (lecturaADC * 360L) / 1023L; // Guardamos la lectura del potenciómetro

            // Mapear el valor del potenciómetro (0 a 1023) a los pasos del motor 512
            pasos_objetivo = (lecturaADC * 512L) / 1023L;// ADC de la MSP430 = 10 bits (2^10 = 1024)
            int diferencia = (int)pasos_objetivo - (int)posicion_actual_motor;

            // Mensaje lcd de grados
            mensaje_numeros(grados);
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
