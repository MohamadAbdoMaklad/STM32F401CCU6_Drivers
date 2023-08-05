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
/*Functions*/
void SysTick_voidInit(void);
void SysTick_SetBusyWait(U32 Copy_TicksCount);
void SysTick_SetIntervalSingle(U32 Copy_TicksCount ,void (*LPF)(void));
void SysTick_SetIntervalPeriodic(U32 Copy_TicksCount ,void (*LPF)(void));
void SysTick_voidGetElapsedTime(U32* ElapsedTime);
void SysTick_voidGetRemainTime(U32* RemainTime);
#endif // !RCC_INTERFACE_H
