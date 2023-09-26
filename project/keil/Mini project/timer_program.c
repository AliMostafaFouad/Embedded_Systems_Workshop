/****************************************************************/
/******* Author    : Ali Mostafa fouad         *****************/
/******* Date      : 19 sep 2023              *****************/
/******* Version   : 0.1                     *****************/
/******* File Name : timer_config.h         *****************/
/***********************************************************/

/*****************************< LIB *****************************/
#include"STD_TYPES.h"
#include"BIT_MATH.h"
/*****************************< MCAL *****************************/
#include "timer_interface.h"
#include "timer_private.h"
#include "timer_config.h"

u32 myTicks =0;
Std_ReturnType MCAL_TIM4_Init()
{
TIM4_PSC &= ~(0XFFFFFFFF);
TIM4_ARR =0X00000008;
SET_BIT(TIM4_CR1,0);
SET_BIT(TIM4_DIER,0);
SET_BIT(TIM4_EGR,0);

}

 Std_ReturnType MCAL_TIM4_Delay( u32 MilliSec)
{
SET_BIT(TIM4_CR1,0);
myTicks=0;
while (myTicks<(MilliSec *1000));
CLR_BIT(TIM4_CR1,0);

}
void TIM4_IRQHandler(void)
{



myTicks++;
CLR_BIT(TIM4_SR,0);

}

 