#include "../RTD/include/Clock_Ip.h"
#include "../RTD/include/Siul2_Port_Ip.h"

#include "../include/UART.h"

extern void OnBytesReceived(uint8_t *bytes);

void Init(void)
{
	Clock_Ip_Init(&Clock_Ip_aClockConfig[0]);

	InitSerialCommunications(OnBytesReceived);

	Siul2_Port_Ip_Init(NUM_OF_CONFIGURED_PINS0, g_pin_mux_InitConfigArr0);
}
