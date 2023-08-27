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
#include "LED_Matrix_Interface.h"
#include "LED_Matrix_Private.h"
#include "LED_Matrix_Config.h"
/*Driver*/
/*Private Functions*/
void LEDMATRIX_voidDisableCols(void)
{
    GPIO_voidSetPinValue(LedMatrix_C0, GPIO_HIGH);
    GPIO_voidSetPinValue(LedMatrix_C1, GPIO_HIGH);
    GPIO_voidSetPinValue(LedMatrix_C2, GPIO_HIGH);
    GPIO_voidSetPinValue(LedMatrix_C3, GPIO_HIGH);
    GPIO_voidSetPinValue(LedMatrix_C4, GPIO_HIGH);
    GPIO_voidSetPinValue(LedMatrix_C5, GPIO_HIGH);
    GPIO_voidSetPinValue(LedMatrix_C6, GPIO_HIGH);
    GPIO_voidSetPinValue(LedMatrix_C7, GPIO_HIGH);
}
void LEDMATRIX_voidSetRowVlaues(U8 Copy_u8Frame)
{
    GPIO_voidSetPinValue(LedMatrix_C0, GetBit(Copy_u8Frame,0));
    GPIO_voidSetPinValue(LedMatrix_C1, GetBit(Copy_u8Frame,1));
    GPIO_voidSetPinValue(LedMatrix_C2, GetBit(Copy_u8Frame,2));
    GPIO_voidSetPinValue(LedMatrix_C3, GetBit(Copy_u8Frame,3));
    GPIO_voidSetPinValue(LedMatrix_C4, GetBit(Copy_u8Frame,4));
    GPIO_voidSetPinValue(LedMatrix_C5, GetBit(Copy_u8Frame,5));
    GPIO_voidSetPinValue(LedMatrix_C6, GetBit(Copy_u8Frame,6));
    GPIO_voidSetPinValue(LedMatrix_C7, GetBit(Copy_u8Frame,7));
}
/*Interface Functions*/
void LEDMATRIX_voidInit(void)
{
    /*Set mode for Colomns __> Outputs*/
    GPIO_voidSetPinMode(LedMatrix_C0, GPIO_OUTPUT);
    GPIO_voidSetPinMode(LedMatrix_C1, GPIO_OUTPUT);
    GPIO_voidSetPinMode(LedMatrix_C2, GPIO_OUTPUT);
    GPIO_voidSetPinMode(LedMatrix_C3, GPIO_OUTPUT);
    GPIO_voidSetPinMode(LedMatrix_C4, GPIO_OUTPUT);
    GPIO_voidSetPinMode(LedMatrix_C5, GPIO_OUTPUT);
    GPIO_voidSetPinMode(LedMatrix_C6, GPIO_OUTPUT);
    GPIO_voidSetPinMode(LedMatrix_C7, GPIO_OUTPUT);
    /*Set mode for Rows __> Outputs*/
    GPIO_voidSetPinMode(LedMatrix_R0, GPIO_OUTPUT);
    GPIO_voidSetPinMode(LedMatrix_R1, GPIO_OUTPUT);
    GPIO_voidSetPinMode(LedMatrix_R2, GPIO_OUTPUT);
    GPIO_voidSetPinMode(LedMatrix_R3, GPIO_OUTPUT);
    GPIO_voidSetPinMode(LedMatrix_R4, GPIO_OUTPUT);
    GPIO_voidSetPinMode(LedMatrix_R5, GPIO_OUTPUT);
    GPIO_voidSetPinMode(LedMatrix_R6, GPIO_OUTPUT);
    GPIO_voidSetPinMode(LedMatrix_R7, GPIO_OUTPUT);
    /*Set Colomns Options__> Outputs*/
    GPIO_voidOutputPinConfig(LedMatrix_C0, GPIO_PushPull, GPIO_Output_LS);
    GPIO_voidOutputPinConfig(LedMatrix_C1, GPIO_PushPull, GPIO_Output_LS);
    GPIO_voidOutputPinConfig(LedMatrix_C2, GPIO_PushPull, GPIO_Output_LS);
    GPIO_voidOutputPinConfig(LedMatrix_C3, GPIO_PushPull, GPIO_Output_LS);
    GPIO_voidOutputPinConfig(LedMatrix_C4, GPIO_PushPull, GPIO_Output_LS);
    GPIO_voidOutputPinConfig(LedMatrix_C5, GPIO_PushPull, GPIO_Output_LS);
    GPIO_voidOutputPinConfig(LedMatrix_C6, GPIO_PushPull, GPIO_Output_LS);
    GPIO_voidOutputPinConfig(LedMatrix_C7, GPIO_PushPull, GPIO_Output_LS);
    /*Set Rows Options__> Outputs*/
    GPIO_voidOutputPinConfig(LedMatrix_R0, GPIO_PushPull, GPIO_Output_LS);
    GPIO_voidOutputPinConfig(LedMatrix_R1, GPIO_PushPull, GPIO_Output_LS);
    GPIO_voidOutputPinConfig(LedMatrix_R2, GPIO_PushPull, GPIO_Output_LS);
    GPIO_voidOutputPinConfig(LedMatrix_R3, GPIO_PushPull, GPIO_Output_LS);
    GPIO_voidOutputPinConfig(LedMatrix_R4, GPIO_PushPull, GPIO_Output_LS);
    GPIO_voidOutputPinConfig(LedMatrix_R5, GPIO_PushPull, GPIO_Output_LS);
    GPIO_voidOutputPinConfig(LedMatrix_R6, GPIO_PushPull, GPIO_Output_LS);
    GPIO_voidOutputPinConfig(LedMatrix_R7, GPIO_PushPull, GPIO_Output_LS);
}
void LEDMATRIX_voidDisplay(U8 *Copy_u8Frame)
{
    for (U8 i =0;i<8;i++)
    {
        LEDMATRIX_voidDisableCols();
        LEDMATRIX_voidSetRowVlaues(Copy_u8Frame[i]);
        switch (i)
        {
        case 0:GPIO_voidSetPinValue(LedMatrix_C0, GPIO_HIGH);break;
        case 1:GPIO_voidSetPinValue(LedMatrix_C1, GPIO_HIGH);break;
        case 2:GPIO_voidSetPinValue(LedMatrix_C2, GPIO_HIGH);break;
        case 3:GPIO_voidSetPinValue(LedMatrix_C3, GPIO_HIGH);break;
        case 4:GPIO_voidSetPinValue(LedMatrix_C4, GPIO_HIGH);break;
        case 5:GPIO_voidSetPinValue(LedMatrix_C5, GPIO_HIGH);break;
        case 6:GPIO_voidSetPinValue(LedMatrix_C6, GPIO_HIGH);break;
        case 7:GPIO_voidSetPinValue(LedMatrix_C7, GPIO_HIGH);break;
        };
        SysTick_SetBusyWait(2500);
    }
}
