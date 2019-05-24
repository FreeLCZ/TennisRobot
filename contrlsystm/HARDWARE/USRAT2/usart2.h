#ifndef __USART2_H
#define __USART2_H 
#include "stdio.h"	
#include "stm32f4xx_conf.h"

#define USART2_MAX_RECV_LEN 20  //最大接收缓存字节数，
#define USART2_MAX_SEND_LEN 100  //最大发送缓存字节数
#define USART2_RX_EN 1  ////使能（1）/禁止（0）串口2接收

extern u8  USART2_RX_BUF[USART2_MAX_RECV_LEN]; //接收缓冲,最大USART2_MAX_RECV_LEN字节
extern u8  USART2_TX_BUF[USART2_MAX_SEND_LEN]; //发送缓冲,最大USART2_MAX_SEND_LEN字节
extern u16 USART2_RX_STA;   //接收数据状态

#define     Bluetooth_prirntf( fmt, ... )           USART2_printf ( USART2, fmt, ##__VA_ARGS__ ) 

void usart2_init(u32 bound);
extern void USART2_printf( USART_TypeDef* USARTx, char *Data, ... );


#endif
