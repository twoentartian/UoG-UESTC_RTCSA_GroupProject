#include "at45db161d.h"

SPI MemorySpi(PC_12, PC_11, PC_10);
DigitalOut MemoryCs(PA_13);

void Memory_Spi_Frequency(int frequency)
{
    MemorySpi.frequency(frequency);
}

int Memory_Spi_Write(int value)
{
    DF_CS_active;
    return MemorySpi.write(value);
    DF_CS_inactive;
}

void Memory_Init()
{
    DF_CS_inactive;
    MemorySpi.format(8, 0);
}

int spi_transfer(int value)
{
    //////////DEBUG//////////
    // Serial pc(USBTX,USBRX);
    // pc.baud(115200);
    //////////DEBUG//////////
    // pc.printf("tran value:%i\n",value);
    return MemorySpi.write(value);
}

uint8_t Memory_ReadStatusRegister()
{
    uint8_t status;
    DF_CS_active;
    spi_transfer(AT45DB161D_STATUS_REGISTER_READ);
    status = spi_transfer(0x00);
    DF_CS_inactive;
    return status;
}
void Memory_ReadManufacturerAndDeviceID(struct ID *id)
{
    DF_CS_active;
    spi_transfer(AT45DB161D_READ_MANUFACTURER_AND_DEVICE_ID);
    id->manufacturer = spi_transfer(0xff);
    id->device[0] = spi_transfer(0xff);
    id->device[1] = spi_transfer(0xff);
    id->extendedInfoLength = spi_transfer(0xff);
    DF_CS_inactive;
}
void Memory_ReadMainMemoryPage(uint16_t page, uint16_t offset)
{
    DF_CS_active;
    spi_transfer(AT45DB161D_PAGE_READ);
    spi_transfer((uint8_t)(page >> 6));
    spi_transfer((uint8_t)((page << 2) | (offset >> 8)));
    spi_transfer((uint8_t)(offset & 0xff));
    spi_transfer(0x00);
    spi_transfer(0x00);
    spi_transfer(0x00);
    spi_transfer(0x00);
    DF_CS_inactive;
}
void Memory_ContinuousArrayRead(uint16_t page, uint16_t offset, uint8_t low)
{
    DF_CS_active;
    spi_transfer(low?AT45DB161D_CONTINUOUS_READ_LOW_FREQ:AT45DB161D_CONTINUOUS_READ_HIGH_FREQ );
    spi_transfer((uint8_t)(page >> 6));
    spi_transfer((uint8_t)((page << 2) | (offset >> 8)));
    spi_transfer((uint8_t)(offset & 0xff));
    if (!low) { spi_transfer(0x00); }
    DF_CS_inactive;
}
void Memory_BufferRead(uint8_t bufferNum, uint16_t offset, uint8_t low)
{
    DF_CS_active;
    if(bufferNum == 1)
    {
        spi_transfer(low?AT45DB161D_BUFFER_1_READ_LOW_FREQ:AT45DB161D_BUFFER_1_READ);
    }
    else
    {
        spi_transfer(low?AT45DB161D_BUFFER_2_READ_LOW_FREQ:AT45DB161D_BUFFER_2_READ);
    }
    spi_transfer(0x00);
    spi_transfer((uint8_t)(offset >> 8));
    spi_transfer((uint8_t)(offset & 0xff));
    DF_CS_inactive;
}
void Memory_BufferWrite(uint8_t bufferNum, uint16_t offset)
{
    DF_CS_active;
    spi_transfer((bufferNum==1)?AT45DB161D_BUFFER_1_WRITE:AT45DB161D_BUFFER_2_WRITE);
    spi_transfer(0x00);
    spi_transfer((uint8_t)(offset >> 8));
    spi_transfer((uint8_t)(offset & 0xff));
    DF_CS_inactive;
}
void Memory_BufferToPage(uint8_t bufferNum, uint16_t page, uint8_t erase)
{
    DF_CS_active;
    if(erase)
    {
        spi_transfer((bufferNum==1)?AT45DB161D_BUFFER_1_TO_PAGE_WITH_ERASE:AT45DB161D_BUFFER_2_TO_PAGE_WITH_ERASE);
    }
    else
    {
        spi_transfer((bufferNum==1)?AT45DB161D_BUFFER_1_TO_PAGE_WITHOUT_ERASE:AT45DB161D_BUFFER_2_TO_PAGE_WITHOUT_ERASE);
    }
    spi_transfer((uint8_t)(page >> 6));
    spi_transfer((uint8_t)(page << 2));
    spi_transfer(0x00);
    DF_CS_inactive;
    DF_CS_active;
    while(!(Memory_ReadStatusRegister() & READY_BUSY))
    {}
    DF_CS_inactive;
}
void Memory_PageToBuffer(uint16_t page, uint8_t bufferNum)
{
    DF_CS_active;
    spi_transfer((bufferNum == 1)?AT45DB161D_TRANSFER_PAGE_TO_BUFFER_1:AT45DB161D_TRANSFER_PAGE_TO_BUFFER_2);
    spi_transfer((uint8_t)(page >> 6));
    spi_transfer((uint8_t)(page << 2));
    spi_transfer(0x00);
    DF_CS_inactive;
    DF_CS_active;
    while(!(Memory_ReadStatusRegister() & READY_BUSY))
    {}
    DF_CS_inactive;
}
void Memory_PageErase(uint16_t page)
{
    DF_CS_active;
    spi_transfer(AT45DB161D_PAGE_ERASE);
    spi_transfer((uint8_t)(page >> 6));
    spi_transfer((uint8_t)(page << 2));
    spi_transfer(0x00);
    DF_CS_inactive;
    DF_CS_active;
    while(!(Memory_ReadStatusRegister() & READY_BUSY))
    {}
    DF_CS_inactive;
}
void Memory_BlockErase(uint16_t block)
{
    DF_CS_active;
    spi_transfer(AT45DB161D_BLOCK_ERASE);
    spi_transfer((uint8_t)(block >> 3));
    spi_transfer((uint8_t)(block << 5));
    spi_transfer(0x00);
    DF_CS_inactive;
    DF_CS_active;
    while(!(Memory_ReadStatusRegister() & READY_BUSY))
    {}
    DF_CS_inactive;
}
void Memory_SectoreErase(uint8_t sector)
{
    DF_CS_active;
    spi_transfer(AT45DB161D_SECTOR_ERASE);
    if((sector == 0x0a) || (sector == 0x0b))
    {
        spi_transfer(0x00);
        spi_transfer(((sector & 0x01) << 4));
        spi_transfer(0x00);
    }
    else
    {
        spi_transfer(sector << 1);
        spi_transfer(0x00);
        spi_transfer(0x00);
    }
    DF_CS_inactive;
    DF_CS_active;
    while(!(Memory_ReadStatusRegister() & READY_BUSY))
    {}
    DF_CS_inactive;
}
void Memory_ChipErase()
{
    DF_CS_active;
    spi_transfer(AT45DB161D_CHIP_ERASE_0);
    spi_transfer(AT45DB161D_CHIP_ERASE_1);
    spi_transfer(AT45DB161D_CHIP_ERASE_2);
    spi_transfer(AT45DB161D_CHIP_ERASE_3);            
    DF_CS_inactive;
    DF_CS_active;
    while(!(Memory_ReadStatusRegister() & READY_BUSY))
    {}
    DF_CS_inactive;
}
void Memory_BeginPageWriteThroughBuffer(uint16_t page, uint16_t offset, uint8_t bufferNum)
{
    DF_CS_active;
    spi_transfer((bufferNum == 1)?AT45DB161D_PAGE_THROUGH_BUFFER_1:AT45DB161D_PAGE_THROUGH_BUFFER_2);
    spi_transfer((uint8_t)(page >> 6));
    spi_transfer((uint8_t)((page << 2) | (offset >> 8)));
    spi_transfer((uint8_t)offset);
    DF_CS_inactive;
}
void Memory_EndAndWait()
{
    DF_CS_active;
    while(!(Memory_ReadStatusRegister() & READY_BUSY))
    {}
    DF_CS_inactive;
}
int8_t Memory_ComparePageToBuffer(uint16_t page, uint8_t bufferNum)
{
    uint8_t status;
    DF_CS_active;
    spi_transfer((bufferNum == 1)?AT45DB161D_COMPARE_PAGE_TO_BUFFER_1:AT45DB161D_COMPARE_PAGE_TO_BUFFER_2);
    spi_transfer((uint8_t)(page >> 6));
    spi_transfer((uint8_t)(page << 2));
    spi_transfer(0x00);
    DF_CS_inactive;
    DF_CS_active;
    while(!((status = Memory_ReadStatusRegister()) & READY_BUSY))
    {}
    DF_CS_inactive;
    return ((status & COMPARE) ? 0 : 1);
}
void Memory_DeepPowerDown()
{
    DF_CS_inactive;
    DF_CS_active;
    spi_transfer(AT45DB161D_DEEP_POWER_DOWN);
    DF_CS_inactive;
    wait_ms(100);
}

void Memory_ResumeFromDeepPowerDown()
{
    DF_CS_inactive;
    DF_CS_active;
    spi_transfer(AT45DB161D_RESUME_FROM_DEEP_POWER_DOWN);
    DF_CS_inactive;
    wait_ms(100);
}
