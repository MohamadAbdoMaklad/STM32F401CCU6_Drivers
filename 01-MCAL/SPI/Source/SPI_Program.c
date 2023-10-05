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
/*LIB Includes*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*Lower Layer Includes*/
#include "GPIO_Interface.h"
/*Driver Files Includes*/
#include "SPI_Interface.h"
#include "SPI_Private.h"
#include "SPI_Config.h"
/*Driver*/
void SPI_voidInit()
{
    SPI1.CR1=0x00000347;
}
void SPI_voidTranceive(U8 Copy_u8DataToBeTransmitted, U8* DataToBeRecieved)
{
    //#define TFT_CS_PIN			GPIOA, PIN2
    //Select slave
	GPIO_voidSetPinValue(GPIO_A2,GPIO_LOW);
	//Send Data
	SPI1.DR = Copy_u8DataToBeTransmitted;
	//Poll until SPI isn't busy
	while(GET_BIT(SPI1.SR, 7) == 0);
	//Deselect slave
    GPIO_voidSetPinValue(GPIO_A2,GPIO_HIGH);
	//Return Data
	*DataToBeRecieved = (U8) (SPI1.DR);
}
