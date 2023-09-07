/**********************************************************/
/**********Author: Ali Mostafa fouad **********************/
/********** Date : 4/9/2023          **********************/
/******** Version:  0.1              **********************/
/******** File Name: RCC_config.h   **********************/
/**********************************************************/
#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_

/**
 * @brief
 * your SYSTEM CLOCK option: RCC_HSI
 *                           RCC_HSE 
 *                           RCC_PLL
*/
#define RCC_SYSCLK       RCC_HSI

/**
 * @brief
 * your options if RCC_HSE was Selected :
 *                                   RCC_RC_CLK_        -> RC will be the source of the clock system
 *                                   RCC_CRYSTAL_CLK_   -> crystal will be the source of the clock system
 * 
 * 
*/
                       
#if RCC_SYSCLK == RCC_HSE

#define RCC_CLC_BYPASS   RCC_RC_CLK_

#endif
/**
 * @brief
 * your options if RCC_PLL was Selected : 
 *                                        1. PLL_CLK_Source: 
 *                                                          Half_HSI
 *                                                          Half_HSE
 *                                                          HSE
 *                                        2. PLL_Multiplication_factor:
 *                                                                       PLL_INPUT_CLK_x2
 *                                                                       PLL_INPUT_CLK_x3
 *                                                                       PLL_INPUT_CLK_x4
 *                                                                       PLL_INPUT_CLK_x5
 *                                                                       PLL_INPUT_CLK_x6
 *                                                                       PLL_INPUT_CLK_x7
 *                                                                       PLL_INPUT_CLK_x8
 *                                                                       PLL_INPUT_CLK_x9
 *                                                                       PLL_INPUT_CLK_x10
 *                                                                       PLL_INPUT_CLK_x11
 *                                                                       PLL_INPUT_CLK_x12
 *                                                                       PLL_INPUT_CLK_x13
 *                                                                       PLL_INPUT_CLK_x14
 *                                                                       PLL_INPUT_CLK_x15
 *                                                                       PLL_INPUT_CLK_x16
*/

#if RCC_SYSCLK == RCC_PLL

#define PLL_CLK_Source            HSE
#define PLL_Multiplication_factor PLL_INPUT_CLK_x2


#endif


/**< MCO Source option :
 * MCO_NO_CLK
 * MCO_System_CLK
 * MCO_HSI_CLK
 * MCO_HSE_CLK
 * MCO_PLL_CLK_divided_by_2 
 * 
*/

 #define MCO_Source  MCO_NO_CLK


/*< AHB Prescaler division factor option:
            AHB_SYSCLK_divided_by_1
            AHB_SYSCLK_divided_by_2,
            AHB_SYSCLK_divided_by_4,
            AHB_SYSCLK_divided_by_8,
            AHB_SYSCLK_divided_by_16,
            AHB_SYSCLK_divided_by_64,
            AHB_SYSCLK_divided_by_128,
            AHB_SYSCLK_divided_by_256,
            AHB_SYSCLK_divided_by_512
*/

#define   AHB_Prescaler_divition_factor   AHB_SYSCLK_divided_by_1 










#endif //RCC_CONFIG_H_