/*
 * DIO_PROGRAM.c
 *
 * Created: 3/14/2024 10:27:21 AM
 *  Author: solo
 */ 
#include "DIO_INTERFACE.h"
#include "BIT_MATH.h"
#include "REG.h"
void PinMode(uint8 PIN_no, uint8 DIR )
{
	uint8 pin=PIN_no%10;
	uint8 port=PIN_no/10;
	switch(DIR)
	{
		case HIGH:
		switch(port)
		{
			case A:
			SET_BIT(DDRA,pin);
			break;
			case B:
			SET_BIT(DDRB,pin);
			break;
			case C:
			SET_BIT(DDRC,pin);
			break;
			case D:
			SET_BIT(DDRD,pin);
			break;
		}
		break;
		
		case LOW:
		switch(port)
		{
			case A:
			CLR_BIT(DDRA,pin);
			break;
			case B:
			CLR_BIT(DDRB,pin);
			break;
			case C:
			CLR_BIT(DDRC,pin);
			break;
			case D:
			CLR_BIT(DDRD,pin);
			break;
		}
		break;
	}
}
void digitalWrite(uint8 PIN_no ,uint8 STATE)
{
	uint8 pin=PIN_no%10;
	uint8 port=PIN_no/10;
	switch(STATE)
	{
		case HIGH:
		switch(port)
		{
			case A:
			SET_BIT(PORTA,pin);
			break;
			case B:
			SET_BIT(PORTB,pin);
			break;
			case C:
			SET_BIT(PORTC,pin);
			break;
			case D:
			SET_BIT(PORTD,pin);
			break;
		}
		break;
		
		case LOW:
		switch(port)
		{
			case A:
			CLR_BIT(PORTA,pin);
			break;
			case B:
			CLR_BIT(PORTB,pin);
			break;
			case C:
			CLR_BIT(PORTC,pin);
			break;
			case D:
			CLR_BIT(PORTD,pin);
			break;
		}
		break;
	}
}
uint8 digitalRead(uint8 PIN_no )
{
	uint8 pin=PIN_no%10;
	uint8 port=PIN_no/10;
	
	switch(port)
	{
		case A:
		return GET_BIT(PINA,pin);
		break;
		case B:
		return GET_BIT(PINB,pin);
		break;
		case C:
		return GET_BIT(PINC,pin);
		break;
		case D:
		return GET_BIT(PIND,pin);
		break;
	}
	
}

void togelpin(uint8 PIN_no)
{
	uint8 pin=PIN_no%10;
	uint8 port=PIN_no/10;
	
	switch(port)
	{
		case A:
		TOGLE_BIT(PORTA,pin);
		break;
		case B:
		TOGLE_BIT(PORTB,pin);
		break;
		case C:
		TOGLE_BIT(PORTC,pin);
		break;
		case D:
		TOGLE_BIT(PORTD,pin);
		break;
	}
	
}

