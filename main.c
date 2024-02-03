/*
 * main.c
 *
 *  Created on: Nov 18, 2023
 *      Author: rahma
 */


#include "STD_TYPES.h"
#include "ErrType.h"
#include "util/delay.h"

#include "PORT_interface.h"
#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "KPD_interface.h"
#include "stopwatch.h"


void main(void)
{
	uint8 Localu8_Arr[8]={'0','0',':','0','0',':','0','0'};

	uint8 Local_u8Pattern[8] = {0b00000100, 0b00001110, 0b00010101, 0b00000100, 0b00000100, 0b00000100, 0b00000100, 0};
	uint8 Localu8KeyPadKey;
	PORT_voidInit();
	CLCD_voidInit();


	while(1)
	{
		for(uint8 i =0;i<8;i++)
		{
			CLCD_voidSendData(Localu8_Arr[i]);

		}
		for(uint8 i =0;i<8;i++)
		{
			if(i==2 || i==5 )
			{
				//do no thing

			}
			else
			{
				CLCD_u8SendSpecialCharacter(0,Local_u8Pattern,i,1);
				do
				{
					Localu8KeyPadKey= KPD_u8GetPressedKey();
				}
				while(Localu8KeyPadKey == 0xff);
				if(Localu8KeyPadKey =='+')
				{
					i--;
					if(i==2 || i==5 )
					{

						i--;
						CLCD_voidGoToXY(i+2,1);
						CLCD_voidSendData(' ');
						CLCD_u8SendSpecialCharacter(0,Local_u8Pattern,i,1);
						do
						{
							Localu8KeyPadKey= KPD_u8GetPressedKey();
						}
						while(Localu8KeyPadKey == 0xff);
						Localu8_Arr[i]=Localu8KeyPadKey;
						CLCD_voidGoToXY(i,0);
						CLCD_voidSendNumber(Localu8_Arr[i]);
						CLCD_voidGoToXY(i,1);
						CLCD_voidSendData(' ');

					}
					else if ((Localu8KeyPadKey >= 0) &&( Localu8KeyPadKey <= 9))
					{
						CLCD_voidGoToXY(i+1,1);
						CLCD_voidSendData(' ');
						CLCD_u8SendSpecialCharacter(0,Local_u8Pattern,i,1);
						do
						{
							Localu8KeyPadKey= KPD_u8GetPressedKey();
						}
						while(Localu8KeyPadKey == 0xff);
						Localu8_Arr[i]=Localu8KeyPadKey;
						CLCD_voidGoToXY(i,0);
						CLCD_voidSendNumber(Localu8_Arr[i]);
						CLCD_voidGoToXY(i,1);
						CLCD_voidSendData(' ');
					}
					else
					{
						i--;

					}
				}
				else if ((Localu8KeyPadKey >= 0) &&( Localu8KeyPadKey <= 9))
				{
					Localu8_Arr[i]=Localu8KeyPadKey;

					CLCD_voidGoToXY(i,0);
					CLCD_voidSendNumber(Localu8_Arr[i]);
					CLCD_voidGoToXY(i,1);
					CLCD_voidSendData(' ');
				}
				else
				{
					i--;

				}
			}
		}

		scan(Localu8_Arr);
		do
		{
			Localu8KeyPadKey= KPD_u8GetPressedKey();
		}
		while(Localu8KeyPadKey == 0xff);
		if (Localu8KeyPadKey=='=')
		{

			//	CLCD_voidSendNumber(Localu8_Arr[1]);

			startStopWatch();
			hamoksha();
		}
		else
		{

			CLCD_voidSendCmd(1);
		}

		_delay_ms(500);



	}
}
