/*
 * File:   main.c
 * Author: Mahmoud
 *
 * Created on October 26, 2020, 6:08 PM
 */


#include <avr/io.h>
#include"SPI.h"
#define LED_PIN                              1
int main(void) {
    /* Replace with your application code */
    SPI_initSlave();
    DDRA |=(1<<LED_PIN); 
    while (1) 
    { 
      if(SPI_receiveByte())
        PORTA |=(1<<LED_PIN); 
      else
        PORTA &=~(1<<LED_PIN);
    }
}
