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
#ifndef TFT_PRIVATE_H
#define TFT_PRIVATE_H

static void Private_voidSendCmd(U8 Copy_u8Command);
static void Private_voidSendData(U8 Copy_u8Data);
static void Private_voidSendResetPulse(void);
#define SLP_OUT_CMD		0x11
#endif // !SWC_PRIVATE_H