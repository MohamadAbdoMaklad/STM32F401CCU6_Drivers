/****************************************************/
/*Author	            : Mohamad Abdo Maklad       */
/*Date		            : 7-8-2023                  */
/*Last Modification		: 7-8-2023                  */
/*Version	            : V01                       */
/****************************************************/
/*Controller            :                           */
/*SWC                   :                           */
/*Description           :                           */
/****************************************************/
/*File Gard*/
#ifndef EXT_Interrupt_PRIVATE_H
#define EXT_Interrupt_PRIVATE_H

/*Register Definitions*/

typedef struct
{
    volatile U32 ISER[8];
    volatile U32 resirved_0[24];
    volatile U32 ICER[8];
    volatile U32 resirved_1[24];
    volatile U32 ISPR[8];
    volatile U32 resirved_2[24];
    volatile U32 ICPR[8];
    volatile U32 resirved_3[24];
    volatile U32 IABR[8];
    volatile U32 resirved_4[56];
    volatile U32 IPR[60];
    volatile U32 resirved_0[24];
    volatile U32 STIR;
} EXT_Interrupt_t;
/*Adress Pointer*/
#define EXT_Interrupt_BoundaryAddress 0xE000E010
#define EXT_Interrupt (*((volatile EXT_Interrupt_t *)NVIC_BoundaryAddress))
/*Private Macros*/

#endif // !EXT_Interrupt_PRIVATE_H