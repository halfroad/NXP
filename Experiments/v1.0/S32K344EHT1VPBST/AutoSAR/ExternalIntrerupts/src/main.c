/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : S32K3XX
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 3.0.0
*   Build Version        : S32K3_RTD_3_0_0_D2303_ASR_REL_4_7_REV_0000_20230331
*
*   Copyright 2020 - 2023 NXP Semiconductors
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

/**
*   @file main.c
*
*   @addtogroup main_module main module documentation
*   @{
*/

/* Including necessary configuration files. */

#include "../RTD/include/Clock_Ip.h"

#include "../RTD/include/Siul2_Port_Ip.h"
#include "../RTD/include/Siul2_Dio_Ip.h"
#include "../RTD/include/Siul2_Icu_Ip.h"
#include "../RTD/include/IntCtrl_Ip.h"
#include "../RTD/include/Siul2_Icu_Ip_Irq.h"

#define PORTB_Instance 1

volatile int exit_code = 0;
/* User includes */

/*!
  \brief The main function for the project.
  \details The startup initialization sequence is the following:
 * - startup asm routine
 * - main()
*/
int main(void)
{
    /* Write your code here */

	Clock_Ip_Init(Clock_Ip_aClockConfig);

#if defined(FEATURE_CLOCK_IP_HAS_SPLL_CLK)

	while (CLOCK_IP_PLL_LOCKED != Clock_Ip_GetPllStatus())
		;

	Clock_Ip_DistributePll();

#endif

	Siul2_Port_Ip_Init(NUM_OF_CONFIGURED_PINS0, g_pin_mux_InitConfigArr0);

	Siul2_Icu_Ip_Init(0u, &Siul2_Icu_Ip_0_Config_PB);

    Siul2_Icu_Ip_EnableNotification(0u, (*Siul2_Icu_Ip_0_Config_PB.pChannelsConfig)[0].hwChannel);

	/* Install IRQ handler for SIUL2 EIRQ8~15 */
	IntCtrl_Ip_InstallHandler(SIUL_1_IRQn, SIUL2_ICU_IRQ_24, NULL_PTR);
	/* Enable SIUL2 EIRQ8~15 in NVIC */
	IntCtrl_Ip_EnableIrq(SIUL_1_IRQn);

	for(;;)
    {
        if(exit_code != 0)
        {
            break;
        }
    }
    return exit_code;
}

ISR(SIUL2_EXT_IRQ_8_15_ISR);

void PTB19_EIRQ_CALLBACK(void)
{
	Siul2_Dio_Ip_TogglePins(LED1_BLUE_PORT, 0x01U << LED1_BLUE_PIN);
}

void PTB20_EIRQ_CALLBACK(void)
{
	Siul2_Dio_Ip_TogglePins(LED2_GREEN_PORT, 0x01U << LED2_GREEN_PIN);
}

void PTB26_EIRQ_CALLBACK(void)
{
	Siul2_Dio_Ip_TogglePins(LED3_RED_PORT, 0x01U << LED3_RED_PIN);
	Siul2_Dio_Ip_TogglePins(LED4_YELLOW_PORT, 0x01U << LED4_YELLOW_PIN);
}

/** @} */
