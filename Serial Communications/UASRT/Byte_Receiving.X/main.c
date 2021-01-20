/*
 * File:   main.c
 * Author: Mahmoud
 *
 * Created on October 1, 2020, 1:30 AM
 */


#include <avr/io.h>
#include"UART.h"

int main(void) {
    /* Replace with your application code */
    //uint8 data;
    DDRA |=(1<<0);
    PORTA |=(1<<0);
   uint8 str[20];
    UART_init();
    while (1) 
    {
        //data = UART_receiveByte();
        //UART_sendByte(data);
        UART_receiveString(str);
        UART_sendString(str);
    }
}
