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
#include "Mcu.h"
#include "Port.h"
#include "Dio.h"

volatile int exit_code = 0;
/* User includes */

void Delay(uint32 delay)
{
	static volatile uint32 DelayTimer = 0;
	while (DelayTimer < delay)
	{
		DelayTimer++;
	}
	DelayTimer = 0;
}

/*!
 \brief The main function for the project.
 \details The startup initialization sequence is the following:
 * - startup asm routine
 * - main()
 */
int main(void)
{
	/*	uint8 count = 0U;	*/

	/* Initialize the Mcu driver */
#if (MCU_PRECOMPILE_SUPPORT == STD_ON)
	    Mcu_Init(NULL_PTR);
	#elif (MCU_PRECOMPILE_SUPPORT == STD_OFF)
	Mcu_Init(&Mcu_Config);
#endif /* (MCU_PRECOMPILE_SUPPORT == STD_ON) */

	/* Initialize the clock tree and apply PLL as system clock */
	Mcu_InitClock(McuClockSettingConfig_0);

	/* Apply a mode configuration */
	Mcu_SetMode(McuModeSettingConf_0);

	/* Initialize all pins using the Port driver */
	Port_Init(NULL_PTR);

	/* Write your code here */

	for (;;)
	{
		Dio_WriteChannel(DioConf_DioChannel_LED1_BLUE_PORT, STD_HIGH);
		Dio_WriteChannel(DioConf_DioChannel_LED2_GREEN_PORT, STD_HIGH);
		Dio_WriteChannel(DioConf_DioChannel_LED3_RED_PORT, STD_HIGH);
		Dio_WriteChannel(DioConf_DioChannel_LED4_YELLOW_PORT, STD_HIGH);

		Delay(5000000);

		Dio_WriteChannel(DioConf_DioChannel_LED1_BLUE_PORT, STD_LOW);
		Dio_WriteChannel(DioConf_DioChannel_LED2_GREEN_PORT, STD_LOW);
		Dio_WriteChannel(DioConf_DioChannel_LED3_RED_PORT, STD_LOW);
		Dio_WriteChannel(DioConf_DioChannel_LED4_YELLOW_PORT, STD_LOW);

		Delay(5000000);

		if (exit_code != 0)
		{
			break;
		}
	}
	return exit_code;
}

/** @} */
