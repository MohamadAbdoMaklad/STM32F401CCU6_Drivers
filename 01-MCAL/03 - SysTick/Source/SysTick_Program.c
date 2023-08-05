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
#include "SysTick_Interface.h"
#include "SysTick_Private.h"
#include "SysTick_Config.h"
/*Driver*/
void SysTick_voidInit(void)
{
    // Stop timer
    ClearBit(STK_CTRL, 0);
    // stop
    ClearBit(STK_CTRL, 0);
    // stop timer
}
void SysTick_SetBusyWait(U32 Copy_TicksCount)
{
    // load the relaod value
    STK_LOAD = Copy_TicksCount;
    // start timer

    // flag pooling
    // while ( count flag == std_high);
    // or
    ////while ( !count flag);

    // Stop timer

    // Load register and valoe register = 0
    /*to make sure that the timer stopes */
}
void SysTick_SetIntervalSingle(U32 Copy_TicksCount, void (*LPF)(void))
{
}
void SysTick_SetIntervalPeriodic(U32 Copy_TicksCount, void (*LPF)(void))
{
}
void SysTick_voidGetElapsedTime(U32 *ElapsedTime)
{
}
void SysTick_voidGetRemainTime(U32 *RemainTime)
{
}