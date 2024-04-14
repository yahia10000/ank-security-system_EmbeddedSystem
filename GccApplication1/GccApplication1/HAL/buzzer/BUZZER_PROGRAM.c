/*
 * BUZZER_PROGRAM.c
 *
 * Created: 3/18/2024 12:51:52 AM
 *  Author: solo
 */ 
#include "BUZZER_INTERFACE.h"


void Buzzer_Init(void)
{
	PinMode(BUZZER_pin,OUTPUT);
}
void Buzzer_tone(void)
{
	digitalWrite(BUZZER_pin,HIGH);
}
void Buzzer_notone(void)
{
		digitalWrite(BUZZER_pin,LOW);

}
