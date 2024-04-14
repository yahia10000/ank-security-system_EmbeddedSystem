/*
 * LCD_INTERFACE.h
 *
 * Created: 3/14/2024 10:29:19 AM
 *  Author: solo
 */ 


#ifndef LCD_INTERFACE_H_
#include "DIO_INTERFACE.h"

#define LCD_DATA_DDR  DDRC
#define LCD_DATA_PORT PORTC
#define LCD_RS_PIN    PC0
#define LCD_EN_PIN    PC1
#define LCD_RW_PIN    PC2


void LCD_Int(void);
void LCD_SendCommand(uint8 cmd);
void LCD_SendData(uint8 data);
void LCD_SendString(uint8 *str);
void LCD_SendInt(uint8 num);







#endif /* LCD_INTERFACE_H_ */