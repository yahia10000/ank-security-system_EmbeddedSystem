/*
 * LED_PROGRAM.c
 *
 * Created: 3/14/2024 10:29:56 AM
 *  Author: solo
 */ 
#include "LED_CONFIG.h"
#include "LED_INTERFACE.h"

void LED_INTIAL(uint8 led_No)
{
	switch(led_No)
	{
		case LED_GREEN:
		PinMode(LED0_PIN,OUTPUT);
		break;
		case LED_RED:
		PinMode(LED1_PIN,OUTPUT);
		break;

	}
}

void LED_ON(uint8 LedNo)
{
	switch(LedNo)
	{
		case LED_GREEN:
		digitalWrite(LED0_PIN,HIGH);
		break;
		case LED_RED:
		digitalWrite(LED1_PIN,HIGH);

		break;
		
	}


}
void LED_OF(uint8 LedNo)
{
	switch(LedNo)
	{
		case LED_GREEN:
		digitalWrite(LED0_PIN,LOW);
		break;
		case LED_RED:
		digitalWrite(LED1_PIN,LOW);

		break;
	}

}

void LED_TOGEL(uint8 LedNo)
{
	switch(LedNo)
	{
		case LED_GREEN:
		togelpin(LED0_PIN);
		break;
		case LED_RED:
		togelpin(LED1_PIN);

		break;
	}
}

