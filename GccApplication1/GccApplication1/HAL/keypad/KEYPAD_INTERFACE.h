/*
 * KEYPAD_INTERFACE.h
 *
 * Created: 3/17/2024 1:42:02 AM
 *  Author: solo
 */ 


#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_

 #include "STD_TYPES.h"
 
#define NOTPRESSED 0Xff


void Keypad_Init(void);
uint8 Keypad_uint8GetPressed(void);




#endif /* KEYPAD_INTERFACE_H_ */