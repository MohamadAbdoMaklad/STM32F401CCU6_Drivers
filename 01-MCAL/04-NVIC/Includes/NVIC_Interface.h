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
#ifndef NVIV_INTERFACE_H
#define NVIV_INTERFACE_H
/*Options*/
/*Function Like Macros*/
#define NVIC_EnableIRQ(PerIntId)           (NVIC.ISER[PerIntId/32] = (1<<(PerIntId%32)))
#define NVIC_DisableIRQ(PerIntId)          (NVIC.ICER[PerIntId/32] = (1<<(PerIntId%32)))
#define NVIC_SetPendingIRQ(PerIntId)       (NVIC.ISPR[PerIntId/32] = (1<<(PerIntId%32)))
#define NVIC_ClrPendingIRQ(PerIntId)       (NVIC.ICPR[PerIntId/32] = (1<<(PerIntId%32)))
#define NVIC_GetPendingIRQ(PerIntId)       (NVIC.ISPR[PerIntId/32] & (1<<(PerIntId%32)))
/*Functions*/
void NVIC_voidPeriphiralState(VectTable_t Copy_PerIntId , State_t Copy_State);

void NVIC_voidPendingFlagState(VectTable_t Copy_PerIntId, State_t Copy_State);

void NVIC_voidSetPeriphiralPripority(VectTable_t Copy_PerIntId, U8 Copy_u8GroupId, U8 Copy_u8SubGroupId);

#endif // !NVIC_INTERFACE_H
