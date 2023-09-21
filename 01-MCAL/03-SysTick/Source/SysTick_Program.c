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
/*Static Glopal Private Function*/
static void (*GpF)(void) = NULL;
/*Glopal Flag */
U8 INTERVAL_FLAG_MODA = SINGLE_INTERVAL;
/*Driver*/
void SysTick_voidInit(SysTickClockSource_t Copy_ClockSource)
{
    // Stop SysTick
    SysTick.STK_CTRL.ENABLE = STD_Low;
    // Stop SysTick Interrupt
    SysTick.STK_CTRL.TICKINT = STD_Low;
    // Set SysTick Clock Source
    SysTick.STK_CTRL.CLKSOURCE = Copy_ClockSource;
}

void SysTick_voidSetState(SysTickState_t Copy_SysTickState)
{
    SysTick.STK_CTRL.ENABLE = Copy_SysTickState;
}

void SysTick_voidSetInterruptState(SysTickInterruptState_t Copy_InterruptState)
{
    SysTick.STK_CTRL.TICKINT = Copy_InterruptState;
}

void SysTick_voidSetClockSource(SysTickClockSource_t Copy_ClockSource)
{
    SysTick.STK_CTRL.CLKSOURCE = Copy_ClockSource;
}

void SysTick_SetBusyWait(U32 Copy_TicksCount)
{
    // Load the RELOAD With Value
    SysTick.STK_LOAD.RELOAD = Copy_TicksCount;
    // Start SysTick
    SysTick.STK_CTRL.ENABLE = STD_High;
    // Stop SysTick Interrupt
    //SysTick.STK_CTRL.TICKINT = STD_Low;
    // POLL On the Counter Flag
    while (!SysTick.STK_CTRL.COUNTFLAG);
    // Stop SysTick
    SysTick.STK_CTRL.ENABLE = STD_Low;
    // Relode With 0
    SysTick.STK_LOAD.RELOAD = 0;
    // Set Value With 0
    SysTick.STK_VAL.CURRENT = 0;
}

void SysTick_SetIntervalSingle(U32 Copy_TicksCount, void (*LPF)(void))
{
    // Load the RELOAD With Value
    SysTick.STK_LOAD.RELOAD = Copy_TicksCount;
    // Start SysTick
    SysTick.STK_CTRL.ENABLE = STD_High;
    // Save CallBack
    GpF = LPF;
    // Set Interval Falg mode to be SINGLE_INTERVAl
    INTERVAL_FLAG_MODA = SINGLE_INTERVAL;
    // Start SysTick Interrupt
    SysTick.STK_CTRL.TICKINT = STD_High;
}
void SysTick_ReSetIntervalSingle(U32 Copy_TicksCount)
{
    // stop timer
    SysTick.STK_LOAD.RELOAD = 0;
    SysTick.STK_VAL.CURRENT = 0;
    // Load the RELOAD With Value
    SysTick.STK_LOAD.RELOAD = Copy_TicksCount;
    // Start SysTick
    SysTick.STK_CTRL.ENABLE = STD_High;
    // Start SysTick Interrupt
    SysTick.STK_CTRL.TICKINT = STD_High;
}
void SysTick_SetIntervalPeriodic(U32 Copy_TicksCount, void (*LPF)(void))
{
    // Load the RELOAD With Value
    SysTick.STK_LOAD.RELOAD = Copy_TicksCount;
    // Start SysTick
    SysTick.STK_CTRL.ENABLE = STD_High;
    // Save CallBack
    GpF = LPF;
    // Set Interval Falg mode to be PERIODIC_INTERVAL
    INTERVAL_FLAG_MODA = PERIODIC_INTERVAL;
    // Start SysTick Interrupt
    SysTick.STK_CTRL.TICKINT = STD_High;
}

void SysTick_voidGetElapsedTime(U32 *ElapsedTime)
{
    *ElapsedTime = SysTick.STK_LOAD.RELOAD;
}

void SysTick_voidGetRemainTime(U32 *RemainTime)
{
    *RemainTime = SysTick.STK_VAL.CURRENT;
}
void SysTick_voidDellayMS_16Mhz(U32 Copy_DelauTime_MS)
{
	for(U32 i = 0;i < Copy_DelauTime_MS;i++)
		SysTick_SetBusyWait(16000);
}
void SysTick_voidDellayMS_FSysTickMhz(U32 Copy_DelauTime_MS,U8 Copy_SysTick_FMHz)
{
	for(U32 i = 0;i < Copy_DelauTime_MS;i++)
			SysTick_SetBusyWait(Copy_SysTick_FMHz*1000);
}

/*SysTick Handler*/
void SysTick_Handler()
{
    if (INTERVAL_FLAG_MODA == SINGLE_INTERVAL)
    {
        // Stop SysTick
        SysTick.STK_CTRL.ENABLE = STD_Low;
        // Stop SysTick Interrupt
        SysTick.STK_CTRL.TICKINT = STD_Low;
        // Relode With 0
        SysTick.STK_LOAD.RELOAD = 0;
        // Set Value With 0
        SysTick.STK_VAL.CURRENT = 0;
    }
    /*Execute Action to be done after the time passed*/
    if (GpF != 0)
    {
        GpF();
    }
    // Clear SysTick Flag (Cleard By Reading)
    U8 Local_U8Temp = 0;
    Local_U8Temp = SysTick.STK_CTRL.COUNTFLAG;
}
