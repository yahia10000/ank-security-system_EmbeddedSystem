/*
 * BUZZER_INTERFACE.h
 *
 * Created: 3/18/2024 12:51:31 AM
 *  Author: solo
 */ 


#ifndef BUZZER_INTERFACE_H_
#define BUZZER_INTERFACE_H_
#include "DIO_INTERFACE.h"

#define BUZZER_pin PA2

void Buzzer_Init(void);
void Buzzer_tone(void);
void Buzzer_notone(void);

#endif /* BUZZER_INTERFACE_H_ */