#ifndef _MAIN_H_
#define _MAIN_H_
#include "typedef.h"

#define __enable_interrupt__ Interrupt_Disable_All()
#define __disable_interrupt__ Interrupt_Disable_All()

extern int main(void);
extern void Schedular(void);

#endif