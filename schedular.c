#include "schedular.h"

extern volatile uint32 timer_tim2_cnt_1ms;

void Schedular(void)
{
	while(1)
	{
		if(timer_tim2_cnt_1ms == 10)
		{
			task();
		}
		else
		{/*do nothing*/}
	}
}

