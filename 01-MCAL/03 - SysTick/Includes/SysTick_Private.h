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
#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

/*Register Definitions*/
#define RCC_BoundaryAddress 0x40021000
#define RCC_RC_Offset       0x00
#define RCC_CFGR_Offset     0x04
#define RCC_CIR_Offset      0x08
#define RCC_APB2RSTR_Offset 0x0C
#define RCC_APB1RSTR_Offset 0x010
#define RCC_AHBENR_Offset   0x14
#define RCC_APB2ENR_Offset  0x18
#define RCC_APB1ENR_Offset  0x1C
#define RCC_BDCR_Offset     0x20
#define RCC_CSR_Offset      0x24

#define RCC_RC       (*((volatile U32 *)(RCC_BoundaryAddress + RCC_RC_Offset      )))           //clock
#define RCC_CFGR     (*((volatile U32 *)(RCC_BoundaryAddress + RCC_CFGR_Offset    )))           //clock
#define RCC_CIR      (*((volatile U32 *)(RCC_BoundaryAddress + RCC_CIR_Offset     )))  //reset
#define RCC_APB2RSTR (*((volatile U32 *)(RCC_BoundaryAddress + RCC_APB2RSTR_Offset)))  //reset
#define RCC_APB1RSTR (*((volatile U32 *)(RCC_BoundaryAddress + RCC_APB1RSTR_Offset)))  //reset
#define RCC_AHBENR   (*((volatile U32 *)(RCC_BoundaryAddress + RCC_AHBENR_Offset  )))           //clock AHB
#define RCC_APB2ENR  (*((volatile U32 *)(RCC_BoundaryAddress + RCC_APB2ENR_Offset )))           //clock APB2
#define RCC_APB1ENR  (*((volatile U32 *)(RCC_BoundaryAddress + RCC_APB1ENR_Offset )))           //clock APB1
#define RCC_BDCR     (*((volatile U32 *)(RCC_BoundaryAddress + RCC_BDCR_Offset    )))  //reset
#define RCC_CSR      (*((volatile U32 *)(RCC_BoundaryAddress + RCC_CSR_Offset     )))  //reset




#endif // !RCC_PRIVATE_H