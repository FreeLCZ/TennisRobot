#ifndef __MAIN_H
#define __MAIN_H

#include "stm32f4xx.h"
#include "pwm.h"
#include "encoder.h"
#include "receiver.h"
#include "sys.h"
#include "delay.h"
#include "usart.h"

#include "usart2.h"   //2019.5.23
#include "tim7.h"     //2019.5.29
#include "maths.h"    //2019.5.29


//四路pwm占空比
extern u32 pwmLeftFrontMotor1;
extern u32 pwmLeftFrontMotor2;
extern u32 pwmLeftBackMotor1;
extern u32 pwmLeftBackMotor2;
extern u32 pwmRightFrontMotor1;
extern u32 pwmRightFrontMotor2;
extern u32 pwmRightBackMotor1;
extern u32 pwmRightBackMotor2;
//四路电机PID结构体
//extern PID_Ctrl pidLeftFront;
//extern PID_Ctrl pidLeftBack;
//extern PID_Ctrl pidRightFront;
//extern PID_Ctrl pidRightBack;
//四路电机实际速度
extern short speedLeftFront;
extern short speedLeftBack;
extern short speedRightFront;
extern short speedRightBack;
//四路电机目标速度
extern short speedTargetLeftFront;
extern short speedTargetLeftBack;
extern short speedTargetRightFront;
extern short speedTargetRightBack;

#endif


