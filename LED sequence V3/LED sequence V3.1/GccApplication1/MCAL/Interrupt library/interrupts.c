/*
 * interrupts.c
 *
 * Created: 4/10/2023 10:24:07 PM
 *  Author: acer
 */ 

#include "interrupts.h"
#include "../../register.h"

// Enable global interrupts
void Global_interrupt_enable (void)
{
	sei();
}

// Disable global interrupts
void Global_interrupt_disable (void)
{
	cli();
}

// enable external interrupt 0
void Exit_enable0 (void)
{
	GICR |= (1<<6);
}

// Choose the external 0 interrupt mode
void External_interrupt0_mode (uint8_t mode)
{
	if (mode==rising_edge)  
	{
		MCUCR |= (1<<0) | (1<<1);
	}
}

// enable external interrupt 1
void Exit_enable1 (void)
{
	GICR |= (1<<7);
}

// Choose the external interrupt 1 mode
void External_interrupt1_mode (uint8_t mode)
{
	if (mode==rising_edge)
	{
		MCUCR |= (1<<2) | (1<<3);
	}
}



