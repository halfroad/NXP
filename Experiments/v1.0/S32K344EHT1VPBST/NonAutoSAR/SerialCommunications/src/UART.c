#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#include "../RTD/include/IntCtrl_Ip.h"

#include "../include/UART.h"

#define MAXIMUM_TRANSMIT_BUFFER_LENGTH			100
#define MAXIMUM_RECEIVE_BUFFER_LENGTH			0xFF
#define TRANSMISSION_HEADER_SIZE				2

uint8_t USART_TRANSMIT_BUFFER[MAXIMUM_TRANSMIT_BUFFER_LENGTH];
uint8_t ReceiveBuffer[MAXIMUM_RECEIVE_BUFFER_LENGTH];

__IO uint16_t IncomingTransmissionBytesSize 	= 0;

void (*BytesReceived)(char *bytes, int size);

void InitSerialCommunications(void (*bytesReceivedHandler)(char *bytes, int size))
{
	/*	Initialize the Interrupt Controls.	*/
	IntCtrl_Ip_Init(&IntCtrlConfig_0);

	/*	Register interrupt LPUART6_IRQn.	*/
	IntCtrl_Ip_InstallHandler(LPUART6_IRQn, LPUART_UART_IP_6_IRQHandler,
	NULL_PTR);
	/*	Enable the interrupt LPUART6_IRQn.	*/
	IntCtrl_Ip_EnableIrq(LPUART6_IRQn);

	if (bytesReceivedHandler)
		BytesReceived = bytesReceivedHandler;

	/*	Initialize LPUART.
	 * https://community.nxp.com/t5/S32K/S32K3-HW-Fault-at-Uart-Init/m-p/1499077
	 * */
	Lpuart_Uart_Ip_Init(LPUART_UART_IP_INSTANCE_USING_6,
			&Lpuart_Uart_Ip_xHwConfigPB_6);
	/*	Asynchronously receive, the received 1 byte will be stored in the ReceiveBuffer.
	 Lpuart_Uart_Ip_AsyncReceive(LPUART_UART_IP_INSTANCE_USING_6, ReceiveBuffer, sizeof ReceiveBuffer);
	 */
	Lpuart_Uart_Ip_AsyncReceive(LPUART_UART_IP_INSTANCE_USING_6, ReceiveBuffer,
	TRANSMISSION_HEADER_SIZE);
}

void Lpuart_Uart6_Ip_BytesReceivedCallback(const uint8 HwInstance,
		const Lpuart_Uart_Ip_EventType Event, void *UserData)
{
	uint32_t BytesRemaining;

	(void) Event;
	(void) UserData;

	Lpuart_Uart_Ip_StatusType Uart_StatusType = Lpuart_Uart_Ip_GetReceiveStatus(
			HwInstance, &BytesRemaining);

	if (Uart_StatusType == LPUART_UART_IP_STATUS_SUCCESS)
	{
		/*
		 * https://community.nxp.com/t5/S32K/UART-Lpuart-Uart-Ip-AsyncReceive-loss-packet/m-p/1551180?profile.language=en
		 * */
		if (IncomingTransmissionBytesSize > 0)
		{
			if (BytesReceived)
			{
				char bytes[IncomingTransmissionBytesSize];

				memcpy(bytes, ReceiveBuffer, IncomingTransmissionBytesSize);
				memset(ReceiveBuffer, 0, IncomingTransmissionBytesSize);

				BytesReceived(bytes, IncomingTransmissionBytesSize);

				Lpuart_Uart_Ip_AsyncReceive(HwInstance, ReceiveBuffer,
				TRANSMISSION_HEADER_SIZE);
			}

			IncomingTransmissionBytesSize = 0;
		}
		else
		{
			IncomingTransmissionBytesSize = ReceiveBuffer[0];
			IncomingTransmissionBytesSize |= ReceiveBuffer[1] << 8;

			Lpuart_Uart_Ip_AsyncReceive(HwInstance, ReceiveBuffer,
					IncomingTransmissionBytesSize);
		}
	}
	/*

	if (Event == LPUART_UART_IP_EVENT_RX_FULL)
	{

	}
	*/
}

void LPUART_printf(char *fmt, ...)
{
	va_list args;

	va_start(args, fmt);

	char *bytes = va_arg(args, char *);
	int size = va_arg(args, int);

	va_end(args);

	char buffer[sizeof(fmt) + size + sizeof(bytes)];

	vsprintf(buffer, fmt, args);

	Lpuart_Uart_Ip_SyncSend(LPUART_UART_IP_INSTANCE_USING_6, (uint8_t *)buffer, sizeof(buffer),
			0xFFFF);
}
