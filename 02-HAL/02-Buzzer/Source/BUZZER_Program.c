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
/*Driver Files Includes*/
#include "BUZZER_Interface.h"
#include "BUZZER_Private.h"
#include "BUZZER_Config.h"
/*Driver*/
void BUZZER_voidConfig(GPIO_PINS_t Copy_PinID,GPIO_OutputPinMode_t Copy_OutputPinMode, GPIO_OutputPinSpeed_t Copy_OutputPinSpeed)
{
    GPIO_voidSetPinMode(Copy_PinID,GPIO_OUTPUT);
    GPIO_voidOutputPinConfig(Copy_PinID,Copy_OutputPinMode,Copy_OutputPinSpeed);
}
void BUZZER_voidSetLED(GPIO_PINS_t Copy_PinID,BUZZERState_t Copy_State)
{
    GPIO_voidSetPinValue(Copy_PinID,Copy_State);
}