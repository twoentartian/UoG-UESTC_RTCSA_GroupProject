#include "at45db161d.h"

ATD45DB161D::ATD45DB161D(PinName mosi, PinName miso, PinName sclk, PinName cs)
  : _spi(mosi, miso, sclk), _cs(cs)
{}

ATD45DB161D::ATD45DB161D(SPI &spi, PinName cs)
  : _spi(spi), _cs(cs)
{}

ATD45DB161D::~ATD45DB161D()
{}

void ATD45DB161D::Init()
{
      DF_CS_inactive;
    _spi.format(8, 0);
}
uint8_t ATD45DB161D::ReadStatusRegister()
{
    uint8_t status;

    DF_CS_inactive;
    DF_CS_active;
    spi_transfer(AT45DB161D_STATUS_REGISTER_READ);
    status = spi_transfer(0x00);
    return status;
}
void ATD45DB161D::ReadManufacturerAndDeviceID(struct ATD45DB161D::ID *id)
{
    
    DF_CS_inactive;
    DF_CS_active;
    spi_transfer(AT45DB161D_READ_MANUFACTURER_AND_DEVICE_ID);
    id->manufacturer = spi_transfer(0xff);
    id->device[0] = spi_transfer(0xff);
    id->device[1] = spi_transfer(0xff);
    id->extendedInfoLength = spi_transfer(0xff);
}
void ATD45DB161D::ReadMainMemoryPage(uint16_t page, uint16_t offset)
{
    DF_CS_inactive;
    DF_CS_active;
    spi_transfer(AT45DB161D_PAGE_READ);
    spi_transfer((uint8_t)(page >> 6));
    spi_transfer((uint8_t)((page << 2) | (offset >> 8)));
    spi_transfer((uint8_t)(offset & 0xff));
    spi_transfer(0x00);
    spi_transfer(0x00);
    spi_transfer(0x00);
    spi_transfer(0x00);
}
void ATD45DB161D::ContinuousArrayRead(uint16_t page, uint16_t offset, uint8_t low)
{
    DF_CS_inactive;
    DF_CS_active;
    spi_transfer(low?AT45DB161D_CONTINUOUS_READ_LOW_FREQ:AT45DB161D_CONTINUOUS_READ_HIGH_FREQ );
    spi_transfer((uint8_t)(page >> 6));
    spi_transfer((uint8_t)((page << 2) | (offset >> 8)));
    spi_transfer((uint8_t)(offset & 0xff));
    if (!low) { spi_transfer(0x00); }
}
void ATD45DB161D::BufferRead(uint8_t bufferNum, uint16_t offset, uint8_t low)
{
    DF_CS_inactive;
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
}
void ATD45DB161D::BufferWrite(uint8_t bufferNum, uint16_t offset)
{
    DF_CS_inactive;
    DF_CS_active;
    spi_transfer((bufferNum==1)?AT45DB161D_BUFFER_1_WRITE:AT45DB161D_BUFFER_2_WRITE);
    spi_transfer(0x00);
    spi_transfer((uint8_t)(offset >> 8));
    spi_transfer((uint8_t)(offset & 0xff));
}
void ATD45DB161D::BufferToPage(uint8_t bufferNum, uint16_t page, uint8_t erase)
{
    DF_CS_inactive;
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
    while(!(ReadStatusRegister() & READY_BUSY))
    {}
}
void ATD45DB161D::PageToBuffer(uint16_t page, uint8_t bufferNum)
{
    DF_CS_inactive;
    DF_CS_active;
    spi_transfer((bufferNum == 1)?AT45DB161D_TRANSFER_PAGE_TO_BUFFER_1:AT45DB161D_TRANSFER_PAGE_TO_BUFFER_2);
    spi_transfer((uint8_t)(page >> 6));
    spi_transfer((uint8_t)(page << 2));
    spi_transfer(0x00);
    DF_CS_inactive;
    DF_CS_active;
    while(!(ReadStatusRegister() & READY_BUSY))
    {}
}
void ATD45DB161D::PageErase(uint16_t page)
{
    DF_CS_inactive;
    DF_CS_active;
    spi_transfer(AT45DB161D_PAGE_ERASE);
    spi_transfer((uint8_t)(page >> 6));
    spi_transfer((uint8_t)(page << 2));
    spi_transfer(0x00);
    DF_CS_inactive;
    DF_CS_active;
    while(!(ReadStatusRegister() & READY_BUSY))
    {}
}
void ATD45DB161D::BlockErase(uint16_t block)
{
    DF_CS_inactive;
    DF_CS_active;
    spi_transfer(AT45DB161D_BLOCK_ERASE);
    spi_transfer((uint8_t)(block >> 3));
    spi_transfer((uint8_t)(block << 5));
    spi_transfer(0x00);
        
    DF_CS_inactive;
    DF_CS_active;
    while(!(ReadStatusRegister() & READY_BUSY))
    {}
}
void ATD45DB161D::SectoreErase(uint8_t sector)
{
    DF_CS_inactive;
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
    while(!(ReadStatusRegister() & READY_BUSY))
    {}
}
void ATD45DB161D::ChipErase()
{
    DF_CS_inactive;
    DF_CS_active;
    spi_transfer(AT45DB161D_CHIP_ERASE_0);
    spi_transfer(AT45DB161D_CHIP_ERASE_1);
    spi_transfer(AT45DB161D_CHIP_ERASE_2);
    spi_transfer(AT45DB161D_CHIP_ERASE_3);            
    DF_CS_inactive;
    DF_CS_active;
    while(!(ReadStatusRegister() & READY_BUSY))
    {}
}
void ATD45DB161D::BeginPageWriteThroughBuffer(uint16_t page, uint16_t offset, uint8_t bufferNum)
{
    DF_CS_inactive;
    DF_CS_active;
    spi_transfer((bufferNum == 1)?AT45DB161D_PAGE_THROUGH_BUFFER_1:AT45DB161D_PAGE_THROUGH_BUFFER_2);
    spi_transfer((uint8_t)(page >> 6));
    spi_transfer((uint8_t)((page << 2) | (offset >> 8)));
    spi_transfer((uint8_t)offset);
}
void ATD45DB161D::EndAndWait()
{
    DF_CS_inactive;
    DF_CS_active;
    while(!(ReadStatusRegister() & READY_BUSY))
    {}
    DF_CS_inactive;
}
int8_t ATD45DB161D::ComparePageToBuffer(uint16_t page, uint8_t bufferNum)
{
    uint8_t status;
    DF_CS_inactive;
    DF_CS_active;
    spi_transfer((bufferNum == 1)?AT45DB161D_COMPARE_PAGE_TO_BUFFER_1:AT45DB161D_COMPARE_PAGE_TO_BUFFER_2);
    spi_transfer((uint8_t)(page >> 6));
    spi_transfer((uint8_t)(page << 2));
    spi_transfer(0x00);
    DF_CS_inactive;
    DF_CS_active;
    while(!((status = ReadStatusRegister()) & READY_BUSY))
    {}
    return ((status & COMPARE) ? 0 : 1);
}
void ATD45DB161D::DeepPowerDown()
{
    DF_CS_inactive;
    DF_CS_active;
    spi_transfer(AT45DB161D_DEEP_POWER_DOWN);
    DF_CS_inactive;
    wait_ms(100);
}

void ATD45DB161D::ResumeFromDeepPowerDown()
{
    DF_CS_inactive;
    DF_CS_active;
    spi_transfer(AT45DB161D_RESUME_FROM_DEEP_POWER_DOWN);
    DF_CS_inactive;
    wait_ms(100);
}