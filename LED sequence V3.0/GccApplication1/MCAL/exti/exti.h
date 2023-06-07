/*
 * interrupts.h
 *
 * Created: 4/9/2023 5:38:27 AM
 *  Author: acer
 */ 


#ifndef INTERRUOTS_H_
#define INTERRUOTS_H_

#include "../../util/register.h"
#include "../../util/std_types.h"

/* External Interrupts vectors */
// External Interrupt request 0
#define EXT_INT_0 __vector_1
// External Interrupt request 1
#define EXT_INT_1 __vector_2
// External Interrupt request 2
#define EXT_INT_2 __vector_3
/* Timer/Counter0 Overflow */
#define TIMER0_OVF_vect	 __vector_11

// External Interrupt sense modes
#define low_level             0
#define anylogical_change     1
#define falling_edge          2
#define rising_edge           3
// External Interrupt state
#define  external_enablestate   1
#define  external_disablestate  0


// set global interrupts, set the I-bit in status register 1
#define sei() __asm__ __volatile__ ("sei" ::: "memory") 
 
// clear global interrupts, set the I-bit in status register 0
#define cli() __asm__ __volatile__ ("cli" ::: "memory")

// ISR definition
#define ISR(INT_VECT)void INT_VECT(void) __attribute__ ((signal,used));\
void INT_VECT(void)



// enable external interrupt 0
void Exit_enable0 (void);
// enable external interrupt 1
void Exit_enable1 (void);
// disable external interrupt 0
void Exit_disable0 (void);
// Enable global interrupts
void Global_interrupt_enable (void);
// Disable global interrupts
void Global_interrupt_disable (void);
// initialize external interrupt
void Exit0_init (void);
void Exit1_init (void);
void External_interrupt0_mode (uint8_t mode);
void External_interrupt1_mode (uint8_t mode);


#endif /* INTERRUOTS_H_ */