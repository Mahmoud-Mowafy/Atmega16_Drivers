

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

#include<avr/io.h>


#define F_CPU                                       1000000UL
#define PWM_PIN_OUT                                 PORTB
#define PWM_PIN                                     0
#define PWM_PIN_DIR                                 DDRB


typedef unsigned char uint8;
typedef unsigned int uint16;

void timer1_init_ctc_mode(uint8 out_compare_value);

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

