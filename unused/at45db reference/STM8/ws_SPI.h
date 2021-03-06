/********************************************************************************************************
*
* File                : ws_SPI.h
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
#ifndef _SPI_H_
#define _SPI_H_

void SPI_Init(void)
{
	SPI_CR1|=0x38;   //波特率
	//SPI_CR1|=0x03;   //时钟格式
	//SPI_CR1&=0x7f;   //帧格式
	
	//SPI_CR2|=0xc0;   //选择单线双向数据模式（输出模式）
	SPI_CR2|=0x03;   //配置NSS脚为1
	SPI_CR1|=0x04;   //配置为主设备
	SPI_CR1|=0x40;   //开启SPI
}

void SPI_sendchar(u8 data)
{	
	SPI_DR=data;
	while(!(SPI_SR & 0x02));
}

u8 SPI_rechar(void)
{	
	u8 data;
	data=SPI_DR;
	while(!(SPI_SR & 0x01));
	return data;
}

#endif /*_SPI_H_*/