/*
 * File:   main.c
 * Author: Mahmoud
 *
 * Created on August 27, 2020, 11:50 PM
 */

#include"timer0.h"
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>



#define NUMBER_OF_OVERFLOW_PER_HLF_SEC     62
#define LED_PORT_DIR                       DDRA
#define LED_PORT_OUT                       PORTA
#define LED_PIN                             0
#define PWM 

#ifdef OVERFLOW
uint16 g_tick=0;

ISR(TIMER0_OVF_vect)
{
    g_tick++;
    
    if(g_tick==NUMBER_OF_OVERFLOW_PER_HLF_SEC)
    {
        LED_PORT_OUT ^=(1<<LED_PIN);
        g_tick=0;
    }
}
int main(void) {
    /* Replace with your application code */
    LED_PORT_DIR |=(1<<LED_PIN);                //define the LED pin as output
    LED_PORT_OUT &=~(1<<LED_PIN);               //output 0 at the LED pin to turn off.
    SREG |=(1<<7);                              //Enable the global interrupt enable bit.
    LED_PORT_OUT ^=(1<<LED_PIN);
    timer0_init_normal_mode(256);               //call the timer0_normal_mode function for initialization.
    while (1) 
    {
    }
}
#else

int main(void)
{
    SREG |=(1<<7);                              //Enable the global interrupt enable bit.
   // timer0_init_pwm_mode(200,8);
    uint8 i;
    
    while (1) 
    {
        timer0_init_pwm_mode(126,8);
        _delay_ms(500);
        /*for(i=15;i<255;i*=2)
        {
          timer0_init_pwm_mode(i,8); 
          //_delay_ms(500);
        }*/
    }
}

#endif
