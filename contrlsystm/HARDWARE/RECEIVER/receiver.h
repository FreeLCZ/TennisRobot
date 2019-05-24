#ifndef __RECEIVER_H
#define __RECEIVER_H

#include "sys.h"
#include "stm32f4xx.h"

extern u32 TIM8Channel_3;	//捕获总高电平的时间
extern u32 TIM8Channel_4;	//捕获总高电平的时间

void TIM8_Cap_Init(u32 arr, u32 psc);




#endif


