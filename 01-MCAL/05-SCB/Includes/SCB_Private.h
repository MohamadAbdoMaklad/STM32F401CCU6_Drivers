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
    volatile U32 SHPR[3];
    volatile U32 SHCSR;
    volatile U8 CFSR_MMFSR;
    volatile U8 CFSR_BFSR;
    volatile U16 CFSR_UFSR;
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
/*System fault handler priority fields Value*/
enum
{
    MemoryManagementFault   =   GetRegBits(SCB.SHPR[0],4,0) ,
    BusFault                =   GetRegBits(SCB.SHPR[0],4,8) ,
    UsageFault              =   GetRegBits(SCB.SHPR[0],4,16),
    SVCall                  =   GetRegBits(SCB.SHPR[1],4,24),
    PendSV                  =   GetRegBits(SCB.SHPR[2],4,16),
    SysTick                 =   GetRegBits(SCB.SHPR[2],4,24)
};
#endif // !SCB_PRIVATE_H