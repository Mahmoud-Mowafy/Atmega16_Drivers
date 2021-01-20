/*
 * File:   timer1.c
 * Author: Mahmoud
 *
 * Created on August 30, 2020, 2:56 PM
 */


#include"timer1.h"

void timer1_init_pwm_mode(uint16 out_compare )
{
    /* timer counter register initial value =0*/
    TCNT1 = 0x00; 
    ICR1 = 2499;
    /* WaveForme generation in this case the TOP value is not fixed(0:65535) it is mapped
     in the OCR1 , and can be changed at any time because the OCR1 is double buffered
     */
    TCCR1A |=(1<<WGM11);
    TCCR1B |=(1<<WGM12)|(1<<WGM13);
    /* Load the OCR1A by the TOP value which is the required compare value at which 
     * the timer will be cleared
     */
    OCR1A = out_compare;
    /* Clear the OC1 pin that used as output in fast_PWM mode when match occurs
     * Non-Inverting fast PWM
     */
    TCCR1A |=(1<<COM1A1);
    TCCR1A &=~(1<<COM1A0);
    /* Reset the Force output compare pin , for PWM mode*/
    TCCR1A &=~(1<<FOC1A);    
    /* Select the required prescaler*/
            TCCR1B |=(1<<CS10)|(1<<CS11);
}

