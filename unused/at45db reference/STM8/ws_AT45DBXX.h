/********************************************************************************************************
*
* File                : ws_AT24CXX.h
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

#ifndef _WS_AT45DBXX_H_
#define _WS_AT45DBXX_H_

#include <ws_spi.h>

#define CS_INIT PC_DDR|=0x10;PC_CR1|=0x10;
#define CS_CLK PC_ODR&=(~0x10);
#define CS_SET PC_ODR|=0x10;

void AT45DBXX_Init(void)
{
	SPI_Init();
	CS_INIT;
	CS_SET;
}

void write_buffer(u16 BufferOffset,u8 Data)
{			
	CS_CLK;
	delay_us(10);
	SPI_sendchar(0x84);			
	SPI_sendchar(0xff);
	SPI_sendchar((u8)BufferOffset>>8);
	SPI_sendchar((u8)BufferOffset);		
	SPI_sendchar(Data);
	delay_us(10);
	CS_SET;
}

u8 read_buffer(u16 BufferOffset)
{		
	u8 temp;
	CS_CLK;
	delay_us(10);
 	SPI_sendchar(0xd4);
	SPI_sendchar(0xff);
	SPI_sendchar((u8)BufferOffset>>8);
	SPI_sendchar((u8)BufferOffset);
	SPI_sendchar(0xff);
	SPI_sendchar(0xff);
	temp=SPI_rechar();
	delay_us(10);
	CS_SET;
	return temp;		
}

#endif /*_WS_AT45DBXX_H_*/