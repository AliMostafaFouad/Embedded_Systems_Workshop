/****************************************************************/
/******* Author    : Ali Mostafa fouad         *****************/
/******* Date      : 19 sep 2023              *****************/
/******* Version   : 0.1                     *****************/
/******* File Name : timer_private.h                *****************/
/***********************************************************/
#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_


#define TIM4_BASE_ADDRESS  0x40000800


#define TIM4_CR1            (*((volatile u32 *)(TIM4_BASE_ADDRESS + 0x00))) 
#define TIM4_CR2            (*((volatile u32 *)(TIM4_BASE_ADDRESS + 0x04))) 
#define TIM4_SMCR           (*((volatile u32 *)(TIM4_BASE_ADDRESS + 0x08))) 
#define TIM4_DIER           (*((volatile u32 *)(TIM4_BASE_ADDRESS + 0x0C))) 
#define TIM4_SR             (*((volatile u32 *)(TIM4_BASE_ADDRESS + 0x10))) 
#define TIM4_EGR            (*((volatile u32 *)(TIM4_BASE_ADDRESS + 0x14))) 
#define TIM4_CCMR1          (*((volatile u32 *)(TIM4_BASE_ADDRESS + 0x18))) 
#define TIM4_CCMR2          (*((volatile u32 *)(TIM4_BASE_ADDRESS + 0x1C))) 
#define TIM4_CCER           (*((volatile u32 *)(TIM4_BASE_ADDRESS + 0x20))) 
#define TIM4_CNT            (*((volatile u32 *)(TIM4_BASE_ADDRESS + 0x24))) 
#define TIM4_PSC            (*((volatile u32 *)(TIM4_BASE_ADDRESS + 0x28))) 
#define TIM4_ARR            (*((volatile u32 *)(TIM4_BASE_ADDRESS + 0x2C))) 
#define TIM4_CCR1           (*((volatile u32 *)(TIM4_BASE_ADDRESS + 0x34))) 
#define TIM4_CCR2           (*((volatile u32 *)(TIM4_BASE_ADDRESS + 0x38))) 
#define TIM4_CCR3           (*((volatile u32 *)(TIM4_BASE_ADDRESS + 0x3C))) 
#define TIM4_CCR4           (*((volatile u32 *)(TIM4_BASE_ADDRESS + 0x40))) 
#define TIM4_DCR            (*((volatile u32 *)(TIM4_BASE_ADDRESS + 0x48))) 
#define TIM4_DMAR           (*((volatile u32 *)(TIM4_BASE_ADDRESS + 0x4C))) 



/*typedef struct TIM4_t
{
    
};*/
 
















#endif /*TIMER_PRIVATE_H_*/