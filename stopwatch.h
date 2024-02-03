/*
 * hamoksha.h
 *
 *  Created on: Nov 25, 2023
 *      Author: rahma
 */


uint8 u8arrClk[3];
uint8 hour = 0 , seconds = 0 , minutes = 0;

void scan(uint8 arr[])
{
	u8arrClk[0]=((arr[0])*10)+(arr[1]);
	u8arrClk[1]=((arr[3])*10)+(arr[4]);
	u8arrClk[2]=((arr[6])*10)+(arr[7]);
	hour=u8arrClk[0];
	minutes=u8arrClk[1];
	seconds=u8arrClk[2];


}


void startStopWatch(void)
{
	uint8_t currentHour = hour;
	uint8_t currentMinute = minutes;
	uint8_t currentSecond = seconds;

	while (currentHour > 0 || currentMinute > 0 || currentSecond > 0)
	{
		if (currentSecond == 0)
		{
			currentSecond = 59;
			if(currentMinute >0)
			{
				currentMinute--;
			}
		}

		if ((currentMinute == 0)&&(currentHour>0))
		{
			currentMinute = 59;
			if(currentHour>0)
			{
				currentHour--;
			}
		}

		if (currentHour <= 9)
		{
			CLCD_voidGoToXY(0, 0);
			CLCD_voidSendData('0');
			CLCD_voidGoToXY(1, 0);
			CLCD_voidSendNumber(currentHour);
		}
		else
		{
			CLCD_voidGoToXY(0, 0);
			CLCD_voidSendNumber(currentHour);
		}

		if (currentMinute <= 9)
		{

			CLCD_voidGoToXY(3, 0);
			CLCD_voidSendData('0');
			CLCD_voidGoToXY(4, 0);
			CLCD_voidSendNumber(currentMinute);
		}
		else
		{
			CLCD_voidGoToXY(3, 0);
			CLCD_voidSendNumber(currentMinute);
		}

		if (currentSecond <= 9)
		{
			CLCD_voidGoToXY(6, 0);
			CLCD_voidSendData('0');
			CLCD_voidGoToXY(7, 0);
			CLCD_voidSendNumber(currentSecond);
		}
		else
		{
			CLCD_voidGoToXY(6, 0);
			CLCD_voidSendNumber(currentSecond);
		}

		currentSecond--;
		_delay_ms(500);
	}
}


uint8 Local_u8Hamoksha[9] ={
		0b00001110,
		0b00001110,
		0b00000100,
		0b00001110,
		0b00010101,
		0b00000100,
		0b00001110,
		0b00010001,0};
uint8 Local_u8HamokshaRUN[9] = {
		0b00001110,
		0b00001110,
		0b00000100,
		0b00001111,
		0b00010100,
		0b00000100,
		0b00001010,
		0b00000001,0};

uint8 Local_u8HamokshaDANCE1[9] = {
		0b00001110,
		0b00001110,
		0b00010101,
		0b00001110,
		0b00000100,
		0b00000010,
		0b00000110,
		0b000010010 };

uint8 Local_u8HamokshaDANCE2[9] = {
		0b00001110,
		0b00001110,
		0b00010101,
		0b00001110,
		0b00000100,
		0b00001000,
		0b00000110,
		0b000010010 };

uint8 Local_u8HamokshaFOOTBALL[9] = {
		0b00001110,
		0b00001110,
		0b00000100,
		0b00001110,
		0b00010101,
		0b00011100,
		0b00001010,
		0b00000001,0 };

uint8 Local_u8Gun[9] = {
		0b00000000,
		0b00000000,
		0b00001111,
		0b00011111,
		0b00010100,
		0b00011000,
		0b00011000,
		0b00011000,0};

uint8 Local_u8GunDOT[9] = {
		0b00000000,
		0b00000000,
		0b00011011,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000,0};


uint8 Local_u8HamokshaKILL[9] =
{		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00011111,
		0b00011111,0
};



void hamoksha(void){



	CLCD_voidSendCmd(1);
	CLCD_voidGoToXY(0,0);
	CLCD_u8SendString("stopWatchIsOver");
	for(uint8 i=0;i<16;i++)
	{
		i++;
		CLCD_voidGoToXY(0,8);
		CLCD_u8SendString("stopWatchIsOver");
		CLCD_u8SendSpecialCharacter(0,Local_u8Hamoksha,5,1);
		CLCD_u8SendSpecialCharacter(0,Local_u8HamokshaDANCE1,5,1);
		_delay_ms(200);
		CLCD_u8SendSpecialCharacter(0,Local_u8Hamoksha,5,1);
		CLCD_u8SendSpecialCharacter(0,Local_u8HamokshaDANCE2,5,1);
		//CLCD_voidSendCmd(1);


	}

}

