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
#include "SysTick_Interface.h"
/*Driver Files Includes*/
#include "SCHADULAR_Config.h"
#include "SCHADULAR_Interface.h"
#include "SCHADULAR_Private.h"
/*Driver*/

void SCH_voidCreateTask(U8 Copy_U8Priority , U32 Copy_U32Priodicity , U32 Copy_U8FirstDelay, void(*Lpf)(void))
{
    Task[Copy_U8Priority].Periodicity = Copy_U32Priodicity;
    Task[Copy_U8Priority].FirestDelay = Copy_U8FirstDelay;
    Task[Copy_U8Priority].pf = Lpf;
}
void SCH_voidStartOs()
{
    /*init system clock*/
    SysTick_voidInit(AHB_8);
    /*Schadular functunality*/
    SysTick_SetIntervalPeriodic(OS_Tick_MS, &Private_voidSchedularStart);
}
void Private_voidSchedularStart()
{
    U8 Local_U8CopyCounter;
    for (Local_U8CopyCounter = 0;Local_U8CopyCounter< OS_Tick_MS;Local_U8CopyCounter++)
    {
        if (Task[Local_U8CopyCounter].FirestDelay == 0)
        {
            Task[Local_U8CopyCounter].pf();
            Task[Local_U8CopyCounter].FirestDelay = Task[Local_U8CopyCounter].Periodicity-1;
        }
        else
        {
            Task[Local_U8CopyCounter].FirestDelay--; 
        }
    }
}