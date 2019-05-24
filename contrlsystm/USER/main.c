#include "main.h"



//四路pwm占空比
u32 pwmLeftFrontMotor1;
u32 pwmLeftFrontMotor2;
u32 pwmLeftBackMotor1;
u32 pwmLeftBackMotor2;
u32 pwmRightFrontMotor1;
u32 pwmRightFrontMotor2;
u32 pwmRightBackMotor1;
u32 pwmRightBackMotor2;
//四路电机PID结构体
//PID_Ctrl pidLeftFront;
//PID_Ctrl pidLeftBack;
//PID_Ctrl pidRightFront;
//PID_Ctrl pidRightBack;
//四路电机实际速度
short speedLeftFront;
short speedLeftBack;
short speedRightFront;
short speedRightBack;
//四路电机目标速度
short speedTargetLeftFront;
short speedTargetLeftBack;
short speedTargetRightFront;
short speedTargetRightBack;


int main(void)
{
//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);    //设置系统中断优先级分组2
	delay_init(168);  
//	uart_init(9600);
	usart2_init(9600);
	TIM1_PWM_Init(1000-1,8-1);//168M/8=21Mhz的计数频率,重装载值1000,所以PWM频率为 21M/1000=21Khz.
	TIM9_PWM_Init(1000-1,8-1);//168M/8=21Mhz的计数频率,重装载值1000,所以PWM频率为 21M/1000=21Khz.
	TIM12_PWM_Init(1000-1,4-1);//84M/4=21Mhz的计数频率,重装载值1000,所以PWM频率为 21M/1000=21Khz.
//  TIM2_Encoder_Config();	
//	TIM3_Encoder_Config();	
//	TIM4_Encoder_Config();	
//	TIM5_Encoder_Config();	
//	Encoder_Start();
//	TIM8_Cap_Init(0xffff,168-1); 
//	
	
	pwmLeftFrontMotor1=200;
	pwmLeftFrontMotor2=200;
  pwmLeftBackMotor1=400;
	pwmLeftBackMotor2=400;
  pwmRightFrontMotor1=600;
	pwmRightFrontMotor2=600;
  pwmRightBackMotor1=800;
	pwmRightBackMotor2=800;
	
	while(1)
	{
//		UpdatePwm();
		Bluetooth_prirntf(" %s\r\n","蓝牙已正常！！！");
		delay_ms(500);
	}
}












