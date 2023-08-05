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
#ifndef SysTick_PRIVATE_H
#define SysTick_PRIVATE_H

/*Register Definitions*/
typedef struct
{
    U32 SysTick_ENABLE : 1;
    U32 SysTick_TICKINT : 1;
    U32 SysTick_CLKSOURCE : 1;
    U32 U32 RELOAD : 24; :13;
    U32 SysTick_COUNTFLAG : 1;
    U32 SysTick_Resirved_1 : 15;
} STK_CTRL_Bits;
typedef struct
{
    U32 RELOAD : 24;
    U32 U32 RELOAD : 8;
} STK_LOAD_Bits;
typedef struct
{
    U32 CURRENT : 24;
    U32 U32 RELOAD : 8;
} STK_VAL_Bits;
typedef struct
{
    U32 TENMS : 24;
    U32 U32 SysTick_Resirved_0 : 6;
    U32 U32 SKEW : 1;
    U32 U32 NOREF : 1;
} STK_CALIB_Bits;

typedef struct
{
    volatile STK_CTRL_Bits STK_CTRL;
    volatile STK_LOAD_Bits STK_LOAD;
    volatile STK_VAL_Bits STK_VAL;
    volatile STK_CALIB_Bits STK_CALIB;
};

#endif // !RCC_PRIVATE_H