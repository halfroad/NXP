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

#include "../generate/include/Clock_Ip_Cfg.h"

#include "../RTD/include/Clock_Ip.h"
#include "../RTD/include/Siul2_Dio_Ip.h"
#include "../RTD/include/Siul2_Port_Ip.h"
#include "../RTD/include/Swt_Ip.h"
#include "../RTD/include/Swt_Ip_Irq.h"

/* SWT instance used - 0 */
#define SWT_INSTANCE                     	0U

volatile int exit_code 						= 0;
/* User includes */

void Delay(uint32_t timeout)
{
	__IO uint32_t i = timeout;

	while (i --)
		;
}

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
     * https://blog.csdn.net/lnniyunlong99/article/details/135383206
     * */

	/*	Initialize the clocks.	*/

	Clock_Ip_InitClock(&Clock_Ip_aClockConfig[0]);

	/*
	 * SWT Expires Only 8 Times
	 * https://community.nxp.com/t5/S32K/SWT-Expires-Only-8-Times/m-p/1569042
	 * For anyone having this issue, it is related to the value of FRET (section 32.8.7 of the Reference Manual). By changing the value of FRET on boot as shown below, the SWT doesn't have a limited number of times to reset the system.
		#define MC_RGM 0x4028C000
		#define MC_RGM_FRET MC_RGM+0x18
		char *pFRET = (char *)MC_RGM_FRET;
		*pFRET = 0;
	 * */
	volatile uint32_t *reg = (uint32_t *)(0x4028C000 + 0x00000018);
	*reg = 0xFF;

	/*	Initialize SWT	*/
	Swt_Ip_Init(SWT_INSTANCE, &Swt_Ip_Cfg0);

	Siul2_Dio_Ip_WritePin(LED1_BLUE_PORT, LED1_BLUE_PIN, 0x01);

	Siul2_Port_Ip_Init(NUM_OF_CONFIGURED_PINS0, g_pin_mux_InitConfigArr0);

	for ( ;; )
	{
		/*	Service SWT0.	*/
		Swt_Ip_Service(SWT_INSTANCE);

		Siul2_Dio_Ip_WritePin(LED1_BLUE_PORT, LED1_BLUE_PIN, 0x00);
		Delay(1 * 2000000U);
		Siul2_Dio_Ip_WritePin(LED1_BLUE_PORT, LED1_BLUE_PIN, 0x01);
		//Delay(1 * 2000000U);
		Delay(3 * 16000000U);
	}

	/*	De-initialize SWT0.
	Swt_Ip_Deinit(SWT_INSTANCE);
	*/

    for(;;)
    {
        if(exit_code != 0)
        {
            break;
        }
    }

    return exit_code;
}

/** @} */
