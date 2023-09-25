/******************************************************************/
/******************************************************************/
/***************   		Author : Hossam Medhat		***************/
/***************   		Layer : APP         		***************/
/***************   		SWC : KEYPAD            	 **************/
/***************   		Version : 1.00      		***************/
/******************************************************************/
/******************************************************************/

#include "STD_TYPES.h"
#include "util/delay.h"

#include "PORT_Interface.h"
#include "LCD_Interface.h"
#include "KPD_Interface.h"

void main (void)
{

	PORT_voidInit();
	LCD_voidInit();
	u8 Local_u8PressedKey = 0xff ; //not pressed


		u8 Arr_u8Password[4]= {'1','2','3','4'};
		u8 Arr_u8User[4]= {0};

		u8 flag = 0 ;     //flag =1 when password is not correct
		u8 Counter_u8Incorrectpass =0;

		while(1)
		{
			for(u8 i =0 ; i<4 ; i++)
			{
				do{
					Local_u8PressedKey = KPD_u8GetPressedKey();
				}while(Local_u8PressedKey==0xff);

				Arr_u8User[i]=Local_u8PressedKey;
				LCD_voidSendData('*');
			}
			LCD_voidClearLCD();
			for(u8 i =0 ; i<4 ; i++)
			{
				if (Arr_u8User[i]==Arr_u8Password[i])
				{
					flag=0;
				}
				else
				{
					LCD_voidSendString("WRONG PASSWORD");
					_delay_ms(1000);
					LCD_voidClearLCD();
					flag=1;
					Counter_u8Incorrectpass++;
					break;
				}
			}

			if (flag==0)
			{
				LCD_voidGoToXY(0,4);
				LCD_voidSendString("WELCOME");
				_delay_ms(2000);
			}
			if(Counter_u8Incorrectpass==3)
			{
				LCD_voidSendString("WRONG PASSWORD");
				LCD_voidGoToXY(1,2);
				LCD_voidSendString("THREE TIMES");
				_delay_ms(2000);
				LCD_voidClearLCD();
				return;

			}
			LCD_voidClearLCD();




		}




}
