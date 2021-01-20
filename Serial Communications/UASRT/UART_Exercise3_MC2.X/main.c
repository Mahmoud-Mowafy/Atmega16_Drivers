/*
 * File:   main.c
 * Author: Mahmoud
 *
 * Created on October 23, 2020, 4:20 AM
 */


#include <avr/io.h>
#include"UART.h"
#include"lcd.h"
#define M2_READY   0x10
int main(void) {
    /* Replace with your application code */
    
    UART_init();
    LCD_init();
    char str[50];
    UART_sendByte(M2_READY);
    char i=0;
   /* char data;
    
    data = UART_receiveByte();
    LCD_displayChracter(data);*/
    UART_receiveString(str);
    while(str[i]!='\0')
    {
        LCD_displayChracter(str[i]);
        i++;
    }
    while (1) 
    {

    }
}
