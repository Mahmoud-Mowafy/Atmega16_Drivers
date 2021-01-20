/*
 * File:   turn.c
 * Author: Mahmoud
 *
 * Created on August 27, 2020, 11:26 AM
 */


/*
 * Challenge1.c
 *
 *  Created on: Jun 4, 2017
 *  Author: Mohamed Tarek
 */

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRA  |=(1<<0) ;	// Configure all PORTC pins as output pins
	PORTA &= ~(1<<0);   // First led is on at the beginning (Positive Logic configuration)

	while(1)
	{

		_delay_ms(500);
		PORTA ^=(1<<0); //every time only one led is ON
	}
}


