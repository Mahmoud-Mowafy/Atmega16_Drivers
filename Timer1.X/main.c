/*
 * File:   main.c
 * Author: Mahmoud
 *
 * Created on August 31, 2020, 1:37 AM
 */

#include"timer1.h"
#include <avr/io.h>
#include<avr/interrupt.h>
#include<util/delay.h>
            
int main(void) 
{
    /* Replace with your application cod*/
    DDRD |=(1<<5);          //make the OC1A as output.
    while(1)
    {
        timer1_init_pwm_mode(65);
        _delay_ms(1500);
       timer1_init_pwm_mode(187);
        _delay_ms(1500);
        timer1_init_pwm_mode(300);
        _delay_ms(1500);
    }
}

