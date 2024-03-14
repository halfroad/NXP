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

#include "../generate/include/Siul2_Dio_Ip_Cfg.h"

#include "../RTD/include/Clock_Ip.h"
#include "../RTD/include/IntCtrl_Ip.h"
#include "../RTD/include/Siul2_Icu_Ip.h"
#include "../RTD/include/Siul2_Port_Ip.h"
#include "../RTD/include/Siul2_Dio_Ip.h"

#define ICU_IP_INSTANCE			0

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
    /* Write your code here
     *
     * https://blog.csdn.net/HeFlyYoung/article/details/122349475
     *
     * Table 35. Interrupt source mapping to SIUL2 interrupt request output for 32 interrupt sources

		Vector/Channel # 								Interrupt vector source
			0 				REQ[07] | REQ[06] | REQ[05] | REQ[04] | REQ[03] | REQ[02] | REQ[01] | REQ[00]
			1 				REQ[15] | REQ[14] | REQ[13] | REQ[12] | REQ[11] | REQ[10] | REQ[09] | REQ[08]
			2 				REQ[23] | REQ[22] | REQ[21] | REQ[20] | REQ[19] | REQ[18] | REQ[17] | REQ[16]
			3 				REQ[31] | REQ[30] | REQ[29] | REQ[28] | REQ[27] | REQ[26] | REQ[25] | REQ[24]
     * */

	/*	Initialize the clocks.	*/
	Clock_Ip_InitClock(&Clock_Ip_aClockConfig[0]);

	/*	Enable the interrupts of all the peripherals.	*/
	IntCtrl_Ip_Init(&IntCtrlConfig_0);

	/*	Initialize the Input Capture Unit driver.	*/
	Siul2_Icu_Ip_Init(ICU_IP_INSTANCE, &Siul2_Icu_Ip_0_Config_PB);

	/*	Enable the interrupt and register the callback for the given pin.	*/
	Siul2_Icu_Ip_EnableInterrupt(ICU_IP_INSTANCE, 13);
	Siul2_Icu_Ip_EnableNotification(ICU_IP_INSTANCE, 13);

	Siul2_Port_Ip_Init(NUM_OF_CONFIGURED_PINS0, g_pin_mux_InitConfigArr0);

    for(;;)
    {
        if(exit_code != 0)
        {
            break;
        }
    }
    return exit_code;
}

void KEY3_PTB26_EIRQ_3_IcuSignalNotification_Callback(void)
{
	Siul2_Dio_Ip_TogglePins(LED1_BLUE_PORT, 0x01UL << LED1_BLUE_PIN);
	Siul2_Dio_Ip_TogglePins(LED2_GREEN_PORT, 0x01UL << LED2_GREEN_PIN);
	Siul2_Dio_Ip_TogglePins(LED3_RED_PORT, 0x01UL << LED3_RED_PIN);
	Siul2_Dio_Ip_TogglePins(LED4_YELLOW_PORT, 0x01UL << LED4_YELLOW_PIN);
}

/** @} */
