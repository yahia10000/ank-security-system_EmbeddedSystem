/*
 * GccApplication1.c
 *
 * Created: 3/14/2024 10:23:32 AM
 * Author : solo
 */ 

#define F_CPU     16000000UL
#include <avr/delay.h>

/***************include*****************************/
#include "DIO_INTERFACE.h"
#include "LED_INTERFACE.h"
#include "LCD_INTERFACE.h"
#include "KEYPAD_INTERFACE.h"
#include "BUZZER_INTERFACE.h"
#include "SEV_SEG_INTERFACE.h"

/***************Macro_Declaration*********************/
#define PASS "122+"
#define RIGHT 1
#define WRONG 0

/**************Function_Defination*****************************/

uint8 compare(uint8 *str, uint8 *ptr){
	uint8 status=RIGHT;
	uint8 counter;
	for(uint8 counter=0;counter<4;counter++){
		if(str[counter] != ptr[counter]){
			status=WRONG;
			break;
		}
	}
	return status;
}

void Clear_Display_screen(void)
{
	LCD_SendCommand(0x01);
}

/*************************************************************/


int main(void)
{
	Keypad_Init();
	LCD_Int();
	Buzzer_Init();
	LED_INTIAL(LED_GREEN);
	LED_INTIAL(LED_RED);
	SEV_SEG_init();
	
	while (1)
	{
		SEV_SEG_off();
		Clear_Display_screen();
		Buzzer_notone();
		LED_OF(LED_GREEN);
		LED_OF(LED_RED);
		uint8 pass[]=PASS;
		uint8 tries=1; // counter of iteration of an incorrectly entered password
		LCD_SendString("welcome");
		_delay_ms(500);
		
		while(tries<=3)
		{
			uint8 value[4];
			uint8 i=0,k=0;
			uint8 st;
			Clear_Display_screen();
			LCD_SendString("password:");
			LCD_SendCommand(0xc0);
			while(i==0)
			{
				value[k]=Keypad_uint8GetPressed();
				if(value[k] != 0xff)
				{
					if(value[k] =='=')
					{
						i=1;
						value[k]='\0';
					}
					else
					{
						
						
						LCD_SendData('*');
						k++;
					}
				}
			}
			Clear_Display_screen();
			st=compare(value,pass);
			if(st==1)
			{
				
				LCD_SendString("right");
				LED_ON(LED_GREEN);
				_delay_ms(2000);
				tries=4;
			}
			else
			{
				if(tries<=2)
				{
					LCD_SendString("wrong try again ");
					_delay_ms(1000);
				}
				if(tries==3)
				{
					
					LCD_SendString("wrong!!!");
					SEV_SEG_on();
					sint8 counter;
					for( counter =9;counter>=0;counter--)
					{
						SEV_SEG_display(counter);
						_delay_ms(1000);
					}
					Buzzer_tone();
					for(counter=0;counter<=5;counter++)
					{
						LED_TOGEL(LED_RED);
						_delay_ms(500);
					}	
				}
				tries++;
				
			}
			
			
		}

	}
}

