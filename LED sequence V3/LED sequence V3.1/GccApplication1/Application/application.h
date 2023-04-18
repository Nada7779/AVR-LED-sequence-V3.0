/*
 * application.h
 *
 * Created: 4/8/2023 10:08:25 AM
 *  Author: acer
 */ 


#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "../EUCAL/LED/led.h"
#include "../EUCAL/Button/button.h"
#include "../MCAL/Interrupt library/interrupts.h"
#include "../MCAL/Timer/timer.h"



void APP_init(void);
void APP_start(void);

void BLINK_1_mode (void);

void BLINK_2_mode (void);

void BLINK_3_mode (void);

void BLINK_4_mode (void);

void BLINK_5_mode (void);



#endif /* APPLICATION_H_ */