#include <stdio.h>
#include "main.h"
#include "typedef.h"
#include "register.h"

void System_Clock_Setup(void);

void main(void)
{
	//Initialize System clock @ 128Mhz internal source oscillator
	System_Clock_Setup();
	
	
	//Should not ideally reach this place
	while(1);
	//return 0;
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