/*************************************************/
/*Author	            : Mohamad Abdo Maklad	 */
/*Date		            : 26-7-2023				 */
/*Last Modification		: 27-7-2023				 */
/*Version	            : V01				   	 */
/*************************************************/
/******(Standard types for ARM)*******************/
/*************************************************/
#ifndef STD_TYPES_H
#define STD_TYPES_H

typedef unsigned char 		U8;
typedef unsigned short int 	U16;
typedef unsigned long int 	U32;

typedef signed char 		S8;
typedef signed short int 	S16;
typedef signed long int 	S32;

typedef float 				F32;
typedef double 				F64;

typedef enum
{
	STD_Low = 0,
	STD_High = 1,
} STD_LevelTypes;
typedef enum
{
	Disable=0,
	Enable=1,
}State_t;
typedef enum
{
	Enable=0,
	Disable=1,
}ReversedState_t;
#ifndef NULL
#define NULL ((void *)0)
#endif


#endif