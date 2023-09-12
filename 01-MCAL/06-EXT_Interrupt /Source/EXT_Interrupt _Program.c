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
#include <stdio.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*Lower Layer Includes*/
/*Driver Files Includes*/
#include "EXT_Interrupt_Private.h"
#include "EXT_Interrupt_Interface.h"
#include "EXT_Interrupt_Config.h"
/*pointer to Function*/
void (*__EXTI__0 )(void) = NULL;
void (*__EXTI__1 )(void) = NULL;
void (*__EXTI__2 )(void) = NULL;
void (*__EXTI__3 )(void) = NULL;
void (*__EXTI__4 )(void) = NULL;
void (*__EXTI__5 )(void) = NULL;
void (*__EXTI__6 )(void) = NULL;
void (*__EXTI__7 )(void) = NULL;
void (*__EXTI__8 )(void) = NULL;
void (*__EXTI__9 )(void) = NULL;
void (*__EXTI__10)(void) = NULL;
void (*__EXTI__11)(void) = NULL;
void (*__EXTI__12)(void) = NULL;
void (*__EXTI__13)(void) = NULL;
void (*__EXTI__14)(void) = NULL;
void (*__EXTI__15)(void) = NULL;

U16 Externl_Interrupt_Flags = 0b0000000000000000;
#define SetExtFlag(EXTno)   (Externl_Interrupt_Flags |=(1U<<EXTno))
#define ClearExtFlag(EXTno)   (Externl_Interrupt_Flags &=~(1U<<EXTno))
#define GetExtFlag(EXTno)     ((Externl_Interrupt_Flags>>EXTno)&1U)
/*Driver*/
void EXTI_voidSetExtiLineEnable(EXTI_Line_t Copy_LineId,EXT_Trig_t Copy_Treg)
{
    U8 EXTI_LineVal = Copy_LineId/16;
    U8 EXTI_PinVal = Copy_LineId%16;
    if ((EXTI_PinVal >= 0) && (EXTI_PinVal <= 3))
    {
        ModRegBits(SYSCFG.EXTICR[0], 4, (EXTI_PinVal * 4), Copy_Treg);
    }
    else if ((EXTI_PinVal >= 4) && (EXTI_PinVal <= 7))
    {
        ModRegBits(SYSCFG.EXTICR[1], 4, ((EXTI_PinVal - 4) * 4), Copy_Treg);
    }
    else if ((EXTI_PinVal >= 8) && (EXTI_PinVal <= 11))
    {
        ModRegBits(SYSCFG.EXTICR[2], 4, ((EXTI_PinVal - 8) * 4), Copy_Treg);
    }
    else if ((EXTI_PinVal >= 12) && (EXTI_PinVal <= 15))
    {
        ModRegBits(SYSCFG.EXTICR[3], 4, ((EXTI_PinVal - 12) * 4), Copy_Treg);
    }

    switch (Copy_Treg)
    {
    case FallingEdge:
        SetBit(ExtInt.FTSR, EXTI_LineVal);
        ClearBit(ExtInt.RTSR, EXTI_LineVal);
        break;
    case RisingEdge:
        ClearBit(ExtInt.FTSR, EXTI_LineVal);
        SetBit(ExtInt.RTSR, EXTI_LineVal);
        break;
    case OnChange:
        SetBit(ExtInt.FTSR, EXTI_LineVal);
        SetBit(ExtInt.RTSR, EXTI_LineVal);
        break;
    default:
        break;
    }
    SetBit(ExtInt.IMR,EXTI_PinVal);
}
void EXTI_voidSetExtiLineDisable(EXTI_Line_t Copy_LineId)
{
    ClearBit(ExtInt.IMR,(Copy_LineId%16));
}
void EXTI_voidSetSenseControl(EXTI_Line_t Copy_LineId,EXT_Trig_t Copy_Treg)
{
    U8 EXTI_LineVal = Copy_LineId/16;
    switch (Copy_Treg)
    {
    case FallingEdge:
        SetBit(ExtInt.FTSR,EXTI_LineVal);
        ClearBit(ExtInt.RTSR,EXTI_LineVal);
        break;
    case RisingEdge:
        ClearBit(ExtInt.FTSR,EXTI_LineVal);
        SetBit(ExtInt.RTSR,EXTI_LineVal);
        break;
    case OnChange:
        SetBit(ExtInt.FTSR,EXTI_LineVal);
        SetBit(ExtInt.RTSR,EXTI_LineVal);
        break;
    default: break;
    }
}
void EXTI_voidSetCallBack(EXTI_Line_t Copy_LineId,void (*LpF)(void))
{
    U8 EXTI_LineVal = Copy_LineId/16;
    switch (EXTI_LineVal)
    {
    case 0 :__EXTI__0  = LpF;break;
    case 1 :__EXTI__1  = LpF;break;
    case 2 :__EXTI__2  = LpF;break;
    case 3 :__EXTI__3  = LpF;break;
    case 4 :__EXTI__4  = LpF;break;
    case 5 :__EXTI__5  = LpF;break;
    case 6 :__EXTI__6  = LpF;break;
    case 7 :__EXTI__7  = LpF;break;
    case 8 :__EXTI__8  = LpF;break;
    case 9 :__EXTI__9  = LpF;break;
    case 10:__EXTI__10 = LpF;break;
    case 11:__EXTI__11 = LpF;break;
    case 12:__EXTI__12 = LpF;break;
    case 13:__EXTI__13 = LpF;break;
    case 14:__EXTI__14 = LpF;break;
    case 15:__EXTI__15 = LpF;break;
    default: break;
    };
}

/*External IRQHandlers*/
void EXTI0_IRQHandler()
{
    if ((__EXTI__0 != NULL)&&(GetExtFlag(0)==1))
    {
        __EXTI__0();
        SET_BIT(ExtInt.PR, 0);
    }
}
void EXTI1_IRQHandler()
{
    if ((__EXTI__1 != NULL)&&(GetExtFlag(1)==1))
    {
        __EXTI__1();
        SET_BIT(ExtInt.PR,1);
    }
}
void EXTI2_IRQHandler()
{
    if ((__EXTI__2 != NULL)&&(GetExtFlag(2)==1))
    {
        __EXTI__2();
        SET_BIT(ExtInt.PR,2);
    }
}
void EXTI3_IRQHandler()
{
    if ((__EXTI__3 != NULL)&&(GetExtFlag(3)==1))
    {
        __EXTI__3();
        SET_BIT(ExtInt.PR,3);
    }
}
void EXTI4_IRQHandler()
{
    if ((__EXTI__4 != NULL)&&(GetExtFlag(4)==1))
    {
        __EXTI__4();
        SET_BIT(ExtInt.PR,4);
    }
}

void EXTI9_5_IRQHandler()
{
    if ((__EXTI__5 != NULL)&&(GetExtFlag(5)==1))
    {
        __EXTI__5();
        SET_BIT(ExtInt.PR,5);
    }

    if ((__EXTI__6 != NULL)&&(GetExtFlag(6)==1))
    {
        __EXTI__6();
        SET_BIT(ExtInt.PR,6);
    }

    if ((__EXTI__7 != NULL)&&(GetExtFlag(7)==1))
    {
        __EXTI__7();
        SET_BIT(ExtInt.PR,7);
    }
    if ((__EXTI__8 != NULL)&&(GetExtFlag(8)==1))
    {
        __EXTI__8();
        SET_BIT(ExtInt.PR,8);
    }
    if ((__EXTI__9 != NULL)&&(GetExtFlag(9)==1))
    {
        __EXTI__9();
        SET_BIT(ExtInt.PR,9);
    }
}


void EXTI15_10_IRQHandler()
{
    if ((__EXTI__10 != NULL)&&(GetExtFlag(10)==1))
    {
        __EXTI__10();
        SET_BIT(ExtInt.PR,10);
    }

    if ((__EXTI__11 != NULL)&&(GetExtFlag(11)==1))
    {
        __EXTI__11();
        SET_BIT(ExtInt.PR,11);
    }

    if ((__EXTI__12 != NULL)&&(GetExtFlag(12)==1))
    {
        __EXTI__12();
        SET_BIT(ExtInt.PR,12);
    }

    if ((__EXTI__13 != NULL)&&(GetExtFlag(13)==1))
    {
        __EXTI__13();
        SET_BIT(ExtInt.PR,13);
    }

    if ((__EXTI__14 != NULL)&&(GetExtFlag(14)==1))
    {
        __EXTI__14();
        SET_BIT(ExtInt.PR,14);
    }

    if ((__EXTI__15 != NULL)&&(GetExtFlag(15)==1))
    {
        __EXTI__15();
        SET_BIT(ExtInt.PR,15);
    }
}
