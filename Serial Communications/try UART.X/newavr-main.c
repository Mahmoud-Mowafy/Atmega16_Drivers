/*
 * File:   uart_main.c
 * Author: Mahmoud
 *
 * Created on October 2, 2020, 1:22 AM
 */

#define FCPU            1000000UL
#include <avr/io.h>
/*void UART_init()
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
//    /* Replace with your application code */

  
/*  UART_init();
    unsigned char str[]="Hello,Bossa";
    unsigned char i=0;
    while (1)
    {
        while(str[i]!='\0')
        {
            UART_send(str[i++]);
        }
        i=0;
    }
}
*/

#define BAUD 9600
#define MYUBRR FCPU/16/BAUD-1

void USART_Transmit( unsigned char data )
{
/* Wait for empty transmit buffer */
while ( !( UCSRA & (1<<UDRE)) )
;
/* Put data into buffer, sends the data */
UDR = data;
}

void USART_Init( unsigned int ubrr)
{
/* Set baud rate */
/*UBRRH = (unsigned char)(ubrr>>8);
UBRRL = (unsigned char)ubrr;*/
    UBRRH = 0;
UBRRL = 6;
/* Enable receiver and transmitter */
UCSRB = (1<<RXEN)|(1<<TXEN);
/* Set frame format: 8data, 2stop bit */
UCSRC = (1<<URSEL)|(3<<UCSZ0);
}

int main( void )
{
USART_Init ( MYUBRR );
USART_Transmit('n');
    while (1)
    {
        
    }   
}