/*
 * uart.c
 *
 *  Created on: 2022年3月26日
 *      Author: Administrator
 */

#include "Lpuart_Uart_Ip.h"
#include "Lpuart_Uart_Ip_Irq.h"

#include"uart.h"
#include "sys.h"

#include <stdio.h>
#include <string.h>
#include "stdarg.h"
#include <stdint.h>
#include <stdbool.h>
char USART_TX_BUF[100];

/* Define channel */



   void LPUART_printf(char* fmt,...)
   {
	   //uint32_t bytesRemaining;
	   //volatile Lpuart_Uart_Ip_StatusType lpuartStatus = LPUART_UART_IP_STATUS_ERROR;

   	va_list ap;
   	va_start(ap,fmt);
   	vsprintf((char*)USART_TX_BUF,fmt,ap);
   	va_end(ap);
//   	LPUART_DRV_SendData(INST_LPUART1, (uint8_t *)USART1_TX_BUF, strlen(USART1_TX_BUF)); //发送
//    while (LPUART_DRV_GetTransmitStatus(INST_LPUART1, &bytesRemaining)
//               != STATUS_SUCCESS)  {}

	Lpuart_Uart_Ip_SyncSend(LPUART6_INSTANCE, (uint8_t *)USART_TX_BUF, strlen(USART_TX_BUF),0xffff);



   }

