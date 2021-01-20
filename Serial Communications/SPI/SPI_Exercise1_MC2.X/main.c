/*
 * File:   main.c
 * Author: Mahmoud
 *
 * Created on October 26, 2020, 6:08 PM
 */


#include <avr/io.h>
#include"SPI.h"
#define SWITCH_PRESSED                              1
#define SWITCH_NOT_PRESSED                          0
int main(void) {
    /* Replace with your application code */
    SPI_initMaster();
    DDRA &=~(1<<0); 
    while (1) 
    { 
      if(IS_BIT_SET(PINA,0))
         SPI_sendByte(SWITCH_PRESSED); 
      else
         SPI_sendByte(SWITCH_NOT_PRESSED);  
    }
}
