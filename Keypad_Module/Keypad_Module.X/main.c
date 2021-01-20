/*
 * File:   main.c
 * Author: Mahmoud
 *
 * Created on October 23, 2020, 2:38 AM
 */


#include <avr/io.h>
#include"keypad.h"
int main(void) {
    /* Replace with your application code */
    DDRB = 255;
    PORTB =0;
    while (1) {
        PORTB = KEYPAD_getPressedKey();
    }
}
