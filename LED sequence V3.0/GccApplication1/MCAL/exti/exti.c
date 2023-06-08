/*
 * interrupts.c
 *
 * Created: 4/10/2023 10:24:07 PM
 *  Author: acer
 */ 

#include "exti.h"


/****************************Pointer to functions to be assigned to ISR*********************************/

static void (*INT0_Fptr) (void)=NULLPTR;
static void (*INT1_Fptr) (void)=NULLPTR;


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
/************************************Call back functions*********************************************/
void EXI0_SetCallBack(void(*LocalPtr)(void))
{
		INT0_Fptr=LocalPtr;
}

/************************************Call back functions*********************************************/
void EXI1_SetCallBack(void(*LocalPtr)(void))
{
		INT1_Fptr=LocalPtr;
}
/*******************************ISR********************************/
ISR(EXT_INT_0) 
{
	if (INT0_Fptr!=NULLPTR)
	{
		INT0_Fptr();
	}
}
ISR(EXT_INT_1)
{
	if (INT1_Fptr!=NULLPTR)
	{
		INT1_Fptr();
	}
}
//*****************************************************************************************************/





