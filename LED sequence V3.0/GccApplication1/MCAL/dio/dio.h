/*
 * DIO.h
 *
 * Created: 4/6/2023 1:22:58 AM
 *  Author: Nada
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "../../util/register.h"
#include "../../util/std_types.h"

// all driver function decelerations

Std_ReturnType DIO_init(uint8_t pinNumber, uint8_t portNumber, uint8_t direction); // Initialize DIO direction

Std_ReturnType DIO_write(uint8_t pinNumber, uint8_t portNumber, uint8_t value); // Write data to DIO

Std_ReturnType DIO_read(uint8_t pinNumber, uint8_t portNumber, uint8_t *value); // Read DIO

// all internal driver typedefs
#define PORT_A  'A'
#define PORT_B  'B'
#define PORT_C  'C'
#define PORT_D  'D'
// direction defines
#define IN 0
#define OUT 1
// value defines
#define LOW 0
#define HIGH 1




#endif /* DIO_H_ */