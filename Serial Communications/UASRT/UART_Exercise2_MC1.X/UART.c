/*
 * File:   UART.c
 * Author: Mahmoud
 *
 * Created on September 30, 2020, 5:29 PM
 */


#include <avr/io.h>
#include"UART.h"


void UART_init()
{
    /*set the desired Baud Rate*/
	UBRRH = BAUD_PRESCALE>>8;
	UBRRL = BAUD_PRESCALE;
    /*set the desired Data Frame*/
    UCSRC |= (1<<URSEL);            /*to use the UCSRC register*/
    UCSRC |=(1<<UCSZ0)|(1<<UCSZ1);
    /*Enable Transmitter and Receiver*/
    UCSRB |=(1<<TXEN)|(1<<RXEN);
    /*use the double data rate transmission*/
    UCSRA |=(1<<U2X);
}

void UART_sendByte(const uint8 data)
{
    /*check the UART Data empty flag */
    while(BIT_IS_CLEAR(UCSRA,UDRE));  
    /*load the UDR with the required data*/
    UDR = data;
}

uint8 UART_receiveByte(void)
{
    /*check the RX complete flag */
    while(BIT_IS_CLEAR(UCSRA,RXC));
    /*return the content of UDR */
    return UDR ;  
}

void UART_sendString(const uint8 *str)
{
    while(*str !='\0')
    {
        UART_sendByte(*str);
        str++;
    }
}

void UART_receiveString(uint8 *str)
{
    uint8 i=0;
    str[i] = UART_receiveByte();
    while(str[i] != '#')
    {
        i++;
        str[i] = UART_receiveByte();
    }
    str[i] = '\0';
}