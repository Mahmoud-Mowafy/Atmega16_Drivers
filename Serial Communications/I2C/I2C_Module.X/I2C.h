

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


typedef unsigned char                           uint8;
#define F_CPU                                   8000000UL
#define IS_BIT_CLEAR(REG,PIN_NUM)                    ( !( REG &=( 1 << (PIN_NUM)) ) )

void TWI_init();
void TWI_start();
void TWI_stop();
void TWI_write( uint8 data);
uint8 TWI_readWithAck(void);
uint8 TWI_readWithNotAck(void);
uint8 TWI_getStatus(void);

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

