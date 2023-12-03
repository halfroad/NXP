/*
 * key.c
 *
 *  Created on: 2022年3月26日
 *      Author: Administrator
 */

#include"system.h"
#include"key.h"
#include"delay.h"

/*0为单次模式 1为连续模式*/
unsigned char  KEY_Proc (unsigned char mode)
{
    static unsigned char key_up=1;     //按键松开标志
    if(mode==1)key_up=1;    //支持连按

    if(key_up&&(BTN1==1||BTN2==1||BTN3==1))
    {
        delay_ms(10);
        key_up=0;
        if(BTN1==1)       return BTN1_PRES;
        else if(BTN2==1)  return BTN2_PRES;
        else if(BTN3==1)  return BTN3_PRES;

    }else if(BTN1==0&&BTN2==0&&BTN3==0)key_up=1;
    return 0;
}
