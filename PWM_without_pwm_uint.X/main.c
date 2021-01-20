/*
 * File:   main.c
 * Author: Mahmoud
 *
 * Created on August 29, 2020, 2:09 PM
 */

#include"timer1.h"
#include <avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>


ISR(TIMER1_COMPA_vect)
{
    PWM_PIN_OUT |=(1<<PWM_PIN);
}

ISR(TIMER1_COMPB_vect)
{
    PWM_PIN_OUT &=~(1<<PWM_PIN);
}

int main(void) {
    /* Replace with your application code */
    SREG |=(1<<7);
    PWM_PIN_DIR |=(1<<PWM_PIN);
    uint8 duty_cycle;
    while (1) 
    {
        for(duty_cycle = 0 ;duty_cycle < 100;duty_cycle++)
        {
            timer1_init_ctc_mode(duty_cycle);
            _delay_ms(500);
        }
         for(duty_cycle = 99 ;duty_cycle > 0; duty_cycle--)
        {
            timer1_init_ctc_mode(duty_cycle);
            _delay_ms(500);
        }
    }
}
