/*
 * File:   main.c
 * Author: Mahmoud
 *
 * Created on October 24, 2020, 4:05 PM
 */


#include <avr/io.h>
#include <util/delay.h>
#include"UART.h"
#include"keypad.h"
#define F_CPU                      1000000UL
int main(void) {
    /* Replace with your application code */
    UART_init();
    while (1) 
    {
      UART_sendByte(KEYPAD_getPressedKey()); 
      _delay_ms(500);
    }
}
