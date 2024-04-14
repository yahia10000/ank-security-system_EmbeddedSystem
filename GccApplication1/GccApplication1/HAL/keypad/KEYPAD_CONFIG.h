/*
 * KEYPAD_CONFIG.h
 *
 * Created: 3/18/2024 12:47:46 AM
 *  Author: solo
 */ 


#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

#include "DIO_INTERFACE.h"
#include "STD_TYPES.h"
#define Keypad_R1 PD0
#define Keypad_R2 PD1
#define Keypad_R3 PD2
#define Keypad_R4 PD3

#define Keypad_C1 PD4
#define Keypad_C2 PD5
#define Keypad_C3 PD6
#define Keypad_C4 PD7

#define Keypad_Row_Init PD0
#define Keypad_Row_End  PD3
#define Keypad_Col_Init PD4
#define Keypad_Col_End  PD7




                               //    c1 c2  c3  c4
uint8 Keypad_Uint8Buttons[4][4]= { {'7','8','9','/'},//R1
								   {'4','5','6','*'},//R2
                                   {'1','2','3','-'},//R3
                                   {'?',0,'=','+'} /*R4*/ };


#endif /* KEYPAD_CONFIG_H_ */