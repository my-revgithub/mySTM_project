#include "typedef.h"
#include "main.h"
#include "register.h"

void Reset_function(void);
extern uint32 _str_sram;
extern uint32 _end_sram;
extern uint32 _str_bss;
extern uint32 _start_data_addr;
extern uint32 _end_fl;
extern uint32 _end_bss;
extern uint32 _stack_ptr;

void NMI_Handler 					(void) __attribute__ ((weak, alias("Default_Handler")));
void HardFault_Handler 				(void) __attribute__ ((weak, alias("Default_Handler")));
void MemManage_Handler 				(void) __attribute__ ((weak, alias("Default_Handler")));
void BusFault_Handler 				(void) __attribute__ ((weak, alias("Default_Handler")));
void UsageFault_Handler 			(void) __attribute__ ((weak, alias("Default_Handler")));
void SVC_Handler 					(void) __attribute__ ((weak, alias("Default_Handler")));
void DebugMon_Handler 				(void) __attribute__ ((weak, alias("Default_Handler")));
void PendSV_Handler   				(void) __attribute__ ((weak, alias("Default_Handler")));
void SysTick_Handler  				(void) __attribute__ ((weak, alias("Default_Handler")));
void WWDG_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));
void PVD_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));             
void TAMP_STAMP_IRQHandler 			(void) __attribute__ ((weak, alias("Default_Handler")));      
void RTC_WKUP_IRQHandler 			(void) __attribute__ ((weak, alias("Default_Handler")));                               
void Flash_Handler 					(void) __attribute__ ((weak, alias("Default_Handler")));                               
void RCC_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));             
void EXTI0_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));           
void EXTI1_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));           
void EXTI2_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));           
void EXTI3_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));           
void EXTI4_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));           
void DMA1_Stream0_IRQHandler 		(void) __attribute__ ((weak, alias("Default_Handler")));    
void DMA1_Stream1_IRQHandler 		(void) __attribute__ ((weak, alias("Default_Handler")));    
void DMA1_Stream2_IRQHandler 		(void) __attribute__ ((weak, alias("Default_Handler")));    
void DMA1_Stream3_IRQHandler 		(void) __attribute__ ((weak, alias("Default_Handler")));    
void DMA1_Stream4_IRQHandler 		(void) __attribute__ ((weak, alias("Default_Handler")));    
void DMA1_Stream5_IRQHandler 		(void) __attribute__ ((weak, alias("Default_Handler")));    
void DMA1_Stream6_IRQHandler 		(void) __attribute__ ((weak, alias("Default_Handler")));    
void ADC_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));             
void CAN1_TX_IRQHandler 			(void) __attribute__ ((weak, alias("Default_Handler")));         
void CAN1_RX0_IRQHandler 			(void) __attribute__ ((weak, alias("Default_Handler")));        
void CAN1_RX1_IRQHandler 			(void) __attribute__ ((weak, alias("Default_Handler")));        
void CAN1_SCE_IRQHandler 			(void) __attribute__ ((weak, alias("Default_Handler")));        
void EXTI9_5_IRQHandler 			(void) __attribute__ ((weak, alias("Default_Handler")));         
void TIM1_BRK_TIM9_IRQHandler 		(void) __attribute__ ((weak, alias("Default_Handler")));   
void TIM1_UP_TIM10_IRQHandler 		(void) __attribute__ ((weak, alias("Default_Handler")));   
void TIM1_TRG_COM_TIM11_IRQHandler 	(void) __attribute__ ((weak, alias("Default_Handler")));
void TIM1_CC_IRQHandler 			(void) __attribute__ ((weak, alias("Default_Handler")));         
void TIM2_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));            
void TIM3_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));            
void TIM4_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));            
void I2C1_EV_IRQHandler 			(void) __attribute__ ((weak, alias("Default_Handler")));         
void I2C1_ER_IRQHandler 			(void) __attribute__ ((weak, alias("Default_Handler")));         
void I2C2_EV_IRQHandler 			(void) __attribute__ ((weak, alias("Default_Handler")));         
void I2C2_ER_IRQHandler 			(void) __attribute__ ((weak, alias("Default_Handler")));         
void SPI1_IRQHandler  				(void) __attribute__ ((weak, alias("Default_Handler")));           
void SPI2_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));            
void USART1_IRQHandler  			(void) __attribute__ ((weak, alias("Default_Handler")));         
void USART2_IRQHandler  			(void) __attribute__ ((weak, alias("Default_Handler")));        
void USART3_IRQHandler   			(void) __attribute__ ((weak, alias("Default_Handler")));        
void EXTI15_10_IRQHandler   		(void) __attribute__ ((weak, alias("Default_Handler")));     
void RTC_Alarm_IRQHandler    		(void) __attribute__ ((weak, alias("Default_Handler")));    
void OTG_FS_WKUP_IRQHandler     	(void) __attribute__ ((weak, alias("Default_Handler"))); 
void TIM8_BRK_TIM12_IRQHandler   	(void) __attribute__ ((weak, alias("Default_Handler")));
void TIM8_UP_TIM13_IRQHandler    	(void) __attribute__ ((weak, alias("Default_Handler")));
void TIM8_TRG_COM_TIM14_IRQHandler 	(void) __attribute__ ((weak, alias("Default_Handler")));
void TIM8_CC_IRQHandler          	(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA1_Stream7_IRQHandler     	(void) __attribute__ ((weak, alias("Default_Handler")));
void FSMC_IRQHandler             	(void) __attribute__ ((weak, alias("Default_Handler")));
void SDIO_IRQHandler             	(void) __attribute__ ((weak, alias("Default_Handler")));
void TIM5_IRQHandler             	(void) __attribute__ ((weak, alias("Default_Handler")));
void SPI3_IRQHandler             	(void) __attribute__ ((weak, alias("Default_Handler")));
void UART4_IRQHandler            	(void) __attribute__ ((weak, alias("Default_Handler")));
void UART5_IRQHandler            	(void) __attribute__ ((weak, alias("Default_Handler")));
void TIM6_DAC_IRQHandler         	(void) __attribute__ ((weak, alias("Default_Handler")));
void TIM7_IRQHandler             	(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream0_IRQHandler     	(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream1_IRQHandler     	(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream2_IRQHandler     	(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream3_IRQHandler     	(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream4_IRQHandler     	(void) __attribute__ ((weak, alias("Default_Handler")));
void ETH_IRQHandler              	(void) __attribute__ ((weak, alias("Default_Handler")));
void ETH_WKUP_IRQHandler         	(void) __attribute__ ((weak, alias("Default_Handler")));
void CAN2_TX_IRQHandler          	(void) __attribute__ ((weak, alias("Default_Handler")));
void CAN2_RX0_IRQHandler         	(void) __attribute__ ((weak, alias("Default_Handler")));
void CAN2_RX1_IRQHandler         	(void) __attribute__ ((weak, alias("Default_Handler")));
void CAN2_SCE_IRQHandler         	(void) __attribute__ ((weak, alias("Default_Handler")));
void OTG_FS_IRQHandler           	(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream5_IRQHandler     	(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream6_IRQHandler     	(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream7_IRQHandler     	(void) __attribute__ ((weak, alias("Default_Handler")));
void USART6_IRQHandler           	(void) __attribute__ ((weak, alias("Default_Handler")));
void I2C3_EV_IRQHandler          	(void) __attribute__ ((weak, alias("Default_Handler")));
void I2C3_ER_IRQHandler          	(void) __attribute__ ((weak, alias("Default_Handler")));
void OTG_HS_EP1_OUT_IRQHandler   	(void) __attribute__ ((weak, alias("Default_Handler")));
void OTG_HS_EP1_IN_IRQHandler    	(void) __attribute__ ((weak, alias("Default_Handler")));
void OTG_HS_WKUP_IRQHandler      	(void) __attribute__ ((weak, alias("Default_Handler")));
void OTG_HS_IRQHandler           	(void) __attribute__ ((weak, alias("Default_Handler")));
void DCMI_IRQHandler             	(void) __attribute__ ((weak, alias("Default_Handler")));
void CRYP_IRQHandler             	(void) __attribute__ ((weak, alias("Default_Handler")));
void HASH_RNG_IRQHandler         	(void) __attribute__ ((weak, alias("Default_Handler")));
void FPU_IRQHandler              	(void) __attribute__ ((weak, alias("Default_Handler")));                          

__attribute__((section(".vect_table"))) uint32 INT_VECTOR[] = 
{
	(uint32)&_stack_ptr,//End of Stack space address
	(uint32)Reset_function,
	(uint32)NMI_Handler,
	(uint32)HardFault_Handler,
	(uint32)MemManage_Handler,
	(uint32)BusFault_Handler,
	(uint32)UsageFault_Handler,
	0,
	0,
	0,
	0,
	(uint32)SVC_Handler,
	(uint32)DebugMon_Handler,
	0,
	(uint32)PendSV_Handler,
	(uint32)SysTick_Handler,
	(uint32)WWDG_IRQHandler,
	(uint32)PVD_IRQHandler,         
	(uint32)TAMP_STAMP_IRQHandler,  
	(uint32)RTC_WKUP_IRQHandler,    
	(uint32)Flash_Handler,                      
	(uint32)RCC_IRQHandler,         
	(uint32)EXTI0_IRQHandler,       
	(uint32)EXTI1_IRQHandler,       
	(uint32)EXTI2_IRQHandler,       
	(uint32)EXTI3_IRQHandler,       
	(uint32)EXTI4_IRQHandler,       
	(uint32)DMA1_Stream0_IRQHandler,
	(uint32)DMA1_Stream1_IRQHandler,
	(uint32)DMA1_Stream2_IRQHandler,
	(uint32)DMA1_Stream3_IRQHandler,
	(uint32)DMA1_Stream4_IRQHandler,
	(uint32)DMA1_Stream5_IRQHandler,
	(uint32)DMA1_Stream6_IRQHandler,
	(uint32)ADC_IRQHandler,         
	(uint32)CAN1_TX_IRQHandler,     
	(uint32)CAN1_RX0_IRQHandler,    
	(uint32)CAN1_RX1_IRQHandler,    
	(uint32)CAN1_SCE_IRQHandler,    
	(uint32)EXTI9_5_IRQHandler,     
	(uint32)TIM1_BRK_TIM9_IRQHandler,
	(uint32)TIM1_UP_TIM10_IRQHandler,
	(uint32)TIM1_TRG_COM_TIM11_IRQHandler,
	(uint32)TIM1_CC_IRQHandler,     
	(uint32)TIM2_IRQHandler,        
	(uint32)TIM3_IRQHandler,        
	(uint32)TIM4_IRQHandler,        
	(uint32)I2C1_EV_IRQHandler,     
	(uint32)I2C1_ER_IRQHandler,     
	(uint32)I2C2_EV_IRQHandler,     
	(uint32)I2C2_ER_IRQHandler,     
	(uint32)SPI1_IRQHandler,        
	(uint32)SPI2_IRQHandler,        
	(uint32)USART1_IRQHandler,      
	(uint32)USART2_IRQHandler,      
	(uint32)USART3_IRQHandler,      
	(uint32)EXTI15_10_IRQHandler,   
	(uint32)RTC_Alarm_IRQHandler,   
	(uint32)OTG_FS_WKUP_IRQHandler, 
	(uint32)TIM8_BRK_TIM12_IRQHandler,
	(uint32)TIM8_UP_TIM13_IRQHandler,
	(uint32)TIM8_TRG_COM_TIM14_IRQHandler,
	(uint32)TIM8_CC_IRQHandler,     
	(uint32)DMA1_Stream7_IRQHandler,
	(uint32)FSMC_IRQHandler,        
	(uint32)SDIO_IRQHandler,        
	(uint32)TIM5_IRQHandler,        
	(uint32)SPI3_IRQHandler,        
	(uint32)UART4_IRQHandler,       
	(uint32)UART5_IRQHandler,       
	(uint32)TIM6_DAC_IRQHandler,    
	(uint32)TIM7_IRQHandler,        
	(uint32)DMA2_Stream0_IRQHandler,
	(uint32)DMA2_Stream1_IRQHandler,
	(uint32)DMA2_Stream2_IRQHandler,
	(uint32)DMA2_Stream3_IRQHandler,
	(uint32)DMA2_Stream4_IRQHandler,
	(uint32)ETH_IRQHandler,         
	(uint32)ETH_WKUP_IRQHandler,    
	(uint32)CAN2_TX_IRQHandler,     
	(uint32)CAN2_RX0_IRQHandler,    
	(uint32)CAN2_RX1_IRQHandler,    
	(uint32)CAN2_SCE_IRQHandler,    
	(uint32)OTG_FS_IRQHandler,      
	(uint32)DMA2_Stream5_IRQHandler,
	(uint32)DMA2_Stream6_IRQHandler,
	(uint32)DMA2_Stream7_IRQHandler,
	(uint32)USART6_IRQHandler,      
	(uint32)I2C3_EV_IRQHandler,     
	(uint32)I2C3_ER_IRQHandler,     
	(uint32)OTG_HS_EP1_OUT_IRQHandler,
	(uint32)OTG_HS_EP1_IN_IRQHandler,
	(uint32)OTG_HS_WKUP_IRQHandler, 
	(uint32)OTG_HS_IRQHandler,      
	(uint32)DCMI_IRQHandler,        
	(uint32)CRYP_IRQHandler,        
	(uint32)HASH_RNG_IRQHandler,    
	(uint32)FPU_IRQHandler,         
};

void Default_Handler(void)
{
	while(1); //do nothing stay here!!!
}

void Reset_function(void)
{
	uint32 sram_copy_size;
	uint32 bss_size;
	uint8 *dst_sram_ptr;
	uint8 *src_ptr;
	//uint8 *src_bss_ptr;
	uint32 i;
	
	//Initialize SRAM data
	dst_sram_ptr = (uint8 *)&_str_sram;
	src_ptr = (uint8 *)&_start_data_addr;
	sram_copy_size = (uint32)&_end_sram - (uint32)&_str_sram; 
	for(i=0;i<sram_copy_size-1;i++)
	{
		*dst_sram_ptr++ = *src_ptr++;
	}
	//Initialize .bss
	bss_size = (uint32)_end_bss - (uint32)_str_bss;
	for(i=0;i<bss_size-1;i++)
	{
		*dst_sram_ptr++ = 0;
	}
	//Read reset source
	//RCC clock control & status register (RCC_CSR)
	//RMVF: Remove reset flag, Clears the reset flag there by the reset source info
	*RCC_CSR |= (uint32)(0x01000000);
	// Start application code
	main();
}