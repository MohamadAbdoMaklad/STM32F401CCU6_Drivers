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
#ifndef SysTick_PRIVATE_H
#define SysTick_PRIVATE_H

/*Register Definitions*/
typedef struct 
{
    U32 name :1;
};
typedef struct 
{
    U32 name :1;
};
typedef struct 
{
    U32 name :1;v
};
typedef struct 
{
    U32 name :1;
};

typedef struct 
{
    volatile U32 STK_CTRL;
    volatile U32 STK_LOAD;
    volatile U32 STK_VAL;
    volatile U32 STK_CALIB;
};

#endif // !RCC_PRIVATE_H