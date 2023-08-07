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
#include "GPIO_Interface.h"
#include "GPIO_Private.h"
#include "GPIO_Config.h"
/*Driver*/
void GPIO_voidSetPinMode(GPIO_PINS_t Copy_PinID, GPIO_PinMode_t Copy_PinMode)
{
    GPIO_PORT_t PortID = Copy_PinID / 16;
    GPIO_PINS_t PinID = Copy_PinID % 16;
    switch (Copy_PinMode)
    {
    case GPIO_INPUT: // 00
        switch (PortID)
        {
        case GPIO_PortA:
            ClearBit(GPIOA.MODER, PinID_Bit1);
            ClearBit(GPIOA.MODER, PinID_Bit2);
            break;
        case GPIO_PortB:
            ClearBit(GPIOB.MODER, PinID_Bit1);
            ClearBit(GPIOB.MODER, PinID_Bit2);
            break;
        case GPIO_PortC:
            ClearBit(GPIOC.MODER, PinID_Bit1);
            ClearBit(GPIOC.MODER, PinID_Bit2);
            break;
        }
        break;
    case GPIO_OUTPUT: // 01
        switch (PortID)
        {
        case GPIO_PortA:
            SetBit(GPIOA.MODER, PinID_Bit1);
            ClearBit(GPIOA.MODER, PinID_Bit2);
            break;
        case GPIO_PortB:
            SetBit(GPIOB.MODER, PinID_Bit1);
            ClearBit(GPIOB.MODER, PinID_Bit2);
            break;
        case GPIO_PortC:
            SetBit(GPIOC.MODER, PinID_Bit1);
            ClearBit(GPIOC.MODER, PinID_Bit2);
            break;
        }
        break;
    case GPIO_AltFunc: // 10
        switch (PortID)
        {
        case GPIO_PortA:
            ClearBit(GPIOA.MODER, PinID_Bit1);
            SetBit(GPIOA.MODER, PinID_Bit2);
            break;
        case GPIO_PortB:
            ClearBit(GPIOB.MODER, PinID_Bit1);
            SetBit(GPIOB.MODER, PinID_Bit2);
            break;
        case GPIO_PortC:
            ClearBit(GPIOC.MODER, PinID_Bit1);
            SetBit(GPIOC.MODER, PinID_Bit2);
            break;
        }
        break;
    case GPIO_ANALOG: // 11
        switch (PortID)
        {
        case GPIO_PortA:
            SetBit(GPIOA.MODER, PinID_Bit1);
            SetBit(GPIOA.MODER, PinID_Bit2);
            break;
        case GPIO_PortB:
            SetBit(GPIOB.MODER, PinID_Bit1);
            SetBit(GPIOB.MODER, PinID_Bit2);
            break;
        case GPIO_PortC:
            SetBit(GPIOC.MODER, PinID_Bit1);
            SetBit(GPIOC.MODER, PinID_Bit2);
            break;
        }
        break;
    }
}
void GPIO_voidInputPinConfig(GPIO_PINS_t Copy_PinID, GPIO_InputPinMode_t Copy_InputPinMode)
{
    GPIO_PORT_t PortID = Copy_PinID / 16;
    GPIO_PINS_t PinID = Copy_PinID % 16;
    switch (Copy_InputPinMode)
    {
    case GPIO_FLOATING: // 00
        switch (PortID)
        {
        case GPIO_PortA:
            ClearBit(GPIOA.PUPDR, PinID_Bit1);
            ClearBit(GPIOA.PUPDR, PinID_Bit2);
            break;
        case GPIO_PortB:
            ClearBit(GPIOB.PUPDR, PinID_Bit1);
            ClearBit(GPIOB.PUPDR, PinID_Bit2);
            break;
        case GPIO_PortC:
            ClearBit(GPIOC.PUPDR, PinID_Bit1);
            ClearBit(GPIOC.PUPDR, PinID_Bit2);
            break;
        }
        break;
    case GPIO_PullUp: // 01
        switch (PortID)
        {
        case GPIO_PortA:
            SetBit(GPIOA.PUPDR, PinID_Bit1);
            ClearBit(GPIOA.PUPDR, PinID_Bit2);
            break;
        case GPIO_PortB:
            SetBit(GPIOB.PUPDR, PinID_Bit1);
            ClearBit(GPIOB.PUPDR, PinID_Bit2);
            break;
        case GPIO_PortC:
            SetBit(GPIOC.PUPDR, PinID_Bit1);
            ClearBit(GPIOC.PUPDR, PinID_Bit2);
            break;
        }
        break;
    case GPIO_PullDown: // 10
        switch (PortID)
        {
        case GPIO_PortA:
            ClearBit(GPIOA.PUPDR, PinID_Bit1);
            SetBit(GPIOA.PUPDR, PinID_Bit2);
            break;
        case GPIO_PortB:
            ClearBit(GPIOB.PUPDR, PinID_Bit1);
            SetBit(GPIOB.PUPDR, PinID_Bit2);
            break;
        case GPIO_PortC:
            ClearBit(GPIOC.PUPDR, PinID_Bit1);
            SetBit(GPIOC.PUPDR, PinID_Bit2);
            break;
        }
        break;
    }
}
void GPIO_voidOutputPinConfig(GPIO_PINS_t Copy_PinID, GPIO_OutputPinMode_t Copy_OutputPinMode, GPIO_OutputPinSpeed_t Copy_OutputPinSpeed)
{
    GPIO_PORT_t PortID = Copy_PinID / 16;
    GPIO_PINS_t PinID = Copy_PinID % 16;

    switch (Copy_OutputPinMode)
    {
    case GPIO_PushPull: // 0
        switch (PortID)
        {
        case GPIO_PortA:
            ClearBit(GPIOA.OTYPER, PinID);
            break;
        case GPIO_PortB:
            ClearBit(GPIOB.OTYPER, PinID);
            break;
        case GPIO_PortC:
            ClearBit(GPIOC.OTYPER, PinID);
            break;
        }
        break;
    case GPIO_OpenDrain: // 1
        switch (PortID)
        {
        case GPIO_PortA:
            SetBit(GPIOA.OTYPER, PinID);
            break;
        case GPIO_PortB:
            SetBit(GPIOB.OTYPER, PinID);
            break;
        case GPIO_PortC:
            SetBit(GPIOC.OTYPER, PinID);
            break;
        }
        break;
    }

    switch (Copy_OutputPinSpeed)
    {
    case GPIO_Output_LS: // 00
        switch (PortID)
        {
        case GPIO_PortA:
            ClearBit(GPIOA.OSPEEDR, PinID_Bit1);
            ClearBit(GPIOA.OSPEEDR, PinID_Bit2);
            break;
        case GPIO_PortB:
            ClearBit(GPIOB.OSPEEDR, PinID_Bit1);
            ClearBit(GPIOB.OSPEEDR, PinID_Bit2);
            break;
        case GPIO_PortC:
            ClearBit(GPIOC.OSPEEDR, PinID_Bit1);
            ClearBit(GPIOC.OSPEEDR, PinID_Bit2);
            break;
        }
        break;
    case GPIO_Output_MS: // 01
        switch (PortID)
        {
        case GPIO_PortA:
            SetBit(GPIOA.OSPEEDR, PinID_Bit1);
            ClearBit(GPIOA.OSPEEDR, PinID_Bit2);
            break;
        case GPIO_PortB:
            SetBit(GPIOB.OSPEEDR, PinID_Bit1);
            ClearBit(GPIOB.OSPEEDR, PinID_Bit2);
            break;
        case GPIO_PortC:
            SetBit(GPIOC.OSPEEDR, PinID_Bit1);
            ClearBit(GPIOC.OSPEEDR, PinID_Bit2);
            break;
        }
        break;
    case GPIO_Output_HS: // 10
        switch (PortID)
        {
        case GPIO_PortA:
            ClearBit(GPIOA.OSPEEDR, PinID_Bit1);
            SetBit(GPIOA.OSPEEDR, PinID_Bit2);
            break;
        case GPIO_PortB:
            ClearBit(GPIOB.OSPEEDR, PinID_Bit1);
            SetBit(GPIOB.OSPEEDR, PinID_Bit2);
            break;
        case GPIO_PortC:
            ClearBit(GPIOC.OSPEEDR, PinID_Bit1);
            SetBit(GPIOC.OSPEEDR, PinID_Bit2);
            break;
        }
        break;
    }
}
void GPIO_voidSetPinValue(GPIO_PINS_t Copy_PinID, GPIO_PinValue_t Copy_PinValue)
{
    GPIO_PORT_t PortID = Copy_PinID / 16;
    GPIO_PINS_t PinID = Copy_PinID % 16;
    switch (Copy_PinValue)
    {
    case GPIO_LOW: // 0
        switch (PortID)
        {
        case GPIO_PortA:
            ClearBit(GPIOA.ODR, PinID);
            break;
        case GPIO_PortB:
            ClearBit(GPIOB.ODR, PinID);
            break;
        case GPIO_PortC:
            ClearBit(GPIOC.ODR, PinID);
            break;
        }
        break;
    case GPIO_HIGH: // 1
        switch (PortID)
        {
        case GPIO_PortA:
            SetBit(GPIOA.ODR, PinID);
            break;
        case GPIO_PortB:
            SetBit(GPIOB.ODR, PinID);
            break;
        case GPIO_PortC:
            SetBit(GPIOC.ODR, PinID);
            break;
        }
        break;
    }
}
void GPIO_voidSetPinValueAtomicly(GPIO_PINS_t Copy_PinID, GPIO_PinValue_t Copy_PinValue)
{
    GPIO_PORT_t PortID = Copy_PinID / 16;
    GPIO_PINS_t PinID = Copy_PinID % 16;
    switch (Copy_PinValue)
    {
    case GPIO_LOW: // 0
        switch (PortID)
        {
        case GPIO_PortA:
            GPIOA.BSRR = AtomicRst_Bit;
            break;
        case GPIO_PortB:
            GPIOB.BSRR = AtomicRst_Bit;
            break;
        case GPIO_PortC:
            GPIOC.BSRR = AtomicRst_Bit;
            break;
        }
        break;
    case GPIO_HIGH: // 1
        switch (PortID)
        {
        case GPIO_PortA:
            GPIOA.BSRR = AtomicSet_Bit;
            break;
        case GPIO_PortB:
            GPIOB.BSRR = AtomicSet_Bit;
            break;
        case GPIO_PortC:
            GPIOC.BSRR = AtomicSet_Bit;
            break;
        }
        break;
    }
}
GPIO_PinValue_t GPIO_U8GetPinValue(GPIO_PINS_t Copy_PinID)
{
    GPIO_PORT_t PortID = Copy_PinID / 16;
    GPIO_PINS_t PinID = Copy_PinID % 16;
    switch (PortID)
    {
    case GPIO_PortA:
        return GetBit(GPIOA.IDR, PinID);
        break;
    case GPIO_PortB:
        return GetBit(GPIOB.IDR, PinID);
        break;
    case GPIO_PortC:
        return GetBit(GPIOC.IDR, PinID);
        break;
    }
}
void GPIO_SetPortValue(GPIO_PORT_t Copy_PortID, U16 Copy_Value)
{
    switch (Copy_PortID)
    {
    case GPIO_PortA:
        *((U16 *)GPIOA.ODR) = Copy_Value;
        break;
    case GPIO_PortB:
        *((U16 *)GPIOB.ODR) = Copy_Value;
        break;
    case GPIO_PortC:
        *((U16 *)GPIOC.ODR) = Copy_Value;
        break;
    }
}
void GPIO_SetPortValueAtomicly(GPIO_PORT_t Copy_PortID, U16 Copy_Value)
{
    switch (Copy_PortID)
    {
    case GPIO_PortA:
        *((U16 *)GPIOA.BSRR) = Copy_Value;
        break;
    case GPIO_PortB:
        *((U16 *)GPIOB.BSRR) = Copy_Value;
        break;
    case GPIO_PortC:
        *((U16 *)GPIOC.BSRR) = Copy_Value;
        break;
    }
}