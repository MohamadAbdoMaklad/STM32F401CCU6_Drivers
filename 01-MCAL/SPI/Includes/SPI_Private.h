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
#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H
/*Register Definitions*/
typedef struct 
{
    volatile U32 CR1;
    volatile U32 CR2;
    volatile U32 SR;
    volatile U32 DR;
    volatile U32 CRCPR;
    volatile U32 RXCRCR;
    volatile U32 TXCRCR;
    volatile U32 I2SCFGR;
    volatile U32 I2SPR;
}SPI_t;

#define SPI1_BoundaryAddress     0x40013000
#define SPI2_BoundaryAddress     0x40003800
#define SPI3_BoundaryAddress     0x40003C00
#define SPI4_BoundaryAddress     0x40013400
#define SPI1 (*((volatile SPI_t *)SPI1_BoundaryAddress))
#define SPI2 (*((volatile SPI_t *)SPI2_BoundaryAddress))
#define SPI3 (*((volatile SPI_t *)SPI3_BoundaryAddress))
#define SPI4 (*((volatile SPI_t *)SPI4_BoundaryAddress))
#endif // !SWC_PRIVATE_H