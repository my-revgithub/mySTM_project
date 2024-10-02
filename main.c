#include <stdio.h>
#include "main.h"
#include "typedef.h"
#include "register.h"
#include "schedular.h"

void System_Clock_Setup(void);
void System_Timer_Init(void);
void Driver_Init(void);
void Interrupt_Enable_All(void);
void Interrupt_Disable_All(void);

volatile uint32 timer_tim2_cnt_1ms = 0;

int main(void)
{
	__disable_interrupt__;
	//Setup System clock @ 128Mhz w/ internal source oscillator
	System_Clock_Setup();
	//Initialize the drivers
	Driver_Init();
	//Jump to ASW and never return
	Schedular();
	//Should not ideally reach this place
	while(1);
	return 0;
}

void Driver_Init(void)
{
	System_Timer_Init();
}

//Initialize the system timer TIM2 to interrupt every 1ms
void System_Timer_Init(void)
{
	//Setup the TIM2 to interrupt every 1ms
	//TIMx control register 1 (TIMx_CR1)
	//Edge aligned, DIR up counter, Auto reload preload register disabled, Disable One pulse
	//Interrupt on OVFL/UNFL,Set URS UDIS, Set CEN post complete configuration of the TIM2 
	//CKD[1:0] 00 ARPE 0 CMS 00 DIR 0(up) OPM 0 URS 1 UDIS 0 CEN 0
	*TIM2_CR1 =(uint16)0x0004;
	
	//TIM2_PSC
	//The counter clock frequency CK_CNT is equal to fCK_PSC / (PSC[15:0] + 1)
	//fck_psc = 128Mhz, PSC = 127(7F),fck_cnt = 128mhz/(127+1) => 1Mhz
	*TIM2_PSC = (uint16)0x007F;
	
	//TIM2_CNT
	//Timer counter = 1000
	*TIM2_CNT = (uint32)(0x3E8);
	
	//TIM2_ARR
	*TIM2_CNT = (uint32)(*TIM2_CNT);
	
	//TIM2_DIER
	//Disable DMA, trigger int enable, update int flag
	//TDE 0 CC4DE 0 CC3DE 0 CC2DE 0 CC1DE 0 UDE 0 TIE 1  CC4IE 0 CC3IE 0 CC2IE 0 CC1IE 0 UIE 1
	*TIM2_DIER = (uint16)(0x0041);
	
	//Enable the Counter interrupt CEN & TIM2 interrupt
	*NVIC_ICER0 |= (0x10000000); //Set TIM2 global interrupt 
	*TIM2_CR1 |=(uint16)0x1;
	//Note that the actual counter enable signal CNT_EN is set 1 clock cycle after CEN
	__asm(
		"nop"
	);
}

//Interrupt handler for TIM2
void TIM2_IRQHandler(void)
{
	//Check for UIF bit
	if((*TIM2_SR & 0x1) != 0x0)
	{
		//Acknowledge the interrupt rc_w0 write 1 to clear the flag
		*TIM2_SR|=0x1;
		timer_tim2_cnt_1ms++;
	};
}

//Setup the system clock @ 128Mhz operation 
//Default operating frequency of the stm32f407 is 16Mhz
void System_Clock_Setup(void)
{
	//RCC_PLLCFGR -> PLLSRC = HSI(default) PLLN = 0x4, PLLM = 0x10, f-hsi = 16mhz
	//f(VCO clock) = f(PLL clock input) × (PLLN / PLLM) => 16Mhz x (192/16) = 192Mhz
	//Configure the f(VCO clock) = 256mhz => F-HSI-16Mhz x (PLLN-192/PLLM-12) = 256Mhz
	//f(PLL general clock output) = f(VCO clock) / PLLP(00) => 256mhz/2 = 128Mhz
	*RCC_PLLCFGR = (uint32)(0x2400301C);
	
	//Select the SW as PLL
	*RCC_CFGR = (uint32)(0x2); // Select SW as 0b10 (Sys clock => PLL)
	
	//Enable the PLL
	*RCC_CR |= (uint32)(0x01000000); // Set PLLON, HSION is set by default
	//Check for PLLRDY flag to check if the PLL is locked and ready for use
	while(((uint32)*RCC_CR & (0x10000000)) != 0x10000000)
	{
		//Wait for PLL to lock;
	}
	//RCC_CSR
}

void Interrupt_Disable_All(void)
{
	uint32 *NVIC_ICERx;
	uint8 i;
	
	NVIC_ICERx = (uint32 *)(NVIC_ICER0);
	
	for(i=0;i<8;i++)
	{
		*NVIC_ICERx = 0xFFFFFFFF;
		NVIC_ICERx++;
	}
}

void Interrupt_Enable_All(void)
{
	uint32 *NVIC_ISERx;
	uint8 i;
	
	NVIC_ISERx = (uint32 *)(NVIC_ISER0);
	
	for(i=0;i<8;i++)
	{
		*NVIC_ISERx = 0xFFFFFFFF;
		NVIC_ISERx++;
	}	
}