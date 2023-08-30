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
#ifndef ACB_INTERFACE_H
#define ACB_INTERFACE_H
/*Options*/
typedef enum
{
    G16S0 = 3,
    G8S2  = 4,
    G4S4  = 5,
    G2S8  = 6,
    G0S16 = 7
}NVIC_Grouping_t;
/*Functions*/
void SCB_voidNVICPriorityConfig(NVIC_Grouping_t Copy_PriorityOption);
void SCB_voidNVIC_ExtPriorityConfig(U8 *Copy_PriorityArray);
#endif // !SCB_INTERFACE_H
