/*
 * button.h
 *
 * Created: 4/7/2023 12:36:36 PM
 *  Author: acer
 */ 


#include "button.h"
 
 // initialize
 void Button_init(uint8_t buttonPort, uint8_t buttonPin) // init button as an input device
 {
	 DIO_init(buttonPin, buttonPort, IN);
 }

 // button read
 void Button_read(uint8_t buttonPort, uint8_t buttonPin, uint8_t *value)
 {
	 DIO_read(buttonPin, buttonPort, value);
 }