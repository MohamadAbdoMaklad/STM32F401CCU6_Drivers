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
#ifndef LED_MATRIX_PRIVATE_H
#define LED_MATRIX_PRIVATE_H
/*Pins Array*/
#define LedMatrix_ColomnsNo 8
#define LedMatrix_RowsNo 8
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
    LedMatrix_R7};

static void LEDMATRIX_voidDisableCols(void);
static void LEDMATRIX_voidSetRowVlaues(U8 Copy_u8Frame);
#endif // !SWC_PRIVATE_H