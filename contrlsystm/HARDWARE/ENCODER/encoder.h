#ifndef __ENCODER_H
#define __ENCODER_H

#include "sys.h"
//#include "pid.h"
#include "stm32f4xx.h"


void TIM2_Encoder_Config(void);
void TIM3_Encoder_Config(void);
void TIM4_Encoder_Config(void);
void TIM5_Encoder_Config(void);

void Encoder_Start(void);
void Encoder_Stop(void);

short Encoder_GetSpeedLeftFront(void);
short Encoder_GetSpeedRightFront(void);
short Encoder_GetSpeedLeftBack(void);
short Encoder_GetSpeedRightBack(void);	

#endif
