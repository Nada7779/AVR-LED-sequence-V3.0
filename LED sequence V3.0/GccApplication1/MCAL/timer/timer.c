/*
 * timer.c
 *
 * Created: 4/15/2023 11:33:17 PM
 *  Author: acer
 */ 


#include "timer.h"

// Pointer to functions to be assigned to ISR
static void (*Timer0_OVF_Fptr) (void)=NULLPTR;

// function definitions

/*Description:
 * Function to initialize timer 0 with specific mode and scaler
 * return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType Timer0_init(TIMER0_Mode_type mode,TIMER0SCALER_type scaler)
{
  Std_ReturnType ret = E_OK;
  
  switch(mode)
  {
	  case TIMER0_NORMAL_MODE:
	                          TCCR0 &= ~(1<<WGM00);
							  TCCR0 &= ~(1<<WGM01);
							  ret = E_OK;
							  break;
	  case TIMER0_PHASECORRECT_MODE:
	                          TCCR0 |= (1<<WGM00);
	                          TCCR0 &= ~(1<<WGM01);
							  ret = E_OK;
	                          break;
	  case TIMER0_CTC_MODE:
	                          TCCR0 &= ~(1<<WGM00);
	                          TCCR0 |= (1<<WGM01);
							  ret = E_OK;
	                          break;
	  case TIMER0_FASTPWM_MODE:
	                          TCCR0 |= (1<<WGM00);
	                          TCCR0 |= (1<<WGM01);
							  ret = E_OK;
							  break;
	 default:
	                          ret = E_NOT_OK;							  
}
TCNT0 = 0X00; // Timer initial value is 0
TCCR0  &= 0xf8; // make sure that the first three bits are set to zeros 11111000 
TCCR0  |= scaler;
return ret;
}

/*Description:
 * Function to use timer 0 to delay with specific time in ms.
 * return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType delay_ms(uint8_t delay_time)
{
	// Decelerations
	Std_ReturnType ret = E_OK;
	uint8_t overflow=0;
	uint8_t number_of_overflows= 4*delay_time;
	
	// timer mode
	ret= Timer0_init(TIMER0_NORMAL_MODE,TIMER0_SCALER_1);

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
	return ret;
}

/*Description:
 * Function to disable timer 0 over flow interrupt
 */
void Timer0_overflowInterrupt_Disable(void)
{
	TIMSK &= ~(1<<TOIE0); // clear bit
}

/*Description:
 * Function to enable timer 0 over flow interrupt
 */
void Timer0_overflowInterrupt_Enable(void)
{
	TIMSK |= (1<<TOIE0); // set bit
}

/*Description:
 * Function to set call back function of timer 0 over flow interrupt
 */
void Timer0_OVF_SetCallBack(void(*LocalFptr)(void))
{
	Timer0_OVF_Fptr=LocalFptr;
}

/*Description:
 * Function of interrupt service routine to implement timer 0 over flow interrupt
 */
ISR(TIMER0_OVF_vect)
{
	if(Timer0_OVF_Fptr!=NULLPTR)
	{
		Timer0_OVF_Fptr();
	}
}