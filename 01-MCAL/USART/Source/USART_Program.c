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
#include "RCC_Interface.h"
#include "GPIO_Interface.h"
/*Driver Files Includes*/
#include "USART_Interface.h"
#include "USART_Private.h"
#include "USART_Config.h"
/*Driver*/
void USART_voidInit(void)
{
    RCC_voidPeripheralClk(USART1,EnablePeripheral,HighPowerMode);
    GPIO_voidSetPinMode(GPIO_A9, GPIO_AltFunc);
    GPIO_voidSetPinMode(GPIO_A10, GPIO_AltFunc);
    GPIO_voidSetPinUlternativeFunction(GPIO_A9,AF7);
    GPIO_voidSetPinUlternativeFunction(GPIO_A10,AF7);
    /*
    USART.CR1.PCE = STD_Low;
    USART.CR1.M = STD_Low;
    USART.CR1.OVER8 = STD_Low;
    USART.CR2.STOP = STD_Low;*/
    USART.CR1.UE = STD_High;
    USART.CR1.RE = STD_High;
    USART.CR1.TE = STD_High;
    USART.BRR = 0x341 ;//0x341; 0x682
}
void USATR_voidTXDate(U8 Copy_U8Data)
{
    USART.DR = Copy_U8Data;
    while(USART.SR.TC == 0);
    USART.SR.TC = 0;
}
U8 USATR_U8RXDate(void)
{
    U32 Data =0;

    while(USART.SR.RXNE == 0);
    Data = USART.DR;
    USART.SR.RXNE = 0;
    return Data;
}
