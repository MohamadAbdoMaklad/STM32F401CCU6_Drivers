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
#ifndef USART_PRIVATE_H
#define USART_PRIVATE_H

/*Register Definitions*/
typedef struct 
{
    U32 PE    :1;
    U32 FE    :1;
    U32 NF    :1;
    U32 ORE    :1;
    U32 IDLE    :1;
    U32 RXNE    :1;
    U32 TC    :1;
    U32 TXE    :1;
    U32 LBD    :1;
    U32 CTS    :1;
    U32 RESERVED_0    :22;
}USART_SR_t;

typedef struct 
{
    U32 SBK:1 ;
    U32 RWU:1 ;
    U32 RE:1 ;
    U32 TE:1 ;
    U32 IDLEIE:1 ;
    U32 RXNEIE:1 ;
    U32 TCIE:1 ;
    U32 TXEIE:1 ;
    U32 PEIE:1 ;
    U32 PS:1 ;
    U32 PCE:1 ;
    U32 WAKE:1 ;
    U32 M:1 ;
    U32 UE:1;
    U32 RESERVED_0:1;
    U32 OVER8:1;
    U32 RESERVED_1:16;
}USART_CR1_t;

typedef struct 
{
    U32 ADD:4 ;
    U32 RESERVED_0:1 ;
    U32 LBDL:1 ;
    U32 LBDIE:1 ;
    U32 RESERVED_1:5 ;
    U32 STOP:2 ;
    U32 RESERVED_2:18;
}USART_CR2_t;

typedef struct
{
    volatile USART_SR_t SR;
    volatile U32 DR;
    volatile U32 BRR;
    volatile USART_CR1_t CR1;
    volatile USART_CR2_t CR2;
    volatile U32 CR3;
    volatile U32 GTPR;

} USART_t;

#define USART_BoundaryAddress     0x40011000
#define USART (*((volatile USART_t *)USART_BoundaryAddress))

#endif // !SWC_PRIVATE_H
