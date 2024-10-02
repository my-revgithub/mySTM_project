#include "typedef.h"

//Register address declaration

//Reset Clock Control Register
#define RCC_CR 		(volatile uint32 *)(0x40023800UL)		//RCC clock control register (RCC_CR)
#define RCC_PLLCFGR (volatile uint32 *)(0x40023804UL)		//RCC PLL configuration register (RCC_PLLCFGR)
#define RCC_CFGR 	(volatile uint32 *)(0x40023808UL)		//RCC Clock configuration register (RCC_CFGR)
#define RCC_CIR 	(volatile uint32 *)(0x4002380CUL)		//RCC clock interrupt register (RCC_CIR)
#define RCC_CSR 	(volatile uint32 *)(0x40023874UL)		//RCC clock control & status register (RCC_CSR)


//System Timer Register

#define TIM2_CR1	(volatile uint16 *)(0x40000000UL)		//TIMx control register 1 (TIMx_CR1)
#define TIM2_CR2	(volatile uint16 *)(0x40000004UL)		//TIMx control register 1 (TIMx_CR2)
#define TIM2_SMCR	(volatile uint32 *)(0x40000008UL)		//TIMx slave mode control register (TIMx_SMCR)
#define TIM2_DIER	(volatile uint16 *)(0x4000000CUL)		//TIMx DMA/Interrupt enable register (TIMx_DIER)
#define TIM2_SR		(volatile uint32 *)(0x40000010UL)		//TIMx status register (TIMx_SR)
#define TIM2_EGR 	(volatile uint32 *)(0x40000014UL)		//TIMx event generation register (TIMx_EGR)
#define TIM2_CNT 	(volatile uint32 *)(0x40000024UL)		//TIMx counter (TIMx_CNT)
#define TIM2_PSC 	(volatile uint16 *)(0x40000028UL)		//TIMx prescaler (TIMx_PSC)
#define TIM2_ARR 	(volatile uint32 *)(0x4000002CUL)		//TIMx auto-reload register (TIMx_ARR)


//NVIC Interrupt Register
#define NVIC_ISER0	(volatile uint16 *)(0xE000E100UL)		//Interrupt set-enable register x (NVIC_ISERx)
#define NVIC_ISER1	(volatile uint16 *)(0xE000E104UL)		//Interrupt set-enable register x (NVIC_ISERx)
#define NVIC_ISER2	(volatile uint16 *)(0xE000E108UL)		//Interrupt set-enable register x (NVIC_ISERx)
#define NVIC_ISER3	(volatile uint16 *)(0xE000E10CUL)		//Interrupt set-enable register x (NVIC_ISERx)
#define NVIC_ISER4	(volatile uint16 *)(0xE000E100UL)		//Interrupt set-enable register x (NVIC_ISERx)
#define NVIC_ISER5	(volatile uint16 *)(0xE000E114UL)		//Interrupt set-enable register x (NVIC_ISERx)
#define NVIC_ISER6	(volatile uint16 *)(0xE000E118UL)		//Interrupt set-enable register x (NVIC_ISERx)
#define NVIC_ISER7	(volatile uint16 *)(0xE000E11CUL)		//Interrupt set-enable register x (NVIC_ISERx)

#define NVIC_ICER0	(volatile uint16 *)(0xE000E180UL)		//Interrupt clear-enable register x (NVIC_ICERx)
#define NVIC_ICER1	(volatile uint16 *)(0xE000E184UL)		//Interrupt clear-enable register x (NVIC_ICERx)
#define NVIC_ICER2	(volatile uint16 *)(0xE000E188UL)		//Interrupt clear-enable register x (NVIC_ICERx)
#define NVIC_ICER3	(volatile uint16 *)(0xE000E18CUL)		//Interrupt clear-enable register x (NVIC_ICERx)
#define NVIC_ICER4	(volatile uint16 *)(0xE000E190UL)		//Interrupt clear-enable register x (NVIC_ICERx)
#define NVIC_ICER5	(volatile uint16 *)(0xE000E194UL)		//Interrupt clear-enable register x (NVIC_ICERx)
#define NVIC_ICER6	(volatile uint16 *)(0xE000E198UL)		//Interrupt clear-enable register x (NVIC_ICERx)
#define NVIC_ICER7	(volatile uint16 *)(0xE000E19CUL)		//Interrupt clear-enable register x (NVIC_ICERx)
