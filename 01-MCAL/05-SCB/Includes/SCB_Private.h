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
#ifndef SCB_PRIVATE_H
#define SCB_PRIVATE_H

typedef struct
{
    U32 VECT_RESET       :1;
    U32 VECT_CLR_ACTIVE  :1;
    U32 SYS_RESET_REQ    :1;
    U32 AIRCR_Reserved_0 :5;
    U32 PRIGROUP         :3;
    U32 AIRCR_Reserved_1 :4;
    U32 ENDIANESS        :1;
    U32 VECTKEYSTAT      :16;

}AIRCR_Bits;

/*Register Definitions*/
typedef struct
{
    volatile U32 CPUID;
    volatile U32 ICSR;
    volatile U32 VTOR;
    volatile AIRCR_Bits AIRCR;
    volatile U32 SCR;
    volatile U32 CCR;
    volatile U32 SHPR1;
    volatile U32 SHPR2;
    volatile U32 SHPR2;
    volatile U32 SHCSR;
    volatile U32 CFSR;
    volatile U32 HFSR;
    volatile U32 MMAR;
    volatile U32 BFAR;
    volatile U32 AFSR;
} SCB_t;
/*Adress Pointer*/
#define SCB_BoundaryAddress 0xE000ED00
#define SCB (*((volatile SCB_t *)SCB_BoundaryAddress))
/*Private Macros*/
#define VECTKEY 0x5FA
#endif // !SCB_PRIVATE_H