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

/*File Gard*/
#ifndef BUZZZER_INTERFACE_H
#define BUZZZER_INTERFACE_H
/*Options*/
typedef enum
{
    BUZZER_OFF = 0,
    BUZZER_ON
}BUZZERState_t;
/*functions Prototypes*/
void BUZZER_voidConfig(GPIO_PINS_t Copy_PinID, GPIO_OutputPinMode_t Copy_OutputPinMode, GPIO_OutputPinSpeed_t Copy_OutputPinSpeed);
void BUZZER_voidSetBuzzer(GPIO_PINS_t Copy_PinID, BUZZERState_t Copy_State);
#endif // !BUZZER_INTERFACE_H
