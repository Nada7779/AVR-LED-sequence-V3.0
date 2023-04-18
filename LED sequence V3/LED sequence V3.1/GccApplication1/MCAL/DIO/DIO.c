/*
 * DIO.c
 *
 * Created: 4/6/2023 1:46:07 AM
 *  Author: Nada
 */ 


#include "DIO.h"

// global variables

// function definitions

void DIO_init(uint8_t pinNumber, uint8_t portNumber, uint8_t direction)
{
	switch(portNumber)
	{
		case PORT_A: 
		if(direction==IN)
		{
			DDRA &= ~(1<<pinNumber); // pin init. input
	    }
		else if(direction==OUT)
		{
			DDRA |= (1<<pinNumber); // pin init. output
		}
	    else
		{
			// Error handling
		}
	    break;
	    
		case PORT_B:
		if(direction==IN)
		{
			DDRB &= ~(1<<pinNumber); // pin init. input
		}
		else if(direction==OUT)
		{
			DDRB |= (1<<pinNumber); // pin init. output
		}
		else
		{
			// Error handling
		}
		break;
		
		case PORT_C:
		if(direction==IN)
		{
			DDRC &= ~(1<<pinNumber); // pin init. input
		}
		else if(direction==OUT)
		{
			DDRC |= (1<<pinNumber); // pin init. output
		}
		else
		{
			// Error handling
		}
		break;
		
		case PORT_D:
		if(direction==IN)
		{
			DDRD &= ~(1<<pinNumber); // pin init. input
		}
		else if(direction==OUT)
		{
			DDRD |= (1<<pinNumber); // pin init. output
		}
		else
		{
			// Error handling
		}
		break;
	}
	}// Initialize DIO direction

void DIO_write(uint8_t pinNumber, uint8_t portNumber, uint8_t value)
{
	switch(portNumber)
	{
		case PORT_A:
		if(value== LOW)
		{
			PORTA &= ~(1<<pinNumber); // write 0
		}
		else if(value==HIGH)
		{
			PORTA |= (1<<pinNumber); // write 1
		}
		else
		{
			// Error handling
		}
		break;
		
		case PORT_B:
		if(value== LOW)
		{
			PORTB &= ~(1<<pinNumber); // write 0
		}
		else if(value==HIGH)
		{
			PORTB |= (1<<pinNumber); // write 1
		}
		else
		{
			// Error handling
		}
		break;
		
		case PORT_C:
		if(value== LOW)
		{
			PORTC &= ~(1<<pinNumber); // write 0
		}
		else if(value==HIGH)
		{
			PORTC |= (1<<pinNumber); // write 1
		}
		else
		{
			// Error handling
		}
		break;
		
		case PORT_D:
		if(value== LOW)
		{
			PORTD &= ~(1<<pinNumber); // write 0
		}
		else if(value==HIGH)
		{
			PORTD |= (1<<pinNumber); // write 1
		}
		else
		{
			// Error handling
		}
		break;	
	}
	} // Write data to DIO


void DIO_read(uint8_t pinNumber, uint8_t portNumber,uint8_t* value)
{
  switch(portNumber)
  {
	case PORT_A:
	     *value= (PINA & (1<<pinNumber))>>pinNumber; //get state read bit
		 break;  	
	case PORT_B:
	    *value= (PINB & (1<<pinNumber))>>pinNumber; //get state read bit
	    break;
	case PORT_C:
	    *value= (PINC & (1<<pinNumber))>>pinNumber; //get state read bit
	    break;
	case PORT_D:
	    *value= (PIND & (1<<pinNumber))>>pinNumber; //get state read bit
	    break;
    default:
	// Error handling
	    break;
  }
} // Read DIO



//void DIO_toggle(uint8_t pinNumber, uint8_t portNumber); // toggle DIO
