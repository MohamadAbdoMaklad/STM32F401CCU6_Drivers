/*************************************************/
/*Author	            : Mohamad Abdo Maklad	 */
/*Date		            : 26-7-2023				 */
/*Last Modification		: 27-7-2023				 */
/*Version	            : V01				   	 */
/*************************************************/
/******(Bit Math Operations)**********************/
/*************************************************/
#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SetBit(Reg,BitNo)           (Reg |=(1<<BitNo))
#define ClearBit(Reg,BitNo)         (Reg &=~(1<<BitNo))
#define ToggleBit(Reg,BitNo)        (Reg ^=(1<<BitNo))
#define GetBit(Reg,BitNo)           ((Reg>>BitNo)&1)

//#define GetBit(Reg,BitNo)           (Reg & (1 << BitNo))
//#define RegMask(Reg,Value,BitNo)    (Reg |=(Value<<BitNo))
#endif