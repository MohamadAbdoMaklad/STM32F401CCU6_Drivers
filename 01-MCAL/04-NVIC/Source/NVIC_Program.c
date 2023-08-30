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
#include "NVIC_Config.h"
#include "NVIC_Private.h"
#include "NVIC_Interface.h"
extern U8 ActivePriorityOption;
/*Driver*/
void NVIC_voidSetPeriphiralState(VectTable_t Copy_PerIntId , State_t Copy_State)
{
    switch (Copy_State)
    {
        case Enable :NVIC.ISER[Copy_PerIntId/32] = (1<<(Copy_PerIntId%32));break;
        case Disable:NVIC.ICER[Copy_PerIntId/32] = (1<<(Copy_PerIntId%32));break;
    };
}
void NVIC_voidPendingFlagState(VectTable_t Copy_PerIntId, State_t Copy_State)
{
    switch (Copy_State)
    {
        case Enable :NVIC.ISPR[Copy_PerIntId/32] = (1<<(Copy_PerIntId%32));break;
        case Disable:NVIC.ICPR[Copy_PerIntId/32] = (1<<(Copy_PerIntId%32));break;
    };
}