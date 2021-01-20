/*
 * File:   main.c
 * Author: Mahmoud
 *
 * Created on October 26, 2020, 6:08 PM
 */


#include <avr/io.h>
#include"SPI.h"
#include"lcd.h"                        
int main(void) {
    /* Replace with your application code */
    char string[20];
    uint8 i=0;
    LCD_init();
    SPI_initSlave();
    SPI_receiveString(string);
    while(string[i]!='\0')
    {
        LCD_displayChracter(string[i]);
        i++;
    }
    while (1) 
    { 
        
    }
}
