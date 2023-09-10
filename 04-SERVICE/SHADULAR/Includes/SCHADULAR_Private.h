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
#ifndef SCHADULAR_PRIVATE_H
#define SCHADULAR_PRIVATE_H
typedef struct 
{
    U32 Periodicity;
    U32 FirestDelay;
    void(*pf)(void);
}TCB_t;
TCB_t Task[TaskNo] = {};
/*Private Functions*/
void Private_voidSchedularStart(void);
#endif // !SWC_PRIVATE_H