/****************************************************/
/*Author	            : Mohamad Abdo Maklad	    */
/*Date		            : 27-7-2023				    */
/*Last Modification		: 27-7-2023				    */
/*Version	            : V01				   	    */
/****************************************************/
/*Controller            :                           */
/*SWC                   :                           */
/*Description           :                           */
/****************************************************/
/*LIB Includes*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*Lower Layer Includes*/
#include "GPIO_Interface.h"
#include "SysTick_Interface.h"
#include "SPI_Interface.h"
/*Driver Files Includes*/
#include "TFT_Interface.h"
#include "TFT_Private.h"
#include "TFT_Config.h"
/*Driver*/
void TFT_voidInit(void)
{
	/*1- Reset Pulse sequence*/
	Private_voidSendResetPulse();
	/*2- Sleep out Command*/
	Private_voidSendCmd(SLP_OUT_CMD);
	/*3- Delay 10 ms*/
	STK_voidSetBusyWait(10000);
	/*4.1 - Colored Mode*/
	Private_voidSendCmd(0x3A);
	/*4.2 - RGB565 selection*/
	Private_voidSendData(0x05);
	/*5- Display ON*/
	Private_voidSendCmd(0x29);
}

void TFT_voidDisplayImage(U16* ImageArr)
{
	U32 Local_u32Counter;

	/*Set x Dimensions Command*/
	Private_voidSendCmd(0x2A);
	/*Start of x*/
	Private_voidSendData(0);
	Private_voidSendData(0);
	/*End of x*/
	Private_voidSendData(0);
	Private_voidSendData(127);

	/*Set y Dimensions Command*/
	Private_voidSendCmd(0x2B);
	/*Start of x*/
	Private_voidSendData(0);
	Private_voidSendData(0);
	/*End of x*/
	Private_voidSendData(0);
	Private_voidSendData(159);

	/*Ram memory write*/
	Private_voidSendCmd(0x2C);

	/*Write on TFT Pixel by Pixel - MSB First, each pixel is 2B, at each time --> 1B*/
	for(Local_u32Counter = 0; Local_u32Counter < 20480; Local_u32Counter++)
	{
		U8 Local_u8low = (U8) ImageArr[Local_u32Counter];
		U8 Local_u8high =(U8) (ImageArr[Local_u32Counter]>>8);
		Private_voidSendData(Local_u8high);
		Private_voidSendData(Local_u8low);
	}
}

static void Private_voidSendCmd(U8 Copy_u8Command)
{
	U8 Local_u8Temp;
	/*Select Command mode*/
	GPIO_voidSetPinValue(TFT_A0_PIN, GPIO_LOW);
	/*Send Command*/
	SPI_voidTranceive(Copy_u8Command, &Local_u8Temp);
	//(void)SPI_voidTranceive(Copy_u8Command);
}

static void Private_voidSendData(U8 Copy_u8Data)
{
	U8 Local_u8Temp=0;
	/*Select Data mode*/
	GPIO_voidSetPinValue(TFT_A0_PIN, GPIO_HIGH);
	/*Send Data*/
	SPI_voidTranceive(Copy_u8Data, &Local_u8Temp);
	//(void)SPI_voidTranceive(Copy_u8Command);
}

static void Private_voidSendResetPulse(void)
{
	GPIO_voidSetPinValue(TFT_RST_PIN, GPIO_HIGH);
	SysTick_SetBusyWait(1000);
	GPIO_voidSetPinValue(TFT_RST_PIN, GPIO_LOW);
	SysTick_SetBusyWait(10);
	GPIO_voidSetPinValue(TFT_RST_PIN, GPIO_HIGH);
	SysTick_SetBusyWait(1000);
	GPIO_voidSetPinValue(TFT_RST_PIN, GPIO_LOW);
	SysTick_SetBusyWait(100000);
	GPIO_voidSetPinValue(TFT_RST_PIN, GPIO_HIGH);
	SysTick_SetBusyWait(120000);
}
