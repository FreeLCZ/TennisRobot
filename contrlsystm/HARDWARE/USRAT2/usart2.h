#ifndef __USART2_H
#define __USART2_H 
#include "stdio.h"	
#include "stm32f4xx_conf.h"

#define USART2_MAX_RECV_LEN 20  //�����ջ����ֽ�����
#define USART2_MAX_SEND_LEN 100  //����ͻ����ֽ���
#define USART2_RX_EN 1  ////ʹ�ܣ�1��/��ֹ��0������2����

extern u8  USART2_RX_BUF[USART2_MAX_RECV_LEN]; //���ջ���,���USART2_MAX_RECV_LEN�ֽ�
extern u8  USART2_TX_BUF[USART2_MAX_SEND_LEN]; //���ͻ���,���USART2_MAX_SEND_LEN�ֽ�
extern u16 USART2_RX_STA;   //��������״̬

#define     Bluetooth_prirntf( fmt, ... )           USART2_printf ( USART2, fmt, ##__VA_ARGS__ ) 

void usart2_init(u32 bound);
extern void USART2_printf( USART_TypeDef* USARTx, char *Data, ... );


#endif
