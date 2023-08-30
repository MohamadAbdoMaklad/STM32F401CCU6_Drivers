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
#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

/*Register Definitions*/
/*
typedef struct
{
    U32 ENABLE : 1;
    U32 TICKINT : 1;
    U32 CLKSOURCE : 1;
    U32 CTRL_Resirved_0 : 13;
    U32 COUNTFLAG : 1;
    U32 CTRL_Resirved_1 : 15;
} STK_CTRL_Bits;
*/
typedef struct
{
    volatile U32 ISER[32];
    volatile U32 ICER[32];
    volatile U32 ISPR[32];
    volatile U32 ICPR[32];
    volatile U32 IABR[32];
    volatile U32 IPR[NVIC_ExternalPeripheralsNo];
    volatile U32 STIR;
} NVIC_t;
/*Adress Pointer*/
#define NVIC_BoundaryAddress 0xE000E100
#define NVIC (*((volatile NVIC_t *)NVIC_BoundaryAddress))
/*Private Macros*/

#endif // !NVIC_PRIVATE_H