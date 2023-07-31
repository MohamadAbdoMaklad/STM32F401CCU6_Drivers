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

/*File Gard*/
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

//Clock Source Options
typedef enum
{
    HSI=0,  //00
    HSE=1,  //01
    PLL=2   //10
}SystemClockSource_t;

//Clock State Fot Buss Peripherals
typedef enum
{
    DisablePeripheral = 0,
    EnablePeripheral  = 1
}BUS_PeripheralState_t;

//Power Mode
typedef enum
{
    HighPowerMode=0,
    LowPowerMode,
}BUS_PeripheralPowerMode_t;

#define AHP1Shift 0
#define AHP2Shift 32
#define APB1Shift 64
#define APB2Shift 96

//All Buses Peripherals
typedef enum
{
    // AHP1 0 +AHB1Shift 0 = 0
    GPIOA   = 0  + AHP1Shift,
    GPIOB   = 1  + AHP1Shift,
    GPIOC   = 2  + AHP1Shift,
    GPIOD   = 3  + AHP1Shift,
    GPIOE   = 4  + AHP1Shift,
    GPIOH   = 7  + AHP1Shift,
    CRC     = 12 + AHP1Shift,
    DMA1    = 21 + AHP1Shift,
    DMA2    = 22 + AHP1Shift,
    // AHP1 31+AHB1Shift 0 = 31
    // AHP2 0 +AHB2Shift 32 = 32
    OTGFS   = 7  + AHP2Shift,
    // AHP2 31+AHB2Shift 32 = 63
    // AHP1 0 +APB1Shift 64 = 64
    TIMER2  = 0  + APB1Shift,
    TIMER3  = 1  + APB1Shift,
    TIMER4  = 2  + APB1Shift,
    TIMER5  = 3  + APB1Shift,
    WWDG    = 11 + APB1Shift,
    SPI2    = 14 + APB1Shift,
    SPI3    = 15 + APB1Shift,
    USART2  = 17 + APB1Shift,
    I2C1    = 21 + APB1Shift,
    I2C2    = 22 + APB1Shift,
    I2C3    = 23 + APB1Shift,
    PWR     = 28 + APB1Shift,
    // AHP1 31+APB1Shift 64 = 95
    // AHP2 0 +APB2Shift 96 = 96
    TIMER1  = 0  + APB2Shift,
    USART1  = 4  + APB2Shift,
    USART6  = 5  + APB2Shift,
    ADC1    = 8  + APB2Shift,
    SDIO    = 11 + APB2Shift,
    SPI1    = 12 + APB2Shift,
    SPI4    = 13 + APB2Shift,
    SYSCFG  = 14 + APB2Shift,
    TIMER9  = 16 + APB2Shift,
    TIMER10 = 17 + APB2Shift,
    TIMER11 = 18 + APB2Shift
    // AHP2 31+APB2Shift 96 = 127

} BUS_Peripherals_t;

typedef enum
{
    Crystal_Source=0,
    RC_Source

}HSE_t;

typedef enum
{
    DisaplCSS=0,
    EnableCSS
}CSS_State_t;

typedef enum
{
    PLLP_2=0,
    PLLP_4,
    PLLP_6,
    PLLP_8
}PLLP_t;

typedef enum
{
    PLLQ_2=2,
    PLLQ_3,
    PLLQ_4,
    PLLQ_5,
    PLLQ_6,
    PLLQ_7,
    PLLQ_8,
    PLLQ_9,
    PLLQ_10,
    PLLQ_11,
    PLLQ_12,
    PLLQ_13,
    PLLQ_14,
    PLLQ_15
}PLLQ_t;

typedef enum
{
    MCO_NoDivision=0,        //000
    MCO_Division2=4,         //100
    MCO_Division3=5,         //101
    MCO_Division4=6,         //110
    MCO_Division5=7         //111
}MCO_Prescaler_t;
typedef enum
{
    COM1_HSI=0,              //00
    COM1_LSE=1,              //01
    COM1_HSE=2,              //10
    COM1_PLL=3               //11
}COM1_ClockSource_t;
typedef enum
{
    COM2_SystemClock=0,      //00
    COM2_PLLI2S=1,           //01
    COM2_HSE=2,              //10
    COM2_PLL=3               //11
}COM2_ClockSource_t;
typedef enum
{
    AHP_NoDivision=0,        //0000
    AHP_Division2=8,         //1000
    AHP_Division4=9,         //1001
    AHP_Division8=10,        //1010
    AHP_Division16=11,       //1011
    AHP_Division64=12,       //1100
    AHP_Division128=13,      //1101
    AHP_Division256=14,      //1110
    AHP_Division512=15      //1111
}AHB_Prescaler_t;   
typedef enum
{
    APB_NoDivision=0,       //000
    APB_Division2=4,        //100
    APB_Division4=5,        //101
    APB_Division8=6,        //110
    APB_Division16=7       //111
}APB_Prescaler_t;
//High Speed Internal Clock Configuration Function
void RCC_voidHSI_Config(U8 Copy_TrimValue);
//High Speed Eexternal Clock Configuration Function
void RCC_voidHSE_Config(HSE_t Copy_HSESource);
//PLL Clock Configuration Function
void RCC_voidPLL_Config(U8 Copy_PLLM,U16 Copy_PLLN);
void RCC_voidPLL_MainClock(PLLP_t Copy_PLLPValue);
void RCC_voidPLL_OTGClock(PLLQ_t Copy_PLLQValue);
//Clock Source Initilization & System Clock Selection with CSS State selection Function
void RCC_voidInitSysClk(SystemClockSource_t Clock_Source,CSS_State_t Copy_CSSState);
//Microconroller Clock Output 1 Configuration & Intialization Function
void RCC_voidMCO1(COM1_ClockSource_t Copy_Source,MCO_Prescaler_t Copy_Prescaler);
//Microconroller Clock Output 2 Configuration & Intialization Function
void RCC_voidMCO2(COM2_ClockSource_t Copy_Source,MCO_Prescaler_t Copy_Prescaler);
//HSE division factor for RTC clock Function
void voidRTC_HSEPrescaler (U8 Copy_Prescaler);
//Bus Prescaling functions
void voidBusClockPrescaler(AHB_Prescaler_t Copy_AHBPrescaler,APB_Prescaler_t Copy_APB1Prescaler,APB_Prescaler_t Copy_APB2Prescaler);
//Microconroller Periphirals Clock State Conrole & Power Mode Selection Function
void RCC_voidPeripheralClk(BUS_Peripherals_t Copy_Peripheral, BUS_PeripheralState_t Copy_State,BUS_PeripheralPowerMode_t Copy_PowerMode);

#endif // !RCC_INTERFACE_H
