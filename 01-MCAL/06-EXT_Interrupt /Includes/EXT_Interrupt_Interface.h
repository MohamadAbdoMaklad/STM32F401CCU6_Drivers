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
#ifndef EXT_INTERRUPT_INTERFACE_H
#define EXT_INTERRUPT_INTERFACE_H

/*Options*/
typedef enum
{
    /*Line A*/
    EXTI_LINE_A0    = 0 ,
    EXTI_LINE_A1    = 1 ,
    EXTI_LINE_A2    = 2 ,
    EXTI_LINE_A3    = 3 ,
    EXTI_LINE_A4    = 4 ,
    EXTI_LINE_A5    = 5 ,
    EXTI_LINE_A6    = 6 ,
    EXTI_LINE_A7    = 7 ,
    EXTI_LINE_A8    = 8 ,
    EXTI_LINE_A9    = 9 ,
    EXTI_LINE_A10   = 10,
    EXTI_LINE_A11   = 11,
    EXTI_LINE_A12   = 12,
    EXTI_LINE_A13   = 13,
    EXTI_LINE_A14   = 14,
    EXTI_LINE_A15   = 15,

    EXTI_LINE_B0    = 16,
    EXTI_LINE_B1    = 17,
    EXTI_LINE_B2    = 18,
    EXTI_LINE_B3    = 19,
    EXTI_LINE_B4    = 20,
    EXTI_LINE_B5    = 21,
    EXTI_LINE_B6    = 22,
    EXTI_LINE_B7    = 23,
    EXTI_LINE_B8    = 24,
    EXTI_LINE_B9    = 25,
    EXTI_LINE_B10   = 26,
    EXTI_LINE_B11   = 27,
    EXTI_LINE_B12   = 28,
    EXTI_LINE_B13   = 29,
    EXTI_LINE_B14   = 30,
    EXTI_LINE_B15   = 31,

    EXTI_LINE_C13   = 45,
    EXTI_LINE_C14   = 46,
    EXTI_LINE_C15   = 47
}EXTI_Line_t;

typedef enum
{
    EXTI_PA =0,
    EXTI_PB =1,
    EXTI_PC =2
}EXT_Source_t;
typedef enum
{
    FallingEdge =0,
    RisingEdge  =1,
    OnChange    =2
}EXT_Trig_t;
/*Functions*/

void EXTI_voidSetExtiLineEnable(EXTI_Line_t Copy_LineId,EXT_Trig_t Copy_Treg);
void EXTI_voidSetExtiLineDisable(EXTI_Line_t Copy_LineId);
void EXTI_voidSetSenseControl(EXTI_Line_t Copy_LineId,EXT_Trig_t Copy_Treg);
void EXTI_voidSetCallBack(EXTI_Line_t Copy_LineId,void (*LpF)(void));
#endif // !EX   T_Interrupt_INTERFACE_H
