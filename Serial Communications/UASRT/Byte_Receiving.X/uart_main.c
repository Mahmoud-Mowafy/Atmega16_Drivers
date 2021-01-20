/*
 * File:   uart_main.c
 * Author: Mahmoud
 *
 * Created on October 2, 2020, 1:22 AM
 */

#define FCPU            1000000UL
#include <avr/io.h>
void URT_init()
{
    UBRRL =6;
    UCSRB |=(1<<TXEN);
    UCSRC |=(1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);
}
void UART_send(const unsigned char data)
{
    while(!(UCSRA & (1<<UDRE)));
    UDR = data;
}
int main(void) {
    /* Replace with your application code */
    UART_init();
    while (1)
    {
        UART_send('G');
    }
}
