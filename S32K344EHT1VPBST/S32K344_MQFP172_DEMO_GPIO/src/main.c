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

volatile int exit_code = 0;
/* User includes */
#include "sys.h"
#include "uart.h"
#include "delay.h"
/*!
  \brief The main function for the project.
  \details The startup initialization sequence is the following:
 * - startup asm routine
 * - main()
*/

#define LPUART6_INSTANCE  6U

void i2c_master_callback(Lpi2c_Ip_MasterEventType event, uint8 userData)
{
	(void) event;
	(void) userData;
}


int main(void)
{
    /* Write your code here */
	uint32 Get_Freq = 0;
	Clock_Ip_Init(&Clock_Ip_aClockConfig[0]);
	IntCtrl_Ip_Init(&IntCtrlConfig_0);


	Get_Freq = Clock_Ip_GetClockFrequency(CORE_CLK);


	 Siul2_Port_Ip_Init(NUM_OF_CONFIGURED_PINS0, g_pin_mux_InitConfigArr0);


	 delay_init(Get_Freq/1000000); //初始化延迟函数需要核心频率,把读取到的频率传入函数。

	 Lpuart_Uart_Ip_Init(LPUART6_INSTANCE, &Lpuart_Uart_Ip_xHwConfigPB_6);
	 Lpi2c_Ip_MasterInit(I2C_MASTER_INSTANCE,&I2c_Lpi2cMasterChannel0);


    oled_init(); //OLED配置参数初始化
	delay_ms(20);
	LPUART_printf("Run frequency is %dmhz\r\n",Get_Freq/1000000);
	OLED_TITLE((uint8_t*) "S32K344", (uint8_t*) "BASEDEMO"); //OLED显示标题
	OLED_ShowString(16, 2, (uint8_t *) " GEEKSTORE", 16, 0);
	OLED_ShowString(0, 4, (uint8_t *) "   This is a", 8, 0);
	OLED_ShowString(0, 5, (uint8_t *) "    S32K344", 8, 0);
	OLED_ShowString(0, 6, (uint8_t *) "   TEST DEMO", 8, 0);


	 while(1)
	 {

		 uint8_t key1 = Siul2_Dio_Ip_ReadPin(KEY1_PORT, KEY1_PIN);
		 uint8_t key2 = Siul2_Dio_Ip_ReadPin(KEY2_PORT, KEY2_PIN);
		 uint8_t key3 = Siul2_Dio_Ip_ReadPin(KEY3_PORT, KEY3_PIN);

	        if(key1 == 1){
	        	LPUART_printf("KEY1 Press\r\n");
		        Siul2_Dio_Ip_WritePin(LED1_RED_PORT, LED1_RED_PIN, 0U);
	        }
	        else if(key1 == 0){
		        Siul2_Dio_Ip_WritePin(LED1_RED_PORT, LED1_RED_PIN, 1U);
	        }


	        if(key2 == 1){
	        	LPUART_printf("KEY2 Press\r\n");
	        	 Siul2_Dio_Ip_WritePin(LED2_GREEN_PORT, LED2_GREEN_PIN, 0U);
	        }
	        else if(key2 == 0){
	        	 Siul2_Dio_Ip_WritePin(LED2_GREEN_PORT, LED2_GREEN_PIN, 1U);
	        }


	        if(key3 == 1){
	        	LPUART_printf("KEY3 Press\r\n");
	        	Siul2_Dio_Ip_WritePin(LED3_BLUE_PORT, LED3_BLUE_PIN, 0U);
	        }
	        else if(key3 == 0){
	        	Siul2_Dio_Ip_WritePin(LED3_BLUE_PORT, LED3_BLUE_PIN, 1U);
	        }



		Siul2_Dio_Ip_TogglePins(LED4_YELLOW_PORT, ( 1<<LED4_YELLOW_PIN ) );
		delay_ms(100);

	 }
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
