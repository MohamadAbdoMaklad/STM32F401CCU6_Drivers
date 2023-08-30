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

#define SetBit(Reg,BitNo)           (Reg |=(1U<<BitNo))
#define ClearBit(Reg,BitNo)         (Reg &=~(1U<<BitNo))
#define ToggleBit(Reg,BitNo)        (Reg ^=(1U<<BitNo))
#define GetBit(Reg,BitNo)           ((Reg>>BitNo)&1U)

#define GetRegBits(Reg,Bits,StartBit)               (((Reg)>>(StartBit))&((1U<<(Bits))-1U))
#define ClearRegBits(Reg,Bits,StartBit)             ((Reg)&=~(((1U<<(Bits))-1U)<<(StartBit)))
#define ModRegBits(Reg,Bits,StartBit,NewValue)      ((Reg)=((Reg)&~(((1U<<(Bits))-1U)<<(StartBit)))|((NewValue)<<(StartBit)))
//#define GetBit(Reg,BitNo)           (Reg & (1 << BitNo))
#endif