#include "task.h"

extern volatile uint32 timer_tim2_cnt_1ms;
void toggle_LED(void);
void Dio_write(uint8 in);

void task(void)
{
	toggle_LED();
}

void toggle_LED(void)
{
	uint8 LED_in;
	LED_in = 0;
	
	if(timer_tim2_cnt_1ms == 1000)
	{
		LED_in++;
		Dio_write(LED_in);
	}	
}
void Dio_write(uint8 in)
{
	//Toggle the LED pin of the development board
}

