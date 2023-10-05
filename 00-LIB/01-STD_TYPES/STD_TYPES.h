/*************************************************/
/*Author	            : Mohamad Abdo Maklad*/
/*Date		            : 26-7-2023		 */
/*Last Modification	    : 27-7-2023		 */
/*Version	            : V01		 */
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

typedef float 			F32;
typedef double 			F64;

//pointers to functions types
typedef void (*v_P2F_v)(void);
typedef U8   (*U8_P2F_v)(void);
typedef U16  (*U16_P2F_v)(void);
typedef U32  (*U32_P2F_v)(void);

// polian function
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
	RevEnable=0,
	RevDisable=1,
}ReversedState_t;

// Null def if not def
#ifndef NULL
#define NULL ((void *)0)
#endif


#endif
