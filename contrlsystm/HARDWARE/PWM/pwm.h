#ifndef __PWM_H
#define __PWM_H

#include "sys.h"
//#include "pid.h"

void TIM1_PWM_Init(u32 arr,u32 psc);
void TIM9_PWM_Init(u32 arr,u32 psc);
void TIM12_PWM_Init(u32 arr,u32 psc);

void UpdatePwm(void);

#endif


