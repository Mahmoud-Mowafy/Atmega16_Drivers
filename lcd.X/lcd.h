

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

#include <xc.h> // include processor files - each processor file is guarded.  

#include <util/delay.h>
#include <avr/io.h>

#define F_CPU                                   8000000UL

typedef unsigned char                           uint8; 
#define LCD_CONTROL_DIR                           DDRB
#define LCD_DATA_DIR                              DDRA
#define LCD_CONTROL_OUT                           PORTB
#define LCD_DATA_OUT                              PORTA

#define RS                                          0
#define RW                                          1
#define EN                                          2

//LCD command 
#define CURSOR_OFF                                  0x0C
#define CLEAR_DISPLAY                               0x01
#define FOUR_BITS_MODE                              0x02
#define FOUR_BITS_MODE_TWO_LINE                     0x28

#define BIT_IS_SET(REG,BIT)         (REG & (1<<BIT) )
#define BIT_IS_CLEAR(REG,BIT)       (!( REG &(1<<BIT) ) )

#define SET_BIT(REG,BIT)            ( REG |=(1<<BIT) )
#define CLEAR_BIT(REG,BIT)          (  REG &=(~(1<<BIT)) )

            

#define BITS_MODE_IS                                4
#define UPPER

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

