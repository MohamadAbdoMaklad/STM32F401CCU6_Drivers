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
#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

typedef enum
{
    // Port A (0 To 15)
    GPIO_A0 = 0, // 0
    GPIO_A1,
    GPIO_A2,
    GPIO_A3,
    GPIO_A4,
    GPIO_A5,
    GPIO_A6,
    GPIO_A7,
    GPIO_A8,
    GPIO_A9,
    GPIO_A10,
    GPIO_A11,
    GPIO_A12,
    GPIO_A13,
    GPIO_A14,
    GPIO_A15, // 15
              //  Port B (0 To 15)
    GPIO_B0, // 16
    GPIO_B1,
    GPIO_B2,
    GPIO_B3,
    GPIO_B4,
    GPIO_B5,
    GPIO_B6,
    GPIO_B7,
    GPIO_B8,
    GPIO_B9,
    GPIO_B10,
    GPIO_B11,
    GPIO_B12,
    GPIO_B13,
    GPIO_B14,
    GPIO_B15, // 31
              //  Port C (13 To 15)
    GPIO_C13 = 45, // 45
    GPIO_C14 = 46,
    GPIO_C15 = 47
} GPIO_PINS_t;
typedef enum
{
    GPIO_PortA = 0,
    GPIO_PortB,
    GPIO_PortC
} GPIO_PORT_t;
typedef enum
{
    GPIO_INPUT = 0,
    GPIO_OUTPUT,
    GPIO_AltFunc,
    GPIO_ANALOG
} GPIO_PinMode_t;
typedef enum
{
    GPIO_FLOATING = 0,
    GPIO_PullUp,
    GPIO_PullDown
} GPIO_InputPinMode_t;
typedef enum
{
    GPIO_PushPull = 0,
    GPIO_OpenDrain
} GPIO_OutputPinMode_t;
typedef enum
{
    GPIO_Output_LS = 0, // 8MHZ
    GPIO_Output_MS,     // 50MHz
    GPIO_Output_HS      // 80MHz
    // GPIO_Output_VHS     // 150MHz Not USed For STM32F401CCU6
} GPIO_OutputPinSpeed_t;
typedef enum
{
    GPIO_LOW = 0,
    GPIO_HIGH
} GPIO_PinValue_t;
void GPIO_voidSetPinMode(GPIO_PINS_t Copy_PinID, GPIO_PinMode_t Copy_PinMode);
void GPIO_voidInputPinConfig(GPIO_PINS_t Copy_PinID,GPIO_InputPinMode_t Copy_InputPinMode);

void GPIO_voidOutputPinConfig(GPIO_PINS_t Copy_PinID,GPIO_OutputPinMode_t Copy_OutputPinMode, GPIO_OutputPinSpeed_t Copy_OutputPinSpeed);
void GPIO_voidSetPinValue(GPIO_PINS_t Copy_PinID,GPIO_PinValue_t Copy_PinValue);
void GPIO_voidSetPinValueAtomicly(GPIO_PINS_t Copy_PinID,GPIO_PinValue_t Copy_PinValue);
GPIO_PinValue_t GPIO_U8GetPinValue(GPIO_PINS_t Copy_PinID);
void GPIO_SetPortValue(GPIO_PORT_t Copy_PortID, U16 Copy_Value);
void GPIO_SetPortValueAtomicly(GPIO_PORT_t Copy_PortID, U16 Copy_Value);

#endif // !GPIO_INTERFACE_H
