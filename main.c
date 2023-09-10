#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_Interface.h"
#include "SysTick_Interface.h"

#include "GPIO_Interface.h"
#include "SCHADULAR_Interface.h"
void APP_LED1();
void APP_LED2();
void APP_LED3();
int main()
{
    RCC_voidInitSysClk(HSI,DisaplCSS);
    RCC_voidPeripheralClk(GPIO_A0,Enable,HighPowerMode);
    voidBusClockPrescaler(AHP_Division2,APB_NoDivision,APB_NoDivision);
    GPIO_voidSetPinMode(GPIO_A0,GPIO_OUTPUT);
    GPIO_voidOutputPinConfig(GPIO_A0,GPIO_PushPull,GPIO_Output_LS);
    
    GPIO_voidSetPinMode(GPIO_A1,GPIO_OUTPUT);
    GPIO_voidOutputPinConfig(GPIO_A1,GPIO_PushPull,GPIO_Output_LS);
    
    GPIO_voidSetPinMode(GPIO_A2,GPIO_OUTPUT);
    GPIO_voidOutputPinConfig(GPIO_A2,GPIO_PushPull,GPIO_Output_LS);

    SCH_voidCreateTask(0,200, APP_LED1,0);
    SCH_voidCreateTask(0,500, APP_LED2,0);
    SCH_voidCreateTask(0,100, APP_LED3,0);
    SCH_voidStartOs();
    return 0;
}

void APP_LED1()
{
    static U8 Local_u8PinValue = 0;
    if(Local_u8PinValue == 0)
    {
        /*Led is OFF*/
        GPIO_voidSetPinValue(GPIO_A0,Local_u8PinValue);
        Local_u8PinValue = 1;
    }
    else
    {
        GPIO_voidSetPinValue(GPIO_A0, Local_u8PinValue);
        Local_u8PinValue = 0;
    }
}

void APP_LED2()
{
    static U8 Local_u8PinValue = 0;
    if(Local_u8PinValue == 0)
    {
        /*Led is OFF*/
        GPIO_voidSetPinValue(GPIO_A1,Local_u8PinValue);
        Local_u8PinValue = 1;
    }
    else
    {
        GPIO_voidSetPinValue(GPIO_A1, Local_u8PinValue);
        Local_u8PinValue = 0;
    }
}

void APP_LED3()
{
    static U8 Local_u8PinValue = 0;
    if(Local_u8PinValue == 0)
    {
        /*Led is OFF*/
        GPIO_voidSetPinValue(GPIO_A2,Local_u8PinValue);
        Local_u8PinValue = 1;
    }
    else
    {
        GPIO_voidSetPinValue(GPIO_A2, Local_u8PinValue);
        Local_u8PinValue = 0;
    }
}
