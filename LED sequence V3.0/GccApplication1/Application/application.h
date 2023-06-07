/*
 * application.h
 *
 * Created: 4/8/2023 10:08:25 AM
 *  Author: acer
 */ 


#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "../HAL/led/led.h"
#include "../HAL/button/button.h"
#include "../MCAL/timer/timer.h"
#include "../MCAL/exti/exti.h"

void APP_init(void);
void APP_start(void);



#endif /* APPLICATION_H_ */