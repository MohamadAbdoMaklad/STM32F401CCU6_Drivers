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
#ifndef SEVENSEGMENT_CONFIG_H
#define SEVENSEGMENT_CONFIG_H
//SSD Enable Lines
#define SevenSegment_1Enable GPIO_A4
#define SevenSegment_2Enable GPIO_A5
//Dot Point
#define SevenSegment_DP GPIO_A4
//SSD Data Lines
#define SevenSegment_Data_PORT GPIO_PortA
#define SevenSegment_Data1 GPIO_A0
#define SevenSegment_Data2 GPIO_A1
#define SevenSegment_Data3 GPIO_A2
#define SevenSegment_Data4 GPIO_A3
//SysTick Frequancy
#define SysTickFrequanct   16

#endif // !SevenSegment_CONFIG_H
