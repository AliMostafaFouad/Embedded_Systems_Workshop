/**********************************************************/
/**********Author: Ali Mostafa fouad **********************/
/********** Date : 4/9/2023          **********************/
/******** Version:  0.1              **********************/
/******** File Name: RCC_program.c   **********************/
/**********************************************************/

/*****************************<LIB*****************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*****************************< MCAL*****************************/
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

std_ReturnType Mcal_RCC_InitSysClok(void)
{
std_ReturnType local_FunctionStatus = E_NOT_OK;

// HSE
#if  RCC_SYSCLK==RCC_HSE
    // select HSE type 
    #if RCC_CLC_BYPASS == RCC_RC_CLK_
        SET_BIT(RCC_CR,RCC_CR_HSEBYP);
    #elif RCC_CLC_BYPASS == RCC_CRYSTAL_CLK_
          CLEAR_BIT(RCC_CR,RCC_CR_HSEBYP);
    #else
          #error "NOT Valid!"

    #endif // RCC_HSE_BYPASS
    SET_BIT(RCC_CR,RCC_CR_HSEON);//enable HSE 
    while (!GET_BIT(RCC_RC,RCC_CR_HSERDY));//Wait untill clk stable
    // System clock Switch (MUX)
    //RCC_CFGR = 0X00000001;// select HSE
    SET_BIT(RCC_CFGR,SW0);
    CLEAR_BIT(RCC_CFGR,SW1);
    local_FunctionStatus = E_OK;

// HSI
#elif  RCC_SYSCLK==RCC_HSI
SET_BIT(RCC_CR,RCC_CR_HSION);//Enable HSI 
while (!GET_BIT(RCC_RC,RCC_CR_HSIRDY));//Wait untill clk stable
// System clock Switch (MUX)
//RCC_CFGR = 0X00000000;// select HSI
CLEAR_BIT(RCC_CFGR,SW0);
CLEAR_BIT(RCC_CFGR,SW1);
local_FunctionStatus = E_OK;

//PLL
#elif RCC_SYSCLK==RCC_PLL
local_FunctionStatus = E_NOT_OK;
// Select PLL clock source 
switch (PLL_CLK_Source)
{
case Half_HSI :
               CLEAR_BIT(RCC_CFGR,RCC_CFGR_PLLSRC);
               local_FunctionStatus = E_OK;
    break;
case Half_HSE :
              SET_BIT(RCC_CFGR,RCC_CFGR_PLLSRC);
              SET_BIT(RCC_CFGR,RCC_CFGR_PLLXTPRE);
              local_FunctionStatus = E_OK;
case HSE :
          SET_BIT(RCC_CFGR,RCC_CFGR_PLLSRC);
          CLEAR_BIT(RCC_CFGR,RCC_CFGR_PLLXTPRE);
          local_FunctionStatus = E_OK;
    break;

default:
        #error "NOT Valid!"
        local_FunctionStatus = E_NOT_OK;
    break;
}
// set multiplication value
switch (PLL_Multiplication_factor)
{
case  PLL_INPUT_CLK_x2:
   RCC_CFGR = (RCC_CFGR & 0XFFC3FFFF) | (PLL_Multiplication_factor << RCC_CFGR_PLLMUL0);
   local_FunctionStatus = E_OK;
    break;
case  PLL_INPUT_CLK_x3:
   RCC_CFGR = (RCC_CFGR & 0XFFC3FFFF) | (PLL_Multiplication_factor << RCC_CFGR_PLLMUL0);
   local_FunctionStatus = E_OK;
   break;
case  PLL_INPUT_CLK_x4:
   RCC_CFGR = (RCC_CFGR & 0XFFC3FFFF) | (PLL_Multiplication_factor << RCC_CFGR_PLLMUL0);
   local_FunctionStatus = E_OK;
    break;
case  PLL_INPUT_CLK_x5:
   RCC_CFGR = (RCC_CFGR & 0XFFC3FFFF) | (PLL_Multiplication_factor << RCC_CFGR_PLLMUL0);
   local_FunctionStatus = E_OK;
    break;
case  PLL_INPUT_CLK_x6:
   RCC_CFGR = (RCC_CFGR & 0XFFC3FFFF) | (PLL_Multiplication_factor << RCC_CFGR_PLLMUL0);
   local_FunctionStatus = E_OK;
    break;
case  PLL_INPUT_CLK_x7:
   RCC_CFGR = (RCC_CFGR & 0XFFC3FFFF) | (PLL_Multiplication_factor << RCC_CFGR_PLLMUL0);
   local_FunctionStatus = E_OK;
   break;
case  PLL_INPUT_CLK_x8:
   RCC_CFGR = (RCC_CFGR & 0XFFC3FFFF) | (PLL_Multiplication_factor << RCC_CFGR_PLLMUL0);
   local_FunctionStatus = E_OK;
    break;
case  PLL_INPUT_CLK_x9:
   RCC_CFGR = (RCC_CFGR & 0XFFC3FFFF) | (PLL_Multiplication_factor << RCC_CFGR_PLLMUL0);
   local_FunctionStatus = E_OK;
    break;
case  PLL_INPUT_CLK_x10:
   RCC_CFGR = (RCC_CFGR & 0XFFC3FFFF) | (PLL_Multiplication_factor << RCC_CFGR_PLLMUL0);
   local_FunctionStatus = E_OK;
    break;
case  PLL_INPUT_CLK_x11:
   RCC_CFGR = (RCC_CFGR & 0XFFC3FFFF) | (PLL_Multiplication_factor << RCC_CFGR_PLLMUL0);
   local_FunctionStatus = E_OK;
   break;
case  PLL_INPUT_CLK_x12:
   RCC_CFGR = (RCC_CFGR & 0XFFC3FFFF) | (PLL_Multiplication_factor << RCC_CFGR_PLLMUL0);
   local_FunctionStatus = E_OK;
    break;
case  PLL_INPUT_CLK_x13:
   RCC_CFGR = (RCC_CFGR & 0XFFC3FFFF) | (PLL_Multiplication_factor << RCC_CFGR_PLLMUL0);
   local_FunctionStatus = E_OK;
    break;
case  PLL_INPUT_CLK_x14:
   RCC_CFGR = (RCC_CFGR & 0XFFC3FFFF) | (PLL_Multiplication_factor << RCC_CFGR_PLLMUL0);
   local_FunctionStatus = E_OK;
    break;
case  PLL_INPUT_CLK_x15:
   RCC_CFGR = (RCC_CFGR & 0XFFC3FFFF) | (PLL_Multiplication_factor << RCC_CFGR_PLLMUL0);
   local_FunctionStatus = E_OK;
   break;
case  PLL_INPUT_CLK_x16:
   RCC_CFGR = (RCC_CFGR & 0XFFC3FFFF) | (PLL_Multiplication_factor << RCC_CFGR_PLLMUL0);
   local_FunctionStatus = E_OK;
    break;

default:
        #error "NOT Valid!"
        local_FunctionStatus = E_NOT_OK;
    break;
}
//Enable PLL
SET_BIT(RCC_CR,RCC_CR_PLLON);
while (!GET_BIT(RCC_RC,RCC_CR_PLLRDY));//Wait untill clk stable
// System clock Switch (MUX)
//RCC_CFGR = 0X00000002;// select PLL
CLEAR_BIT(RCC_CFGR,SW0);
SET_BIT(RCC_CFGR,SW1);
local_FunctionStatus = E_OK;


//Else
#else
    #error "NOT Valid!"
#endif

return local_FunctionStatus;

}



std_ReturnType Mcal_RCC_EnablePeripheral( u8 copy_PeripherlId, u8 copy_BusId)
{
    std_ReturnType local_FunctionStatus = E_NOT_OK;

    switch (copy_BusId)
    {
    case RCC_AHB:
                SET_BIT(RCC_AHBENR,copy_PeripherlId );
                local_FunctionStatus = E_OK;
        break;
    case RCC_APB1:
                 SET_BIT(RCC_APB1ENR,copy_PeripherlId );
                 local_FunctionStatus = E_OK;
        break;

    case RCC_APB2:
                SET_BIT(RCC_APB2ENR,copy_PeripherlId );
                local_FunctionStatus = E_OK;
        break;

    default:
     local_FunctionStatus = E_NOT_OK;
        break;
    }




return local_FunctionStatus;
}



std_ReturnType Mcal_RCC_disablePeripheral( u8 copy_PeripherlId, u8 copy_BusId)
{
    std_ReturnType local_FunctionStatus = E_NOT_OK;

    switch (copy_BusId)
    {
    case RCC_AHB:
                CLEAR_BIT(RCC_AHBENR,copy_PeripherlId );
                local_FunctionStatus = E_OK;
        break;
    case RCC_APB1:
                 CLEAR_BIT(RCC_APB1ENR,copy_PeripherlId );
                 local_FunctionStatus = E_OK;
        break;

    case RCC_APB2:
                CLEAR_BIT(RCC_APB2ENR,copy_PeripherlId );
                local_FunctionStatus = E_OK;
        break;

    default:
     local_FunctionStatus = E_NOT_OK;
        break;
    }

 return local_FunctionStatus;
}


std_ReturnType RCC_MCO_CLK(void)
{

    std_ReturnType local_FunctionStatus = E_NOT_OK;
    switch (MCO_Source)
    {

    case  MCO_NO_CLK:
        RCC_CFGR=(RCC_CFGR & 0XF8FFFFFF) | (MCO_Source)<< RCC_CFGR_MCO0;
        local_FunctionStatus = E_OK;
        break;
    case MCO_System_CLK:
        RCC_CFGR=(RCC_CFGR & 0XF8FFFFFF) | (MCO_Source)<< RCC_CFGR_MCO0;
        local_FunctionStatus = E_OK;
        break;
    case MCO_HSI_CLK:
        RCC_CFGR=(RCC_CFGR & 0XF8FFFFFF) | (MCO_Source)<< RCC_CFGR_MCO0;
        local_FunctionStatus = E_OK;
        break;
    case MCO_HSE_CLK:
        RCC_CFGR=(RCC_CFGR & 0XF8FFFFFF) | (MCO_Source)<< RCC_CFGR_MCO0;
        local_FunctionStatus = E_OK;
        break;
    case MCO_PLL_CLK_divided_by_2:
        RCC_CFGR=(RCC_CFGR & 0XF8FFFFFF) | (MCO_Source)<< RCC_CFGR_MCO0;
        local_FunctionStatus = E_OK;
        break;
    default:
            #error "NOT Valid!"
            local_FunctionStatus = E_NOT_OK;
        break;


    }

    return local_FunctionStatus;

}




std_ReturnType RCC_AHB_Prescale(void)
{

    std_ReturnType local_FunctionStatus = E_NOT_OK;
    switch ( AHB_Prescaler_divition_factor)
    {
    case AHB_SYSCLK_divided_by_1:
        RCC_CFGR=(RCC_CFGR & 0XFFFFFF0F) | (AHB_Prescaler_divition_factor << RCC_CFGR_HPRE0);
        local_FunctionStatus = E_OK;
        break;
    case AHB_SYSCLK_divided_by_2:
        RCC_CFGR=(RCC_CFGR & 0XFFFFFF0F) | (AHB_Prescaler_divition_factor << RCC_CFGR_HPRE0);
        local_FunctionStatus = E_OK;
        break;
    case AHB_SYSCLK_divided_by_4:
        RCC_CFGR=(RCC_CFGR & 0XFFFFFF0F) | (AHB_Prescaler_divition_factor << RCC_CFGR_HPRE0);
        local_FunctionStatus = E_OK;
        break;
    case AHB_SYSCLK_divided_by_8:
        RCC_CFGR=(RCC_CFGR & 0XFFFFFF0F) | (AHB_Prescaler_divition_factor << RCC_CFGR_HPRE0);
        local_FunctionStatus = E_OK;
        break;
    case AHB_SYSCLK_divided_by_16:
        RCC_CFGR=(RCC_CFGR & 0XFFFFFF0F) | (AHB_Prescaler_divition_factor << RCC_CFGR_HPRE0);
        local_FunctionStatus = E_OK;
        break;
    case AHB_SYSCLK_divided_by_64:
        RCC_CFGR=(RCC_CFGR & 0XFFFFFF0F) | (AHB_Prescaler_divition_factor << RCC_CFGR_HPRE0);
        local_FunctionStatus = E_OK;
        break;
    case AHB_SYSCLK_divided_by_128:
        RCC_CFGR=(RCC_CFGR & 0XFFFFFF0F) | (AHB_Prescaler_divition_factor << RCC_CFGR_HPRE0);
        local_FunctionStatus = E_OK;
        break;
    case AHB_SYSCLK_divided_by_256:
        RCC_CFGR=(RCC_CFGR & 0XFFFFFF0F) | (AHB_Prescaler_divition_factor << RCC_CFGR_HPRE0);
        local_FunctionStatus = E_OK;
        break;
    case AHB_SYSCLK_divided_by_512:
        RCC_CFGR=(RCC_CFGR & 0XFFFFFF0F) | (AHB_Prescaler_divition_factor << RCC_CFGR_HPRE0);
        local_FunctionStatus = E_OK;
        break;

    default:
    #error "NOT Valid!"
    local_FunctionStatus = E_NOT_OK;
        break;
    }

    return local_FunctionStatus;


}













