/********************************************************************************************************
*********************************************************************************************************
*
* File                : AT45DBXXX_LCD12864.c
* Hardware Environment:
* Build Environment   : AVR Studio 4.16 + Winavr 20090313
* Version             : V1.0
* By                  : Wu Ze
*
*                                  (c) Copyright 2005-2009, WaveShare
*                                       http://www.waveShare.net
*                                          All Rights Reserved
*
*********************************************************************************************************
********************************************************************************************************/

#define _DVK501_M128_EX_ 1
#include <avr/io.h>
#include <util/delay.h>
#include <ws_at45dbxxx_port.h>
#include <ws_lcd_ST7920_port.h>

int main(void)
{
	uint8_t num;
	uint8_t tmp[255];
	DDRA=0xFF;
	spiInitAt45db();
	for(num=0;num<255;num++) /*д��flash*/
	{
		write_buffer((uint16_t)num,num);
		_delay_ms(1);
	}
	for(num=0;num<255;num++) /*����flash*/
	{
		tmp[num]=read_buffer(num);
		_delay_ms(1);
	}
	st7920LcdInit(); /*LCD��ʼ��*/
	showLine(0,0,lcd_buffer,"����΢ѩ����");
	showLine(0,1,lcd_buffer,"��ȡflash:");
	refreshLCD(lcd_buffer); /*ˢ��LCD*/
	for(num=0;num<255;num++)
	{
		showLine(11,1,lcd_buffer,"%d3",tmp[num]);
		refreshLCD(lcd_buffer); /*ˢ��LCD*/
		_delay_ms(1000);
	}
	while(1);
}
