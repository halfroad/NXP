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

#include "Siul2_Port_Ip.h"
#include "Siul2_Dio_Ip.h"
#include "Siul2_Port_Ip_Cfg.h"

volatile int exit_code = 0;
/* User includes */

void DelayMicroseconds(uint32 delay);

/*!
 \brief The main function for the project.
 \details The startup initialization sequence is the following:
 * - startup asm routine
 * - main()
 *
 * https://community.nxp.com/t5/S32-Design-Studio-Knowledge-Base/HOWTO-Create-a-Blinking-LED-application-project-for-S32G-using/ta-p/1562381
 * https://blog.csdn.net/HeFlyYoung/article/details/122349475
 */
int main(void)
{
	/* Write your code here */

	Siul2_Port_Ip_Init(NUM_OF_CONFIGURED_PINS0, g_pin_mux_InitConfigArr0);

	uint8_t key1, key2, key3;

	for (;;)
	{
		if (exit_code != 0)
		{
			break;
		}

		key1 = Siul2_Dio_Ip_ReadPin(KEY1_PORT, KEY1_PIN);
		key2 = Siul2_Dio_Ip_ReadPin(KEY2_PORT, KEY2_PIN);
		key3 = Siul2_Dio_Ip_ReadPin(KEY3_PORT, KEY3_PIN);

		if (key1 == 1)
			Siul2_Dio_Ip_WritePin(LED1_BLUE_PORT, LED1_BLUE_PIN, 0U);
		else if (key1 == 0)
			Siul2_Dio_Ip_WritePin(LED1_BLUE_PORT, LED1_BLUE_PIN, 1U);

		if (key2 == 1)
			Siul2_Dio_Ip_WritePin(LED2_GREEN_PORT, LED2_GREEN_PIN, 0U);
		else if (key2 == 0)
			Siul2_Dio_Ip_WritePin(LED2_GREEN_PORT, LED2_GREEN_PIN, 1U);

		if (key3 == 1)
			Siul2_Dio_Ip_WritePin(LED3_RED_PORT, LED3_RED_PIN, 0U);
		else if (key3 == 0)
			Siul2_Dio_Ip_WritePin(LED3_RED_PORT, LED3_RED_PIN, 1U);

		Siul2_Dio_Ip_TogglePins(LED4_YELLOW_PORT, 1 << LED4_YELLOW_PIN);

		DelayMicroseconds(2000000);
	}
	return exit_code;
}

void DelayMicroseconds(uint32 delay)
{
	static volatile uint32 DelayTimer = 0;

	while (DelayTimer < delay)

		DelayTimer++;

	DelayTimer = 0;
}

/** @} */
