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

/*Functions*/
void NVIC_voidPeriphiralState(VectTable_t Copy_PerIntId , State_t Copy_State);

void NVIC_voidPendingFlagState(VectTable_t Copy_PerIntId, State_t Copy_State);

void NVIC_voidSetPeriphiralPripority(VectTable_t Copy_PerIntId, U8 Copy_u8GroupId, U8 Copy_u8SubGroupId);

#endif // !NVIC_INTERFACE_H
