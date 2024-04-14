/*
 * SEV_SEG_INTERFACE.h
 *
 * Created: 3/21/2024 10:00:47 PM
 *  Author: solo
 */ 


#ifndef SEV_SEG_INTERFACE_H_
#define SEV_SEG_INTERFACE_H_

#include "STD_TYPES.h"


#define SEV_SEG_PIN_A  PA3
#define SEV_SEG_PIN_B  PA4
#define SEV_SEG_PIN_C  PA5
#define SEV_SEG_PIN_D  PA6
#define SEV_SEG_COMMON PA7

void SEV_SEG_init(void);
void SEV_SEG_on(void);
void SEV_SEG_off(void);
void SEV_SEG_display(uint8 digit);




#endif /* SEV_SEG_INTERFACE_H_ */