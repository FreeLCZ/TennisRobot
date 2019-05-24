#include "main.h"


//arr���Զ���װֵ
//psc��ʱ��Ԥ��Ƶ��
void TIM1_PWM_Init(u32 arr,u32 psc)
{		 					 
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	
	//������ʱ��ʱ�Ӻ�GPIOʱ��
	/***************************************************************/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1,ENABLE);  	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE); 
	/***************************************************************/
	
	//GPIO���õ���ʱ��
	/***************************************************************/
	GPIO_PinAFConfig(GPIOE,GPIO_PinSource9,GPIO_AF_TIM1); 
	GPIO_PinAFConfig(GPIOE,GPIO_PinSource11,GPIO_AF_TIM1); 
	GPIO_PinAFConfig(GPIOE,GPIO_PinSource13,GPIO_AF_TIM1); 
	GPIO_PinAFConfig(GPIOE,GPIO_PinSource14,GPIO_AF_TIM1);
	/****************************************************************/
	
	//����GPIO
	/****************************************************************/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;          
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;    //����ģʽ   
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	  //�ٶ�Ϊ100HZ
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //����ģʽ
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;        //�������
	GPIO_Init(GPIOE,&GPIO_InitStructure);           //��ʼ���ṹ��
	  
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;     	
	GPIO_Init(GPIOE,&GPIO_InitStructure);    

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;   	
	GPIO_Init(GPIOE,&GPIO_InitStructure);    
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;  	
	GPIO_Init(GPIOE,&GPIO_InitStructure);    
	/*************************************************************************/
	
	//���ö�ʱ��
	/*************************************************************************/
	TIM_TimeBaseStructure.TIM_Prescaler=psc;    //��ʱ����Ƶ
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;   //���ϼ���ģ��
	TIM_TimeBaseStructure.TIM_Period=arr;    //�Զ���װ��ֵ
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;   //����Ƶ
	TIM_TimeBaseInit(TIM1,&TIM_TimeBaseStructure);
	/**************************************************************************/

  //���ö�ʱ��ͨ��
	//TIM1
	/**************************************************************************/
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;       //PWM1ģʽ
 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;   //����OC�������Ӧ����
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;       //������Ըߵ�
	TIM_OC1Init(TIM1, &TIM_OCInitStructure);                      //����Ƚϳ�ʼ��
	TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable);            //ʹ��TIM3��CCR1�ϵ�Ԥװ�ؼĴ���
	
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
	
  TIM_ARRPreloadConfig(TIM1,ENABLE);            //�����ڶ�ʱ��1����ʱ��ARR�Ļ�������д����ֵ
	
	TIM_Cmd(TIM1, ENABLE);  
	
	TIM_CtrlPWMOutputs(TIM1, ENABLE);//ʹ��TIM1��PWM�����TIM1��TIM8���߼���ʱ������Ч,���û�����л��������
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
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;    //����ģʽ   
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	  //�ٶ�Ϊ100HZ
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //����ģʽ
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;        //�������
	GPIO_Init(GPIOE,&GPIO_InitStructure);           //��ʼ���ṹ��
	  
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;     	
	GPIO_Init(GPIOE,&GPIO_InitStructure);    
	
	TIM_TimeBaseStructure.TIM_Prescaler=psc;    //��ʱ����Ƶ
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;   //���ϼ���ģ��
	TIM_TimeBaseStructure.TIM_Period=arr;    //�Զ���װ��ֵ
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;   //����Ƶ
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
	
	TIM_ARRPreloadConfig(TIM9,ENABLE);            //�����ڶ�ʱ��9����ʱ��ARR�Ļ�������д����ֵ
	
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
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;    //����ģʽ   
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	  //�ٶ�Ϊ100HZ
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //����ģʽ
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;        //�������
	GPIO_Init(GPIOB,&GPIO_InitStructure);           //��ʼ���ṹ��
	  
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;     	
	GPIO_Init(GPIOB,&GPIO_InitStructure);    
	
	TIM_TimeBaseStructure.TIM_Prescaler=psc;    //��ʱ����Ƶ
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;   //���ϼ���ģ��
	TIM_TimeBaseStructure.TIM_Period=arr;    //�Զ���װ��ֵ
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;   //����Ƶ
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
	
	TIM_ARRPreloadConfig(TIM12,ENABLE);            //�����ڶ�ʱ��12����ʱ��ARR�Ļ�������д����ֵ

  TIM_Cmd(TIM12, ENABLE); 
}

void UpdatePwm(void)
{ 
	TIM_SetCompare1(TIM1,pwmLeftFrontMotor1);           //����ռ�ձȣ�0~1000��
	TIM_SetCompare2(TIM1,pwmLeftFrontMotor2);
	
	TIM_SetCompare3(TIM1,pwmLeftBackMotor1);            //����ռ�ձȣ�0~1000��
	TIM_SetCompare4(TIM1,pwmLeftBackMotor2);
	
	TIM_SetCompare1(TIM9,pwmRightFrontMotor1);          //����ռ�ձȣ�0~1000��
	TIM_SetCompare2(TIM9,pwmRightFrontMotor2);
	
	TIM_SetCompare1(TIM12,pwmRightBackMotor1);          //����ռ�ձȣ�0~1000��
	TIM_SetCompare2(TIM12,pwmRightBackMotor2);
}

