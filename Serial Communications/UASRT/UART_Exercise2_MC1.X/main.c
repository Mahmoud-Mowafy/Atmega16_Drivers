/*
 * File:   Control a 8 LEDs using Keypad and UART
 * Author: Mahmoud
 *
 * Created on October 23, 2020, 4:08 AM
 */


#include <avr/io.h>
#include"UART.h"
#include"keypad.h"
int main(void) {
    /* Replace with your application code */
    UART_init();
    while (1)
    {
      UART_sendByte(KEYPAD_getPressedKey());  
    }
}
