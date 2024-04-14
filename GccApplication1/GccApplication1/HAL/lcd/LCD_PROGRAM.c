/*
 * LCD_PROGRAM.c
 *
 * Created: 3/14/2024 10:29:36 AM
 *  Author: solo
 */ 
#define F_CPU 16000000UL

#include "LCD_INTERFACE.h"
#include <avr/delay.h>

void LCD_Int(void)
{
	_delay_ms(20);
	LCD_DATA_DDR |= 0xf0;
	PinMode(LCD_RS_PIN,OUTPUT);
	PinMode(LCD_EN_PIN,OUTPUT);
	PinMode(LCD_RW_PIN,OUTPUT);
	
	LCD_SendCommand(0x02);
	LCD_SendCommand(0x28); //4_bit_mode
	LCD_SendCommand(0x0c);
	LCD_SendCommand(0x01);
	LCD_SendCommand(0x06);
	_delay_ms(20);
}
void LCD_SendCommand(uint8 cmd)
{
	digitalWrite(LCD_RS_PIN,LOW);
	digitalWrite(LCD_RW_PIN,LOW);

	//LCD_DATA_PORT=cmd;
	LCD_DATA_PORT = (LCD_DATA_PORT & 0x0f)|(cmd & (0xf0) );
	
	digitalWrite(LCD_EN_PIN,HIGH);
	_delay_ms(2);
	digitalWrite(LCD_EN_PIN,LOW);
	_delay_ms(2);
	
	LCD_DATA_PORT = (LCD_DATA_PORT & 0x0f)|(cmd<<4);
	_delay_ms(2);
	
	digitalWrite(LCD_EN_PIN,HIGH);
	_delay_ms(2);
	digitalWrite(LCD_EN_PIN,LOW);
	_delay_ms(20);
}
void LCD_SendData(uint8 data)
{
	digitalWrite(LCD_RS_PIN,HIGH);
	digitalWrite(LCD_RW_PIN,LOW);

	LCD_DATA_PORT = (LCD_DATA_PORT &0x0f)|(data& (0xf0));
	
	digitalWrite(LCD_EN_PIN,HIGH);
	_delay_ms(2);
	digitalWrite(LCD_EN_PIN,LOW);
	_delay_ms(2);
	
	LCD_DATA_PORT = (LCD_DATA_PORT &0x0f)|(data<<4);
		_delay_ms(2);

	digitalWrite(LCD_EN_PIN,HIGH);
	_delay_ms(2);
	digitalWrite(LCD_EN_PIN,LOW);
	_delay_ms(20);
}
void LCD_SendString(uint8 *str) 
{
	while(*str != '\0')
		{
			LCD_SendData(*str);
			str++;
		}
	
}
void LCD_SendInt(uint8 num)
	{
		num+=0x30;
		LCD_SendData(num);
	}