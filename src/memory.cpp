#include "memory.h"

SPI spi(PC_12, PC_11, PC_10); // mosi, miso, sclk
ATD45DB161D memory(spi, PD_2);

void Memory_Init()
{
    spi.frequency(16000000);
}

void Memory_Write(int addr, char *buf, int len)
{
    int i;
    memory.BufferWrite(WRITE_BUFFER, addr % PAGE_SIZE);
    for (i = 0; i < len; i ++)
    {
        spi.write(buf[i]);
    }
    memory.BufferToPage(WRITE_BUFFER, addr / PAGE_SIZE, 1);
}

void Memory_Read(int addr, char *buf, int len)
{
    int i;
    memory.PageToBuffer(addr / PAGE_SIZE, READ_BUFFER);
    memory.BufferRead(READ_BUFFER, addr % PAGE_SIZE, 1);
    for (i = 0; i < len; i ++)
    {
        buf[i] = spi.write(0xff);
    }
}