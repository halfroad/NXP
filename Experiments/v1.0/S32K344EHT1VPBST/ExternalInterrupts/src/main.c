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
#include "Mcal.h"

#include "../RTD/include/Siul2_Icu_Ip.h"
#include "../RTD/include/Siul2_Icu_Ip_Irq.h"
#include "../RTD/include/IntCtrl_Ip.h"
#include "../RTD/include/Clock_Ip.h"
#include "../RTD/include/Siul2_Port_Ip.h"

#include "../generate/include/Clock_Ip_Cfg.h"
#include "../generate/include/Siul2_Icu_Ip_SA_PBcfg.h"

#include "../board/Siul2_Port_Ip_Cfg.h"

volatile int exit_code = 0;
volatile uint8_t irq_sw5_counter;

/* User includes */

/*!
 \brief The main function for the project.
 \details The startup initialization sequence is the following:
 * - startup asm routine
 * - main()
 *
 * https://blog.csdn.net/HeFlyYoung/article/details/122349475
 * https://blog.csdn.net/enchanter11111/article/details/131183995
 */
int main(void)
{
	/* Write your code here */

	/* Clock settings. */

	Clock_Ip_StatusType Status_Init_Clock = CLOCK_IP_ERROR;
	Status_Init_Clock = Clock_Ip_Init(Clock_Ip_aClockConfig);

	if (Status_Init_Clock != CLOCK_IP_SUCCESS)
	{
		while (1)
			; /* Error during initialization. */
	}

	/* Initialize all pins using the Port driver */
	Siul2_Port_Ip_PortStatusType Status_Init_Port = SIUL2_PORT_ERROR;
	Status_Init_Port = Siul2_Port_Ip_Init(NUM_OF_CONFIGURED_PINS0,
			g_pin_mux_InitConfigArr0);

	if (Status_Init_Port != SIUL2_PORT_SUCCESS)
	{
		while (1)
			; /* Error during initialization. */
	}

	/* Interrutps enablement. */
	Siul2_Port_Ip_Init(NUM_OF_CONFIGURED_PINS0, g_pin_mux_InitConfigArr0);

	IntCtrl_Ip_InstallHandler(SIUL_1_IRQn, &SIUL2_EXT_IRQ_8_15_ISR, NULL_PTR);
	IntCtrl_Ip_EnableIrq(SIUL_1_IRQn);

	/* Siul2. */

	Siul2_Icu_Ip_Init(0, &Siul2_Icu_Ip_0_Config_PB);

	Siul2_Icu_Ip_EnableInterrupt(0, 13);
	Siul2_Icu_Ip_EnableNotification(0, 13);

	for (;;)
	{
		if (exit_code != 0)
		{
			break;
		}
	}
	return exit_code;
}

void Icu_sw5_callback(void)
{
	irq_sw5_counter ++;
}

/** @} */
