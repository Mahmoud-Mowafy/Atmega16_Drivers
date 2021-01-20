/*
 * File:   main.c
 * Author: Mahmoud
 *
 * Created on October 24, 2020, 4:11 PM
 */


#include <avr/io.h>
#include"lcd.h"
#include"UART.h"
int main(void) {
    /* Replace with your application code */
    UART_init();
    LCD_init();
    uint8 data;
    while (1) 
    {
        data = UART_receiveByte();
        if((data >=0) && (data<=9))
            LCD_integerToString(data);
        else
            LCD_displayChracter(data);
    }
}
