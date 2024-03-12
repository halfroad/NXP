/*
 * TasksScheduler.c
 *
 *  Created on: 2024Äê2ÔÂ1ÈÕ
 *      Author: Developer
 */

#include "../FreeRTOS/Source/include/FreeRTOS.h"
#include "../FreeRTOS/Source/include/task.h"

#include "../../RTD/include/Siul2_Dio_Ip.h"
#include "../../RTD/include/Siul2_Port_Ip.h"
#include "../../board/Siul2_Port_Ip_Cfg.h"

#define UNUSED(x) (void)(x)

#define START_FLASH_BLUE_LED_TASK_STACK_DEPTH				configMINIMAL_STACK_SIZE
#define START_FLASH_GREEN_LED_TASK_STACK_DEPTH				configMINIMAL_STACK_SIZE
#define START_FLASH_RED_LED_TASK_STACK_DEPTH				configMINIMAL_STACK_SIZE
#define START_FLASH_YELLOW_LED_TASK_STACK_DEPTH				configMINIMAL_STACK_SIZE

#define START_FLASH_BLUE_LED_TASK_PRIORITY					( tskIDLE_PRIORITY + 2 )
#define START_FLASH_GREEN_LED_TASK_PRIORITY					START_FLASH_BLUE_LED_TASK_PRIORITY
#define START_FLASH_RED_LED_TASK_PRIORITY					START_FLASH_BLUE_LED_TASK_PRIORITY
#define START_FLASH_YELLOW_LED_TASK_PRIORITY				START_FLASH_BLUE_LED_TASK_PRIORITY

TaskHandle_t StartFlashBlueLedTaskHandle;
TaskHandle_t StartFlashGreenLedTaskHandle;
TaskHandle_t StartFlashRedLedTaskHandle;
TaskHandle_t StartFlashYellowLedTaskHandle;

void StartFlashBlueLedTask(void *arguments);
void StartFlashGreenLedTask(void *arguments);
void StartFlashRedLedTask(void *arguments);
void StartFlashYellowLedTask(void *arguments);

void LaunchScheduler(void *arguments)
{
	UNUSED(arguments);

	vPortEnterCritical();

	xTaskCreate(StartFlashBlueLedTask, "StartFlashBlueLedTaskName",
			START_FLASH_BLUE_LED_TASK_STACK_DEPTH, NULL,
			START_FLASH_BLUE_LED_TASK_PRIORITY, &StartFlashBlueLedTaskHandle);
	xTaskCreate(StartFlashGreenLedTask, "StartFlashGreenLedTaskName",
			START_FLASH_GREEN_LED_TASK_STACK_DEPTH, NULL,
			START_FLASH_GREEN_LED_TASK_PRIORITY, &StartFlashGreenLedTaskHandle);
	xTaskCreate(StartFlashRedLedTask, "StartFlashRedLedTaskName",
			START_FLASH_RED_LED_TASK_STACK_DEPTH, NULL,
			START_FLASH_RED_LED_TASK_PRIORITY, &StartFlashRedLedTaskHandle);
	xTaskCreate(StartFlashYellowLedTask, "StartFlashYellowLedTaskName",
			START_FLASH_YELLOW_LED_TASK_STACK_DEPTH, NULL,
			START_FLASH_YELLOW_LED_TASK_PRIORITY,
			&StartFlashYellowLedTaskHandle);

	vTaskDelete(NULL);

	vPortExitCritical();
}

void StartFlashBlueLedTask(void *arguments)
{
	UNUSED(arguments);

	for (;;)
	{
		Siul2_Dio_Ip_TogglePins(LED1_BLUE_PORT, 1 << LED1_BLUE_PIN);

		vTaskDelay(pdMS_TO_TICKS(250));
	}
}

void StartFlashGreenLedTask(void *arguments)
{
	UNUSED(arguments);

	for (;;)
	{
		Siul2_Dio_Ip_TogglePins(LED2_GREEN_PORT, 1 << LED2_GREEN_PIN);

		vTaskDelay(pdMS_TO_TICKS(250));
	}
}

void StartFlashRedLedTask(void *arguments)
{
	UNUSED(arguments);

	for (;;)
	{
		Siul2_Dio_Ip_TogglePins(LED3_RED_PORT, 1 << LED3_RED_PIN);

		vTaskDelay(pdMS_TO_TICKS(250));
	}
}

void StartFlashYellowLedTask(void *arguments)
{
	UNUSED(arguments);

	for (;;)
	{
		Siul2_Dio_Ip_TogglePins(LED4_YELLOW_PORT, 1 << LED4_YELLOW_PIN);

		vTaskDelay(pdMS_TO_TICKS(250));
	}
}
