/*
 * File:   main.c
 * Author: Mahmoud
 *
 * Created on October 23, 2020, 4:20 AM
 */


#include <avr/io.h>
#include"UART.h"
int main(void) {
    /* Replace with your application code */
    UART_init();
    while (1) 
    {
       UART_sendString("I am Micro 1#");
    }
}
