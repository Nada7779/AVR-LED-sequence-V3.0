/*
 * led.h
 *
 * Created: 4/7/2023 12:41:48 AM
 *  Author: acer
 */ 


#ifndef LED_H_
#define LED_H_

//#include "../DIO/DIO.h"
#include "../../MCAL/DIO/DIO.h"

#define led_1_port  PORT_A
#define led_1_pin       4
#define led_2_port  PORT_A
#define led_2_pin       3
#define led_3_port  PORT_A
#define led_3_pin       2
#define led_4_port  PORT_A
#define led_4_pin       1 

void LED_init(uint8_t ledPort, uint8_t ledPin);
void LED_on(uint8_t ledPort, uint8_t ledPin);
void LED_off(uint8_t ledPort, uint8_t ledPin);
void LED_toggle(uint8_t ledPort, uint8_t ledPin);






#endif /* LED_H_ */