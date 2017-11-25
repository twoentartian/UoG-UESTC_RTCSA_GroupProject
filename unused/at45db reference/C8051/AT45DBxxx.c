/********************************************************************************************************
*
* File                : AT45DBxxx.c
* Hardware Environment:	DVK501 && F320 EX
* Build Environment   : uVision3 V3.80 20100913
* Version             : 
* By                  : Su Wei Feng
*
*                                  (c) Copyright 2005-2010, WaveShare
*                                       http://www.waveshare.net
*                                          All Rights Reserved
*
*********************************************************************************************************/

#define _DVK501_F320_EX_

#include <c8051f320.h>
#include <ws_clock.h>
#include <ws_delay.h>
#include <ws_at45dbxxx_port.h>
#include <ws_lcd_ST7920_port.h>

void main(void)
{
	uchar num;
	uchar tmp[31];
	
	PCA0MD &= ~0x40;     //Clear watchdog timer enable
	XBR1 = 0x40;
	clock_external();    
	delay_ms(100);
	SPI_Init();
	st7920LcdInit();
	showLine(0,0,lcd_buffer,"AT45DBXX Example");
	showLine(0,1,lcd_buffer,"Program: OK!");
	showLine(0,2,lcd_buffer,"Verify: OK!");
	showLine(0,3,lcd_buffer,"Output:");
	refreshLCD(lcd_buffer); 

	for(num=0;num<29;num++) 
	{
		write_buffer((uint)num,num);
		delay_ms(1);
	}
	for(num=0;num<29;num++)
	{
		tmp[num]=read_buffer(num);
		delay_ms(1);
	}
	for(num=0;num<29;num++)
	{
		showLine(8,3,lcd_buffer,"0x%x2",tmp[num]);
		refreshLCD(lcd_buffer); 
		delay_ms(1000);
	}
	while(1)
	{
	}
}
