/****************************************************/
/*Author	            : Mohamad Abdo Maklad	    */
/*Date		            : 27-7-2023				    */
/*Last Modification		: 27-7-2023				    */
/*Version	            : V01				   	    */
/****************************************************/
/*Controller            : STM32F401CC               */
/*SWC                   : RCC                       */
/*Description           : Reset & Controle Clock    */
/****************************************************/
/*LIB Includes*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*Lower Layer Includes*/
/*Driver Files Includes*/
#include "RCC_Interface.h"
#include "RCC_Private.h"
#include "RCC_Config.h"
/*Driver*/
/************************************************************************************/
/* Func. Name : RCC_voidHSI_Config                                                  */
/* I/p Arguments : U8 Copy_TrimValue --->(intial value 16) Range (0 - 31)           */
/* Return : Nothing                                                                 */
/* Desc. : This Api allows the user to configure High Speed Internal Clock Trimming */
/************************************************************************************/
void RCC_voidHSI_Config(U8 Copy_TrimValue)
{
    RCC_CC.RC.HSITRIN = Copy_TrimValue;
}

/************************************************************************************/
/* Func. Name : RCC_voidPLL_Config                                                  */
/* I/p Arguments :U8 Copy_PLLM  Range(2 ≤ PLLM ≤ 63)                                */
/* I/p Arguments :U16 Copy_PLLN Range(192 ≤ PLLN ≤ 432)                             */
/* Return : Nothing                                                                 */
/* Desc. : This Api allows the user to configure PLL For Fvco_clock                 */
/* Equation : f(VCO clock) = f(PLL clock input) × (PLLN / PLLM)                     */
/************************************************************************************/
void RCC_voidPLL_Config(U8 Copy_PLLM, U16 Copy_PLLN)
{
    if (Copy_PLLM >= 2 && Copy_PLLM <= 63)
    {
        RCC_CC.PLLCFGR.PLLM = Copy_PLLM;
    }
    else
    {

    }

    if (Copy_PLLN >= 192 && Copy_PLLN <= 432)
    {
        RCC_CC.PLLCFGR.PLLN = Copy_PLLN;
    }
    else
    {

    }
}
void RCC_voidPLL_MainClock(PLLP_t Copy_PLLPValue)
{
    RCC_CC.PLLCFGR.PLLP = Copy_PLLPValue;
}
void RCC_voidPLL_OTGClock(PLLQ_t Copy_PLLQValue)
{
    RCC_CC.PLLCFGR.PLLQ = Copy_PLLQValue;
}
/************************************************************************************/
/* Func. Name : RCC_voidInitSysClk                                                  */
/* I/p Arguments :SystemClockSource_t Clock_Source (HSI,HSE,PLL)                    */
/* I/p Arguments :CSS_State_t Copy_CSSState        (DisaplCSS,EnableCSS)            */
/* Return : Nothing                                                                 */
/* Desc. : This Api allows the user to  Clock Source Initilization                  */
/*         & System Clock Selection with CSS State selection                        */
/************************************************************************************/
void RCC_voidInitSysClk(SystemClockSource_t Clock_Source, CSS_State_t Copy_CSSState)
{
    switch (Clock_Source)
    {
    case HSI:
        RCC_CC.RC.HSION = STD_High;
        RCC_CC.CFGR.SW_rw = Clock_Source;
        break;
    case HSE_Crystal:
        RCC_CC.RC.HSEON = STD_High;
        RCC_CC.RC.HSEBYP = STD_Low;
        RCC_CC.CFGR.SW_rw = Clock_Source;
        break;
    case HSE_RC:
        RCC_CC.RC.HSEON = STD_High;
        RCC_CC.RC.HSEBYP = STD_High;
        RCC_CC.CFGR.SW_rw = (Clock_Source-2);
        break;
    case PLL_HSI:
        RCC_CC.RC.HSION = STD_High;
        RCC_CC.RC.PLLON = STD_High;
        RCC_CC.PLLCFGR.PLLSRC = STD_Low;
        RCC_CC.CFGR.SW_rw = Clock_Source;
        break;
    case PLL_HSE:
        RCC_CC.RC.HSEON = STD_High;
        RCC_CC.RC.PLLON = STD_High;
        RCC_CC.PLLCFGR.PLLSRC = STD_High;
        RCC_CC.CFGR.SW_rw = (Clock_Source - 2);
        break;
    };
    RCC_CC.RC.CSSON = Copy_CSSState;
}
/**************************************************************************************/
/* Func. Name : RCC_voidMCO1                                                          */
/* I/p Arguments :COM1_ClockSource_t Copy_Source (COM1_HSI,COM1_LSE,COM1_HSE,COM1_PLL)*/
/* I/p Arguments :MCO_Prescaler_t Copy_Prescaler (MCO_NoDivision,MCO_Division2,       */
/*                                      MCO_Division3,MCO_Division4,MCO_Division5)    */
/* Return : Nothing                                                                   */
/* Desc. : This Api allows the user to Microconroller Clock Output 1 Configuration    */
/*              & Intialization Function                                              */
/**************************************************************************************/
void RCC_voidMCO1(COM1_ClockSource_t Copy_Source, MCO_Prescaler_t Copy_Prescaler)
{
    RCC_CC.CFGR.MCO1 = Copy_Source;
    RCC_CC.CFGR.MCO1PRE = Copy_Prescaler;
}
/**************************************************************************************/
/* Func. Name : RCC_voidMCO2                                                          */
/* I/p Arguments :COM2_ClockSource_t Copy_Source (COM2_SystemClock=0,COM2_PLLI2S,     */
/*                                                  COM2_HSE,COM2_PLL)                */
/* I/p Arguments :MCO_Prescaler_t Copy_Prescaler (MCO_NoDivision,MCO_Division2,       */
/*                                      MCO_Division3,MCO_Division4,MCO_Division5)    */
/* Return : Nothing                                                                   */
/* Desc. : This Api allows the user to Microconroller Clock Output 2 Configuration    */
/*              & Intialization Function                                              */
/**************************************************************************************/
void RCC_voidMCO2(COM2_ClockSource_t Copy_Source, MCO_Prescaler_t Copy_Prescaler)
{
    RCC_CC.CFGR.MCO2 = Copy_Source;
    RCC_CC.CFGR.MCO2PRE = Copy_Prescaler;
}
/**************************************************************************************/
/* Func. Name : voidRTC_HSEPrescaler                                                  */
/* I/p Arguments :U8 Copy_Prescaler Range (0 - 31)                                    */
/* Return : Nothing                                                                   */
/* Desc. : This Api allows the user to set HSE division factor for RTC clock Function */
/**************************************************************************************/
void voidRTC_HSEPrescaler(U8 Copy_Prescaler)
{
    if (Copy_Prescaler <= 31)
    {
        RCC_CC.CFGR.RTCPRE = Copy_Prescaler;
    }
    else
    {

    }
}
/************************************************************************/
/* Func. Name : voidBusClockPrescaler                                   */
/* I/p Arguments :AHB_Prescaler_t Copy_AHBPrescaler   (AHP_NoDivision   */
/*                                                    AHP_Division2     */
/*                                                    AHP_Division4     */
/*                                                    AHP_Division8     */
/*                                                    AHP_Division16    */
/*                                                    AHP_Division64    */
/*                                                    AHP_Division128   */
/*                                                    AHP_Division256   */
/*                                                    AHP_Division512)  */
/* I/p Arguments :APB_Prescaler_t Copy_APB1Prescaler (APB_NoDivision    */
/*                                                    APB_Division2     */
/*                                                    APB_Division4     */
/*                                                    APB_Division8     */
/*                                                    APB_Division16)   */
/* I/p Arguments :APB_Prescaler_t Copy_APB2Prescaler                    */
/* Return : Nothing                                                     */
/* Desc. : This Api allows the user to set Bus Prescaling               */
/************************************************************************/
void voidBusClockPrescaler(AHB_Prescaler_t Copy_AHBPrescaler, APB_Prescaler_t Copy_APB1Prescaler, APB_Prescaler_t Copy_APB2Prescaler)
{
    RCC_CC.CFGR.HPRE = Copy_AHBPrescaler;
    RCC_CC.CFGR.PPRE1 = Copy_APB1Prescaler;
    RCC_CC.CFGR.PPRE2 = Copy_APB2Prescaler;
}

/****************************************************************************/
/* Func. Name : RCC_voidPeripheralClk                                       */
/* I/p Arguments :BUS_Peripherals_t Copy_Peripheral                         */
/*                  (GPIOA,GPIOB,GPIOC,GPIOD,GPIOE,GPIOH,CRC,DMA1,          */
/*                  DMA2,OTGFS,TIMER2,TIMER3,TIMER4,TIMER5,WWDG,SPI2,       */
/*                  SPI3,USART2,I2C1,I2C2,I2C3,PWR,TIMER1,USART1,USART6,    */
/*                  ADC1,SDIO,SPI1,SPI4,SYSCFG,TIMER9,TIMER10,TIMER11)      */
/* I/p Arguments :BUS_PeripheralState_t Copy_State (DisablePeripheral,      */
/*                                                  EnablePeripheral)       */
/* I/p Arguments :BUS_PeripheralPowerMode_t Copy_PowerMode (HighPowerMode,  */
/*                                                          LowPowerMode)   */
/* Return : Nothing                                                         */
/* Desc. : This Api allows the user Periphirals Clock State Conrole         */
/*                          & Power Mode Selection Function                 */
/****************************************************************************/
void RCC_voidPeripheralClk(BUS_Peripherals_t Copy_Peripheral, BUS_PeripheralState_t Copy_State, BUS_PeripheralPowerMode_t Copy_PowerMode)
{
    if (Copy_Peripheral >= 0 && Copy_Peripheral <= 31)
    {
        switch (Copy_State)
        {
        case EnablePeripheral:
            switch (Copy_PowerMode)
            {
            case HighPowerMode:
                SetBit(RCC_CC.AHB1ENR, (Copy_Peripheral - AHP1Shift));
                break;
            case LowPowerMode:
                SetBit(RCC_CC.AHB1LPENR, (Copy_Peripheral - AHP1Shift));
                break;
            };
            break;
        case DisablePeripheral:
            switch (Copy_PowerMode)
            {
            case HighPowerMode:
                ClearBit(RCC_CC.AHB1ENR, (Copy_Peripheral - AHP1Shift));
                break;
            case LowPowerMode:
                ClearBit(RCC_CC.AHB1LPENR, (Copy_Peripheral - AHP1Shift));
                break;
            };
            break;
        }
    }
    else if (Copy_Peripheral >= 32 && Copy_Peripheral <= 63)
    {
        switch (Copy_State)
        {
        case EnablePeripheral:
            switch (Copy_PowerMode)
            {
            case HighPowerMode:
                SetBit(RCC_CC.AHB2ENR, (Copy_Peripheral - AHP2Shift));
                break;
            case LowPowerMode:
                SetBit(RCC_CC.AHB2LPENR, (Copy_Peripheral - AHP2Shift));
                break;
            };
            break;
        case DisablePeripheral:
            switch (Copy_PowerMode)
            {
            case HighPowerMode:
                ClearBit(RCC_CC.AHB2ENR, (Copy_Peripheral - AHP2Shift));
                break;
            case LowPowerMode:
                ClearBit(RCC_CC.AHB1LPENR, (Copy_Peripheral - AHP2Shift));
                break;
            };
            break;
        }
    }
    else if (Copy_Peripheral >= 64 && Copy_Peripheral <= 95)
    {
        switch (Copy_State)
        {
        case EnablePeripheral:
            switch (Copy_PowerMode)
            {
            case HighPowerMode:
                SetBit(RCC_CC.APB1RENR, (Copy_Peripheral - APB1Shift));
                break;
            case LowPowerMode:
                SetBit(RCC_CC.APB1RLPENR, (Copy_Peripheral - APB1Shift));
                break;
            };
            break;
        case DisablePeripheral:
            switch (Copy_PowerMode)
            {
            case HighPowerMode:
                ClearBit(RCC_CC.APB1RENR, (Copy_Peripheral - APB1Shift));
                break;
            case LowPowerMode:
                ClearBit(RCC_CC.APB1RLPENR, (Copy_Peripheral - APB1Shift));
                break;
            };
            break;
        }
    }
    else if (Copy_Peripheral >= 96 && Copy_Peripheral <= 127)
    {
        switch (Copy_State)
        {
        case EnablePeripheral:
            switch (Copy_PowerMode)
            {
            case HighPowerMode:
                SetBit(RCC_CC.APB2RENR, (Copy_Peripheral - APB2Shift));
                break;
            case LowPowerMode:
                SetBit(RCC_CC.APB2RLPENR, (Copy_Peripheral - APB2Shift));
                break;
            };
            break;
        case DisablePeripheral:
            switch (Copy_PowerMode)
            {
            case HighPowerMode:
                ClearBit(RCC_CC.APB2RENR, (Copy_Peripheral - APB2Shift));
                break;
            case LowPowerMode:
                ClearBit(RCC_CC.APB2RLPENR, (Copy_Peripheral - APB2Shift));
                break;
            };
            break;
        }
    }
}
