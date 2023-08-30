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
/*System fault handler priority fields Value*/

/*Driver*/
void SCB_voidNVICPriorityConfig(NVIC_Grouping_t Copy_PriorityOption)
{
    SCB.AIRCR.VECTKEYSTAT = VECTKEY;
    SCB.AIRCR.PRIGROUP = Copy_PriorityOption;
    ActivePriorityOption = Copy_PriorityOption;
}
//U8 Arr[6]={MemoryManagementFault,BusFault,UsageFault,SVCall,PendSV,SysTick};
void SCB_voidNVIC_ArrIntPriority(U8 *Copy_PriorityArray)
{
    U32 PriorityVal=0;
    ModRegBits(PriorityVal,4,0,GetRegBits(SCB.SHPR[0],4,0));
    ModRegBits(PriorityVal,4,4,GetRegBits(SCB.SHPR[0],4,8));
    ModRegBits(PriorityVal,4,8,GetRegBits(SCB.SHPR[0],4,16));
    ModRegBits(PriorityVal,4,12,GetRegBits(SCB.SHPR[1],4,24));
    ModRegBits(PriorityVal,4,16,GetRegBits(SCB.SHPR[2],4,16));
    ModRegBits(PriorityVal,4,20,GetRegBits(SCB.SHPR[2],4,24));

    StoreVal_t NewVal;
    NewVal.Val1 = GetRegBits(PriorityVal,4,Copy_PriorityArray[0]);
    NewVal.Val2 = GetRegBits(PriorityVal,4,Copy_PriorityArray[1]);
    NewVal.Val3 = GetRegBits(PriorityVal,4,Copy_PriorityArray[2]);
    NewVal.Val4 = GetRegBits(PriorityVal,4,Copy_PriorityArray[3]);
    NewVal.Val5 = GetRegBits(PriorityVal,4,Copy_PriorityArray[4]);
    NewVal.Val6 = GetRegBits(PriorityVal,4,Copy_PriorityArray[5]);

    ModRegBits(SCB.SHPR[0],4,4, NewVal.Val1);
    ModRegBits(SCB.SHPR[0],4,12,NewVal.Val2);
    ModRegBits(SCB.SHPR[0],4,20,NewVal.Val3);
    ModRegBits(SCB.SHPR[1],4,28,NewVal.Val4);
    ModRegBits(SCB.SHPR[2],4,20,NewVal.Val5);
    ModRegBits(SCB.SHPR[2],4,28,NewVal.Val6);
}