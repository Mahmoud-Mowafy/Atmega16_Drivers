/*
 * File:   timer1.c
 * Author: Mahmoud
 *
 * Created on August 29, 2020, 3:10 PM
 */
#include"timer1.h"

void timer1_init_ctc_mode(uint8 out_compare_value)
{
   /*initiate the timer1 register*/
    TCNT1 = 0x00;
    /*Enable CTCA and CTCB interrupt*/
    TIMSK |=(1<<OCIE1A)|(1<<OCIE1B);
    /*Force output compare*/
    TCCR1A |=(1<<FOC1A) |(1<<FOC1B);
    /*CTC mode*/
    TCCR1A |=(1<<WGM12);
    /*no prescaller for higher resolution (F_pwm = F_clk / 2*N*(510+1))*/
    TCCR1B |=(1<<CS10);
    /*check on the compare value*/
    if(out_compare_value>100)
        out_compare_value=100;
    OCR1A = out_compare_value*100;
    OCR1B = 10000 - (out_compare_value*100);
}
