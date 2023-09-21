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
/*Driver Files Includes*/
#include "STP_Interface.h"
#include "STP_Private.h"
#include "STP_Config.h"
/*Driver*/
void voidSendData(U8 Copy_U8Data)
{ 
    U8 i;
    for (i = 7;i>=0;i--)
    {
        GPIO_voidSetPinValue(STP_SerialPin,GetBit(Copy_U8Data,i));

        GPIO_voidSetPinValue(STP_SH_Clock,GetBit(Copy_U8Data,i));
        SysTick_SetBusyWait(1);
        GPIO_voidSetPinValue(STP_SH_Clock,GetBit(Copy_U8Data,i));
        SysTick_SetBusyWait(1);
    }
    GPIO_voidSetPinValue(STP_ST_Clock,GetBit(Copy_U8Data,i));
    SysTick_SetBusyWait(1);
    GPIO_voidSetPinValue(STP_ST_Clock,GetBit(Copy_U8Data,i));
    SysTick_SetBusyWait(1);
}