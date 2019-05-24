#include "main.h"


//arr：自动重装值
//psc：时钟预分频数
void TIM1_PWM_Init(u32 arr,u32 psc)
{		 					 
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	
	//开启定时器时钟和GPIO时钟
	/***************************************************************/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1,ENABLE);  	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE); 
	/***************************************************************/
	
	//GPIO复用到定时器
	/***************************************************************/
	GPIO_PinAFConfig(GPIOE,GPIO_PinSource9,GPIO_AF_TIM1); 
	GPIO_PinAFConfig(GPIOE,GPIO_PinSource11,GPIO_AF_TIM1); 
	GPIO_PinAFConfig(GPIOE,GPIO_PinSource13,GPIO_AF_TIM1); 
	GPIO_PinAFConfig(GPIOE,GPIO_PinSource14,GPIO_AF_TIM1);
	/****************************************************************/
	
	//配置GPIO
	/****************************************************************/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;          
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;    //复用模式   
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	  //速度为100HZ
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //推挽模式
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;        //推挽输出
	GPIO_Init(GPIOE,&GPIO_InitStructure);           //初始化结构体
	  
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;     	
	GPIO_Init(GPIOE,&GPIO_InitStructure);    

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;   	
	GPIO_Init(GPIOE,&GPIO_InitStructure);    
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;  	
	GPIO_Init(GPIOE,&GPIO_InitStructure);    
	/*************************************************************************/
	
	//配置定时器
	/*************************************************************************/
	TIM_TimeBaseStructure.TIM_Prescaler=psc;    //定时器分频
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;   //向上计数模数
	TIM_TimeBaseStructure.TIM_Period=arr;    //自动重装载值
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;   //不分频
	TIM_TimeBaseInit(TIM1,&TIM_TimeBaseStructure);
	/**************************************************************************/

  //配置定时器通道
	//TIM1
	/**************************************************************************/
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;       //PWM1模式
 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;   //开启OC输出到对应引脚
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;       //输出极性高低
	TIM_OC1Init(TIM1, &TIM_OCInitStructure);                      //输出比较初始化
	TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable);            //使能TIM3在CCR1上的预装载寄存器
	
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; 
 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; 
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; 
	TIM_OC2Init(TIM1, &TIM_OCInitStructure); 
	TIM_OC2PreloadConfig(TIM1, TIM_OCPreload_Enable);  
	
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; 
 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; 
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; 
	TIM_OC3Init(TIM1, &TIM_OCInitStructure); 
	TIM_OC3PreloadConfig(TIM1, TIM_OCPreload_Enable); 
	
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; 
 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; 
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; 
	TIM_OC4Init(TIM1, &TIM_OCInitStructure); 
	TIM_OC4PreloadConfig(TIM1, TIM_OCPreload_Enable); 
	/*************************************************************************/
	
  TIM_ARRPreloadConfig(TIM1,ENABLE);            //允许在定时器1工作时向ARR的缓冲器中写入新值
	
	TIM_Cmd(TIM1, ENABLE);  
	
	TIM_CtrlPWMOutputs(TIM1, ENABLE);//使能TIM1的PWM输出，TIM1与TIM8（高级定时器）有效,如果没有这行会出现问题
}





void TIM9_PWM_Init(u32 arr,u32 psc)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM9,ENABLE); 
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE); 
	
	GPIO_PinAFConfig(GPIOE,GPIO_PinSource5,GPIO_AF_TIM9); 
	GPIO_PinAFConfig(GPIOE,GPIO_PinSource6,GPIO_AF_TIM9); 
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;          
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;    //复用模式   
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	  //速度为100HZ
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //推挽模式
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;        //推挽输出
	GPIO_Init(GPIOE,&GPIO_InitStructure);           //初始化结构体
	  
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;     	
	GPIO_Init(GPIOE,&GPIO_InitStructure);    
	
	TIM_TimeBaseStructure.TIM_Prescaler=psc;    //定时器分频
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;   //向上计数模数
	TIM_TimeBaseStructure.TIM_Period=arr;    //自动重装载值
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;   //不分频
	TIM_TimeBaseInit(TIM9,&TIM_TimeBaseStructure);
	
	//TIM9
	/*************************************************************************/
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; 
 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; 
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; 
	TIM_OC1Init(TIM9, &TIM_OCInitStructure); 
	TIM_OC1PreloadConfig(TIM9, TIM_OCPreload_Enable); 
	
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; 
 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; 
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; 
	TIM_OC2Init(TIM9, &TIM_OCInitStructure); 
	TIM_OC2PreloadConfig(TIM9, TIM_OCPreload_Enable); 
	/*************************************************************************/
	
	TIM_ARRPreloadConfig(TIM9,ENABLE);            //允许在定时器9工作时向ARR的缓冲器中写入新值
	
	TIM_Cmd(TIM9, ENABLE); 
}



void TIM12_PWM_Init(u32 arr,u32 psc)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM12,ENABLE); 
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE); 
	
	GPIO_PinAFConfig(GPIOB,GPIO_PinSource14,GPIO_AF_TIM12); 
	GPIO_PinAFConfig(GPIOB,GPIO_PinSource15,GPIO_AF_TIM12);	
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;          
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;    //复用模式   
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	  //速度为100HZ
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //推挽模式
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;        //推挽输出
	GPIO_Init(GPIOB,&GPIO_InitStructure);           //初始化结构体
	  
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;     	
	GPIO_Init(GPIOB,&GPIO_InitStructure);    
	
	TIM_TimeBaseStructure.TIM_Prescaler=psc;    //定时器分频
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;   //向上计数模数
	TIM_TimeBaseStructure.TIM_Period=arr;    //自动重装载值
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;   //不分频
	TIM_TimeBaseInit(TIM12,&TIM_TimeBaseStructure);
	
	//TIM12
	/*************************************************************************/
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; 
 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; 
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; 
	TIM_OC1Init(TIM12, &TIM_OCInitStructure); 
	TIM_OC1PreloadConfig(TIM12, TIM_OCPreload_Enable); 
	
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; 
 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; 
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; 
	TIM_OC2Init(TIM12, &TIM_OCInitStructure); 
	TIM_OC2PreloadConfig(TIM12, TIM_OCPreload_Enable); 
	/****************************************************************************/
	
	TIM_ARRPreloadConfig(TIM12,ENABLE);            //允许在定时器12工作时向ARR的缓冲器中写入新值

  TIM_Cmd(TIM12, ENABLE); 
}

void UpdatePwm(void)
{ 
	TIM_SetCompare1(TIM1,pwmLeftFrontMotor1);           //设置占空比（0~1000）
	TIM_SetCompare2(TIM1,pwmLeftFrontMotor2);
	
	TIM_SetCompare3(TIM1,pwmLeftBackMotor1);            //设置占空比（0~1000）
	TIM_SetCompare4(TIM1,pwmLeftBackMotor2);
	
	TIM_SetCompare1(TIM9,pwmRightFrontMotor1);          //设置占空比（0~1000）
	TIM_SetCompare2(TIM9,pwmRightFrontMotor2);
	
	TIM_SetCompare1(TIM12,pwmRightBackMotor1);          //设置占空比（0~1000）
	TIM_SetCompare2(TIM12,pwmRightBackMotor2);
}

