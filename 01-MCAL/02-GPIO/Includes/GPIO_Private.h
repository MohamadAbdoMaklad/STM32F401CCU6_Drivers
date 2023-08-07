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

typedef struct
{
    volatile U32 MODER;
    volatile U32 OTYPER;
    volatile U32 OSPEEDR;
    volatile U32 PUPDR;
    volatile U32 IDR;
    volatile U32 ODR;
    volatile U32 BSRR;
    volatile U32 LCKR;
    volatile U32 AFRL;
    volatile U32 AFRH;
} GPIO_t;
#define GPIOA_BoundaryAddress 0x40020000
#define GPIOB_BoundaryAddress 0x40020400
#define GPIOC_BoundaryAddress 0x40020800

#define GPIOA (*((volatile GPIO_t *)GPIOA_BoundaryAddress))
#define GPIOB (*((volatile GPIO_t *)GPIOB_BoundaryAddress))
#define GPIOC (*((volatile GPIO_t *)GPIOC_BoundaryAddress))

#endif // !RCC_PRIVATE_H