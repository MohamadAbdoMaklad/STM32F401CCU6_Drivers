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
    
}
void LEDMATRIX_voidSetRowVlaues(U8 Copy_u8Frame);
/*Interface Functions*/
void LEDMATRIX_voidInit(void)
{
    /*Set mode for Colomns __> Outputs*/
    GPIO_voidSetPinMode(LedMatrix_C0,GPIO_OUTPUT);
    GPIO_voidSetPinMode(LedMatrix_C1,GPIO_OUTPUT);
    GPIO_voidSetPinMode(LedMatrix_C2,GPIO_OUTPUT);
    GPIO_voidSetPinMode(LedMatrix_C3,GPIO_OUTPUT);
    GPIO_voidSetPinMode(LedMatrix_C4,GPIO_OUTPUT);
    GPIO_voidSetPinMode(LedMatrix_C5,GPIO_OUTPUT);
    GPIO_voidSetPinMode(LedMatrix_C6,GPIO_OUTPUT);
    GPIO_voidSetPinMode(LedMatrix_C7,GPIO_OUTPUT);
    /*Set mode for Rows __> Outputs*/
    GPIO_voidSetPinMode(LedMatrix_R0,GPIO_OUTPUT);
    GPIO_voidSetPinMode(LedMatrix_R1,GPIO_OUTPUT);
    GPIO_voidSetPinMode(LedMatrix_R2,GPIO_OUTPUT);
    GPIO_voidSetPinMode(LedMatrix_R3,GPIO_OUTPUT);
    GPIO_voidSetPinMode(LedMatrix_R4,GPIO_OUTPUT);
    GPIO_voidSetPinMode(LedMatrix_R5,GPIO_OUTPUT);
    GPIO_voidSetPinMode(LedMatrix_R6,GPIO_OUTPUT);
    GPIO_voidSetPinMode(LedMatrix_R7,GPIO_OUTPUT);
    /*Set Colomns Options__> Outputs*/
    GPIO_voidOutputPinConfig(LedMatrix_C0,GPIO_PushPull,GPIO_Output_LS);
    GPIO_voidOutputPinConfig(LedMatrix_C1,GPIO_PushPull,GPIO_Output_LS);
    GPIO_voidOutputPinConfig(LedMatrix_C2,GPIO_PushPull,GPIO_Output_LS);
    GPIO_voidOutputPinConfig(LedMatrix_C3,GPIO_PushPull,GPIO_Output_LS);
    GPIO_voidOutputPinConfig(LedMatrix_C4,GPIO_PushPull,GPIO_Output_LS);
    GPIO_voidOutputPinConfig(LedMatrix_C5,GPIO_PushPull,GPIO_Output_LS);
    GPIO_voidOutputPinConfig(LedMatrix_C6,GPIO_PushPull,GPIO_Output_LS);
    GPIO_voidOutputPinConfig(LedMatrix_C7,GPIO_PushPull,GPIO_Output_LS);
    /*Set Rows Options__> Outputs*/
    GPIO_voidOutputPinConfig(LedMatrix_R0,GPIO_PushPull,GPIO_Output_LS);
    GPIO_voidOutputPinConfig(LedMatrix_R1,GPIO_PushPull,GPIO_Output_LS);
    GPIO_voidOutputPinConfig(LedMatrix_R2,GPIO_PushPull,GPIO_Output_LS);
    GPIO_voidOutputPinConfig(LedMatrix_R3,GPIO_PushPull,GPIO_Output_LS);
    GPIO_voidOutputPinConfig(LedMatrix_R4,GPIO_PushPull,GPIO_Output_LS);
    GPIO_voidOutputPinConfig(LedMatrix_R5,GPIO_PushPull,GPIO_Output_LS);
    GPIO_voidOutputPinConfig(LedMatrix_R6,GPIO_PushPull,GPIO_Output_LS);
    GPIO_voidOutputPinConfig(LedMatrix_R7,GPIO_PushPull,GPIO_Output_LS);
}
void LEDMATRIX_voidDisplay(U8 *Copy_u8Frame);
