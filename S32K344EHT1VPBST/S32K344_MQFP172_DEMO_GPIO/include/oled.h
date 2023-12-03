/*
 * oled.h
 *
 *  Created on: 2021Äê3ÔÂ5ÈÕ
 *      Author: Administrator
 */

#ifndef OLED_H_
#define OLED_H_

#define XLevelL  	0x00
#define XLevelH  	0x10
#define XLevel          ((XLevelH&0x0F)*16+XLevelL)
#define Max_Column 	128
#define Max_Row  	64
#define Brightness 	0xCF
#define X_WIDTH 	128
#define Y_WIDTH 	64

 uint8_t I2c_Send_Byte(uint8_t Dev_reg,uint8_t data);
 uint8_t I2c_Read_Byte(uint8_t Dev_reg);
 void oled_init(void);
 void OLED_WrDat(unsigned char IIC_Data);
 void OLED_WrCmd(unsigned char IIC_Command);
 void OLED_Set_Pos(unsigned char x, unsigned char y);
 void OLED_Fill(unsigned char bmp_dat)	;
 void OLED_CLS(void);
 void OLED_Init(void);
 void LCD_clear_L(unsigned char x,unsigned char y);
   void LCD_clear_L_POS(unsigned char x1,unsigned char x2,unsigned char y);
 void OLED_Clear(void);
 void LCD_P6x8Str(unsigned char x,unsigned char  y,unsigned char ch[])	;
 void LCD_P6x8Char(unsigned char x,unsigned char  y,unsigned char ucData);
 void OLED_write_number(unsigned char x,unsigned char y, float number,uint8_t fontsize,uint8_t mode);
 void OLED_Clear(void)  ;
 void OLED_task (void * pvParameters);
 void OLED_process(void);
 void OLED_show(int count,int page,int refresh_flag);
 void Draw_Logo1(void);
 void OLED_ShowChar(uint8_t x,uint8_t y,uint8_t chr,uint8_t Char_Size,uint8_t mode);
 void OLED_ShowString(uint8_t x,uint8_t y,uint8_t *chr,uint8_t Char_Size,uint8_t MODE);
 void OLED_ShowStringCHN(uint8_t x,uint8_t y,uint8_t *chr,uint8_t MODE);
 void OLED_ShowCHinese(uint8_t x,uint8_t y,uint8_t no,uint8_t mode);
 void OLED_TITLE(uint8_t * type,uint8_t * title);
  void OLED_TITLE2(uint8_t * type,uint8_t * title);

#endif /* OLED_H_ */
