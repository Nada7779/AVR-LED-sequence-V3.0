/*
 * timer.c
 *
 * Created: 4/15/2023 11:33:17 PM
 *  Author: acer
 */ 

#include "../../register.h"
#include "../../types.h"
#include "timer.h"


void Timer0_init(TIMER0_Mode_type mode,TIMER0SCALER_type scaler)
{
  switch(mode)
  {
	  case TIMER0_NORMAL_MODE:
	                          TCCR0 &= ~(1<<WGM00);
							  TCCR0 &= ~(1<<WGM01);
							  break;
	  case TIMER0_PHASECORRECT_MODE:
	                          TCCR0 |= (1<<WGM00);
	                          TCCR0 &= ~(1<<WGM01);
	                          break;
	  case TIMER0_CTC_MODE:
	                          TCCR0 &= ~(1<<WGM00);
	                          TCCR0 |= (1<<WGM01);
	                          break;
	  case TIMER0_FASTPWM_MODE:
	                          TCCR0 |= (1<<WGM00);
	                          TCCR0 |= (1<<WGM01);
							  break;
	  default:
		  //Error handling
}
TCNT0 = 0X00; // Timer initial value is 0
TCCR0  &= 0xf8; // make sure that the first three bits are set to zeros 11111000 
TCCR0  |= scaler;
}

void Timer0_overflowInterrupt_Disable(void)
{
	TIMSK &= ~(1<<TOIE0); // clear bit
}

void Timer0_overflowInterrupt_Enable(void)
{
	TIMSK |= (1<<TOIE0); // set bit
}
void delay_ms(uint8_t delay_time)
{
	// timer mode
	Timer0_init(TIMER0_NORMAL_MODE,TIMER0_SCALER_1);
	uint8_t overflow=0;
	uint8_t number_of_overflows= 4*delay_time;
	// timer start
	TCCR0 |= (1<<0);
	while(overflow < number_of_overflows)
	{
		// wait until the overflow flag to be set
		while((TIFR & (1<<0))==0) ;
		// CLEAR THE OVERFLOW FLAG
		TIFR |= (1<<0);
		overflow++;
	}
	// TIMER STOP
	TCCR0= 0x00;
}
