/*
 * timer.h
 *
 * Created: 4/15/2023 11:33:02 PM
 *  Author: NADA
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "../../util/register.h"
#include "../../util/std_types.h"


//Enums for modes
typedef enum
{
	TIMER0_NORMAL_MODE=0,
	TIMER0_PHASECORRECT_MODE,
	TIMER0_CTC_MODE,
	TIMER0_FASTPWM_MODE	
}TIMER0_Mode_type;

typedef enum
{
	TIMER0_STOP=0,
	TIMER0_SCALER_1,
    TIMER0_SCALER_8,
	TIMER0_SCALER_64,
	TIMER0_SCALER_256,
	TIMER0_SCALER_1024,
	EXTERNAL_FALLING_EDGE,
	EXTERNAL_RISING_EDGE,
}TIMER0SCALER_type;


Std_ReturnType Timer0_init(TIMER0_Mode_type mode,TIMER0SCALER_type scaler);
Std_ReturnType delay_ms(uint8_t delay_time);
void Timer0_overflowInterrupt_Disable(void);
void Timer0_overflowInterrupt_Enable(void);
void Timer0_OVF_SetCallBack(void(*LocalFptr)(void));


	
	
#endif /* TIMER_H_ */