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
#include <stdio.h>

#include "../../board/Siul2_Port_Ip_Cfg.h"

#include "../../generate/include/IntCtrl_Ip_Cfg.h"

#include "../../RTD/include/Adc_Sar_Ip.h"
#include "../../RTD/include/Clock_Ip.h"
#include "../../RTD/include/IntCtrl_Ip.h"
#include "../../RTD/include/Siul2_Dio_Ip.h"
#include "../../RTD/include/Siul2_Icu_Ip.h"
#include "../../RTD/include/Siul2_Port_Ip.h"

#define SIUL2_ICU_IP_INSTANCE				(0U)

ISR(Adc_Sar_1_Isr);

volatile int exit_code = 0;
/* User includes */

static void Delay(uint32_t delay)
{
	static volatile uint32_t DelayTimer = 0;

	while (DelayTimer < delay)
		DelayTimer++;

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
	/* Write your code here */

	while (CLOCK_IP_SUCCESS != Clock_Ip_Init(&Clock_Ip_aClockConfig[0]))
		;
	while (INTCTRL_IP_STATUS_SUCCESS != IntCtrl_Ip_Init(&IntCtrlConfig_0))
		;
	/*
	 * https://blog.csdn.net/Oushuwen/article/details/120968224
	 * https://blog.csdn.net/kk_willbegood/article/details/133383881
	 * https://blog.csdn.net/lnniyunlong99/article/details/136059070
	 *https://community.nxp.com/t5/S32-Design-Studio-Knowledge-Base/SIUL2-external-interrupt-example-project-using-S32K3-RTD-without/ta-p/1552335
	 * */
	while (SIUL2_ICU_IP_SUCCESS
			!= Siul2_Icu_Ip_Init(SIUL2_ICU_IP_INSTANCE,
					&Siul2_Icu_Ip_0_Config_PB))
		;

	Siul2_Icu_Ip_EnableInterrupt(SIUL2_ICU_IP_INSTANCE,
			Siul2_Icu_Ip_0_ChannelConfig_PB[0].hwChannel);
	Siul2_Icu_Ip_EnableNotification(SIUL2_ICU_IP_INSTANCE,
			Siul2_Icu_Ip_0_ChannelConfig_PB[0].hwChannel);

	while (SIUL2_PORT_SUCCESS
			!= Siul2_Port_Ip_Init(NUM_OF_CONFIGURED_PINS0,
					g_pin_mux_InitConfigArr0))
		;

	while (E_OK != Adc_Sar_Ip_Init(ADCHWUNIT_0_INSTANCE, &AdcHwUnit_0))
		;

    IntCtrl_Ip_InstallHandler(ADC1_IRQn, Adc_Sar_1_Isr, NULL_PTR);
    IntCtrl_Ip_EnableIrq(ADC1_IRQn);

	/*	Calibrate the converter for multiple times to mitigate the instability of the board source.	*/
	for (uint8_t i = 0; i < 5; i++)
	{
		if (E_OK == Adc_Sar_Ip_DoCalibration(ADCHWUNIT_0_INSTANCE))
			break;
	}

	Adc_Sar_Ip_EnableNotifications(ADCHWUNIT_0_INSTANCE,
			ADC_SAR_IP_NOTIF_FLAG_NORMAL_ENDCHAIN
					| ADC_SAR_IP_NOTIF_FLAG_INJECTED_ENDCHAIN);

	/*
	 * Table 35. Interrupt source mapping to SIUL2 interrupt request output for 32 interrupt sources

	 Vector/Channel # 								Interrupt vector source
	 0 				REQ[07] | REQ[06] | REQ[05] | REQ[04] | REQ[03] | REQ[02] | REQ[01] | REQ[00]
	 1 				REQ[15] | REQ[14] | REQ[13] | REQ[12] | REQ[11] | REQ[10] | REQ[09] | REQ[08]
	 2 				REQ[23] | REQ[22] | REQ[21] | REQ[20] | REQ[19] | REQ[18] | REQ[17] | REQ[16]
	 3 				REQ[31] | REQ[30] | REQ[29] | REQ[28] | REQ[27] | REQ[26] | REQ[25] | REQ[24]
	 * */

	for (;;)
	{
		Siul2_Dio_Ip_TogglePins(LED2_GREEN_PORT, 0x01UL << LED2_GREEN_PIN);

		Delay(16000000);

		if (exit_code != 0)
		{
			break;
		}
	}
	return exit_code;
}

void KEY1_Pressed_IcuSignalNotification(void)
{
	Siul2_Dio_Ip_TogglePins(LED1_RED_PORT, 0x01UL << LED1_RED_PIN);

	Adc_Sar_Ip_StartConversion(ADCHWUNIT_0_INSTANCE,
			ADC_SAR_IP_CONV_CHAIN_NORMAL);
}

void ADC_1_STREAM_10_END_OF_NORMAL_CHAIN_NOTIFICATION(void)
{
	volatile uint16_t data = Adc_Sar_Ip_GetConvData(ADCHWUNIT_0_INSTANCE, 34);
	double analogy = data * 5.0 / ((1UL << 14) - 1);

	printf("Analogous Value converted: %.3f.\n", analogy);
}

/** @} */
