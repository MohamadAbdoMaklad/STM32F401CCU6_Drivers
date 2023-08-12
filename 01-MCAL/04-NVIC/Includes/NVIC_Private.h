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
typedef struct
{
    U32 ENABLE : 1;
    U32 TICKINT : 1;
    U32 CLKSOURCE : 1;
    U32 CTRL_Resirved_0 : 13;
    U32 COUNTFLAG : 1;
    U32 CTRL_Resirved_1 : 15;
} STK_CTRL_Bits;
typedef struct
{
    U32 RELOAD : 24;
    U32 LOAD_Resirved_0 : 8;
} STK_LOAD_Bits;
typedef struct
{
    U32 CURRENT : 24;
    U32 VAL_Resirved_0 : 8;
} STK_VAL_Bits;
typedef struct
{
    U32 TENMS : 24;
    U32 CALIB_Resirved_0 : 6;
    U32 SKEW : 1;
    U32 NOREF : 1;
} STK_CALIB_Bits;

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
} NVIC_t;
/*Adress Pointer*/
#define NVIC_BoundaryAddress 0xE000E010
#define NVIC (*((volatile NVIC_t *)NVIC_BoundaryAddress))
/*Private Macros*/

#endif // !NVIC_PRIVATE_H