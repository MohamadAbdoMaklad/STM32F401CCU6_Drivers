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
#ifndef LED_MATRIX_CONFIG_H
#define LED_MATRIX_CONFIG_H

#define LedMatrix_ColomnsNo 8
#define LedMatrix_RowsNo 8

#define LedMatrix_C0    GPIO_A0
#define LedMatrix_C1    GPIO_A1
#define LedMatrix_C2    GPIO_A2
#define LedMatrix_C3    GPIO_A3
#define LedMatrix_C4    GPIO_A4
#define LedMatrix_C5    GPIO_A5
#define LedMatrix_C6    GPIO_A6
#define LedMatrix_C7    GPIO_A7

#define LedMatrix_R0    GPIO_B0
#define LedMatrix_R1    GPIO_B1
#define LedMatrix_R2    GPIO_B5
#define LedMatrix_R3    GPIO_B6
#define LedMatrix_R4    GPIO_B7
#define LedMatrix_R5    GPIO_B8
#define LedMatrix_R6    GPIO_B9
#define LedMatrix_R7    GPIO_B10

U8 LEDMatrix_Colomns[LedMatrix_ColomnsNo] = {
LedMatrix_C0,
LedMatrix_C1,
LedMatrix_C2,
LedMatrix_C3,
LedMatrix_C4,
LedMatrix_C5,
LedMatrix_C6,
LedMatrix_C7};
U8 LEDMatrix_Rows[LedMatrix_RowsNo] = {
LedMatrix_R0,
LedMatrix_R1,
LedMatrix_R2,
LedMatrix_R3,
LedMatrix_R4,
LedMatrix_R5,
LedMatrix_R6,
LedMatrix_R7
};
#endif // !SWC_CONFIG_H