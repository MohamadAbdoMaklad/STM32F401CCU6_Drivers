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
/*Driver Files Includes*/
#include "IR_Interface.h"
#include "IR_Private.h"
#include "IR_Config.h"
/*Driver*/
U32 Frame = 0;
void IR_voidGetFrame(void)
{
    static U8 APP_u8StartFlag = 0;
	/*Check if the Received Edge The very first falling edge or not*/
	if(APP_u8StartFlag == 0)
	{
		/*Start Timer To Count The Ticks*/
        SysTick_ReSetIntervalSingle(1000000);
		APP_u8StartFlag = 1;
	}
	else if((APP_u8StartFlag>0)&&(APP_u8StartFlag<=32))
	{
		U32 PulseTime = 0;	
        SysTick_voidGetElapsedTime(&PulseTime);
        if((PulseTime>=1000)&&(PulseTime<=1500))
        {
            ClearBit(Frame,(APP_u8StartFlag-1));
        }
        else if ((PulseTime>=2000)&&(PulseTime<=2500))
        {
            SetBit(Frame,(APP_u8StartFlag-1));
        }

        if(APP_u8StartFlag == 32)
        {
            APP_u8StartFlag = 0;
            return Frame;
        }
        else
        {
            APP_u8StartFlag++;
		    SysTick_ReSetIntervalSingle(1000000);
        }
		
	}
}
U8 IR_U8GetFrameData(void)
{
    return GetRegBits(Frame,8,16);
}
U8 IR_U8GetDeviceID(void)
{
    return GetRegBits(Frame,8,0);
}