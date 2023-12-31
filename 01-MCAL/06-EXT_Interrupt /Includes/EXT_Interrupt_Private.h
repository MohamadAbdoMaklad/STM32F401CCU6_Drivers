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
#ifndef EXT_INTERRUPT_PRIVATE_H
#define EXT_INTERRUPT_PRIVATE_H
/*Register Definitions*/
/*External Interrupts Registers*/
typedef struct
{
    volatile U32 IMR;
    volatile U32 EMR;
    volatile U32 RTSR;
    volatile U32 FTSR;
    volatile U32 SWIER;
    volatile U32 PR;
} EXT_Interrupt_t;
/*Adress Pointer*/
#define EXT_Interrupt_BoundaryAddress 0x40013C00
#define ExtInt (*((volatile EXT_Interrupt_t *)EXT_Interrupt_BoundaryAddress))

/*Sysytem Configuratiion Related External Interrupts Registers*/
typedef struct
{
    volatile U32 MEMRMP;
    volatile U32 PMC;
    volatile U32 EXTICR[4];
    volatile U32 CMPCR;
} ESYSCFG_t;
/*Adress Pointer*/
#define SYSCFG_BoundaryAddress 0x40013800
#define SYSCFG (*((volatile ESYSCFG_t *)SYSCFG_BoundaryAddress))
/*Private Macros*/


/*External Interrupts Flags*/
U16 External_Interrupt_Flags = 0b0000000000000000;
#endif // !EXT_Interrupt_PRIVATE_H