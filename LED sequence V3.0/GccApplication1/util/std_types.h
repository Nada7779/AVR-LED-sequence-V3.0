/*
 * types.h
 *
 * Created: 4/6/2023 1:14:03 AM
 *  Author: acer
 */ 


#ifndef TYPES_H_
#define TYPES_H_

typedef unsigned char uint8_t;
typedef uint8_t Std_ReturnType;

// Macros Decelerations
#define E_OK         (Std_ReturnType)0x01
#define E_NOT_OK     (Std_ReturnType)0x00
#define NULLPTR      ((void*)0)

// Macros like Functions
// ISR definition
#define ISR(INT_VECT)void INT_VECT(void) __attribute__ ((signal,used));\
void INT_VECT(void)



#endif /* TYPES_H_ */