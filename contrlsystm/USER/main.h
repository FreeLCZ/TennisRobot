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


//��·pwmռ�ձ�
extern u32 pwmLeftFrontMotor1;
extern u32 pwmLeftFrontMotor2;
extern u32 pwmLeftBackMotor1;
extern u32 pwmLeftBackMotor2;
extern u32 pwmRightFrontMotor1;
extern u32 pwmRightFrontMotor2;
extern u32 pwmRightBackMotor1;
extern u32 pwmRightBackMotor2;
//��·���PID�ṹ��
//extern PID_Ctrl pidLeftFront;
//extern PID_Ctrl pidLeftBack;
//extern PID_Ctrl pidRightFront;
//extern PID_Ctrl pidRightBack;
//��·���ʵ���ٶ�
extern short speedLeftFront;
extern short speedLeftBack;
extern short speedRightFront;
extern short speedRightBack;
//��·���Ŀ���ٶ�
extern short speedTargetLeftFront;
extern short speedTargetLeftBack;
extern short speedTargetRightFront;
extern short speedTargetRightBack;

#endif


