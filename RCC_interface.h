/**********************************************************/
/**********Author: Ali Mostafa fouad **********************/
/********** Date : 4/9/2023          **********************/
/******** Version:  0.1              **********************/
/******** File Name: RCC_interface.h   **********************/
/**********************************************************/
#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

#define RCC_AHB     0
#define RCC_APB1    1
#define RCC_APB2    2








// functions
std_ReturnType Mcal_RCC_InitSysClok(void);// select system clock function 

std_ReturnType Mcal_RCC_EnablePeripheral( u8 copy_PeripherlId, u8 copy_BusId);//enable peripheral

std_ReturnType Mcal_RCC_disablePeripheral( u8 copy_PeripherlId, u8 copy_BusId);//disable peripheral

std_ReturnType RCC_MCO_CLK(void);// MCO Function

std_ReturnType RCC_AHB_Prescale(void);






#endif //RCC_INTERFACE_H_