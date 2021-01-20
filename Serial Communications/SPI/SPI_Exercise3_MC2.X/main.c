/*
 * File:   main.c
 * Author: Mahmoud
 *
 * Created on October 24, 2020, 4:05 PM
 */


#include <avr/io.h>
#include"SPI.h"
#include"lcd.h"
int main(void) {
    /* Replace with your application code */
    uint8 data;
    SPI_initSlave();
    LCD_init();
    while (1) 
    {
      data = SPI_receiveByte();
      if((data >=0) &&(data <=9))
          LCD_integerToString(data);
      else
          LCD_displayChracter(data);
    }
}
