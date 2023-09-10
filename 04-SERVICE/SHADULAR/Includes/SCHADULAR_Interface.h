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
#ifndef SCHADULAR_INTERFACE_H
#define SCHADULAR_INTERFACE_H
/*Options*/

/*functions Prototypes*/
void SCH_voidCreateTask(U8 Copy_U8Priority , U32 Copy_U32Priodicity , U8 Copy_U8FirstDelay, void(*Lpf)(void));
void SCH_voidStartOs();
#endif // !SWC_INTERFACE_H
