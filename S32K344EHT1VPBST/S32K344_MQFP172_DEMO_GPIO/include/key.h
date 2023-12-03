/*
 * key.h
 *
 *  Created on: 2022Äê3ÔÂ26ÈÕ
 *      Author: Administrator
 */

#ifndef KEY_H_
#define KEY_H_


#include "system.h"
#include <stdio.h>
#include <stdint.h>
#include "sys.h"
#ifndef KEY_INPUT_H_
#define KEY_INPUT_H_



#define BTN1 Siul2_Dio_Ip_ReadPin(KEY1_PORT, KEY1_PIN)
#define BTN2 Siul2_Dio_Ip_ReadPin(KEY2_PORT, KEY2_PIN)
#define BTN3 Siul2_Dio_Ip_ReadPin(KEY3_PORT, KEY3_PIN)

#define BTN1_PRES 	1
#define BTN2_PRES	2
#define BTN3_PRES	3
unsigned char  KEY_Proc (unsigned char mode);



#endif /* KEY_INPUT_H_ */


#endif /* KEY_H_ */
