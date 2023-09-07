/**********************************************************/
/**********Author: Ali Mostafa fouad **********************/
/********** Date : 4/9/2023          **********************/
/******** Version:  0.1              **********************/
/******** File Name: RCC_Private.h             **********************/
/**********************************************************/
#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_

// define preipheral address and it's registers
#define RCC_BASE_ADDRESS                       0X40021000
#define RCC_CR             *((volatile u32 *) (0X40021000+0X00))
#define RCC_CFGR           *((volatile u32 *) (0X40021000+0X04))
#define RCC_CIR            *((volatile u32 *) (0X40021000+0X08))
#define RCC_APB2RSTR       *((volatile u32 *) (0X40021000+0X0C))
#define RCC_APB1RSTR       *((volatile u32 *) (0X40021000+0X010))
#define RCC_AHBENR         *((volatile u32 *) (0X40021000+0X14))
#define RCC_APB2ENR        *((volatile u32 *) (0X40021000+0X18))
#define RCC_APB1ENR        *((volatile u32 *) (0X40021000+0X1C))
#define RCC_BDCR           *((volatile u32 *) (0X40021000+0X20))
#define RCC_CSR            *((volatile u32 *) (0X40021000+0X24))

// define register RCC_CR Bits  
#define RCC_CR_HSION    0
#define RCC_CR_HSIRDY   1
#define RCC_CR_HSITRIM0 3
#define RCC_CR_HSITRIM1 4
#define RCC_CR_HSITRIM2 5
#define RCC_CR_HSITRIM3 6
#define RCC_CR_HSITRIM4 7
#define RCC_CR_HSICAL0  8
#define RCC_CR_HSICAL1  9
#define RCC_CR_HSICAL2  10
#define RCC_CR_HSICAL3  11
#define RCC_CR_HSICAL4  12
#define RCC_CR_HSICAL5  13
#define RCC_CR_HSICAL6  14
#define RCC_CR_HSICAL7  15
#define RCC_CR_HSEON    16
#define RCC_CR_HSERDY   17
#define RCC_CR_HSEBYP   18
#define RCC_CR_CSSON    19
#define RCC_CR_PLLON    24
#define RCC_CR_PLLRDY   25

// define register RCC_CFGR Bits 
enum
{   RCC_CFGR_SW0,
    RCC_CFGR_SW1,
    RCC_CFGR_SWS0,
    RCC_CFGR_SWS1,
    RCC_CFGR_HPRE0,
    RCC_CFGR_HPRE1,
    RCC_CFGR_HPRE2,
    RCC_CFGR_HPRE3,
    RCC_CFGR_PPRE10,
    RCC_CFGR_PPRE11,
    RCC_CFGR_PPRE12,
    RCC_CFGR_PPRE20,
    RCC_CFGR_PPRE21,
    RCC_CFGR_PPRE22,
    RCC_CFGR_ADCPRE0,
    RCC_CFGR_ADCPRE1,
    RCC_CFGR_PLLSRC,
    RCC_CFGR_PLLXTPRE,
    RCC_CFGR_PLLMUL0,
    RCC_CFGR_PLLMUL1,
    RCC_CFGR_PLLMUL2,
    RCC_CFGR_PLLMUL3,
    RCC_CFGR_USBPRE,
    RCC_CFGR_MCO0 =24,
    RCC_CFGR_MCO1,
    RCC_CFGR_MCO2
};

// define register RCC_CIR Bits 
enum
{
    RCC_RCC_CIR_LSIRDYF,
    RCC_RCC_CIR_LSERDYF,
    RCC_RCC_CIR_HSIRDYF,
    RCC_RCC_CIR_HSERDYF,
    RCC_RCC_CIR_PLLRDYF,
    RCC_RCC_CIR_CSSF=7,
    RCC_RCC_CIR_LSIRDYIE,
    RCC_RCC_CIR_LSERDYIE,
    RCC_RCC_CIR_HSIRDYIE,
    RCC_RCC_CIR_HSERDYIE,
    RCC_RCC_CIR_PLLRDYIE,
    RCC_RCC_CIR_LSIRDYC=16,
    RCC_RCC_CIR_LSERDYC,
    RCC_RCC_CIR_HSIRDYC,
    RCC_RCC_CIR_HSERDYC,
    RCC_RCC_CIR_PLLRDYC,
    RCC_RCC_CIR_CSSC=23,

};









#define RCC_HSI    0
#define RCC_HSE    1 
#define RCC_PLL    2

#define RCC_CRYSTAL_CLK_    0
#define RCC_RC_CLK_         1

// PLL Sources
enum
{
    Half_HSI,
    Half_HSE,
    HSE
};

// PLL Multiplication Factor 
enum
{
    PLL_INPUT_CLK_x2,
    PLL_INPUT_CLK_x3,
    PLL_INPUT_CLK_x4,
    PLL_INPUT_CLK_x5,
    PLL_INPUT_CLK_x6,
    PLL_INPUT_CLK_x7,
    PLL_INPUT_CLK_x8,
    PLL_INPUT_CLK_x9,
    PLL_INPUT_CLK_x10,
    PLL_INPUT_CLK_x11,
    PLL_INPUT_CLK_x12,
    PLL_INPUT_CLK_x13,
    PLL_INPUT_CLK_x14,
    PLL_INPUT_CLK_x15,
    PLL_INPUT_CLK_x16,

};


// MCO sources
enum
{
    MCO_NO_CLK,
    MCO_System_CLK=4,
    MCO_HSI_CLK,
    MCO_HSE_CLK,
    MCO_PLL_CLK_divided_by_2
};

// AHB Presscale values
enum
{
 AHB_SYSCLK_divided_by_1,
 AHB_SYSCLK_divided_by_2 = 8,
 AHB_SYSCLK_divided_by_4,
 AHB_SYSCLK_divided_by_8,
 AHB_SYSCLK_divided_by_16,
 AHB_SYSCLK_divided_by_64,
 AHB_SYSCLK_divided_by_128,
 AHB_SYSCLK_divided_by_256,
 AHB_SYSCLK_divided_by_512

};








#endif //RCC_PRIVATE_H_