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
#include "SCB_Interface.h"
#include "SCB_Private.h"
#include "SCB_Config.h"
/*Glopal Var*/
NVIC_Grouping_t ActivePriorityOption;

/*Driver*/
void SCB_voidNVICPriorityConfig(NVIC_Grouping_t Copy_PriorityOption)
{
    SCB.AIRCR.VECTKEYSTAT = VECTKEY;
    SCB.AIRCR.PRIGROUP = Copy_PriorityOption;
    ActivePriorityOption = Copy_PriorityOption;
}

//U8 IntPriorityArray[6]={MemoryManagementFault,BusFault,UsageFault,SVCall,PendSV,SysTick};
void SCB_voidNVIC_IntPriorityConfig(U8 *Copy_PriorityArray)
{
    ModRegBits(SCB.SHPR[0],4,4,Copy_PriorityArray[0]);
    ModRegBits(SCB.SHPR[0],4,12,Copy_PriorityArray[1]);
    ModRegBits(SCB.SHPR[0],4,20,Copy_PriorityArray[2]);
    ModRegBits(SCB.SHPR[1],4,28,Copy_PriorityArray[3]);
    ModRegBits(SCB.SHPR[2],4,20,Copy_PriorityArray[4]);
    ModRegBits(SCB.SHPR[2],4,28,Copy_PriorityArray[5]);
}