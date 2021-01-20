
/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h> 


#define F_CPU                      1000000UL

#define USART_BAUDRATE              9600
#define BAUD_PRESCALE        (((F_CPU / (USART_BAUDRATE * 8UL))) - 1)

#define BIT_IS_SET(REG,BIT)         (REG & (1<<BIT) )
#define BIT_IS_CLEAR(REG,BIT)       (!( REG &(1<<BIT) ) )

#define SET_BIT(REG,BIT)            ( REG |=(1<<BIT) )
#define CLEAR_BIT(REG,BIT)          (  REG &=(~(1<<BIT)) )

typedef  unsigned char              uint8 ;
typedef  unsigned int              uint16 ;

void UART_init();
void UART_sendByte(uint8 data);
uint8 UART_receiveByte(void);
void UART_sendString(const uint8 *str);
void UART_receiveString(uint8 *str);

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

