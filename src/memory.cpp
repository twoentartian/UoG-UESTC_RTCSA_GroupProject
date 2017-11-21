#include "memory.h"

// SPI spi(PC_12, PC_11, PC_10); // mosi, miso, sclk
// ATD45DB161D memory(spi, PD_2);

void MemoryTop_Init()
{
    Memory_Spi_Frequency(16000000);
}

void MemoryTop_Write(int addr, char *buf, int len)
{
    Memory_BufferWrite(WRITE_BUFFER, addr % PAGE_SIZE);
    for (int i = 0; i < len; i ++)
    {
        Memory_Spi_Write(buf[i]);
    }
    Memory_BufferToPage(WRITE_BUFFER, addr / PAGE_SIZE, 1);
}

void MemoryTop_Read(int addr, char *buf, int len)
{
    Memory_PageToBuffer(addr / PAGE_SIZE, READ_BUFFER);
    Memory_BufferRead(READ_BUFFER, addr % PAGE_SIZE, 1);
    for (int i = 0; i < len; i ++)
    {
        buf[i] = Memory_Spi_Write(0xff);
    }
}