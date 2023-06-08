/*
 * led.h
 *
 * Created: 4/7/2023 12:42:03 AM
 *  Author: acer
 */ 



#include "led.h"




void LED_init(uint8_t ledPort, uint8_t ledPin)
{
	DIO_init(ledPin, ledPort, OUT);	
}

void LED_on(uint8_t ledPort, uint8_t ledPin)
{
	DIO_write(ledPin, ledPort, HIGH);
}
void LED_off(uint8_t ledPort, uint8_t ledPin)
{
    DIO_write(ledPin, ledPort, LOW);
}




