/********************************************************************************************************
*
* File                : AT45DBXX.c
* Hardware Environment: 
* Build Environment   : ST Visual Develop 4.1.6
* Version             : V1.0
* By                  : Xiao xian hui
*
*                                  (c) Copyright 2005-2010, WaveShare
*                                       http://www.waveShare.net
*                                          All Rights Reserved
*
*********************************************************************************************************/

#define EXSTM8Q80A
#include <STM8S208MB.h>
#include <system.h>
#include <ws_at45dbxx.h>
#include <ws_lcd_st7920.h>

main()
{
	u8 num=0;
	u8 tmp[30];
	AT45DBXX_Init();/*
	write_buffer((u16)0x02,0x75);
	delay_ms(100);
	a=read_buffer((u16)0x02);
	delay_ms(100);*/
	for(num=0;num<30;num++) 
	{
		write_buffer((u16)num,num);
		delay_ms(1);
	}
	for(num=0;num<30;num++)
	{
		tmp[num]=read_buffer((u16)num);
		delay_ms(1);
	}
	sendCodeST7920(0x80);
	st7920LcdInit();
	showLine(0,0,lcd_buffer,"AT45DBXX Example");
	showLine(0,1,lcd_buffer,"Program: OK!");
	showLine(0,2,lcd_buffer,"Verify: OK!");
	showLine(0,3,lcd_buffer,"Output:");
	//refreshLCD(lcd_buffer);
	
	for(num=0;num<30;num++)
	{
		showLine(8,3,lcd_buffer,"0x%x2",(u16)tmp[num]);
		refreshLCD(lcd_buffer);
		delay_ms(1000);
	}
	
	while (1);
}