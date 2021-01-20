/*
 * File:   main.c
 * Author: Mahmoud
 *
 * Created on October 26, 2020, 6:08 PM
 */


#include <avr/io.h>
#include <util/delay.h>
#include"SPI.h"
int main(void) {
    /* Replace with your application code */
    SPI_initMaster();
    _delay_ms(50);
    SPI_sendString("I am Micro 1#");
    while (1) 
    {  
    }
}
