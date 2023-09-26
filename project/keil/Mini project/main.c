/****************************************************************/
/******* Author    : Ali Mostafa fouad         *****************/
/******* Date      : 19 sep 2023              *****************/
/******* Version   : 0.1                     *****************/
/******* File Name : main.c                 *****************/
/***********************************************************/

/*     LIB        */
#include "BIT_MATH.h"
#include "STD_TYPES.h"
/*     MCAL       */
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"
#include "timer_interface.h"

void Delay(u32 ms);



int main(void)
{
/* set up code */
	
/* intialize system clock   */
MCAL_RCC_InitSysClock();
/* Enable Clock OF GPIO_PORTA */
MCAL_RCC_EnablePeripheral(RCC_APB2,RCC_APB2ENR_IOPAEN);
MCAL_RCC_EnablePeripheral(RCC_APB1,RCC_APB1ENR_TIM4EN);

/*set pins mode of port A*/
MCAL_GPIO_SetPinMode(GPIO_PORTA,GPIO_PIN3, GPIO_INPUT_PULL_DOWN_MOD  );
MCAL_GPIO_SetPinMode(GPIO_PORTA,GPIO_PIN4, GPIO_OUTPUT_PUSH_PULL_2MHZ);
MCAL_GPIO_SetPinMode(GPIO_PORTA,GPIO_PIN5, GPIO_OUTPUT_PUSH_PULL_2MHZ);
MCAL_GPIO_SetPinMode(GPIO_PORTA,GPIO_PIN6, GPIO_OUTPUT_PUSH_PULL_2MHZ); 

MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN6,GPIO_HIGH);
MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN5,GPIO_LOW);
MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN4,GPIO_LOW);
/* intialize interrupt  */
MCAL_NVIC_EnableIRQ(NVIC_EXTI3_IRQn);
EXTI_vInit();
EXTI_InitForGPIO(GPIO_PIN3,GPIO_PORTA);
EXTI_EnableLine(EXTI_LINE3);
MCAL_NVIC_EnableIRQ(NVIC_TIM4_IRQn);

/* Super Loop*/
while(1)
{
MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN6,GPIO_HIGH);
MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN5,GPIO_LOW);
MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN4,GPIO_LOW);
//MCAL_STK_SetDelay_ms(5000);
Delay(170);
MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN6,GPIO_LOW);
MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN5,GPIO_HIGH);
MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN4,GPIO_LOW);
Delay(170);
MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN6,GPIO_LOW);
MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN5,GPIO_LOW);
MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN4,GPIO_HIGH);
Delay(170);
MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN6,GPIO_LOW);
MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN5,GPIO_HIGH);
MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN4,GPIO_LOW);
Delay(170);
}


 
}

void EXTI3_IRQHandler(void)
{
MCAL_NVIC_DisableIRQ(9);
EXTI_DisableLine(EXTI_LINE3);
u8 green_read=0;
u8 yellow_read=0;
u8 red_read=0;
u8 is_press=0;
MCAL_GPIO_GetPinValue(GPIO_PORTA,GPIO_PIN6,&green_read);
MCAL_GPIO_GetPinValue(GPIO_PORTA,GPIO_PIN5,&yellow_read);
MCAL_GPIO_GetPinValue(GPIO_PORTA,GPIO_PIN4,&red_read);


	
if (red_read)
{
	
}	
else if(green_read)
{
		MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN6,GPIO_LOW);
		MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN4,GPIO_LOW);
    MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN5,GPIO_HIGH);
    Delay(170);
		MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN6,GPIO_LOW);
		MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN5,GPIO_LOW);
    MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN4,GPIO_HIGH);
		Delay(170);
		MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN6,GPIO_LOW);
    MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN4,GPIO_LOW);
	  MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN5,GPIO_HIGH);
    Delay(170);
	  MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN6,GPIO_HIGH);
    MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN5,GPIO_LOW);
    MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN4,GPIO_LOW);
	  
}

else if(yellow_read)
{
		MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN6,GPIO_LOW);
		MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN4,GPIO_LOW);
    MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN5,GPIO_HIGH);
    Delay(170);
		MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN6,GPIO_LOW);
		MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN5,GPIO_LOW);
    MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN4,GPIO_HIGH);
	  Delay(170);
	  MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN6,GPIO_LOW);
		MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN4,GPIO_LOW);
    MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN5,GPIO_HIGH);
    Delay(170);
	 

}

//EXTI_WritePending(EXTI_LINE3);
//MCAL_NVIC_SetPendingIRQ(9);
MCAL_NVIC_ClearPendingIRQ(9);
MCAL_NVIC_EnableIRQ(NVIC_EXTI3_IRQn);
EXTI_EnableLine(EXTI_LINE3);




}

void Delay(u32 ms)
{
for(u32 i=0;i<ms;i++)
	{for(u32 j=0;j<1275;j++);}

}

























