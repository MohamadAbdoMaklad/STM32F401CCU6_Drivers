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
#ifndef SysTick_INTERFACE_H
#define SysTick_INTERFACE_H
/*Options*/
typedef enum
{
    DisableSysTick=0,
    EnableSysTick=1
}SysTickState_t;
typedef enum
{
    AHB_8=0,
    AHB=1
}SysTickClockSource_t;
typedef enum
{
    DisableSysTickInterrupt=0,
    EnableSysTickInterrupt=1
}SysTickInterruptState_t;
/*Functions*/
void SysTick_voidInit(SysTickClockSource_t Copy_ClockSource);
void SysTick_voidSetState(SysTickState_t Copy_SysTickState);
void SysTick_voidSetInterruptState(SysTickInterruptState_t Copy_InterruptState);
void SysTick_voidSetClockSource(SysTickClockSource_t Copy_ClockSource);
void SysTick_SetBusyWait(U32 Copy_TicksCount);
void SysTick_SetIntervalSingle(U32 Copy_TicksCount, void (*LPF)(void));
void SysTick_SetIntervalPeriodic(U32 Copy_TicksCount, void (*LPF)(void));
void SysTick_voidGetElapsedTime(U32 *ElapsedTime);
void SysTick_voidGetRemainTime(U32 *RemainTime);
#endif // !RCC_INTERFACE_H
