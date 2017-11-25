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
	SPI_CR1|=0x38;   //������
	//SPI_CR1|=0x03;   //ʱ�Ӹ�ʽ
	//SPI_CR1&=0x7f;   //֡��ʽ
	
	//SPI_CR2|=0xc0;   //ѡ����˫������ģʽ�����ģʽ��
	SPI_CR2|=0x03;   //����NSS��Ϊ1
	SPI_CR1|=0x04;   //����Ϊ���豸
	SPI_CR1|=0x40;   //����SPI
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