#include "typedef.h"

//Register address declaration

//Reset Clock Control Register
#define RCC_CR 		(volatile uint32 *)(0x40023800UL)		//RCC clock control register (RCC_CR)
#define RCC_PLLCFGR (volatile uint32 *)(0x40023804UL)		//RCC PLL configuration register (RCC_PLLCFGR)
#define RCC_CFGR 	(volatile uint32 *)(0x40023808UL)		//RCC Clock configuration register (RCC_CFGR)
#define RCC_CIR 	(volatile uint32 *)(0x4002380CUL)		//RCC clock interrupt register (RCC_CIR)
#define RCC_CSR 	(volatile uint32 *)(0x40023874UL)		//RCC clock control & status register (RCC_CSR)


//System Timer Register

#define TIM2_CR1	(volatile uint32 *)(0x40000000UL)		//TIMx control register 1 (TIMx_CR1)
#define TIM2_SMCR	(volatile uint32 *)(UL)		//
#define TIM2_EGR 	(volatile uint32 *)(UL)		//
