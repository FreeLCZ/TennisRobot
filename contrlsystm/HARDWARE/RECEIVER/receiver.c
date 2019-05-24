#include "main.h"


u8 TIM8CH3_CAPTURE_STA = 0;	//ͨ��1���벶���־������λ�������־����6λ�������־		
u16 TIM8CH3_CAPTURE_UPVAL;
u16 TIM8CH3_CAPTURE_DOWNVAL;

u8 TIM8CH4_CAPTURE_STA = 0;	//ͨ��4���벶���־������λ�������־����6λ�������־		
u16 TIM8CH4_CAPTURE_UPVAL;
u16 TIM8CH4_CAPTURE_DOWNVAL;

u32 TIM8Channel_3 = 0;	//�����ܸߵ�ƽ��ʱ��
u32 TIM8Channel_4 = 0;	//�����ܸߵ�ƽ��ʱ��

u32 TIM8_T3;
u32 TIM8_T4;


void TIM8_Cap_Init(u32 arr, u32 psc)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_ICInitTypeDef TIM8_ICInitStructure;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM8, ENABLE);	//ʹ��TIM8ʱ��
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);  //ʹ��GPIOCʱ��
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8; //GPIOC8
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;//���ù���
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//�ٶ�100MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; //���츴�����
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN; //����
	GPIO_Init(GPIOC,&GPIO_InitStructure); //��ʼ��PA2
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9; //GPIOC9
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;//���ù���
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//�ٶ�100MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; //���츴�����
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN; //����
	GPIO_Init(GPIOC,&GPIO_InitStructure); 
	
	GPIO_PinAFConfig(GPIOC,GPIO_PinSource8,GPIO_AF_TIM8); 
  GPIO_PinAFConfig(GPIOC,GPIO_PinSource9,GPIO_AF_TIM8); 
	
	
	//��ʼ��TIM8	 
	TIM_TimeBaseStructure.TIM_Period = arr; //�趨�������Զ���װֵ 
	TIM_TimeBaseStructure.TIM_Prescaler = psc; 	//Ԥ��Ƶ�� 
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
	TIM_TimeBaseInit(TIM8, &TIM_TimeBaseStructure); //����TIM_TimeBaseInitStruct��ָ���Ĳ�����ʼ��TIMx��ʱ�������λ


	//��ʼ��TIM8���벶����� ͨ��3
	TIM8_ICInitStructure.TIM_Channel = TIM_Channel_3; //CC1S=01 	ѡ������� IC1ӳ�䵽TI1��
	TIM8_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;	//�����ز���
	TIM8_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI; //ӳ�䵽TI1��
	TIM8_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;	  //���������Ƶ,����Ƶ 
	TIM8_ICInitStructure.TIM_ICFilter = 0x00;	  //IC1F=0000 ���������˲��� ���˲�
	TIM_ICInit(TIM8, &TIM8_ICInitStructure);

	//��ʼ��TIM8���벶����� ͨ��4
	TIM8_ICInitStructure.TIM_Channel = TIM_Channel_4; //CC1S=01 	ѡ������� IC1ӳ�䵽TI1��
	TIM8_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;	//�����ز���
	TIM8_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI; //ӳ�䵽TI1��
	TIM8_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;	  //���������Ƶ,����Ƶ 
	TIM8_ICInitStructure.TIM_ICFilter = 0x00;	  //IC1F=0000 ���������˲��� ���˲�
	TIM_ICInit(TIM8, &TIM8_ICInitStructure);

	//�жϷ����ʼ��
	NVIC_InitStructure.NVIC_IRQChannel = TIM8_CC_IRQn;  //TIM8�ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=2;//��ռ���ȼ�
	NVIC_InitStructure.NVIC_IRQChannelSubPriority =0;		//�����ȼ�
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQͨ����ʹ��
	NVIC_Init(&NVIC_InitStructure);   //����NVIC_InitStruct��ָ���Ĳ�����ʼ������NVIC�Ĵ��� 

	TIM_ITConfig(TIM8, TIM_IT_CC3 | TIM_IT_CC4,ENABLE);   //����������жϣ�����CC1IE,CC2IE,CC3IE,CC4IE�����ж�	

	TIM_Cmd(TIM8, ENABLE); 		//ʹ�ܶ�ʱ��5
}


void TIM8_CC_IRQHandler(void)
{
	if ((TIM8CH3_CAPTURE_STA & 0X80) == 0)		//��δ�ɹ�����	
	{
		if (TIM_GetITStatus(TIM8, TIM_IT_CC3) != RESET)		//����3���������¼�
		{
			TIM_ClearITPendingBit(TIM8, TIM_IT_CC3);		//����жϱ�־λ
			if (TIM8CH3_CAPTURE_STA & 0X40)		//����һ���½���
			{
				TIM8CH3_CAPTURE_DOWNVAL = TIM_GetCapture3(TIM8);//��¼�´�ʱ�Ķ�ʱ������ֵ
				if (TIM8CH3_CAPTURE_DOWNVAL < TIM8CH3_CAPTURE_UPVAL)
				{
					TIM8_T3 = 65535;
				}
				else
					TIM8_T3 = 0;
				TIM8Channel_3 = TIM8CH3_CAPTURE_DOWNVAL - TIM8CH3_CAPTURE_UPVAL
						+ TIM8_T3;		//�õ��ܵĸߵ�ƽ��ʱ��
				TIM8CH3_CAPTURE_STA = 0;		//�����־λ����
				TIM_OC3PolarityConfig(TIM8, TIM_ICPolarity_Rising); //����Ϊ�����ز���		  
			}
			else //��������ʱ�䵫�����½��أ���һ�β��������أ���¼��ʱ�Ķ�ʱ������ֵ
			{
				TIM8CH3_CAPTURE_UPVAL = TIM_GetCapture3(TIM8);		//��ȡ����������
				TIM8CH3_CAPTURE_STA |= 0X40;		//����Ѳ���������
				TIM_OC3PolarityConfig(TIM8, TIM_ICPolarity_Falling);//����Ϊ�½��ز���
			}
		}
	}

	if ((TIM8CH4_CAPTURE_STA & 0X80) == 0)		//��δ�ɹ�����	
	{
		if (TIM_GetITStatus(TIM8, TIM_IT_CC4) != RESET)		//����4���������¼�
		{
			TIM_ClearITPendingBit(TIM8, TIM_IT_CC4);		//����жϱ�־λ
			if (TIM8CH4_CAPTURE_STA & 0X40)		//����һ���½���
			{
				TIM8CH4_CAPTURE_DOWNVAL = TIM_GetCapture4(TIM8);//��¼�´�ʱ�Ķ�ʱ������ֵ
				if (TIM8CH4_CAPTURE_DOWNVAL < TIM8CH4_CAPTURE_UPVAL)
				{
					TIM8_T4 = 65535;
				}
				else
					TIM8_T4 = 0;
				TIM8Channel_4 = TIM8CH4_CAPTURE_DOWNVAL - TIM8CH4_CAPTURE_UPVAL
						+ TIM8_T4;		//�õ��ܵĸߵ�ƽ��ʱ��
				TIM8CH4_CAPTURE_STA = 0;		//�����־λ����
				TIM_OC4PolarityConfig(TIM8, TIM_ICPolarity_Rising); //����Ϊ�����ز���		  
			}
			else //��������ʱ�䵫�����½��أ���һ�β��������أ���¼��ʱ�Ķ�ʱ������ֵ
			{
				TIM8CH4_CAPTURE_UPVAL = TIM_GetCapture4(TIM8);		//��ȡ����������
				TIM8CH4_CAPTURE_STA |= 0X40;		//����Ѳ���������
				TIM_OC4PolarityConfig(TIM8, TIM_ICPolarity_Falling);//����Ϊ�½��ز���
			}
		}
	}
}

