#ifndef __UART_H
#define __UART_H

#include "../RTD/include/Lpuart_Uart_Ip.h"

void InitSerialCommunications(void (*bytesReceivedHandler)(char *bytes, int size));

void LPUART_printf(char *fmt, ...);

#endif	/*	#ifndef __UART_H	*/
