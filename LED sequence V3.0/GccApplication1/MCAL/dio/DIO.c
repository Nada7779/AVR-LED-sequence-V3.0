/*
 * DIO.c
 *
 * Created: 4/6/2023 1:46:07 AM
 *  Author: Nada
 */ 


#include "dio.h"


// function definitions

/*Description:
 * Function to initialize specific pin of port number with direction
 * return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType DIO_init(uint8_t pinNumber, uint8_t portNumber, uint8_t direction)
{
	Std_ReturnType ret = E_OK;
	
	switch(portNumber)
	{
		case PORT_A: 
		if(direction==IN)
		{
			DDRA &= ~(1<<pinNumber); // pin init. input
			ret = E_OK;
	    }
		else if(direction==OUT)
		{
			DDRA |= (1<<pinNumber); // pin init. output
			ret = E_OK;
		}
	    else
		{
			ret = E_NOT_OK;
		}
	    break;
	    
		case PORT_B:
		if(direction==IN)
		{
			DDRB &= ~(1<<pinNumber); // pin init. input
			ret = E_OK;
		}
		else if(direction==OUT)
		{
			DDRB |= (1<<pinNumber); // pin init. output
			ret = E_OK;
		}
		else
		{
			ret = E_NOT_OK;
		}
		break;
		
		case PORT_C:
		if(direction==IN)
		{
			DDRC &= ~(1<<pinNumber); // pin init. input
			ret = E_OK;
		}
		else if(direction==OUT)
		{
			DDRC |= (1<<pinNumber); // pin init. output
			ret = E_OK;
		}
		else
		{
			ret = E_NOT_OK;
		}
		break;
		
		case PORT_D:
		if(direction==IN)
		{
			DDRD &= ~(1<<pinNumber); // pin init. input
			ret = E_OK;
		}
		else if(direction==OUT)
		{
			DDRD |= (1<<pinNumber); // pin init. output
			ret = E_OK;
		}
		else
		{
			ret = E_NOT_OK;
		}
		break;
		default:
		ret = E_NOT_OK;
	}
	return ret;
	}
	
/*Description:
 * Function to write value to specific pin of port number
 * return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType DIO_write(uint8_t pinNumber, uint8_t portNumber, uint8_t value)
{
	Std_ReturnType ret = E_OK;
	
	switch(portNumber)
	{
		case PORT_A:
		if(value== LOW)
		{
			PORTA &= ~(1<<pinNumber); // write 0
			ret = E_OK;
		}
		else if(value==HIGH)
		{
			PORTA |= (1<<pinNumber); // write 1
			ret = E_OK;
		}
		else
		{
			ret = E_NOT_OK;
		}
		break;
		
		case PORT_B:
		if(value== LOW)
		{
			PORTB &= ~(1<<pinNumber); // write 0
			ret = E_OK;
		}
		else if(value==HIGH)
		{
			PORTB |= (1<<pinNumber); // write 1
			ret = E_OK;
		}
		else
		{
			ret = E_NOT_OK;
		}
		break;
		
		case PORT_C:
		if(value== LOW)
		{
			PORTC &= ~(1<<pinNumber); // write 0
			ret = E_OK;
		}
		else if(value==HIGH)
		{
			PORTC |= (1<<pinNumber); // write 1
			ret = E_OK;
		}
		else
		{
			ret = E_NOT_OK;
		}
		break;
		
		case PORT_D:
		if(value== LOW)
		{
			PORTD &= ~(1<<pinNumber); // write 0
			ret = E_OK;
		}
		else if(value==HIGH)
		{
			PORTD |= (1<<pinNumber); // write 1
			ret = E_OK;
		}
		else
		{
			ret = E_NOT_OK;
		}
		break;
		default:
		ret = E_NOT_OK;	
	}
	return ret;
	} 

/*Description:
 * Function to get the value of specific pin of port number 
 * return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType DIO_read(uint8_t pinNumber, uint8_t portNumber, uint8_t *value)
{
  Std_ReturnType ret = E_OK;
  
  switch(portNumber)
  {
	case PORT_A:
	     *value= (PINA & (1<<pinNumber))>>pinNumber; //get state read bit
		 ret = E_OK;
		 break;  	
	case PORT_B:
	    *value= (PINB & (1<<pinNumber))>>pinNumber; //get state read bit
		ret = E_OK;
	    break;
	case PORT_C:
	    *value= (PINC & (1<<pinNumber))>>pinNumber; //get state read bit
		ret = E_OK;
	    break;
	case PORT_D:
	    *value= (PIND & (1<<pinNumber))>>pinNumber; //get state read bit
		ret = E_OK;
	    break;
    default:
	ret = E_NOT_OK;
	    break;
  }
  return ret;
} 




