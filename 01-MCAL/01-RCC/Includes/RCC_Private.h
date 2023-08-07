/****************************************************/
/*Author	            : Mohamad Abdo Maklad	    */
/*Date		            : 27-7-2023				    */
/*Last Modification		: 27-7-2023				    */
/*Version	            : V01				   	    */
/****************************************************/
/*Controller            : STM32F401CC               */
/*SWC                   : RCC                       */
/*Description           : Reset & Controle Clock    */
/****************************************************/

/*File Gard*/
#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

/*Register Definitions*/
typedef struct
{
    U32 HSION               : 1;
    U32 HSIRDY              : 1;
    U32 RC_Reserved_0       : 1;//Reserved
    U32 HSITRIN             : 5;
    U32 HSICAL              : 8;
    U32 HSEON               : 1;
    U32 HSERDY              : 1;
    U32 HSEBYP              : 1;
    U32 CSSON               : 1;
    U32 RC_Reserved_1       : 4;//Reserved
    U32 PLLON               : 1;
    U32 PLLRDY              : 1;
    U32 PLLI2SON            : 1;
    U32 PLLI2SRDY           : 1;
    U32 RC_Reserved_2       : 4;//Reserved
} RC_Register;

typedef struct
{
    U32 PLLM                : 6;
    U32 PLLN                : 9;
    U32 PLLCFGR_Reserved_0  : 1;//Reserved
    U32 PLLP                : 2;
    U32 PLLCFGR_Reserved_1  : 4;//Reserved
    U32 PLLSRC              : 1;
    U32 PLLCFGR_Reserved_2  : 1;//Reserved
    U32 PLLQ                : 4;
    U32 PLLCFGR_Reserved_4  : 4;//Reserved
} PLLCFGR_Register;

typedef struct
{
    U32 SW_rw               : 2;
    U32 SW_r                : 2;
    U32 HPRE                : 4;
    U32 CFGR_Reserved_0     : 2;//Reserved
    U32 PPRE1               : 3;
    U32 PPRE2               : 3;
    U32 RTCPRE              : 5;
    U32 MCO1                : 2;
    U32 I2SSC               : 1;
    U32 MCO1PRE             : 3;
    U32 MCO2PRE             : 3;
    U32 MCO2                : 2;
} CFGR_Register;
typedef struct
{
    volatile RC_Register RC;
    volatile PLLCFGR_Register PLLCFGR;
    volatile CFGR_Register CFGR;
    volatile U32 CIR;
    volatile U32 RCC_CC_RESERVED_0[8];
    volatile U32 AHB1ENR;
    volatile U32 AHB2ENR;
    volatile U32 RCC_CC_RESERVED_1[2];
    volatile U32 APB1RENR;
    volatile U32 APB2RENR;
    volatile U32 RCC_CC_RESERVED_2[2];
    volatile U32 AHB1LPENR;
    volatile U32 AHB2LPENR;
    volatile U32 RCC_CC_RESERVED_3[2];
    volatile U32 APB1RLPENR;
    volatile U32 APB2RLPENR;
    volatile U32 RCC_CC_RESERVED_4[10];
} RCC_CC_t;

#define RCC_BoundaryAddress 0x40023800
#define RCC_CC (*((volatile RCC_CC_t *)RCC_BoundaryAddress))

#endif // !RCC_PRIVATE_H
