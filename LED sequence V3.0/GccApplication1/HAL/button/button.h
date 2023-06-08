/*
 * button.h
 *
 * Created: 4/7/2023 12:36:51 PM
 *  Author: acer
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCAL/dio/dio.h"


#define BUTTON_1_PORT  PORT_C
#define BUTTON_1_PIN   1

#define BUTTON_2_PORT  PORT_D
#define BUTTON_2_PIN   7

// button state
#define LOW   0
#define HIGH  1


// initialize
void Button_init(uint8_t buttonPort, uint8_t buttonPin);

// button read
void Button_read(uint8_t buttonPort, uint8_t buttonPin, uint8_t *value);



#endif /* BUTTON_H_ */