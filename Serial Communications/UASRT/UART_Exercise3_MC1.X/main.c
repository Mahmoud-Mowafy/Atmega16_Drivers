/*
 * File:   main.c
 * Author: Mahmoud
 *
 * Created on October 23, 2020, 8:42 PM
 */


#include <avr/io.h>
#include"UART.h"
#define MC2_READY   0x10
int main(void) {
    /* Replace with your application code */
    UART_init();
    while(UART_receiveByte()!=MC2_READY)
    {}
    UART_sendString("I am Micro1#");
    while (1)
    {
    }
}
