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
#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H
/*Options*/
typedef enum
{
    LED_OFF = 0,
    LED_ON
} LEDState_t;
/*functions Prototypes*/
void LED_voidConfig(GPIO_PINS_t Copy_PinID, GPIO_OutputPinMode_t Copy_OutputPinMode, GPIO_OutputPinSpeed_t Copy_OutputPinSpeed);
void LED_voidSetLED(GPIO_PINS_t Copy_PinID, LEDState_t Copy_State);
#endif // !LED_INTERFACE_H
