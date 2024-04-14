/*
 * SEV_SEG_PROGRAM.c
 *
 * Created: 3/21/2024 10:00:13 PM
 *  Author: solo
 */ 

#include "SEV_SEG_INTERFACE.h"
#include "BIT_MATH.h"

#include "DIO_INTERFACE.h"

void SEV_SEG_init(void){
	PinMode(SEV_SEG_PIN_A,OUTPUT);
	PinMode(SEV_SEG_PIN_B,OUTPUT);
	PinMode(SEV_SEG_PIN_C,OUTPUT);
	PinMode(SEV_SEG_PIN_D,OUTPUT);
	PinMode(SEV_SEG_COMMON,OUTPUT);
}

void SEV_SEG_on(void){
	digitalWrite(SEV_SEG_COMMON, 1 );
}

void SEV_SEG_off(void){
	digitalWrite(SEV_SEG_COMMON, 0 );
}

void SEV_SEG_display(uint8 digit){
	digitalWrite(SEV_SEG_PIN_A, GET_BIT(digit,0) );
	digitalWrite(SEV_SEG_PIN_B, GET_BIT(digit,1) );
	digitalWrite(SEV_SEG_PIN_C, GET_BIT(digit,2) );
	digitalWrite(SEV_SEG_PIN_D, GET_BIT(digit,3) );
}
