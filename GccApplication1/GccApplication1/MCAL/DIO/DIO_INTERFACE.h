/*
 * IncFile1.h
 *
 * Created: 3/14/2024 10:27:29 AM
 *  Author: solo
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "STD_TYPES.h"
#include "REG.h"

#define PA0 0
#define PA1 1
#define PA2 2
#define PA3 3
#define PA4 4
#define PA5 5
#define PA6 6
#define PA7 7

#define PB0 10
#define PB1 11
#define PB2 12
#define PB3 13
#define PB4 14
#define PB5 15
#define PB6 16
#define PB7 17

#define PC0 20
#define PC1 21
#define PC2 22
#define PC3 23
#define PC4 24
#define PC5 25
#define PC6 26
#define PC7 27

#define PD0 30
#define PD1 31
#define PD2 32
#define PD3 33
#define PD4 34
#define PD5 35
#define PD6 36
#define PD7 37

#define A 0
#define B 1
#define C 2
#define D 3

#define HIGH 1
#define LOW 0

#define INPUT  0
#define OUTPUT 1


 /**
  * @brief    Initializing the microcontroller pins (read/write)
  * @param    (PIN_no) Pass the pin number value
  * @param    (DIR) Pass pin status value (output/input)
  */
void PinMode(uint8 PIN_no, uint8 DIR );

/*----------------------------------------------------------------*/
 /**
  * @brief    Write (0/1) in the location of pins 
  * @param    (PIN_no) Pass the pin number value
  * @retval   (STATE) Pass pin status value (high/low)
  */
void digitalWrite(uint8 PIN_no ,uint8 STATE);

/*----------------------------------------------------------------*/
 /**
  * @brief    Read the data of pins
  * @param    (PIN_no) Pass the pin number value
  * @retval   Value of pins stored in register (0/1)
  */
uint8 digitalRead(uint8 PIN_no );

/*----------------------------------------------------------------*/
 /**
  * @brief  Reverse the value of the pins stored in the register (0/1) -> (1/0)
  * @param  (PIN_no) Pass the pin number value
  */
void togelpin(uint8 PIN_no);




#endif /*  DIO_INTERFACE_H_ */