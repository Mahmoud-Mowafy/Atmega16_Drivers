/*
 * File:   main.c
 * Author: Mahmoud
 *
 * Created on October 24, 2020, 12:35 PM
 */


#include <avr/io.h>
#include"lcd.h"
int main(void) {
    /* Replace with your application code */
    LCD_init();
    LCD_displayString("I am mahmoud");
    while (1)
    {
    }
}
