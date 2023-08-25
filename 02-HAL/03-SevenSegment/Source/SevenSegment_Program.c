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
/*Driver Files Includes*/
#include "SevenSegment_Interface.h"
#include "SevenSegment_Private.h"
#include "SevenSegment_Config.h"
/*Driver*/
void SevenSegment_voidInit(void)
{
    // SSD Enable Lines
    GPIO_voidSetPinMode(SevenSegment_1Enable, GPIO_OUTPUT);
    GPIO_voidOutputPinConfig(SevenSegment_1Enable, GPIO_PushPull, GPIO_Output_LS);
    GPIO_voidSetPinMode(SevenSegment_2Enable, GPIO_OUTPUT);
    GPIO_voidOutputPinConfig(SevenSegment_2Enable, GPIO_PushPull, GPIO_Output_LS);
    // Dot Point
    GPIO_voidSetPinMode(SevenSegment_DP, GPIO_OUTPUT);
    GPIO_voidOutputPinConfig(SevenSegment_DP, GPIO_PushPull, GPIO_Output_LS);
    // SSD Data Lines
    GPIO_voidSetPinMode(SevenSegment_Data1, GPIO_OUTPUT);
    GPIO_voidOutputPinConfig(SevenSegment_Data1, GPIO_PushPull, GPIO_Output_LS);
    GPIO_voidSetPinMode(SevenSegment_Data2, GPIO_OUTPUT);
    GPIO_voidOutputPinConfig(SevenSegment_Data2, GPIO_PushPull, GPIO_Output_LS);
    GPIO_voidSetPinMode(SevenSegment_Data3, GPIO_OUTPUT);
    GPIO_voidOutputPinConfig(SevenSegment_Data3, GPIO_PushPull, GPIO_Output_LS);
    GPIO_voidSetPinMode(SevenSegment_Data4, GPIO_OUTPUT);
    GPIO_voidOutputPinConfig(SevenSegment_Data4, GPIO_PushPull, GPIO_Output_LS);
    // SSD Turn OFF
    GPIO_voidSetPinValue(SevenSegment_1Enable, GPIO_LOW);
    GPIO_voidSetPinValue(SevenSegment_2Enable, GPIO_LOW);
}
void SevenSegment_voidDisplay(U8 Num)
{
	/*
    if (Num <= 10)
    {
        Num *= 10;
        GPIO_voidSetPinValue(SevenSegment_DP, GPIO_HIGH);
    }*/
    U8 SevenSegment_First_Digit = ((U8)Num / 10);
    U8 SevenSegment_Second_Digit = ((U8)Num % 10);
    if (/*Num > 10 && */Num < 100)
    {

        // Enable SSD1 & Disable SSD2
        GPIO_voidSetPinValue(SevenSegment_1Enable, GPIO_HIGH);
        GPIO_voidSetPinValue(SevenSegment_2Enable, GPIO_LOW);
        // Write First Digit
        //GPIO_SetPortValueAtomicly(SevenSegment_Data_PORT, SevenSegment_First_Digit);

        GPIO_voidSetPinValue(SevenSegment_Data1, GetBit(SevenSegment_First_Digit, 0));
        GPIO_voidSetPinValue(SevenSegment_Data2, GetBit(SevenSegment_First_Digit, 1));
        GPIO_voidSetPinValue(SevenSegment_Data3, GetBit(SevenSegment_First_Digit, 2));
        GPIO_voidSetPinValue(SevenSegment_Data4, GetBit(SevenSegment_First_Digit, 3));

        SysTick_voidDellayMS_FSysTickMhz(1, SysTickFrequanct);
        // Disable SSD1 & Enable SSD2
        GPIO_voidSetPinValue(SevenSegment_1Enable, GPIO_LOW);
        GPIO_voidSetPinValue(SevenSegment_2Enable, GPIO_HIGH);
        // Write First Digit

        //GPIO_SetPortValueAtomicly(SevenSegment_Data_PORT, SevenSegment_Second_Digit);

        GPIO_voidSetPinValue(SevenSegment_Data1, GetBit(SevenSegment_Second_Digit, 0));
        GPIO_voidSetPinValue(SevenSegment_Data2, GetBit(SevenSegment_Second_Digit, 1));
        GPIO_voidSetPinValue(SevenSegment_Data3, GetBit(SevenSegment_Second_Digit, 2));
        GPIO_voidSetPinValue(SevenSegment_Data4, GetBit(SevenSegment_Second_Digit, 3));

        SysTick_voidDellayMS_FSysTickMhz(1, SysTickFrequanct);
    }
    else
    {
        GPIO_voidSetPinValue(SevenSegment_1Enable, GPIO_LOW);
        GPIO_voidSetPinValue(SevenSegment_2Enable, GPIO_LOW);
    }
}
void SevenSegment_voidDisplay_With_Delay(U8 Num, U32 Delay)
{
    for (U32 Count = 0; Count < Delay; Count++)
    {
        SevenSegment_voidDisplay(Num);
        SysTick_voidDellayMS_FSysTickMhz(1, SysTickFrequanct);
    }
}
