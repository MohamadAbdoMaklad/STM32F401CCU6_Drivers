/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stdio.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_Interface.h"
#include "GPIO_Interface.h"
#include "USART_Interface.h"



int main(void)
{
	RCC_voidInitSysClk(HSI,EnableCSS);
	voidBusClockPrescaler(AHP_Division2,APB_NoDivision,APB_NoDivision);
	RCC_voidPeripheralClk(GPIOA,EnablePeripheral, HighPowerMode);
	USART_voidInit();
	GPIO_voidSetPinMode(GPIO_A0, GPIO_OUTPUT);
	GPIO_voidOutputPinConfig(GPIO_A0, GPIO_PushPull, GPIO_Output_LS);
	while(1)
	{
		//USATR_voidTXDate('A');
		U8 Data = USATR_U8RXDate();
		if (Data == 'A')
		{
			GPIO_voidSetPinValue(GPIO_A0,STD_High);
			USATR_voidTXDate('C');
		}
		if (Data == 'a')
		{
			GPIO_voidSetPinValue(GPIO_A0,STD_Low);
			USATR_voidTXDate('D');

		}
	}
}
