/*
 * KEYPAD_PROGRAM.c
 *
 * Created: 3/17/2024 1:53:18 AM
 *  Author: solo
 */ 

#define F_CPU     16000000UL
#include "KEYPAD_INTERFACE.h"
#include "KEYPAD_CONFIG.h"
#include "DIO_INTERFACE.h"
#include <avr/delay.h>

void Keypad_Init(void)
{
	//connect pull up for the pins of the rows
	PinMode(Keypad_R1,INPUT);	
	PinMode(Keypad_R2,INPUT);
	PinMode(Keypad_R3,INPUT);
	PinMode(Keypad_R4,INPUT);

	digitalWrite(Keypad_R1,HIGH);
	digitalWrite(Keypad_R2,HIGH);
	digitalWrite(Keypad_R3,HIGH);
	digitalWrite(Keypad_R4,HIGH);
	
	//connect the pins of the columns as output pins (HIGH)
	PinMode(Keypad_C1,OUTPUT);
	PinMode(Keypad_C2,OUTPUT);
	PinMode(Keypad_C3,OUTPUT);
	PinMode(Keypad_C4,OUTPUT);

	digitalWrite(Keypad_C1,HIGH);
	digitalWrite(Keypad_C2,HIGH);
	digitalWrite(Keypad_C3,HIGH);
	digitalWrite(Keypad_C4,HIGH);
}
uint8 Keypad_uint8GetPressed(void)
{
	uint8 uint8ReturnData=NOTPRESSED;
	uint8 Uint8GetPressed;
	
	//iterators
	uint8 Uint8Row;
	uint8 Uint8Col;
	
	for(Uint8Col=0+Keypad_Col_Init ; Uint8Col < Keypad_Col_End+1 ; Uint8Col++)
	{
		digitalWrite(Uint8Col,LOW);// low on columns
		for(Uint8Row=0+Keypad_Row_Init ; Uint8Row < Keypad_Row_End+1;Uint8Row++)
		{
			Uint8GetPressed=digitalRead(Uint8Row); //take row value (low / high)
			if(LOW==Uint8GetPressed)
			{
				_delay_ms(50);//delay for bouncing
				Uint8GetPressed=digitalRead(Uint8Row); //to make sure that the button still low
				if(LOW==Uint8GetPressed)
				{
					uint8ReturnData=Keypad_Uint8Buttons [Uint8Row-Keypad_Row_Init][Uint8Col-Keypad_Col_Init] ;//return ascii code
				}
				Uint8GetPressed=digitalRead(Uint8Row);
				//stay here if the button is pressed 
				while(LOW==Uint8GetPressed)
				{
					Uint8GetPressed=digitalRead(Uint8Row);
				}
				break;
			}
		}
		//return columns pin to high
		digitalWrite(Uint8Col,HIGH);
	}
	return uint8ReturnData;
	
}