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
#ifndef SysTick_PRIVATE_H
#define SysTick_PRIVATE_H

/*Register Definitions*/
typedef struct
{
    U32 ENABLE              :1  ;
    U32 TICKINT             :1  ;
    U32 CLKSOURCE           :1  ;
    U32 CTRL_Resirved_0     :13 ;
    U32 COUNTFLAG           :1  ;
    U32 CTRL_Resirved_1     :15 ;
} STK_CTRL_Bits;
typedef struct
{
    U32 RELOAD              :24 ;
    U32 LOAD_Resirved_0     :8  ;
} STK_LOAD_Bits;
typedef struct
{
    U32 CURRENT             :24 ;
    U32 VAL_Resirved_0      :8  ;
} STK_VAL_Bits;
typedef struct
{
    U32 TENMS               :24 ;
    U32 CALIB_Resirved_0    :6  ;
    U32 SKEW                :1  ;
    U32 NOREF               :1  ;
} STK_CALIB_Bits;

typedef struct
{
    volatile STK_CTRL_Bits STK_CTRL;
    volatile STK_LOAD_Bits STK_LOAD;
    volatile STK_VAL_Bits STK_VAL;
    volatile STK_CALIB_Bits STK_CALIB;
}SysTick_t;
/*Adress Pointer*/
#define SysTick_BoundaryAddress 0xE000E010
#define SysTick (*((volatile SysTick_t *)SysTick_BoundaryAddress))
/*Private Macros*/
#define SINGLE_INTERVAL     0
#define PERIODIC_INTERVAL   1
#endif // !RCC_PRIVATE_H