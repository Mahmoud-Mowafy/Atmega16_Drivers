/*
 * File:   I2C Module
 * Author: Mahmoud Saeed Muhammed
 *
 * Created on October 30, 2020, 2:11 AM
 */


#include <avr/io.h>
#include"I2C.h"


void TWI_init()
{
    /**
     * F_CPU = 8 MHZ.
     * Set the SCL frequency = 50K , this is done by set the TWBR = 71,
     * the TWPS =0 . 
     * Enable the TWI module.
     */
    TWBR = 71;
    TWSR &=(~(1<<TWPS0)) & (~(1<<TWPS1)); 
    TWCR |=(1<<TWEN);
}

void TWI_start()
{
    /**
     * Enable the TW module.
     * Clear the TWINT flag by writing logic one on it.
     * Enable the start condition bit . 
     */
    TWCR |=(1<<TWSTA) | (1<<TWEN) | (TWINT);
    /*Check if the TWINT is not set,this means that it doesn't finish its current job.*/
    while(IS_BIT_CLEAR(TWCR,TWINT));
}

void TWI_stop()
{
    /**
     * Enable the TW module.
     * Clear the TWINT flag by writing logic one on it.
     * Enable the stop condition bit .
     */
    TWCR |=(1<<TWSTO) | (1<<TWEN) | (TWINT);
}

void TWI_write( uint8 data)
{
    /**
     * Put data On TWI data Register.
     * Enable the TW module.
     * Clear the TWINT flag by writing logic one on it.
     */
    TWDR = data;
    TWCR |=(1<<TWEN) | (1<<TWINT);
    /*Check if the TWINT is not set,this means that it doesn't finish its current job.*/    
    while(IS_BIT_CLEAR(TWCR,TWINT));
}

uint8 TWI_readWithAck(void)
{
    /**
     * Enable the TW module & enable the Acknowledge bit in TWCR-----> TWEA.
     * Clear the TWINT flag by writing logic one on it.
     */
    TWCR |=(1<<TWEN) | (1<<TWINT) | (1<<TWEA);  
    /*Check if the TWINT is not set,this means that it doesn't finish its current job.*/    
    while(IS_BIT_CLEAR(TWCR,TWINT));
    return TWDR;
}
uint8 TWI_readWithNotAck(void)
{
    /**
     * Enable the TW module.
     * Clear the TWINT flag by writing logic one on it.
     */
    TWCR |=(1<<TWEN) | (1<<TWINT);  
    /*Check if the TWINT is not set,this means that it doesn't finish its current job.*/    
    while(IS_BIT_CLEAR(TWCR,TWINT));
    return TWDR;
}
uint8 TWI_getStatus(void)
{
    uint8 status;
    /* masking to eliminate first 3 bits and get the last 5 bits (status bits) */
    status = TWSR & 0xF8;
    return status;
}